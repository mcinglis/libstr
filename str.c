
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


#include "str.h"

#include <limits.h>

#include <libtypes/types.h>
#include <libmacro/assert.h>
#include <libmacro/minmax.h>
#include <libbase/char.h>
#include <libmaybe/def/maybe-size.h>


char const *
str__id(
        char const * const xs )
{
    return xs;
}


size_t
str__length(
        char const * const xs )
{
    ASSERT( xs != NULL );

    size_t len = 0;
    while ( xs[ len ] != '\0' ) {
        len++;
    }
    return len;
}


size_t
str__size(
        char const * const xs )
{
    ASSERT( xs != NULL );

    size_t const len = str__length( xs );
    ASSERT( len != SIZE_MAX );
    return len + 1;
}


bool
str__is_empty(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return xs[ 0 ] == '\0';
}


bool
str__is_length_1(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return str__length( xs ) == 1;
}


char
str__at(
        char const * const xs,
        size_t const index )
{
    ASSERT( xs != NULL, index <= str__length( xs ) );

    return xs[ index ];
}


char const *
str__ptr_at(
        char const * const xs,
        size_t const index )
{
    ASSERT( xs != NULL, index <= str__length( xs ) );

    return xs + index;
}


char
str__first(
        char const * const xs )
{
    ASSERT( xs != NULL, str__length( xs ) >= 1 );

    return str__at( xs, 0 );
}


char
str__last(
        char const * const xs )
{
    ASSERT( xs != NULL, str__length( xs ) >= 1 );

    return str__at( xs, str__length( xs ) - 1 );
}


bool
str__any(
        char const * const xs,
        bool ( * const p )( char ) )
{
    ASSERT( xs != NULL, p != NULL );

    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        if ( p( xs[ i ] ) ) {
            return true;
        }
    }
    return false;
}


bool
str__all(
        char const * const xs,
        bool ( * const p )( char ) )
{
    ASSERT( xs != NULL, p != NULL );

    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        if ( !p( xs[ i ] ) ) {
            return false;
        }
    }
    return true;
}


size_t
str__count(
        char const * const xs,
        bool ( * const p )( char ) )
{
    ASSERT( xs != NULL, p != NULL );

    size_t count = 0;
    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        if ( p( xs[ i ] ) ) {
            count++;
        }
    }
    return count;
}


size_t
str__count_first(
        char const * const xs,
        bool ( * const p )( char ) )
{
    ASSERT( xs != NULL, p != NULL );

    size_t count = 0;
    while ( xs[ count ] != '\0' && p( xs[ count ] ) ) {
        count++;
    }
    return count;
}


size_t
str__count_last(
        char const * const xs,
        bool ( * const p )( char ) )
{
    ASSERT( xs != NULL, p != NULL );

    size_t const len = str__length( xs );
    size_t count = 0;
    while ( count < len && p( xs[ len - count - 1 ] ) ) {
        count++;
    }
    return count;
}


char const *
str__take_end(
        char const * const xs,
        size_t const n )
{
    ASSERT( xs != NULL );

    size_t const len = str__length( xs );
    if ( n > len ) {
        return xs;
    } else {
        return xs + ( len - n );
    }
}


char const *
str__take_end_1(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return str__take_end( xs, 1 );
}


char const *
str__take_end_2(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return str__take_end( xs, 1 );
}


char const *
str__take_end_3(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return str__take_end( xs, 1 );
}


char const *
str__take_end_while(
        char const * const xs,
        bool ( * const p )( char ) )
{
    ASSERT( xs != NULL, p != NULL );

    return str__take_end( xs, str__count_last( xs, p ) );
}


char const *
str__drop(
        char const * const xs,
        size_t const n )
{
    ASSERT( xs != NULL );

    return xs + MIN( n, str__length( xs ) );
}


char const *
str__drop_1(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return str__drop( xs, 1 );
}


char const *
str__drop_2(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return str__drop( xs, 2 );
}


char const *
str__drop_3(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return str__drop( xs, 3 );
}


char const *
str__drop_while(
        char const * const xs,
        bool ( * const p )( char ) )
{
    ASSERT( xs != NULL, p != NULL );

    return str__drop( xs, str__count_first( xs, p ) );
}


bool
str__equal_by(
        char const * const xs,
        char const * const ys,
        bool ( * const eq )( char, char ) )
{
    ASSERT( xs != NULL, ys != NULL, eq != NULL );

    size_t i = 0;
    bool b;
    while ( b = eq( xs[ i ], ys[ i ] ),
            b == true && xs[ i ] != '\0' && ys[ i ] != '\0' ) {
        i++;
    }
    return b;
}


