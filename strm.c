
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

#include <limits.h>

#include <libtypes/types.h>
#include <libmacro/assert.h>
#include <libmacro/minmax.h>
#include <libbase/char.h>
#include <libmaybe/def/maybe-size.h>

#include "str.h"


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


bool
strm__any(
        char * const xs,
        bool ( * const p )( char ) )
{
    return str__any( xs, p );
}


bool
strm__all(
        char * const xs,
        bool ( * const p )( char ) )
{
    return str__all( xs, p );
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


bool
strm__equal_by(
        char * const xs,
        char * const ys,
        bool ( * const eq )( char, char ) )
{
    return str__equal_by( xs, ys, eq );
}


bool
strm__equal(
        char * const xs,
        char * const ys )
{
    return str__equal( xs, ys );
}


bool
strm__equal_i(
        char * const xs,
        char * const ys )
{
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
strm__elem_by(
        char * const xs,
        char const c,
        bool ( * const eq )( char, char ) )
{
    return str__elem_by( xs, c, eq );
}


bool
strm__elem(
        char * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return strm__elem_by( xs, c, char__equal );
}


bool
strm__elem_i(
        char * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return strm__elem_by( xs, c, char__equal_i );
}


bool
strm__not_elem(
        char * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return !strm__elem( xs, c );
}


bool
strm__not_elem_i(
        char * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return !strm__elem_i( xs, c );
}


Maybe_size
strm__elem_index_by(
        char * const xs,
        char const c,
        bool ( * const eq )( char, char ) )
{
    return str__elem_index_by( xs, c, eq );
}


Maybe_size
strm__elem_index(
        char * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return strm__elem_index_by( xs, c, char__equal );
}


Maybe_size
strm__elem_index_i(
        char * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return strm__elem_index_by( xs, c, char__equal_i );
}


char *
strm__elem_ptr_by(
        char * const xs,
        char const c,
        bool ( * const eq )( char, char ) )
{
    ASSERT( xs != NULL, eq != NULL );

    Maybe_size const mi = strm__elem_index_by( xs, c, eq );
    return mi.nothing ? NULL : xs + mi.value;
}


char *
strm__elem_ptr(
        char * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return strm__elem_ptr_by( xs, c, char__equal );
}


char *
strm__elem_ptr_i(
        char * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return strm__elem_ptr_by( xs, c, char__equal_i );
}


char *
strm__find(
        char * const xs,
        bool ( * const p )( char ) )
{
    ASSERT( xs != NULL, p != NULL );

    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        if ( p( xs[ i ] ) ) {
            return xs + i;
        }
    }
    return NULL;
}


size_t
strm__count_elem_by(
        char * const xs,
        char const c,
        bool ( * const eq )( char, char ) )
{
    return str__count_elem_by( xs, c, eq );
}


size_t
strm__count_elem(
        char * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return strm__count_elem_by( xs, c, char__equal );
}


size_t
strm__count_elem_i(
        char * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return strm__count_elem_by( xs, c, char__equal_i );
}


bool
strm__is_prefix_by(
        char * const xs,
        char * const prefix,
        bool ( * const eq )( char, char ) )
{
    return str__is_prefix_by( xs, prefix, eq );
}


bool
strm__is_prefix(
        char * const xs,
        char * const prefix )
{
    ASSERT( xs != NULL, prefix != NULL );

    return strm__is_prefix_by( xs, prefix, char__equal );
}


bool
strm__is_prefix_i(
        char * const xs,
        char * const prefix )
{
    ASSERT( xs != NULL, prefix != NULL );

    return strm__is_prefix_by( xs, prefix, char__equal_i );
}


bool
strm__is_suffix_by(
        char * const xs,
        char * const suffix,
        bool ( * const eq )( char, char ) )
{
    return str__is_suffix_by( xs, suffix, eq );
}


bool
strm__is_suffix(
        char * const xs,
        char * const suffix )
{
    ASSERT( xs != NULL, suffix != NULL );

    return strm__is_suffix_by( xs, suffix, char__equal );
}


bool
strm__is_suffix_i(
        char * const xs,
        char * const suffix )
{
    ASSERT( xs != NULL, suffix != NULL );

    return strm__is_suffix_by( xs, suffix, char__equal_i );
}


bool
strm__is_infix_by(
        char * const xs,
        char * const ys,
        bool ( * const eq )( char, char ) )
{
    ASSERT( xs != NULL, ys != NULL, eq != NULL );

    return !( strm__index_strm_by( xs, ys, eq ).nothing );
}


bool
strm__is_infix(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return strm__is_infix_by( xs, ys, char__equal );
}


bool
strm__is_infix_i(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return strm__is_infix_by( xs, ys, char__equal_i );
}


Maybe_size
strm__index_strm_by(
        char * const xs,
        char * const ys,
        bool ( * const eq )( char, char ) )
{
    return str__index_str_by( xs, ys, eq );
}


Maybe_size
strm__index_strm(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return strm__index_strm_by( xs, ys, char__equal );
}


Maybe_size
strm__index_strm_i(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return strm__index_strm_by( xs, ys, char__equal_i );
}


ord
strm__compare_by(
        char * const xs,
        char * const ys,
        ord ( * const cmp )( char, char ) )
{
    return str__compare_by( xs, ys, cmp );
}


ord
strm__compare(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return strm__compare_by( xs, ys, char__compare );
}


ord
strm__compare_i(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return strm__compare_by( xs, ys, char__compare_i );
}


bool
strm__less_than(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return strm__compare( xs, ys ) == LT;
}


bool
strm__less_than_or_eq(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return strm__compare( xs, ys ) <= EQ;
}


bool
strm__greater_than_or_eq(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return strm__compare( xs, ys ) >= EQ;
}


bool
strm__greater_than(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return strm__compare( xs, ys ) == GT;
}


char *
strm__min2(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return strm__less_than( xs, ys ) ? xs : ys;
}


char *
strm__max2(
        char * const xs,
        char * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return strm__greater_than( xs, ys ) ? xs : ys;
}


char *
strm__min_n(
        char * const * const xss,
        size_t const n )
{
    ASSERT( xss != NULL, n != 0 );

    char * min = xss[ 0 ];
    for ( size_t i = 0; i < n; i++ ) {
        if ( strm__less_than( xss[ i ], min ) ) {
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
        if ( strm__greater_than( xss[ i ], max ) ) {
            max = xss[ i ];
        }
    }
    return max;
}


char *
strm__clamp(
        char * const lower,
        char * const upper,
        char * const xs )
{
    ASSERT( lower != NULL, upper != NULL, xs != NULL );

    if ( strm__greater_than_or_eq( lower, xs ) ) {
        return lower;
    } else if ( strm__less_than_or_eq( upper, xs ) ) {
        return upper;
    } else {
        return xs;
    }
}


bool
strm__in_range(
        char * const lower,
        char * const upper,
        char * const xs )
{
    ASSERT( lower != NULL, upper != NULL, xs != NULL );

    return strm__less_than_or_eq( lower, xs )
        && strm__greater_than_or_eq( upper, xs );
}


bool
strm__in_xrange(
        char * const lower,
        char * const upper,
        char * const xs )
{
    ASSERT( lower != NULL, upper != NULL, xs != NULL );

    return strm__less_than( lower, xs )
        && strm__greater_than( upper, xs );
}


char
strm__minimum_by(
        char * const xs,
        ord ( * const cmp )( char, char ) )
{
    ASSERT( xs != NULL, cmp != NULL );

    char min = xs[ 0 ];
    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        if ( cmp( xs[ i ], min ) <= LT ) {
            min = xs[ i ];
        }
    }
    return min;
}


char
strm__minimum(
        char * const xs )
{
    ASSERT( xs != NULL );

    return strm__minimum_by( xs, char__compare );
}


char
strm__maximum_by(
        char * const xs,
        ord ( * const cmp )( char, char ) )
{
    ASSERT( xs != NULL, cmp != NULL );

    char max = xs[ 0 ];
    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        if ( cmp( xs[ i ], max ) >= GT ) {
            max = xs[ i ];
        }
    }
    return max;
}


char
strm__maximum(
        char * const xs )
{
    ASSERT( xs != NULL );

    return strm__maximum_by( xs, char__compare );
}

