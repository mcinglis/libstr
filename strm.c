
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


#include "strm.h"

#include <stdlib.h>
#include <ctype.h>

#include <libtypes/types.h>
#include <libmacro/assert.h>
#include <libmacro/minmax.h>

#include "str.h"


static
bool
char_equal( char const x,
            char const y )
{
    return x == y;
}


static
bool
char_equal_i( char const x,
              char const y )
{
    return toupper( x ) == toupper( y );
}



char *
strm__copy_str(
        char const * const xs )
{
    ASSERT( xs != NULL );

    size_t const n = str__size( xs );
    char * const strm = malloc( n );
    str__copy_into_strm( xs, strm, n );
    return strm;
}


char *
strm__copy_strm(
        char * const xs )
{
    return strm__copy_str( xs );
}


char *
strm__id(
        char * const xs )
{
    return xs;
}


size_t
strm__length(
        char * const xs )
{
    return str__length( xs );
}


size_t
strm__size(
        char * const xs )
{
    return str__size( xs );
}


bool
strm__is_empty(
        char * const xs )
{
    return str__is_empty( xs );
}


bool
strm__is_length_1(
        char * const xs )
{
    return str__is_length_1( xs );
}


char
strm__at(
        char * const xs,
        size_t const index )
{
    return str__at( xs, index );
}


char *
strm__ptr_at(
        char * const xs,
        size_t const index )
{
    ASSERT( xs != NULL, index <= strm__length( xs ) );

    return xs + index;
}


char
strm__first(
        char * const xs )
{
    return str__first( xs );
}


char
strm__last(
        char * const xs )
{
    return str__last( xs );
}


size_t
strm__count(
        char * const xs,
        bool ( * const p )( char ) )
{
    return str__count( xs, p );
}


size_t
strm__count_first(
        char * const xs,
        bool ( * const p )( char ) )
{
    return str__count_first( xs, p );
}


size_t
strm__count_last(
        char * const xs,
        bool ( * const p )( char ) )
{
    return str__count_last( xs, p );
}


char *
strm__take_end(
        char * const xs,
        size_t const n )
{
    ASSERT( xs != NULL );

    size_t const len = strm__length( xs );
    if ( n > len ) {
        return xs;
    } else {
        return xs + ( len - n );
    }
}


char *
strm__take_end_1(
        char * const xs )
{
    ASSERT( xs != NULL );

    return strm__take_end( xs, 1 );
}


char *
strm__take_end_2(
        char * const xs )
{
    ASSERT( xs != NULL );

    return strm__take_end( xs, 1 );
}


char *
strm__take_end_3(
        char * const xs )
{
    ASSERT( xs != NULL );

    return strm__take_end( xs, 1 );
}


char *
strm__take_end_while(
        char * const xs,
        bool ( * const p )( char ) )
{
    ASSERT( xs != NULL, p != NULL );

    return strm__take_end( xs, strm__count_last( xs, p ) );
}


char *
strm__drop(
        char * const xs,
        size_t const n )
{
    ASSERT( xs != NULL );

    return xs + MIN( n, strm__length( xs ) );
}


char *
strm__drop_1(
        char * const xs )
{
    ASSERT( xs != NULL );

    return strm__drop( xs, 1 );
}


char *
strm__drop_2(
        char * const xs )
{
    ASSERT( xs != NULL );

    return strm__drop( xs, 2 );
}


char *
strm__drop_3(
        char * const xs )
{
    ASSERT( xs != NULL );

    return strm__drop( xs, 3 );
}


char *
strm__drop_while(
        char * const xs,
        bool ( * const p )( char ) )
{
    ASSERT( xs != NULL, p != NULL );

    return strm__drop( xs, strm__count_first( xs, p ) );
}


char *
strm__find(
        char * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    Maybe_size const mi = str__find_index( xs, f );
    return mi.nothing ? NULL : xs + mi.value;
}


char *
strm__find_not(
        char * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    Maybe_size const mi = str__find_index_not( xs, f );
    return mi.nothing ? NULL : xs + mi.value;
}


char *
strm__find_last(
        char * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    Maybe_size const mi = str__find_last_index( xs, f );
    return mi.nothing ? NULL : xs + mi.value;
}


char *
strm__find_last_not(
        char * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    Maybe_size const mi = str__find_last_index_not( xs, f );
    return mi.nothing ? NULL : xs + mi.value;
}


Maybe_size
strm__find_index(
        char * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__find_index( xs, f );
}


Maybe_size
strm__find_index_not(
        char * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__find_index_not( xs, f );
}


Maybe_size
strm__find_last_index(
        char * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__find_last_index( xs, f );
}


Maybe_size
strm__find_last_index_not(
        char * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__find_last_index( xs, f );
}


