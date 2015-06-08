
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

#include "str.h"

#include <libtypes/types.h>
#include <libmacro/assert.h>


char *
strm__null(
        void )
{
    return NULL;
}


bool
strm__is_null(
        char * const xs )
{
    return xs == NULL;
}


bool
strm__is_empty(
        char * const xs )
{
    return str__is_empty( xs );
}


bool
strm__isnt_empty(
        char * const xs )
{
    return str__isnt_empty( xs );
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
    return str__not_equal( xs, ys );
}


bool
strm__not_equal_i(
        char * const xs,
        char * const ys )
{
    return str__not_equal_i( xs, ys );
}


ord
strm__compare(
        char * const xs,
        char * const ys )
{
    return str__compare( xs, ys );
}


ord
strm__compare_i(
        char * const xs,
        char * const ys )
{
    return str__compare_i( xs, ys );
}


