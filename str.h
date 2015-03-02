
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
#include <libmacro/nelem.h>
#include <libmaybe/def/maybe-size.h>


char const *
str__id(
        char const * xs );


size_t
str__length(
        char const * xs );


size_t
str__size(
        char const * xs );


bool
str__is_empty(
        char const * xs );


bool
str__is_length_1(
        char const * xs );


char
str__at(
        char const * xs,
        size_t index );


char const *
str__ptr_at(
        char const * xs,
        size_t index );


char
str__first(
        char const * xs );


char
str__last(
        char const * xs );


bool
str__any(
        char const * xs,
        bool ( * p )( char ) );


bool
str__all(
        char const * xs,
        bool ( * p )( char ) );


size_t
str__count(
        char const * xs,
        bool ( * p )( char ) );


size_t
str__count_first(
        char const * xs,
        bool ( * p )( char ) );


size_t
str__count_last(
        char const * xs,
        bool ( * p )( char ) );


char const *
str__take_end(
        char const * xs,
        size_t n );


char const *
str__take_end_1(
        char const * xs );


char const *
str__take_end_2(
        char const * xs );


char const *
str__take_end_3(
        char const * xs );


char const *
str__take_end_while(
        char const * xs,
        bool ( * p )( char ) );


char const *
str__drop(
        char const * xs,
        size_t n );


char const *
str__drop_1(
        char const * xs );


char const *
str__drop_2(
        char const * xs );


char const *
str__drop_3(
        char const * xs );


char const *
str__drop_while(
        char const * xs,
        bool ( * p )( char ) );


bool
str__equal_by(
        char const * xs,
        char const * ys,
        bool ( * eq )( char, char ) );


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


bool
str__elem_by(
        char const * xs,
        char c,
        bool ( * eq )( char, char ) );


bool
str__elem(
        char const * xs,
        char c );


bool
str__elem_i(
        char const * xs,
        char c );


bool
str__not_elem(
        char const * xs,
        char c );


bool
str__not_elem_i(
        char const * xs,
        char c );


Maybe_size
str__elem_index_by(
        char const * xs,
        char c,
        bool ( * eq )( char, char ) );


Maybe_size
str__elem_index(
        char const * xs,
        char c );


Maybe_size
str__elem_index_i(
        char const * xs,
        char c );


char const *
str__elem_ptr_by(
        char const * xs,
        char c,
        bool ( * eq )( char, char ) );


char const *
str__elem_ptr(
        char const * xs,
        char c );


char const *
str__elem_ptr_i(
        char const * xs,
        char c );


char const *
str__find(
        char const * xs,
        bool ( * p )( char ) );


size_t
str__count_elem_by(
        char const * xs,
        char c,
        bool ( * eq )( char, char ) );


size_t
str__count_elem(
        char const * xs,
        char c );


size_t
str__count_elem_i(
        char const * xs,
        char c );


bool
str__is_prefix_by(
        char const * xs,
        char const * prefix,
        bool ( * eq )( char, char ) );


bool
str__is_prefix(
        char const * xs,
        char const * prefix );


bool
str__is_prefix_i(
        char const * xs,
        char const * prefix );


bool
str__is_suffix_by(
        char const * xs,
        char const * suffix,
        bool ( * eq )( char, char ) );


bool
str__is_suffix(
        char const * xs,
        char const * suffix );


bool
str__is_suffix_i(
        char const * xs,
        char const * suffix );


bool
str__is_infix_by(
        char const * xs,
        char const * ys,
        bool ( * eq )( char, char ) );


bool
str__is_infix(
        char const * xs,
        char const * ys );


bool
str__is_infix_i(
        char const * xs,
        char const * ys );


Maybe_size
str__index_str_by(
        char const * xs,
        char const * ys,
        bool ( * eq )( char, char ) );


Maybe_size
str__index_str(
        char const * xs,
        char const * ys );


Maybe_size
str__index_str_i(
        char const * xs,
        char const * ys );


ord
str__compare_by(
        char const * xs,
        char const * ys,
        ord ( * cmp )( char, char ) );


ord
str__compare(
        char const * xs,
        char const * ys );


ord
str__compare_i(
        char const * xs,
        char const * ys );


bool
str__less_than(
        char const * xs,
        char const * ys );


bool
str__less_than_or_eq(
        char const * xs,
        char const * ys );


bool
str__greater_than_or_eq(
        char const * xs,
        char const * ys );


bool
str__greater_than(
        char const * xs,
        char const * ys );


char const *
str__min2(
        char const * xs,
        char const * ys );


char const *
str__max2(
        char const * xs,
        char const * ys );


char const *
str__min_n(
        char const * const * xss,
        size_t n );


char const *
str__max_n(
        char const * const * xss,
        size_t const n );


#define str__min( ... ) \
    str__min_n( ( char const * [] ){ __VA_ARGS__ }, \
                NELEM( ( char const * [] ){ __VA_ARGS__ } ) )


#define str__max( ... ) \
    str__max_n( ( char const * [] ){ __VA_ARGS__ }, \
                NELEM( ( char const * [] ){ __VA_ARGS__ } ) )


char const *
str__clamp(
        char const * lower,
        char const * upper,
        char const * xs );


bool
str__in_range(
        char const * lower,
        char const * upper,
        char const * xs );


bool
str__in_xrange(
        char const * lower,
        char const * upper,
        char const * xs );


char
str__minimum_by(
        char const * xs,
        ord ( * cmp )( char, char ) );


char
str__minimum(
        char const * xs );


char
str__maximum_by(
        char const * xs,
        ord ( * cmp )( char, char ) );


char
str__maximum(
        char const * xs );


#endif // ifndef LIBSTR_STR_H