bool
strm__any(
        char * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__any( xs, f );
}


bool
strm__all(
        char * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__all( xs, f );
}


bool
strm__only_one(
        char * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__only_one( xs, f );
}


bool
strm__only_one_not(
        char * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__only_one_not( xs, f );
}


char
strm__foldl(
        char * const xs,
        char const init,
        char ( * const f )( char acc, char x ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__foldl( xs, init, f );
}


char
strm__foldl1(
        char * const xs,
        char ( * const f )( char acc, char x ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__foldl1( xs, f );
}


char
strm__foldr(
        char * const xs,
        char const init,
        char ( * const f )( char x, char acc ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__foldr( xs, init, f );
}


char
strm__foldr1(
        char * const xs,
        char ( * const f )( char acc, char x ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__foldr1( xs, f );
}


char *
strm__pick(
        char * const xs,
        bool ( * const f )( char const * pick, char x ) )
{
    ASSERT( xs != NULL, f != NULL );

    char * pick = NULL;
    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        char * const x = xs + i;
        if ( f( pick, *x ) ) {
            pick = x;
        }
    }
    return pick;
}


bool
strm__each_(
        char * const xs,
        struct strm__each__options const o )
{
    ASSERT( xs != NULL );

    return str__each( xs, .where = o.where, .where_not = o.where_not,
                          .f = o.f, .b = o.b, .e = o.e );
}


bool
strm__equal_by(
        char * const xs,
        char * const ys,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, ys != NULL, f != NULL );

    return str__equal_by( xs, ys, f );
}


bool
strm__elem_by(
        char * const xs,
        char const y,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__elem_by( xs, y, f );
}


char *
strm__elem_ptr_by(
        char * const xs,
        char const y,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, f != NULL );

    Maybe_size const mi = str__elem_index_by( xs, y, f );
    return mi.nothing ? NULL : xs + mi.value;
}


Maybe_size
strm__elem_index_by(
        char * const xs,
        char const y,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__elem_index_by( xs, y, f );
}


size_t
strm__elem_count_by(
        char * const xs,
        char const y,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__elem_count_by( xs, y, f );
}


bool
strm__infix_by(
        char * const xs,
        char * const ys,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, ys != NULL, f != NULL );

    return str__infix_by( xs, ys, f );
}



char *
strm__infix_ptr_by(
        char * const xs,
        char * const ys,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, ys != NULL, f != NULL );

    Maybe_size const mi = str__infix_index_by( xs, ys, f );
    return mi.nothing ? NULL : xs + mi.value;
}


Maybe_size
strm__infix_index_by(
        char * const xs,
        char * const ys,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, ys != NULL, f != NULL );

    return str__infix_index_by( xs, ys, f );
}


size_t
strm__infix_count_by(
        char * const xs,
        char * const ys,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, ys != NULL, f != NULL );

    return str__infix_count_by( xs, ys, f );
}


bool
strm__is_prefix_by(
        char * const xs,
        char * const ps,
        bool ( * const f )( char x, char p ) )
{
    ASSERT( xs != NULL, ps != NULL, f != NULL );

    return str__is_prefix_by( xs, ps, f );
}


bool
strm__is_suffix_by(
        char * const xs,
        char * const ss,
        bool ( * const f )( char x, char s ) )
{
    ASSERT( xs != NULL, ss != NULL, f != NULL );

    return str__is_suffix_by( xs, ss, f );
}


ord
strm__compare_by(
        char * const xs,
        char * const ys,
        ord ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, ys != NULL, f != NULL );

    return str__compare_by( xs, ys, f );
}


