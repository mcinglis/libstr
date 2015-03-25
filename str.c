
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

#include <ctype.h>
#include <errno.h>

#include <libtypes/types.h>
#include <libmacro/assert.h>
#include <libmacro/compare.h>
#include <libmacro/minmax.h>


static
ord
char_compare( char const x,
              char const y )
{
    return COMPARE( x, y );
}


static
bool
char_equal( char const x,
            char const y )
{
    return x == y;
}


static
ord
char_compare_i( char const x,
                char const y )
{
    return COMPARE( toupper( x ), toupper( y ) );
}


static
bool
char_equal_i( char const x,
              char const y )
{
    return toupper( x ) == toupper( y );
}




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

    return str__length( xs ) + 1;
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


size_t
str__count(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    size_t count = 0;
    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        if ( f( xs[ i ] ) ) {
            count++;
        }
    }
    return count;
}


size_t
str__count_first(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    size_t count = 0;
    while ( xs[ count ] != '\0' && f( xs[ count ] ) ) {
        count++;
    }
    return count;
}


size_t
str__count_last(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    size_t const len = str__length( xs );
    size_t count = 0;
    while ( count < len && f( xs[ len - count - 1 ] ) ) {
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
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__take_end( xs, str__count_last( xs, f ) );
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
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__drop( xs, str__count_first( xs, f ) );
}


char const *
str__find(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    Maybe_size const mi = str__find_index( xs, f );
    return mi.nothing ? NULL : xs + mi.value;
}


char const *
str__find_not(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    Maybe_size const mi = str__find_index_not( xs, f );
    return mi.nothing ? NULL : xs + mi.value;
}


char const *
str__find_last(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    Maybe_size const mi = str__find_last_index( xs, f );
    return mi.nothing ? NULL : xs + mi.value;
}


char const *
str__find_last_not(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    Maybe_size const mi = str__find_last_index_not( xs, f );
    return mi.nothing ? NULL : xs + mi.value;
}


static
Maybe_size
find_index( char const * const xs,
            bool ( * const f )( char ),
            bool const result )
{
    ASSERT( xs != NULL, f != NULL );

    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        if ( f( xs[ i ] ) == result ) {
            return ( Maybe_size ){ .value = i };
        }
    }
    return ( Maybe_size ){ .nothing = true };
}


Maybe_size
str__find_index(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return find_index( xs, f, true );
}


Maybe_size
str__find_index_not(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return find_index( xs, f, false );
}


static
Maybe_size
find_last_index( char const * const xs,
                 bool ( * const f )( char ),
                 bool const result )
{
    ASSERT( xs != NULL, f != NULL );

    for ( size_t i = str__length( xs ); i > 0; i-- ) {
        size_t const ix = i - 1;
        if ( f( xs[ ix ] ) == result ) {
            return ( Maybe_size ){ .value = ix };
        }
    }
    return ( Maybe_size ){ .nothing = true };
}


Maybe_size
str__find_last_index(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return find_last_index( xs, f, true );
}


Maybe_size
str__find_last_index_not(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return find_last_index( xs, f, false );
}


bool
str__any(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__find( xs, f ) != NULL;
}


bool
str__all(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__find_not( xs, f ) == NULL;
}


bool
str__only_one(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    char const * const first = str__find( xs, f );
    if ( first == NULL ) {
        return false;
    } else {
        return first == str__find_last( xs, f );
    }
}


bool
str__only_one_not(
        char const * const xs,
        bool ( * const f )( char ) )
{
    ASSERT( xs != NULL, f != NULL );

    char const * const first = str__find_not( xs, f );
    if ( first == NULL ) {
        return false;
    } else {
        return first == str__find_last_not( xs, f );
    }
}


char
str__foldl(
        char const * const xs,
        char const init,
        char ( * const f )( char acc, char x ) )
{
    ASSERT( xs != NULL, f != NULL );

    char acc = init;
    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        acc = f( acc, xs[ i ] );
    }
    return acc;
}


char
str__foldl1(
        char const * const xs,
        char ( * const f )( char acc, char x ) )
{
    ASSERT( xs != NULL, f != NULL, str__length( xs ) > 0 );

    return str__foldl( xs + 1, xs[ 0 ], f );
}


char
str__foldr(
        char const * const xs,
        char const init,
        char ( * const f )( char x, char acc ) )
{
    ASSERT( xs != NULL, f != NULL );

    char acc = init;
    for ( size_t i = str__length( xs ); i > 0; i-- ) {
        acc = f( xs[ i - 1 ], acc );
    }
    return acc;
}


char
str__foldr1(
        char const * const xs,
        char ( * const f )( char acc, char x ) )
{
    ASSERT( xs != NULL, f != NULL, str__length( xs ) > 0 );

    char acc = xs[ 0 ];
    for ( size_t i = str__length( xs ) - 1; i > 0; i-- ) {
        acc = f( xs[ i - 1 ], acc );
    }
    return acc;
}