bool
str__equal(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__equal_by( xs, ys, char__equal );
}


bool
str__equal_i(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__equal_by( xs, ys, char__equal_i );
}


bool
str__not_equal(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return !str__equal( xs, ys );
}


bool
str__not_equal_i(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return !str__equal_i( xs, ys );
}


bool
str__elem_by(
        char const * const xs,
        char const c,
        bool ( * const eq )( char, char ) )
{
    ASSERT( xs != NULL );

    return !( str__elem_index_by( xs, c, eq ).nothing );
}


bool
str__elem(
        char const * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return str__elem_by( xs, c, char__equal );
}


bool
str__elem_i(
        char const * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return str__elem_by( xs, c, char__equal_i );
}


bool
str__not_elem(
        char const * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return !str__elem( xs, c );
}


bool
str__not_elem_i(
        char const * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return !str__elem_i( xs, c );
}


Maybe_size
str__elem_index_by(
        char const * const xs,
        char const c,
        bool ( * const eq )( char, char ) )
{
    ASSERT( xs != NULL, eq != NULL );

    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        if ( eq( xs[ i ], c ) ) {
            return ( Maybe_size ){ .value = i };
        }
    }
    return ( Maybe_size ){ .nothing = true };
}


Maybe_size
str__elem_index(
        char const * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return str__elem_index_by( xs, c, char__equal );
}


Maybe_size
str__elem_index_i(
        char const * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return str__elem_index_by( xs, c, char__equal_i );
}


char const *
str__elem_ptr_by(
        char const * const xs,
        char const c,
        bool ( * const eq )( char, char ) )
{
    ASSERT( xs != NULL, eq != NULL );

    Maybe_size const mi = str__elem_index_by( xs, c, eq );
    return mi.nothing ? NULL : xs + mi.value;
}


char const *
str__elem_ptr(
        char const * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return str__elem_ptr_by( xs, c, char__equal );
}


char const *
str__elem_ptr_i(
        char const * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return str__elem_ptr_by( xs, c, char__equal_i );
}


char const *
str__find(
        char const * const xs,
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
str__count_elem_by(
        char const * const xs,
        char const c,
        bool ( * const eq )( char, char ) )
{
    ASSERT( xs != NULL, eq != NULL );

    size_t count = 0;
    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        if ( eq( xs[ i ], c ) ) {
            count++;
        }
    }
    return count;
}


size_t
str__count_elem(
        char const * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return str__count_elem_by( xs, c, char__equal );
}


size_t
str__count_elem_i(
        char const * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return str__count_elem_by( xs, c, char__equal_i );
}


bool
str__is_prefix_by(
        char const * const xs,
        char const * const prefix,
        bool ( * const eq )( char, char ) )
{
    ASSERT( xs != NULL, prefix != NULL, eq != NULL );

    for ( size_t i = 0; prefix[ i ] != '\0'; i++ ) {
        if ( xs[ i ] == '\0' || !eq( xs[ i ], prefix[ i ] ) ) {
            return false;
        }
    }
    return true;
}


bool
str__is_prefix(
        char const * const xs,
        char const * const prefix )
{
    ASSERT( xs != NULL, prefix != NULL );

    return str__is_prefix_by( xs, prefix, char__equal );
}


bool
str__is_prefix_i(
        char const * const xs,
        char const * const prefix )
{
    ASSERT( xs != NULL, prefix != NULL );

    return str__is_prefix_by( xs, prefix, char__equal_i );
}


bool
str__is_suffix_by(
        char const * const xs,
        char const * const suffix,
        bool ( * const eq )( char, char ) )
{
    ASSERT( xs != NULL, suffix != NULL, eq != NULL );

    size_t const xs_len = str__length( xs );
    size_t const suf_len = str__length( suffix );
    if ( suf_len > xs_len ) {
        return false;
    }
    size_t const offset = xs_len - suf_len;
    for ( size_t i = 0; suffix[ i ] != '\0'; i++ ) {
        if ( !eq( xs[ offset + i ], suffix[ i ] ) ) {
            return false;
        }
    }
    return true;
}


bool
str__is_suffix(
        char const * const xs,
        char const * const suffix )
{
    ASSERT( xs != NULL, suffix != NULL );

    return str__is_suffix_by( xs, suffix, char__equal );
}


bool
str__is_suffix_i(
        char const * const xs,
        char const * const suffix )
{
    ASSERT( xs != NULL, suffix != NULL );

    return str__is_suffix_by( xs, suffix, char__equal_i );
}


