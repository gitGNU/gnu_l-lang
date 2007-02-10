## Makefile.am -- Makefile template for the compiler
# Copyright (C) 2007 Matthieu Lemerre.
#
# This file is part of the L Programming Language.
# 
# The L Programming Language is free software; you can redistribute it
# and/or modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either version
# 2.1 of the License, or (at your option) any later version.
#
# The L Programming Language is distributed in the hope that it will
# be useful, but WITHOUT ANY WARRANTY; without even the implied
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301
# USA.

lib_LTLIBRARIES = libl-std.la

libl_std_la_SOURCES =  init_library.c xml.c list.c output.c print.c hash.c l-form.c \
		       creator.c


#bin_PROGRAMS = test
##test_SOURCES = ../lexer/nfa.c ../lexer/transitions.c ../lexer/character_set.c ../lexer/list_set.c ../lexer/determinize.c ../lexer/compile.c ../runtime/panic.c ../runtime/read-sexp.c ../memory/code.c ../memory/memory.c ../objects/symbol.c ../objects/object.c ../objects/pair.c ../runtime/write-object.c ../objects/fixnum.c ../objects/string.c
#test_LDFLAGS = -lJudy
#test_SOURCES = generate.c location.c form.c analysis.c
#test_LDADD = ../memory/libl-memory.a ../runtime/libl-runtime.a  \
#	     ../objects/libl-objects.a  ../memory/libl-memory.a \
#	     ../lexer/libl-lexer.a
#
AM_CFLAGS = -g -O0 -Wall
CFLAGS = -g -O0 -Wall