char const *
str__pick(
        char const * const xs,
        bool ( * const f )( char const * pick, char x ) )
{
    ASSERT( xs != NULL, f != NULL );

    char const * pick = NULL;
    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        char const * const x = xs + i;
        if ( f( pick, *x ) ) {
            pick = x;
        }
    }
    return pick;
}


bool
str__each_(
        char const * const xs,
        struct str__each__options const o )
{
    ASSERT( xs != NULL );

    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        char const x = xs[ i ];
        if ( ( o.where != NULL && o.where( x ) == false )
          || ( o.where_not != NULL && o.where_not( x ) == true ) ) {
            continue;
        }
        if ( o.e != NULL ) {
            o.e( x );
            if ( errno ) { return false; }
        } else if ( o.b != NULL ) {
            if ( o.b( x ) == false ) { return false; }
        } else if ( o.f != NULL ) {
            o.f( x );
        }
    }
    return true;
}


bool
str__equal_by(
        char const * const xs,
        char const * const ys,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, ys != NULL, f != NULL );

    size_t i = 0;
    bool b;
    while ( b = f( xs[ i ], ys[ i ] ),
            b == true && xs[ i ] != '\0' && ys[ i ] != '\0' ) {
        i++;
    }
    return b;
}


bool
str__elem_by(
        char const * const xs,
        char const y,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, f != NULL );

    return str__elem_ptr_by( xs, y, f ) != NULL;
}


char const *
str__elem_ptr_by(
        char const * const xs,
        char const y,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, f != NULL );

    Maybe_size const mi = str__elem_index_by( xs, y, f );
    return mi.nothing ? NULL : xs + mi.value;
}


Maybe_size
str__elem_index_by(
        char const * const xs,
        char const y,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, f != NULL );

    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        if ( f( xs[ i ], y ) ) {
            return ( Maybe_size ){ .value = i };
        }
    }
    return ( Maybe_size ){ .nothing = true };
}


size_t
str__elem_count_by(
        char const * const xs,
        char const y,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, f != NULL );

    size_t count = 0;
    char const * xp = xs;
    Maybe_size mi;
    while ( mi = str__elem_index_by( xp, y, f ), !mi.nothing ) {
        xp = xs + mi.value + 1;
        count++;
    }
    return count;
}


bool
str__infix_by(
        char const * const xs,
        char const * const ys,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, ys != NULL, f != NULL );

    return str__infix_ptr_by( xs, ys, f ) != NULL;
}



char const *
str__infix_ptr_by(
        char const * const xs,
        char const * const ys,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, ys != NULL, f != NULL );

    Maybe_size const mi = str__infix_index_by( xs, ys, f );
    return mi.nothing ? NULL : xs + mi.value;
}


Maybe_size
str__infix_index_by(
        char const * const xs,
        char const * const ys,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, ys != NULL, f != NULL );

    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        // Check that `ys` is a prefix of `xs + i`:
        char const * xp = xs + i;
        char const * yp = ys;
        bool r;
        while ( r = f( *xp, *yp ),
                r == true && *xp != '\0' && *yp != '\0' ) {
            xp++;
            yp++;
        }
        // If we got to the end of `xs + i` before we got to the end of `ys`,
        // then `ys` can't possibly be a prefix of `xs + i + 1`:
        if ( *xp == '\0' && *yp != '\0' ) {
            break;
        // Otherwise, if `f` returned `true` for all `j` up to the end of
        // `ys`, then we found it infix in `xs` at the `i`th index:
        } else if ( r == true ) {
            return ( Maybe_size ){ .value = i };
        }
    }
    // If here, `ys` was not a prefix of `xs + i` for all `i` below the
    // length of `xs`, so it's not infix (by `f`) anywhere in `xs`:
    return ( Maybe_size ){ .nothing = true };
}


size_t
str__infix_count_by(
        char const * const xs,
        char const * const ys,
        bool ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, ys != NULL, f != NULL );

    size_t count = 0;
    char const * xp = xs;
    Maybe_size mi;
    while ( mi = str__infix_index_by( xp, ys, f ), !mi.nothing ) {
        xp = xs + mi.value + 1;
        count++;
    }
    return count;
}


bool
str__is_prefix_by(
        char const * const xs,
        char const * const ps,
        bool ( * const f )( char x, char p ) )
{
    ASSERT( xs != NULL, ps != NULL, f != NULL );

    for ( size_t i = 0; ps[ i ] != '\0'; i++ ) {
        if ( xs[ i ] == '\0' || !f( xs[ i ], ps[ i ] ) ) {
            return false;
        }
    }
    return true;
}


bool
str__is_suffix_by(
        char const * const xs,
        char const * const ss,
        bool ( * const f )( char x, char s ) )
{
    ASSERT( xs != NULL, ss != NULL, f != NULL );

    size_t const xs_len = str__length( xs );
    size_t const ss_len = str__length( ss );
    if ( ss_len > xs_len ) {
        return false;
    }
    size_t const offset = xs_len - ss_len;
    for ( size_t i = 0; ss[ i ] != '\0'; i++ ) {
        if ( !f( xs[ offset + i ], ss[ i ] ) ) {
            return false;
        }
    }
    return true;
}


