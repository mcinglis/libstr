
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
#include <libmaybe/def/maybe_size.h>


char *
strm__copy_str(
        char const * const xs );


char *
strm__copy_strm(
        char * const xs );


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


size_t
strm__count(
        char * xs,
        bool ( * f )( char ) );


size_t
strm__count_first(
        char * xs,
        bool ( * f )( char ) );


size_t
strm__count_last(
        char * xs,
        bool ( * f )( char ) );


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
        bool ( * f )( char ) );


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
        bool ( * f )( char ) );


char *
strm__find(
        char * xs,
        bool ( * f )( char ) );


char *
strm__find_not(
        char * xs,
        bool ( * f )( char ) );


char *
strm__find_last(
        char * xs,
        bool ( * f )( char ) );


char *
strm__find_last_not(
        char * xs,
        bool ( * f )( char ) );


Maybe_size
strm__find_index(
        char * xs,
        bool ( * f )( char ) );


Maybe_size
strm__find_index_not(
        char * xs,
        bool ( * f )( char ) );


Maybe_size
strm__find_last_index(
        char * xs,
        bool ( * f )( char ) );


Maybe_size
strm__find_last_index_not(
        char * xs,
        bool ( * f )( char ) );


bool
strm__any(
        char * xs,
        bool ( * f )( char ) );


bool
strm__all(
        char * xs,
        bool ( * f )( char ) );


bool
strm__only_one(
        char * xs,
        bool ( * f )( char ) );


bool
strm__only_one_not(
        char * xs,
        bool ( * f )( char ) );


char
strm__foldl(
        char * xs,
        char init,
        char ( * f )( char acc, char x ) );


char
strm__foldl1(
        char * xs,
        char ( * f )( char acc, char x ) );


char
strm__foldr(
        char * xs,
        char init,
        char ( * f )( char x, char acc ) );


char
strm__foldr1(
        char * xs,
        char ( * f )( char x, char acc ) );


char *
strm__pick(
        char * xs,
        bool ( * f )( char const * pick, char x ) );


struct strm__each__options {
    bool ( * where )( char );
    bool ( * where_not )( char );
    void ( * f )( char );
    void ( * e )( char );
    bool ( * b )( char );
};

bool
strm__each_(
        char * xs,
        struct strm__each__options const o );

#define strm__each( XS, ... ) \
    strm__each_( XS, ( struct strm__each__options ){ __VA_ARGS__ } )


bool
strm__equal_by(
        char * xs,
        char * ys,
        bool ( * eq )( char, char ) );


bool
strm__elem_by(
        char * xs,
        char y,
        bool ( * f )( char x, char y ) );


char *
strm__elem_ptr_by(
        char * xs,
        char y,
        bool ( * f )( char x, char y ) );


Maybe_size
strm__elem_index_by(
        char * xs,
        char y,
        bool ( * f )( char x, char y ) );


size_t
strm__elem_count_by(
        char * xs,
        char y,
        bool ( * f )( char x, char y ) );


bool
strm__infix_by(
        char * xs,
        char * ys,
        bool ( * f )( char x, char y ) );


char *
strm__infix_ptr_by(
        char * xs,
        char * ys,
        bool ( * f )( char x, char y ) );


Maybe_size
strm__infix_index_by(
        char * xs,
        char * ys,
        bool ( * f )( char x, char y ) );


size_t
strm__infix_count_by(
        char * xs,
        char * ys,
        bool ( * f )( char x, char y ) );


bool
strm__is_prefix_by(
        char * xs,
        char * ps,
        bool ( * f )( char x, char p ) );


bool
strm__is_suffix_by(
        char * xs,
        char * ss,
        bool ( * f )( char x, char s ) );


ord
strm__compare_by(
        char * xs,
        char * ys,
        ord ( * f )( char x, char y ) );


char
strm__minimum_by(
        char * xs,
        ord ( * f )( char x, char min ) );


char
strm__maximum_by(
        char * xs,
        ord ( * f )( char x, char max ) );


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
strm__elem(
        char * xs,
        char y );


bool
strm__elem_i(
        char * xs,
        char y );


char *
strm__elem_ptr(
        char * xs,
        char y );


char *
strm__elem_ptr_i(
        char * xs,
        char y );


Maybe_size
strm__elem_index(
        char * xs,
        char y );


Maybe_size
strm__elem_index_i(
        char * xs,
        char y );


size_t
strm__elem_count(
        char * xs,
        char y );


size_t
strm__elem_count_i(
        char * xs,
        char y );


bool
strm__infix(
        char * xs,
        char * ys );


bool
strm__infix_i(
        char * xs,
        char * ys );


char *
strm__infix_ptr(
        char * xs,
        char * ys );


char *
strm__infix_ptr_i(
        char * xs,
        char * ys );


Maybe_size
strm__infix_index(
        char * xs,
        char * ys );


Maybe_size
strm__infix_index_i(
        char * xs,
        char * ys );


size_t
strm__infix_count(
        char * xs,
        char * ys );


size_t
strm__infix_count_i(
        char * xs,
        char * ys );


bool
strm__is_prefix(
        char * xs,
        char * prefix );


bool
strm__is_prefix_i(
        char * xs,
        char * prefix );


bool
strm__is_suffix(
        char * xs,
        char * suffix );


bool
strm__is_suffix_i(
        char * xs,
        char * suffix );


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
        char * xs,
        char * lower,
        char * upper );


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
strm__minimum(
        char * xs );


char
strm__maximum(
        char * xs );


char *
strm__from_str( char const * xs );


void
strm__arg_parse(
        char const * name,
        char const * value,
        void * destination );


#endif // ifndef LIBSTR_STRM_H