bool
str__is_infix_by(
        char const * const xs,
        char const * const ys,
        bool ( * const eq )( char, char ) )
{
    ASSERT( xs != NULL, ys != NULL, eq != NULL );

    return !( str__index_str_by( xs, ys, eq ).nothing );
}


bool
str__is_infix(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__is_infix_by( xs, ys, char__equal );
}


bool
str__is_infix_i(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__is_infix_by( xs, ys, char__equal_i );
}


Maybe_size
str__index_str_by(
        char const * const xs,
        char const * const ys,
        bool ( * const eq )( char, char ) )
{
    ASSERT( xs != NULL, ys != NULL, eq != NULL );

    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        char const * const xs_i = xs + i;
        // Check if `ys` is a prefix of `xs + i`, but if we get to the end of
        // `xs_i` before the end of `ys`, then `ys` is longer than `xs_i`, and
        // so `ys` can't possibly be contained in `xs_i + 1`.
        for ( size_t j = 0; ys[ j ] != '\0'; j++ ) {
            if ( xs_i[ j ] == '\0' ) {
                return ( Maybe_size ){ .nothing = true };
            } else if ( !eq( xs_i[ j ], ys[ j ] ) ) {
                goto next_i;
            }
        }
        // If here, `ys` is a prefix of `xs_i`:
        return ( Maybe_size ){ .value = i };
next_i:
        continue;
    }
    // If here, `ys` was not a prefix of `xs`, nor `xs + 1`, nor `xs + 2`, up
    // to the end of `xs`:
    return ( Maybe_size ){ .nothing = true };
}


Maybe_size
str__index_str(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__index_str_by( xs, ys, char__equal );
}


Maybe_size
str__index_str_i(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__index_str_by( xs, ys, char__equal_i );
}


ord
str__compare_by(
        char const * const xs,
        char const * const ys,
        ord ( * const cmp )( char, char ) )
{
    ASSERT( xs != NULL, ys != NULL, cmp != NULL );

    size_t i = 0;
    ord c;
    while ( c = cmp( xs[ i ], ys[ i ] ),
            c == EQ && xs[ i ] != '\0' && ys[ i ] != '\0' ) {
        i++;
    }
    return c;
}


ord
str__compare(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__compare_by( xs, ys, char__compare );
}


ord
str__compare_i(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__compare_by( xs, ys, char__compare_i );
}


bool
str__less_than(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__compare( xs, ys ) == LT;
}


bool
str__less_than_or_eq(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__compare( xs, ys ) <= EQ;
}


bool
str__greater_than_or_eq(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__compare( xs, ys ) >= EQ;
}


bool
str__greater_than(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__compare( xs, ys ) == GT;
}


char const *
str__min2(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__less_than( xs, ys ) ? xs : ys;
}


char const *
str__max2(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__greater_than( xs, ys ) ? xs : ys;
}


char const *
str__min_n(
        char const * const * const xss,
        size_t const n )
{
    ASSERT( xss != NULL, n != 0 );

    char const * min = xss[ 0 ];
    for ( size_t i = 0; i < n; i++ ) {
        if ( str__less_than( xss[ i ], min ) ) {
            min = xss[ i ];
        }
    }
    return min;
}


char const *
str__max_n(
        char const * const * const xss,
        size_t const n )
{
    ASSERT( xss != NULL, n != 0 );

    char const * max = xss[ 0 ];
    for ( size_t i = 0; i < n; i++ ) {
        if ( str__greater_than( xss[ i ], max ) ) {
            max = xss[ i ];
        }
    }
    return max;
}


char const *
str__clamp(
        char const * const lower,
        char const * const upper,
        char const * const xs )
{
    ASSERT( lower != NULL, upper != NULL, xs != NULL );

    if ( str__greater_than_or_eq( lower, xs ) ) {
        return lower;
    } else if ( str__less_than_or_eq( upper, xs ) ) {
        return upper;
    } else {
        return xs;
    }
}


bool
str__in_range(
        char const * const lower,
        char const * const upper,
        char const * const xs )
{
    ASSERT( lower != NULL, upper != NULL, xs != NULL );

    return str__less_than_or_eq( lower, xs )
        && str__greater_than_or_eq( upper, xs );
}


bool
str__in_xrange(
        char const * const lower,
        char const * const upper,
        char const * const xs )
{
    ASSERT( lower != NULL, upper != NULL, xs != NULL );

    return str__less_than( lower, xs )
        && str__greater_than( upper, xs );
}


char
str__minimum_by(
        char const * const xs,
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
str__minimum(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return str__minimum_by( xs, char__compare );
}


char
str__maximum_by(
        char const * const xs,
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
str__maximum(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return str__maximum_by( xs, char__compare );
}

