
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
    ASSERT( from != NULL, to != NULL );

    if ( n == 0 ) { return; }
    for ( size_t i = 0; i < ( n - 1 ); i++ ) {
        to[ i ] = from[ i ];
    }
    to[ n - 1 ] = '\0';
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
str__length_null(
        char const * const xs )
{
    if ( xs == NULL ) {
        return 0;
    } else {
        return str__length( xs );
    }
}


size_t
str__size(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return str__length( xs ) + 1;
}


size_t
str__size_null(
        char const * const xs )
{
    if ( xs == NULL ) {
        return 0;
    } else {
        return str__size( xs );
    }
}


bool
str__is_empty(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return str__length( xs ) == 0;
}


bool
str__isnt_empty(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return !str__is_empty( xs );
}


bool
str__is_length_1(
        char const * const xs )
{
    ASSERT( xs != NULL );

    return str__length( xs ) == 1;
}


bool
str__equal_by(
        char const * const xs,
        char const * const ys,
        bool ( * const eq )( char x, char y ) )
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


ord
str__compare_by(
        char const * const xs,
        char const * const ys,
        ord ( * const cmp )( char x, char y ) )
{
    ASSERT( xs != NULL, ys != NULL, cmp != NULL );

    size_t i = 0;
    ord r;
    while ( r = cmp( xs[ i ], ys[ i ] ),
            r == EQ && xs[ i ] != '\0' && ys[ i ] != '\0' ) {
        i++;
    }
    return r;
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

