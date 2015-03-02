
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
#include <libmacro/nelem.h>
#include <libmaybe/def/maybe-size.h>


char *
strm__id(
        char * xs );


size_t
strm__length(
        char * xs );


size_t
strm__size(
        char * xs );


bool
strm__is_empty(
        char * xs );


bool
strm__is_length_1(
        char * xs );


char
strm__at(
        char * xs,
        size_t index );


char *
strm__ptr_at(
        char * xs,
        size_t index );


char
strm__first(
        char * xs );


char
strm__last(
        char * xs );


bool
strm__any(
        char * xs,
        bool ( * p )( char ) );


bool
strm__all(
        char * xs,
        bool ( * p )( char ) );


size_t
strm__count(
        char * xs,
        bool ( * p )( char ) );


size_t
strm__count_first(
        char * xs,
        bool ( * p )( char ) );


size_t
strm__count_last(
        char * xs,
        bool ( * p )( char ) );


char *
strm__take_end(
        char * xs,
        size_t n );


char *
strm__take_end_1(
        char * xs );


char *
strm__take_end_2(
        char * xs );


char *
strm__take_end_3(
        char * xs );


char *
strm__take_end_while(
        char * xs,
        bool ( * p )( char ) );


char *
strm__drop(
        char * xs,
        size_t n );


char *
strm__drop_1(
        char * xs );


char *
strm__drop_2(
        char * xs );


char *
strm__drop_3(
        char * xs );


char *
strm__drop_while(
        char * xs,
        bool ( * p )( char ) );


bool
strm__equal_by(
        char * xs,
        char * ys,
        bool ( * eq )( char, char ) );


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


bool
strm__elem_by(
        char * xs,
        char c,
        bool ( * eq )( char, char ) );


bool
strm__elem(
        char * xs,
        char c );


bool
strm__elem_i(
        char * xs,
        char c );


bool
strm__not_elem(
        char * xs,
        char c );


bool
strm__not_elem_i(
        char * xs,
        char c );


Maybe_size
strm__elem_index_by(
        char * xs,
        char c,
        bool ( * eq )( char, char ) );


Maybe_size
strm__elem_index(
        char * xs,
        char c );


Maybe_size
strm__elem_index_i(
        char * xs,
        char c );


char *
strm__elem_ptr_by(
        char * xs,
        char c,
        bool ( * eq )( char, char ) );


char *
strm__elem_ptr(
        char * xs,
        char c );


char *
strm__elem_ptr_i(
        char * xs,
        char c );


char *
strm__find(
        char * xs,
        bool ( * p )( char ) );


size_t
strm__count_elem_by(
        char * xs,
        char c,
        bool ( * eq )( char, char ) );


size_t
strm__count_elem(
        char * xs,
        char c );


size_t
strm__count_elem_i(
        char * xs,
        char c );


bool
strm__is_prefix_by(
        char * xs,
        char * prefix,
        bool ( * eq )( char, char ) );


bool
strm__is_prefix(
        char * xs,
        char * prefix );


bool
strm__is_prefix_i(
        char * xs,
        char * prefix );


bool
strm__is_suffix_by(
        char * xs,
        char * suffix,
        bool ( * eq )( char, char ) );


bool
strm__is_suffix(
        char * xs,
        char * suffix );


bool
strm__is_suffix_i(
        char * xs,
        char * suffix );


bool
strm__is_infix_by(
        char * xs,
        char * ys,
        bool ( * eq )( char, char ) );


bool
strm__is_infix(
        char * xs,
        char * ys );


bool
strm__is_infix_i(
        char * xs,
        char * ys );


Maybe_size
strm__index_strm_by(
        char * xs,
        char * ys,
        bool ( * eq )( char, char ) );


Maybe_size
strm__index_strm(
        char * xs,
        char * ys );


Maybe_size
strm__index_strm_i(
        char * xs,
        char * ys );


ord
strm__compare_by(
        char * xs,
        char * ys,
        ord ( * cmp )( char, char ) );


ord
strm__compare(
        char * xs,
        char * ys );


ord
strm__compare_i(
        char * xs,
        char * ys );


bool
strm__less_than(
        char * xs,
        char * ys );


bool
strm__less_than_or_eq(
        char * xs,
        char * ys );


bool
strm__greater_than_or_eq(
        char * xs,
        char * ys );


bool
strm__greater_than(
        char * xs,
        char * ys );


char *
strm__min2(
        char * xs,
        char * ys );


char *
strm__max2(
        char * xs,
        char * ys );


char *
strm__min_n(
        char * const * xss,
        size_t n );


char *
strm__max_n(
        char * const * xss,
        size_t const n );


#define strm__min( ... ) \
    strm__min_n( ( char * [] ){ __VA_ARGS__ }, \
                NELEM( ( char * [] ){ __VA_ARGS__ } ) )


#define strm__max( ... ) \
    strm__max_n( ( char * [] ){ __VA_ARGS__ }, \
                NELEM( ( char * [] ){ __VA_ARGS__ } ) )


char *
strm__clamp(
        char * lower,
        char * upper,
        char * xs );


bool
strm__in_range(
        char * lower,
        char * upper,
        char * xs );


bool
strm__in_xrange(
        char * lower,
        char * upper,
        char * xs );


char
strm__minimum_by(
        char * xs,
        ord ( * cmp )( char, char ) );


char
strm__minimum(
        char * xs );


char
strm__maximum_by(
        char * xs,
        ord ( * cmp )( char, char ) );


char
strm__maximum(
        char * xs );


#endif // ifndef LIBSTR_STRM_H
