/* compile.c - Compile an automaton
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

#include "../memory/code.h"
//#include <lightning.h>

#include "determinize.h"
#include "character_set.h"
#include <assert.h>

#undef CONS
#define CONS(element, list)			\
  ({typeof (element) element_ = element;	\
    element_->next = list;			\
    element_;})


#undef FOREACH
#define FOREACH(element, list)				\
  for(element = list; element; element = element->next)

/* XXX: il y a encore des optimisiations possibles.

   Par exemple si on doit compiler une transition du style:

   [a-gi-l] -> c
   [h]->a

   On irait plus vite si on faisait:
   if(h)
    then goto a;
   if(>a and <l)
    then goto c;

    alors que pour le moment on teste pour voir si on est inferieur a g etc...

 */


/* XXX: cest pas vraiment un character que l'on compile, juste une
   partie d'un character.
   */
//static

/* On pourrait utiliser un tableau et pas se faire trop chier.
   En plus un tableau ca doit etre utile pour la minimisation.

 */
typedef struct ref_list
{
  struct ref_list *next;
  jit_insn *ref;
} *ref_list_t;

typedef struct patch_list
{
  ref_list_t refs;
  dfa_state_t state;
  struct patch_list *next; 
} *patch_list_t;

typedef void (*dfa_state_to_void_t)(dfa_state_t);

/* The start IPs of the different states.  */
void **state_ips;

/* The list of patches for each state.  */
patch_list_t *state_patch_lists;


 jit_insn *
compile_character(character_set_t character,
		  dfa_state_t to_state)
{
  /* XXX: ne pas transmettre de patch si il n'y en pas besoin.  */
  /* XXX: Optimisation: Regarder si c'est mieux de compiler en inverse.  */
  /* XXX: Optimisation: ne pas tester si on est en dessous de 255,
     c'est evident. */
  jit_insn *to_patch_ref; 	/* La reference vers l'etat. */
  jit_insn *ref;

  if (character->min == character->max)
    {
      to_patch_ref = jit_beqi_ui (jit_forward(), JIT_R0, character->min);
      /* Ah en fait jit_forward place le PC a cet endroit, comme
	 ca il pourra faire le calcul apres, et n'a qu'a stocker
	 l'endroit. Pas bete. */
    }
  else
    {
      if (character->max == 255) /* XXX: hardcoded 255. */
	{
	  to_patch_ref = jit_bgei_ui (jit_forward (), JIT_R0, character->min);
	}
      else if (character->min == 0) /* XXX: hardcoded 0 */
	{
	  to_patch_ref = jit_blei_ui (jit_forward (), JIT_R0, character->max);
	}
      else
	{
	  ref = jit_blti_ui (jit_forward (), JIT_R0, character->min);
	  to_patch_ref = jit_blei_ui(jit_forward (), JIT_R0, character->max);
	  jit_patch(ref);
	}
    }
  return to_patch_ref;
}


ref_list_t
compile_transition(dfa_transition_t transition)
{
  assert(transition->character);

//  if (!is_better_character_set_than_complement (transition->character))
//    {
//      display_character_set (transition->character);
//      display_character_set (complement_character_set (transition->character));
//    }
//      
//  assert (is_better_character_set_than_complement (transition->character));

  ref_list_t to_patch_refs = NULL;
  /* A mettre dans une phase d'optimisation a part*/
  if(is_better_character_set_than_complement (transition->character))
    {

      /* XXX: si l'ip existe deja, pas besoin de referencer.  */
      character_set_t character;
      FOREACH (character, transition->character)
	{
	  jit_insn *ref;
	  ref = compile_character (character, transition->state);
	  ref_list_t ref_elm = MALLOC (ref_list);
	  ref_elm->ref = ref;
	  to_patch_refs = CONS (ref_elm, to_patch_refs);
	}
    }
  else
    {
      character_set_t comp = complement_character_set (transition->character);
      
      ref_list_t refs = NULL;

      /* XXX: si l'ip existe deja, pas besoin de referencer.  */
      character_set_t character;
      FOREACH (character, comp)
	{
	  jit_insn *ref;
	  ref = compile_character (character, transition->state);
	  ref_list_t ref_elm = MALLOC (ref_list);
	  ref_elm->ref = ref;
	  refs = CONS (ref_elm, refs);
	}
      to_patch_refs = MALLOC (ref_list);
      to_patch_refs->ref = jit_jmpi (jit_forward ());
      to_patch_refs->next = NULL;

      ref_list_t iter;
      FOREACH (iter, refs)
	{
	  jit_patch (iter->ref);
	}

      free (comp);
      
    }

  return to_patch_refs;
}



