## Makefile.am -- Makefile template for L
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

SUBDIRS = memory compiler expander parser std objects c-output new-parser

#the L library, useful for linking with other programs.
lib_LTLIBRARIES = libl.la

libl_la_SOURCES = init.c eval.c

libl_la_LIBADD = objects/libl-objects.la \
	  	memory/libl-memory.la \
		parser/libl-parser.la \
		compiler/libl-generator.la \
	        expander/libl-expand.la \
		memory/libl-memory.la \
		std/libl-std.la  \
		c-output/libl-c-output.la \
		new-parser/libl-new-parser.la \
		-lJudy -lm
#		/usr/lib/libJudy.a /usr/lib/libm.a


bin_PROGRAMS = L c_output # test
L_SOURCES = main.c
# init.c eval.c

L_LDADD = libl.la

#objects/libl-objects.la \
#	     memory/libl-memory.la \
#	     parser/libl-parser.la \
#             compiler/libl-generator.la \
#             expander/libl-expand.la \
#	     memory/libl-memory.la lexer/libl-lexer.a  \
#	     std/libl-std.la  \
#	     c-output/libl-c-output.la \
#	     -lJudy -lm


L_LDFLAGS = -lJudy

#Test is useful to test another file. Don't forget to init L in the file if you need it.
c_output_SOURCES = c-output/c-output.c
c_output_LDADD = libl.la

test_SOURCES = test.c
test_LDADD= libl.la
test_LDFLAGS = -lJudy

AM_CFLAGS = -g -O0 -Wall
CFLAGS = -g -O0 -Wall
