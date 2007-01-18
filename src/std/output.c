/* output.c - Output functions base.
   Copyright (C) 2007 Matthieu Lemerre <racin@free.fr>

   This file is part of the L programming language.

   The L programming language is free software; you can redistribute it 
   and/or modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.
   
   The L programming language is distributed in the hope that it will be 
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty 
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
   GNU Lesser General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public License
   along with the L programming language; see the file COPYING.  If not,
   write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
   Boston, MA  02110-1301  USA.  */

#include <assert.h>
#include "../compiler/c-to-l.h"
#include <l/sys/panic.h>
#include <l/string.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>


/* Buffered output: print_string.  */
   
typedef struct output_buffer
{
  /* Current location of the buffer; where to write to it.  */
  void *current;

  /* Start of the buffer.  */
  void *start;

  /* End of the buffer.  If reached, the buffer _has_ to be flushed.  */
  void *end;

  /* Output buffers are chained in lists.  */
  struct output_buffer *next;
} *output_buffer_t;

/* For now, output_buffer_queue isn't a queue.  */
static output_buffer_t
output_buffer_queue;

static unsigned int page_size;

static unsigned int log2_page_size;

/* Get an output buffer from the queue.  The size of an output buffer
   is always a page.  */
output_buffer_t
get_output_buffer (void)
{
  if(output_buffer_queue == NULL)
    {
      output_buffer_t ob = MALLOC (output_buffer);
      ob->start = mmap (NULL, page_size, PROT_WRITE,
			MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
      //      if(ob->start == (void *) -1)
      //	printf ("ERROR: %s\n", strerror (errno));
	
      assert (ob->start !=(void *) -1);
      ob->current = ob->start;
      ob->end = ob->start + page_size;
      return ob;
    }

  output_buffer_t ob = output_buffer_queue;
  output_buffer_queue = ob->next;
  ob->current = ob->start;
  return ob;
}

/* Replace an output buffer to the queue.  Does not flush its contents
   into memory.  */
void
free_output_buffer (output_buffer_t output_buffer)
{
  output_buffer->next = output_buffer_queue;
  output_buffer_queue = output_buffer;
}

typedef void (*flush_output_buffer_function)(void *, output_buffer_t);


/* Output descriptors.  */

typedef struct output_descriptor
{
  /* Current output buffer.  */
  output_buffer_t current_output_buffer;

  /* The flush function is in fact a closure.  */
  void *flush_data;
  
  flush_output_buffer_function flush_function;
} *output_descriptor_t;

/* All print functions write to this.  If you want to change where you
   write, use the with_output_to macro, that is the equivalent of a
   special let. */
/* __thread */ output_descriptor_t current_output_descriptor;

/* Flush an output descriptor.  */
void
flush_output_descriptor (output_descriptor_t output_descriptor)
{
  if(output_descriptor->current_output_buffer)
    {
      output_descriptor->flush_function (output_descriptor->flush_data,
					 output_descriptor->current_output_buffer);
      free_output_buffer (output_descriptor->current_output_buffer);
      output_descriptor->current_output_buffer = NULL;
    }
}

void
flush (void)
{
  flush_output_descriptor (current_output_descriptor);
}


/* Later, we will write also a multi-threaded aware version.  */
void print_string (string_t string)
{
  output_descriptor_t output_descriptor = current_output_descriptor;
  output_buffer_t output_buffer = output_descriptor->current_output_buffer;

  if(output_buffer == NULL)
    {
      output_descriptor->current_output_buffer
	= output_buffer
	= get_output_buffer ();
    }
  
  if(output_buffer->current + string->length <= output_buffer->end)
    {
      /* Multi_threaded: use fetch and add on output_buffer->current
	 first.  */
      memcpy (output_buffer->current, string->content, string->length);
      output_buffer->current += string->length;
    }
  else
    {
      /* If the string spans on several pages, we put the first part
	 to output buffers, send directly the middle part (without
	 copying), and put the last part to an output buffer too.

	 Note: this test is not accurate.  */
      if(((unsigned int) (string->content + string->length) >> log2_page_size)
	 - ((unsigned int) string->content >> log2_page_size) > 2)
	{
	  panic ("Not yet implemented\n");
	}
      
      unsigned int copied_bytes = output_buffer->end - output_buffer->current;
      
      /* Fill the output buffer until the end.  */
      memcpy (output_buffer->current, string->content, copied_bytes);
      output_buffer->current = output_buffer->end;
      output_descriptor->flush_function (output_descriptor->flush_data,
					 output_buffer);

      /* Get a new output buffer.  */
      output_buffer_t new_output_buffer = get_output_buffer ();

      output_descriptor->current_output_buffer = new_output_buffer;

      /* Write the end of the string.
	 Note: this assertion may be triggered is the string is > pagesize.  */
      assert (string->length - copied_bytes <= page_size);

      memcpy (new_output_buffer->start, string->content + copied_bytes,
	      string->length - copied_bytes);
      new_output_buffer->current = new_output_buffer->start +
	(string->length - copied_bytes);
    }
}

/* Print a string to a different output descriptor.  A with_output_to
   macro should do this.  */
void print_string_to_output_descriptor (string_t string,
					output_descriptor_t od)
{
  output_descriptor_t save_od = current_output_descriptor;
  current_output_descriptor = od;
  print_string (string);
  current_output_descriptor = save_od;
}


/* Some output descriptors.  */

output_descriptor_t stdout_output_descriptor;
output_descriptor_t stderr_output_descriptor;


/* Flush output to a UNIX file descriptor.  */
void flush_unix_fd (void *file_descriptor, output_buffer_t buffer)
{
  assert (buffer);
  int fd = (int) file_descriptor;
  write (fd, buffer->start, buffer->current - buffer->start);
}

output_descriptor_t
make_unix_fd_output_descriptor (int fd)
{
  output_descriptor_t od = MALLOC (output_descriptor);
  od->flush_data = (void *) fd;
  od->flush_function = flush_unix_fd;
  od->current_output_buffer = NULL;
  return od;
}



#include <math.h>
void
init_output (void)
{
  page_size = getpagesize ();

  log2_page_size = (unsigned int) log2f ((float) page_size);
  /* Declare the type output descriptor, and the functions to read and
     write to them.  */
  
  stdout_output_descriptor = make_unix_fd_output_descriptor (1);
  stderr_output_descriptor = make_unix_fd_output_descriptor (2);

  current_output_descriptor = stdout_output_descriptor;

  DEFINE_C_FUNCTION2 ("print_String", print_string, "void <- (String)");
  DEFINE_C_FUNCTION (flush, "void <- ()");
  
  /* For now, maybe_flush is just like flush; but with
     maybe_flush,flushing must be done only if the stream is
     interactive.  */
  DEFINE_C_FUNCTION2 ("maybe_flush", flush, "void <- ()");
}

void
cleanup_output (void)
{
  /* XXX:  Flush every open output buffers, and close them.  */
}
