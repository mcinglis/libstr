
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


#ifndef LIBSTR_STRM_H
#define LIBSTR_STRM_H


#include <libtypes/types.h>


// These functions are provided to be used when working with data structures
// of "char *", and the API expects functions taking arguments of type
// "char *".


bool
strm__is_empty(
        char * xs );


bool
strm__isnt_empty(
        char * xs );


bool
strm__is_length_1(
        char * xs );


bool
strm__equal(
        char * xs,
        char * ys );


bool
strm__equal_i(
        char * xs,
        char * ys );


bool
strm__not_equal(
        char * x,
        char * y );


bool
strm__not_equal_i(
        char * xs,
        char * ys );


ord
strm__compare(
        char * xs,
        char * ys );


ord
strm__compare_i(
        char * xs,
        char * ys );


char *
strm__null(
        void );


bool
strm__is_null(
        char * );


#endif // ifndef LIBSTR_STRM_H