/* XXX: optimisation: si l'union des character set d'une transition
   est 0-255, il est inutile de faire des tests pour la derniere, et
   il ne sert a rien de faire un jit_ret non plus.
   */

/* Compile un état, et renvoie l'association list
   (etat . liste_ref_a_patcher_pour_cet_etat) */
patch_list_t
compile_state(dfa_state_t state, dfa_state_to_void_t compile_get_next, void_to_void_t compile_ungetc)
{
  /* Get the letter in R0.  */
  compile_get_next(state);

  patch_list_t patch_list = NULL;

  dfa_transition_t transition;
  FOREACH (transition, state->transitions)
    {
      ref_list_t refs = compile_transition (transition);
      patch_list_t element = MALLOC (patch_list);
      element->refs = refs;
      element->state = transition->state;
      patch_list = CONS (element, patch_list);
    }
  
  /* Le truc n'a pas su ou aller. On remet le charactere precedent et
     On renvoie l'etat actuel.  Sauf pour les character class negatif
     en fait.  */
  /* XXX: est qu'il faut faire un ungetc quand on est pas reconnu? cf grep. non je crois pas.  */
  if (state->terminal)
    compile_ungetc ();
  jit_movi_ui (JIT_RET, state->terminal);
  jit_ret ();

  return patch_list;
  
}

void
patch_state (patch_list_t patches)
{
  patch_list_t patch_list;
  FOREACH (patch_list, patches)
    {
      dfa_state_t destination = patch_list->state;
      jit_insn *destination_ip = state_ips[destination->index];

      ref_list_t patch;
      FOREACH (patch, patch_list->refs)
	{
	  jit_insn *ref = patch->ref;
	  jit_patch_at (ref, destination_ip);
	}
    }
}

//jit_insn code_buffer[4096];

/* Compiles the deterministic automaton AUTOMATON. COMPILE_GET_NEXT
   must output code to put the current letter in R0. */
void_to_ui_t
compile_dfa_automaton (dfa_automaton_t automaton, dfa_state_to_void_t compile_get_next, void_to_void_t compile_ungetc)
{
  unsigned int nb_states = automaton->nb_states;
  state_ips = CALLOC (nb_states, void *);
  state_patch_lists = CALLOC (nb_states, patch_list_t);
  
//  jit_insn* code_buffer = xmalloc (521 * sizeof(jit_insn)
//				   * automaton->nb_states);
//  
//  void_to_ui_t automaton_function = jit_set_ip (code_buffer).uiptr;
//

  void * code_buffer = allocate_code_space (512 * sizeof(jit_insn)
					    * automaton->nb_states);
  
  /* XXX: we should use leaf instead of prolog depending on
     compile_get_next. */
  //  jit_prolog (0);
  jit_leaf (0);

  unsigned int index;

  for (index = 0; index < nb_states; index++)
    {
      state_ips[index] = jit_get_ip ().ptr;
      state_patch_lists[index] = compile_state (automaton->states[index],
						compile_get_next,
						compile_ungetc);
    }

    for (index = 0; index < nb_states; index++)
    {
      patch_state (state_patch_lists[index]);
    }

    finish_code (code_buffer);

    void_to_ui_t automaton_function = (void_to_ui_t) code_buffer;
    //    jit_flush_code (code_buffer, jit_get_ip ().ptr);
    //    xrealloc (code_buffer, (char *) jit_get_ip ().ptr - (char *) code_buffer);
    /* XXX: asserts that the buffer has not been moved and was big
       enough.  */
    return automaton_function;
}


//char *test_string;
volatile char *test_string_current;
unsigned int test_string_index = 0;
#define PAS_INDEX 		/* Pas d'index, mais current */

#ifdef PAS_INDEX

