
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



static
bool
char_equal(
        char const x,
        char const y )
{
    return x == y;
}


static
bool
char_equal_i(
        char const x,
        char const y )
{
    return tolower( x ) == tolower( y );
}


static
ord
char_compare(
        char const x,
        char const y )
{
    return COMPARE( x, y );
}


static
ord
char_compare_i(
        char const x,
        char const y )
{
    return COMPARE( tolower( x ), tolower( y ) );
}






void
str__copy_into_strm(
        char const * const from,
        char * const to,
        size_t const n )
{
    if ( from == NULL || to == NULL || n == 0 ) { return; }
    for ( size_t i = 0; i < ( n - 1 ); i++ ) {
        to[ i ] = from[ i ];
    }
    to[ n - 1 ] = '\0';
}


size_t
str__length(
        char const * const xs )
{
    if ( xs == NULL ) { return 0; }
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
    if ( xs == NULL ) {
        return 0;
    } else {
        return str__length( xs ) + 1;
    }
}


char const *
str__null(
        void )
{
    return NULL;
}


bool
str__is_null(
        char const * const xs )
{
    return xs == NULL;
}


bool
str__is_empty(
        char const * const xs )
{
    return str__length( xs ) == 0;
}


bool
str__isnt_empty(
        char const * const xs )
{
    return !str__is_empty( xs );
}


char const *
str__drop(
        char const * const xs,
        size_t const n )
{
    if ( str__length( xs ) == 0 ) {
        return xs;
    } else {
        return xs + n;
    }
}


char const *
str__take_end(
        char const * const xs,
        size_t const n )
{
    if ( n == 0 ) {
        return NULL;
    } else {
        size_t const len = str__length( xs );
        if ( n <= len ) {
            return xs + len - n;
        } else {
            return xs;
        }
    }
}


bool
str__equal_by(
        char const * const xs,
        char const * const ys,
        bool ( * const eq )( char x, char y ) )
{
    ASSERT( eq != NULL );

    if ( xs == NULL && ys == NULL ) {
        return true;
    } else if ( xs != NULL && ys != NULL ) {
        if ( xs == ys ) { return true; }
        size_t const xs_len = str__length( xs );
        size_t const ys_len = str__length( ys );
        if ( xs_len != ys_len ) { return false; }
        for ( size_t i = 0; i < xs_len; i++ ) {
            if ( !eq( xs[ i ], ys[ i ] ) ) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}


bool
str__has_prefix_by(
        char const * const xs,
        char const * const prefix,
        bool ( * const eq )( char x, char y ) )
{
    ASSERT( eq != NULL );

    if ( prefix == NULL ) {
        return true;
    } else if ( xs == NULL ) {
        return false;
    } else { // xs != NULL && prefix != NULL
        if ( xs == prefix ) { return true; }
        size_t const xs_len = str__length( xs );
        size_t const prefix_len = str__length( prefix );
        if ( prefix_len > xs_len ) { return false; }
        for ( size_t i = 0; i < prefix_len; i++ ) {
            if ( !eq( xs[ i ], prefix[ i ] ) ) {
                return false;
            }
        }
        return true;
    }
}


bool
str__has_suffix_by(
        char const * const xs,
        char const * const suffix,
        bool ( * const eq )( char x, char y ) )
{
    ASSERT( eq != NULL );

    return str__equal_by( str__take_end( xs, str__length( suffix ) ), suffix,
                          eq );
}


bool
str__has_infix_by(
        char const * const xs,
        char const * const infix,
        bool ( * const eq )( char x, char y ) )
{
    ASSERT( eq != NULL );

    for ( size_t i = 0; i < str__length( xs ); i++ ) {
        if ( str__has_prefix_by( str__drop( xs, i ), infix, eq ) ) {
            return true;
        }
    }
    return false;
}


ord
str__compare_by(
        char const * const xs,
        char const * const ys,
        ord ( * const cmp )( char x, char y ) )
{
    if ( xs == NULL && ys == NULL ) {
        return EQ;
    } else if ( xs != NULL && ys != NULL ) {
        ASSERT( cmp != NULL );
        size_t i = 0;
        ord r;
        while ( r = cmp( xs[ i ], ys[ i ] ),
                r == EQ && xs[ i ] != '\0' && ys[ i ] != '\0' ) {
            i++;
        }
        return r;
    } else {
        return COMPARE( xs != NULL, ys != NULL );
    }
}


bool
str__equal(
        char const * const xs,
        char const * const ys )
{
    return str__equal_by( xs, ys, char_equal );
}


bool
str__equal_i(
        char const * const xs,
        char const * const ys )
{
    return str__equal_by( xs, ys, char_equal_i );
}


bool
str__not_equal(
        char const * const xs,
        char const * const ys )
{
    return !str__equal( xs, ys );
}


bool
str__not_equal_i(
        char const * const xs,
        char const * const ys )
{
    return !str__equal( xs, ys );
}


bool
str__has_prefix(
        char const * const xs,
        char const * const prefix )
{
    return str__has_prefix_by( xs, prefix, char_equal );
}


bool
str__has_prefix_i(
        char const * const xs,
        char const * const prefix )
{
    return str__has_prefix_by( xs, prefix, char_equal );
}


bool
str__has_suffix(
        char const * const xs,
        char const * const suffix )
{
    return str__has_suffix_by( xs, suffix, char_equal );
}


bool
str__has_suffix_i(
        char const * const xs,
        char const * const suffix )
{
    return str__has_suffix_by( xs, suffix, char_equal );
}


bool
str__has_infix(
        char const * const xs,
        char const * const infix )
{
    return str__has_infix_by( xs, infix, char_equal );
}


bool
str__has_infix_i(
        char const * const xs,
        char const * const infix )
{
    return str__has_infix_by( xs, infix, char_equal );
}


ord
str__compare(
        char const * const xs,
        char const * const ys )
{
    return str__compare_by( xs, ys, char_compare );
}


ord
str__compare_i(
        char const * const xs,
        char const * const ys )
{
    return str__compare_by( xs, ys, char_compare_i );
}


char const *
str__from_str(
        char const * const str )
{
    return str;
}


void
str__arg_parse(
        char const * const name,
        char const * const arg,
        void * const vdest )
{
    ASSERT( arg != NULL );

    errno = 0;
    if ( vdest == NULL ) { return; }
    char const * * const dest = vdest;
    *dest = arg;
}

