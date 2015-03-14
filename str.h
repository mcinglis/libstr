
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


size_t
str__count(
        char const * xs,
        bool ( * f )( char ) );


size_t
str__count_first(
        char const * xs,
        bool ( * f )( char ) );


size_t
str__count_last(
        char const * xs,
        bool ( * f )( char ) );


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
        bool ( * f )( char ) );


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
        bool ( * f )( char ) );


char const *
str__find(
        char const * xs,
        bool ( * f )( char ) );


char const *
str__find_not(
        char const * xs,
        bool ( * f )( char ) );


char const *
str__find_last(
        char const * xs,
        bool ( * f )( char ) );


char const *
str__find_last_not(
        char const * xs,
        bool ( * f )( char ) );


Maybe_size
str__find_index(
        char const * xs,
        bool ( * f )( char ) );


Maybe_size
str__find_index_not(
        char const * xs,
        bool ( * f )( char ) );


Maybe_size
str__find_last_index(
        char const * xs,
        bool ( * f )( char ) );


Maybe_size
str__find_last_index_not(
        char const * xs,
        bool ( * f )( char ) );


bool
str__any(
        char const * xs,
        bool ( * f )( char ) );


bool
str__all(
        char const * xs,
        bool ( * f )( char ) );


bool
str__only_one(
        char const * xs,
        bool ( * f )( char ) );


bool
str__only_one_not(
        char const * xs,
        bool ( * f )( char ) );


char
str__foldl(
        char const * xs,
        char init,
        char ( * f )( char acc, char x ) );


char
str__foldl1(
        char const * xs,
        char ( * f )( char acc, char x ) );


char
str__foldr(
        char const * xs,
        char init,
        char ( * f )( char x, char acc ) );


char
str__foldr1(
        char const * xs,
        char ( * f )( char x, char acc ) );


char const *
str__pick(
        char const * xs,
        bool ( * f )( char const * pick, char x ) );


struct str__each__options {
    bool ( * where )( char );
    bool ( * where_not )( char );
    void ( * f )( char );
    void ( * e )( char );
    bool ( * b )( char );
};

bool
str__each_(
        char const * const xs,
        struct str__each__options const o );

#define str__each( XS, ... ) \
    str__each_( XS, ( struct str__each__options ){ __VA_ARGS__ } )


bool
str__equal_by(
        char const * xs,
        char const * ys,
        bool ( * eq )( char, char ) );


bool
str__elem_by(
        char const * xs,
        char y,
        bool ( * f )( char x, char y ) );


char const *
str__elem_ptr_by(
        char const * xs,
        char y,
        bool ( * f )( char x, char y ) );


Maybe_size
str__elem_index_by(
        char const * xs,
        char y,
        bool ( * f )( char x, char y ) );


size_t
str__elem_count_by(
        char const * xs,
        char y,
        bool ( * f )( char x, char y ) );


bool
str__infix_by(
        char const * xs,
        char const * ys,
        bool ( * f )( char x, char y ) );


char const *
str__infix_ptr_by(
        char const * xs,
        char const * ys,
        bool ( * f )( char x, char y ) );


Maybe_size
str__infix_index_by(
        char const * xs,
        char const * ys,
        bool ( * f )( char x, char y ) );


size_t
str__infix_count_by(
        char const * const xs,
        char const * const ys,
        bool ( * const f )( char x, char y ) );


bool
str__is_prefix_by(
        char const * xs,
        char const * ps,
        bool ( * f )( char x, char p ) );


bool
str__is_suffix_by(
        char const * xs,
        char const * ss,
        bool ( * f )( char x, char s ) );


ord
str__compare_by(
        char const * xs,
        char const * ys,
        ord ( * f )( char x, char y ) );


char
str__minimum_by(
        char const * xs,
        ord ( * f )( char x, char min ) );


char
str__maximum_by(
        char const * xs,
        ord ( * f )( char x, char max ) );


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
str__elem(
        char const * xs,
        char y );


bool
str__elem_i(
        char const * xs,
        char y );


char const *
str__elem_ptr(
        char const * xs,
        char y );


char const *
str__elem_ptr_i(
        char const * xs,
        char y );


Maybe_size
str__elem_index(
        char const * xs,
        char y );


Maybe_size
str__elem_index_i(
        char const * xs,
        char y );


size_t
str__elem_count(
        char const * xs,
        char y );


size_t
str__elem_count_i(
        char const * xs,
        char y );


bool
str__infix(
        char const * xs,
        char const * ys );


bool
str__infix_i(
        char const * xs,
        char const * ys );


char const *
str__infix_ptr(
        char const * xs,
        char const * ys );


char const *
str__infix_ptr_i(
        char const * xs,
        char const * ys );


Maybe_size
str__infix_index(
        char const * xs,
        char const * ys );


Maybe_size
str__infix_index_i(
        char const * xs,
        char const * ys );


size_t
str__infix_count(
        char const * const xs,
        char const * const ys );


size_t
str__infix_count_i(
        char const * const xs,
        char const * const ys );


bool
str__is_prefix(
        char const * xs,
        char const * prefix );


bool
str__is_prefix_i(
        char const * xs,
        char const * prefix );


bool
str__is_suffix(
        char const * xs,
        char const * suffix );


bool
str__is_suffix_i(
        char const * xs,
        char const * suffix );


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
str__minimum(
        char const * xs );


char
str__maximum(
        char const * xs );


#endif // ifndef LIBSTR_STR_H

