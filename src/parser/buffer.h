/* buffer.h - 
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

#ifndef _BUFFER_H
#define _BUFFER_H

#include <l/sys/panic.h>

/* This is for a non-zero terminated read buffer.  */
typedef struct read_buffer
{
  char *current;
  char *start; /* XXX: start is in fact useless.  */
  char *end;
} *read_buffer_t;

typedef read_buffer_t Read_Buffer;

static inline char
buffer_getchar (Read_Buffer buffer)
{
  if(buffer->current >= buffer->end)
     panic ("Buffer too short\n");

  return *buffer->current++;
}

static inline char
buffer_nextchar (Read_Buffer buffer)
{
  if(buffer->current >= buffer->end)
    panic ("Buffer too short\n");

  return *buffer->current;
}

//inline int
//is_end_of_buffer (Read_Buffer buffer)
//{
//}

static inline Read_Buffer
Read_Buffer_From_String (char *string)
{
  Read_Buffer buf = MALLOC (read_buffer);

  buf->start = strdup (string);
  buf->current = buf->start;
  buf->end = buf->start + strlen (string) + 1;

  return buf;
}

Read_Buffer
Read_Buffer_From_File_Name (char *filename);

typedef struct zero_terminated_read_buffer
{
  char *current;
} *zero_terminated_read_buffer_t;

typedef zero_terminated_read_buffer_t Zero_Terminated_Read_Buffer;

//inline char
//zero_buffer_getchar 

#endif