ord
str__compare_by(
        char const * const xs,
        char const * const ys,
        ord ( * const f )( char x, char y ) )
{
    ASSERT( xs != NULL, ys != NULL, f != NULL );

    size_t i = 0;
    ord r;
    while ( r = f( xs[ i ], ys[ i ] ),
            r == EQ && xs[ i ] != '\0' && ys[ i ] != '\0' ) {
        i++;
    }
    return r;
}


char
str__minimum_by(
        char const * const xs,
        ord ( * const f )( char x, char min ) )
{
    ASSERT( xs != NULL, f != NULL );

    char min = xs[ 0 ];
    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        if ( f( xs[ i ], min ) <= LT ) {
            min = xs[ i ];
        }
    }
    return min;
}


char
str__maximum_by(
        char const * const xs,
        ord ( * const f )( char x, char max ) )
{
    ASSERT( xs != NULL, f != NULL );

    char max = xs[ 0 ];
    for ( size_t i = 0; xs[ i ] != '\0'; i++ ) {
        if ( f( xs[ i ], max ) >= GT ) {
            max = xs[ i ];
        }
    }
    return max;
}


bool
str__equal(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__equal_by( xs, ys, char_equal );
}


bool
str__equal_i(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__equal_by( xs, ys, char_equal_i );
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
str__elem(
        char const * const xs,
        char const y )
{
    ASSERT( xs != NULL );

    return str__elem_by( xs, y, char_equal );
}


bool
str__elem_i(
        char const * const xs,
        char const y )
{
    ASSERT( xs != NULL );

    return str__elem_by( xs, y, char_equal_i );
}


char const *
str__elem_ptr(
        char const * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return str__elem_ptr_by( xs, c, char_equal );
}


char const *
str__elem_ptr_i(
        char const * const xs,
        char const c )
{
    ASSERT( xs != NULL );

    return str__elem_ptr_by( xs, c, char_equal_i );
}


Maybe_size
str__elem_index(
        char const * const xs,
        char const y )
{
    ASSERT( xs != NULL );

    return str__elem_index_by( xs, y, char_equal );
}


Maybe_size
str__elem_index_i(
        char const * const xs,
        char const y )
{
    ASSERT( xs != NULL );

    return str__elem_index_by( xs, y, char_equal_i );
}


size_t
str__elem_count(
        char const * const xs,
        char const y )
{
    ASSERT( xs != NULL );

    return str__elem_count_by( xs, y, char_equal );
}


size_t
str__elem_count_i(
        char const * const xs,
        char const y )
{
    ASSERT( xs != NULL );

    return str__elem_count_by( xs, y, char_equal_i );
}


bool
str__infix(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__infix_by( xs, ys, char_equal );
}


bool
str__infix_i(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__infix_by( xs, ys, char_equal_i );
}


char const *
str__infix_ptr(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__infix_ptr_by( xs, ys, char_equal );
}


char const *
str__infix_ptr_i(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__infix_ptr_by( xs, ys, char_equal_i );
}


Maybe_size
str__infix_index(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__infix_index_by( xs, ys, char_equal );
}


Maybe_size
str__infix_index_i(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__infix_index_by( xs, ys, char_equal_i );
}


size_t
str__infix_count(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__infix_count_by( xs, ys, char_equal );
}


size_t
str__infix_count_i(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__infix_count_by( xs, ys, char_equal_i );
}


bool
str__is_prefix(
        char const * const xs,
        char const * const ps )
{
    ASSERT( xs != NULL, ps != NULL );

    return str__is_prefix_by( xs, ps, char_equal );
}


bool
str__is_prefix_i(
        char const * const xs,
        char const * const ps )
{
    ASSERT( xs != NULL, ps != NULL );

    return str__is_prefix_by( xs, ps, char_equal_i );
}


bool
str__is_suffix(
        char const * const xs,
        char const * const ss )
{
    ASSERT( xs != NULL, ss != NULL );

    return str__is_suffix_by( xs, ss, char_equal );
}


bool
str__is_suffix_i(
        char const * const xs,
        char const * const ss )
{
    ASSERT( xs != NULL, ss != NULL );

    return str__is_suffix_by( xs, ss, char_equal_i );
}


ord
str__compare(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__compare_by( xs, ys, char_compare );
}


ord
str__compare_i(
        char const * const xs,
        char const * const ys )
{
    ASSERT( xs != NULL, ys != NULL );

    return str__compare_by( xs, ys, char_compare_i );
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
        char const * const xs,
        char const * const lower,
        char const * const upper )
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
str__minimum(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return str__minimum_by( xs, char_compare );
}


char
str__maximum(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return str__maximum_by( xs, char_compare );
}