/* For a string. Et ca fera une bonne introduction a ldi, ldxi et extr
   et sti. Et a l'integration C/assembleur.  Evidememnt on pourrait
   utiliser getc, mais plus tard il vaut mieux mmaper le fichier en
   memoire, donc ca reviendra aux strings. */
void
compile_get_next_string (dfa_state_t state)
{
#if 0
  jit_ldi_p (JIT_R0, &test_string_current);
  jit_ldi_p (JIT_R1, &test_string_current);
  /* jit_ldi_ui (JIT_R1, &test_string_index);*/
  /* Attention, on serait
					      tente de faire un simple
					      move, mais dans ce cas
					      la valeur est celle a la
					      compilation, et pas
					      celle a l'execution. */
  jit_movr_p (JIT_R1, JIT_R0);
  jit_ldr_uc (JIT_R0, JIT_R1);
  jit_extr_uc_ui (JIT_R0, JIT_R0); /* Passe en unsigned int */

  jit_addi_p (JIT_R1, JIT_R1, 1);
  jit_sti_p (&test_string_current, JIT_R1);
  

#else  
  jit_ldi_p (JIT_R1, &test_string_current);
  /* jit_ldi_ui (JIT_R1, &test_string_index);*/
  /* Attention, on serait
					      tente de faire un simple
					      move, mais dans ce cas
					      la valeur est celle a la
					      compilation, et pas
					      celle a l'execution. */
  jit_ldr_uc (JIT_R0, JIT_R1);
  jit_extr_uc_ui (JIT_R0, JIT_R0); /* Passe en unsigned int */

  jit_addi_p (JIT_R1, JIT_R1, 1);
  jit_sti_p (&test_string_current, JIT_R1);
  #endif
}  
#else

/* For a string. Et ca fera une bonne introduction a ldi, ldxi et extr
   et sti. Et a l'integration C/assembleur.  Evidememnt on pourrait
   utiliser getc, mais plus tard il vaut mieux mmaper le fichier en
   memoire, donc ca reviendra aux strings. */
void
compile_get_next (dfa_state_t state)
{
  jit_ldi_p (JIT_R0, &test_string);
  jit_ldi_ui (JIT_R1, &test_string_index); /* Attention, on serait
					      tente de faire un simple
					      move, mais dans ce cas
					      la valeur est celle a la
					      compilation, et pas
					      celle a l'execution. */
  jit_ldxr_c (JIT_R0, JIT_R0, JIT_R1);
  jit_extr_c_ui (JIT_R0, JIT_R0); /* Passe en unsigned int */

  jit_addi_ui (JIT_R1, JIT_R1, 1);
  jit_sti_ui (&test_string_index, JIT_R1);
}  
#endif

#if 0
/* For a string. Et ca fera une bonne introduction a ldi, ldxi et extr
   et sti. Et a l'integration C/assembleur.  Evidememnt on pourrait
   utiliser getc, mais plus tard il vaut mieux mmaper le fichier en
   memoire, donc ca reviendra aux strings. */
void
compile_get_next_grep (dfa_state_t state)
{
  /* Bon il faudrait mettre R0 a 1 au debut sinon on risque de faire de la merde.  */
  /* Ca c'est n'imp, il suffit que . ne comprenne pas le 0 et le \n et
     on gagne du temps.  */
  /* On peut aussi gagner en utilisantun pointeur sur char au lieu
     d'un index a la con. */
  jit_insn *ref1 = jit_beqi_ui (jit_forward (), JIT_R0, 0);
  jit_insn *ref2 = jit_beqi_ui (jit_forward (), JIT_R0, (unsigned int) '\n');
  jit_insn *ref3 = jit_jmpi (jit_forward ());
  
  jit_patch (ref1);
  jit_patch (ref2);
  jit_movi_ui (JIT_RET, state->terminal);
  jit_ret ();

  jit_patch (ref3);
  
  jit_ldi_p (JIT_R0, &test_string);
  jit_ldi_ui (JIT_R1, &test_string_index); /* Attention, on serait
					      tente de faire un simple
					      move, mais dans ce cas
					      la valeur est celle a la
					      compilation, et pas
					      celle a l'execution. */
  jit_ldxr_c (JIT_R0, JIT_R0, JIT_R1);
  jit_extr_c_ui (JIT_R0, JIT_R0); /* Passe en unsigned int */

  jit_addi_ui (JIT_R1, JIT_R1, 1);
  jit_sti_ui (&test_string_index, JIT_R1);

  
  
}  
#endif

       #include <sys/types.h>
       #include <sys/stat.h>
       #include <unistd.h>
       #include <fcntl.h>
       #include <sys/mman.h>