char
strm__minimum_by(
        char * const xs,
        ord ( * const f )( char x, char min ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__minimum_by( xs, f );
}


char
strm__maximum_by(
        char * const xs,
        ord ( * const f )( char x, char max ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__maximum_by( xs, f );
}


bool
strm__equal(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__equal( xs, ys );
}


bool
strm__equal_i(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__equal_i( xs, ys );
}


bool
strm__not_equal(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return !strm__equal( xs, ys );
}


bool
strm__not_equal_i(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return !strm__equal_i( xs, ys );
}


bool
strm__elem(
        char * const xs,
        char const y )
{
    ASSERT( xs != NULL );

    return str__elem( xs, y );
}


bool
strm__elem_i(
        char * const xs,
        char const y )
{
    ASSERT( xs != NULL );

    return str__elem_i( xs, y );
}


char *
strm__elem_ptr(
        char * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return strm__elem_ptr_by( xs, c, char_equal );
}


char *
strm__elem_ptr_i(
        char * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return strm__elem_ptr_by( xs, c, char_equal_i );
}


Maybe_size
strm__elem_index(
        char * const xs,
        char const y )
{
    ASSERT( xs != NULL );

    return str__elem_index( xs, y );
}


Maybe_size
strm__elem_index_i(
        char * const xs,
        char const y )
{
    ASSERT( xs != NULL );

    return str__elem_index_i( xs, y );
}


size_t
strm__elem_count(
        char * const xs,
        char const y )
{
    ASSERT( xs != NULL );

    return str__elem_count( xs, y );
}


size_t
strm__elem_count_i(
        char * const xs,
        char const y )
{
    ASSERT( xs != NULL );

    return str__elem_count_i( xs, y );
}


bool
strm__infix(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__infix( xs, ys );
}


bool
strm__infix_i(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__infix_i( xs, ys );
}


char *
strm__infix_ptr(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return strm__infix_ptr_by( xs, ys, char_equal );
}


char *
strm__infix_ptr_i(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return strm__infix_ptr_by( xs, ys, char_equal_i );
}


Maybe_size
strm__infix_index(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__infix_index( xs, ys );
}


Maybe_size
strm__infix_index_i(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__infix_index_i( xs, ys );
}


size_t
strm__infix_count(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__infix_count( xs, ys );
}


size_t
strm__infix_count_i(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__infix_count_i( xs, ys );
}


bool
strm__is_prefix(
        char * const xs,
        char * const ps )
{
    ASSERT( xs != NULL, ps != NULL );

    return str__is_prefix( xs, ps );
}


bool
strm__is_prefix_i(
        char * const xs,
        char * const ps )
{
    ASSERT( xs != NULL, ps != NULL );

    return str__is_prefix( xs, ps );
}


bool
strm__is_suffix(
        char * const xs,
        char * const ss )
{
    ASSERT( xs != NULL, ss != NULL );

    return str__is_suffix( xs, ss );
}


bool
strm__is_suffix_i(
        char * const xs,
        char * const ss )
{
    ASSERT( xs != NULL, ss != NULL );

    return str__is_suffix_i( xs, ss );
}


ord
strm__compare(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__compare( xs, ys );
}


ord
strm__compare_i(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__compare_i( xs, ys );
}


bool
strm__less_than(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__less_than( xs, ys );
}


bool
strm__less_than_or_eq(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__less_than_or_eq( xs, ys );
}


bool
strm__greater_than_or_eq(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__greater_than_or_eq( xs, ys );
}


bool
strm__greater_than(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__greater_than( xs, ys );
}


char *
strm__min2(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__less_than( xs, ys ) ? xs : ys;
}


char *
strm__max2(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__greater_than( xs, ys ) ? xs : ys;
}


char *
strm__min_n(
        char * const * const xss,
        size_t const n )
{
    ASSERT( xss != NULL, n != 0 );

    char * min = xss[ 0 ];
    for ( size_t i = 0; i < n; i++ ) {
        if ( str__less_than( xss[ i ], min ) ) {
            min = xss[ i ];
        }
    }
    return min;
}


char *
strm__max_n(
        char * const * const xss,
        size_t const n )
{
    ASSERT( xss != NULL, n != 0 );

    char * max = xss[ 0 ];
    for ( size_t i = 0; i < n; i++ ) {
        if ( str__greater_than( xss[ i ], max ) ) {
            max = xss[ i ];
        }
    }
    return max;
}


char *
strm__clamp(
        char * const xs,
        char * const lower,
        char * const upper )
{
    ASSERT( lower != NULL, upper != NULL, xs != NULL );

    return str__greater_than_or_eq( lower, xs ) ? lower
         : str__less_than_or_eq( upper, xs )    ? upper
                                                : xs;
}


bool
strm__in_range(
        char * const lower,
        char * const upper,
        char * const xs )
{
    ASSERT( lower != NULL, upper != NULL, xs != NULL );

    return str__in_range( lower, upper, xs );
}


bool
strm__in_xrange(
        char * const lower,
        char * const upper,
        char * const xs )
{
    ASSERT( lower != NULL, upper != NULL, xs != NULL );

    return str__in_xrange( lower, upper, xs );
}


char
strm__minimum(
        char * const xs )
{
    ASSERT( xs != NULL );

    return str__minimum( xs );
}


char
strm__maximum(
        char * const xs )
{
    ASSERT( xs != NULL );

    return str__maximum( xs );
}


char *
strm__from_str( char const * const xs )
{
    ASSERT( xs != NULL );

    return strm__copy_str( xs );
}


void
strm__arg_parse(
        char const * const name,
        char const * const value,
        void * const vdest )
{
    ASSERT( value != NULL, vdest != NULL );

    char * * const dest = vdest;
    *dest = strm__from_str( value );
}


