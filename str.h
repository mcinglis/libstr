
// Copyright 2015  Malcolm Inglis <http://minglis.id.au>
//
// This file is part of Libstr.
//
// Libstr is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the
// Free Software Foundation, either version 3 of the License, or (at your
// option) any later version.
//
// Libstr is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
// more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with Libstr. If not, see <https://gnu.org/licenses/>.


#ifndef LIBSTR_STR_H
#define LIBSTR_STR_H


#include <libtypes/types.h>


void
str__copy_into_strm(
        char const * from,
        char * to,
        size_t n );


size_t
str__length(
        char const * xs );


size_t
str__length_null(
        char const * xs );


size_t
str__size(
        char const * xs );


size_t
str__size_null(
        char const * xs );


bool
str__is_empty(
        char const * xs );


bool
str__isnt_empty(
        char const * xs );


bool
str__is_length_1(
        char const * xs );


bool
str__equal_by(
        char const * xs,
        char const * ys,
        bool ( * eq )( char x, char y ) );


ord
str__compare_by(
        char const * xs,
        char const * ys,
        ord ( * f )( char x, char y ) );


bool
str__equal(
        char const * xs,
        char const * ys );


bool
str__equal_i(
        char const * xs,
        char const * ys );


bool
str__not_equal(
        char const * x,
        char const * y );


bool
str__not_equal_i(
        char const * xs,
        char const * ys );


ord
str__compare(
        char const * xs,
        char const * ys );


ord
str__compare_i(
        char const * xs,
        char const * ys );


#endif // ifndef LIBSTR_STR_H