/* Grep-test: */

//#include "lexer.c"

#if 0
int
grep_main (int argc, char **argv)
{
  
  //test_merge_list_transition_into ();
  //thompson_automaton_t automaton = parse_regexp ("([a-f]*|[b-h])");
  //  thompson_automaton_t automaton = parse_regexp (".*[a-z ]+.*\n");
  //    thompson_automaton_t automaton = parse_regexp ("[a-z]+.*[a-z]*\n");
  
  /* On pourrait faire le truc suivant: on fait un multi-regexp match,
     un est .*\n, l'autre est .*int.*\n, comme ca on sait lequel a
     marche.  */
  //thompson_automaton_t automaton = parse_regexp (".*int.*\n");
  thompson_automaton_t automaton = parse_regexp (".*(int|char).*\n");
  //  thompson_automaton_t automaton = parse_regexp (".*(a*b|ab*).*\n");
  //    thompson_automaton_t automaton = parse_regexp ("(a*b|ab*)");
  
  //      thompson_automaton_t automaton = parse_regexp (".*(int|truc).*\n"); /* XXX: celle la est plus longue. Trouver pourquoi. Quel est l'influence de la minimisation de l'automate. */
  //thompson_automaton_t automaton = parse_regexp (".*to");
  //  thompson_automaton_t automaton = parse_regexp ("a");
  //  thompson_automaton_t automaton = parse_regexp ("[b-f]a");
  //  thompson_automaton_t automaton = parse_regexp ("[a-f]*");
  display_automaton (automaton);

  //  asm("jmp 0");
  //  make_eclosure_list_transition (automaton->initial);
  dfa_state_t dfa_states = determinize (automaton);

  
  display_dfa_automaton (dfa_states);
  
  dfa_automaton_t dfa_automaton = indexate_automaton (dfa_states);

  //void_to_ui_t fun = compile_dfa_automaton (dfa_automaton, &compile_get_next_grep);
  void_to_ui_t fun = compile_dfa_automaton (dfa_automaton, &compile_get_next_string);

  unsigned int result;

  unsigned int old_string_index = 0;
  
  //test_string = strdup ("ccccaint\ntruc muche\n toto\n int\nint\n int "); //"totoalaplage";

  unsigned int fd = open ("test", O_RDONLY);
  struct stat the_stat;

  stat ("test", &the_stat);
  off_t length = the_stat.st_size;

  printf ("Size: %d\n", length);
  
  //test_string = test_string;
  test_string_current = mmap (0, length, PROT_READ, MAP_SHARED, fd, 0);
  char *old_string_current = test_string_current;

#ifdef PAS_INDEX  
  while (*test_string_current)
    {
      result = fun ();
      if (result)
	{
//	{
//	  char *string = strndup (old_string_current, test_string_current - old_string_current - 1 );
//	  printf (string);
//	  //	  *(test_string_current) = 0;
//	  //	  puts (old_string_current);
//	  //	  printf ("\n");
	  test_string_current --;
	  write (1, old_string_current, test_string_current - old_string_current);
	
	}
//	}
//	old_string_current = test_string_current + 1;
//	}
//      else
//	{

      if (*(test_string_current - 1) != '\n')
      	fprintf (stderr, "error\n");

	  old_string_current = test_string_current;
	  //	}

	  
    }

  
  #else
  //  size_t size = strlen (test_string);

  /* XXX: plutot que d'ecrire des 0, il suffit d'appeller write en fait. */
  //  while (test_string_index <= size)
    while (test_string[test_string_index])
    {
      result = fun ();
      if (result)
	{
	  write (1, &test_string[old_string_index], test_string_index - old_string_index);
	  //	  char c = 0;
	  // write (1, &c, 1);
	}
	//	printf ("phrase: %s\n", &test_string[old_string_index]);
      old_string_index = test_string_index;
    }
  #endif
  return 0;
}
#endif
