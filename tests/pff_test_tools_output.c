/*
 * Tools output functions test program
 *
 * Copyright (C) 2008-2026, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#include <stdio.h>

#if defined( HAVE_IO_H ) || defined( WINAPI )
#include <io.h>
#endif

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "pff_test_libcerror.h"
#include "pff_test_macros.h"
#include "pff_test_unused.h"

#include "../pfftools/pfftools_output.h"

/* Tests the pfftools_output_initialize function
 * Returns 1 if successful or 0 if not
 */
int pff_test_tools_output_initialize(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = pfftools_output_initialize(
	          _IONBF,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	PFF_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = pfftools_output_initialize(
	          -1,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	PFF_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the pfftools_output_copyright_fprint function
 * Returns 1 if successful or 0 if not
 */
int pff_test_tools_output_copyright_fprint(
     void )
{
	FILE *stream = NULL;
	int result   = 0;

	/* Initialize test
	 */
	stream = tmpfile();

	PFF_TEST_ASSERT_IS_NOT_NULL(
	 "stream",
	 stream );

	/* Test invocation of function only
	 */
	pfftools_output_copyright_fprint(
	 stream );

	/* Test error cases
	 */
	pfftools_output_copyright_fprint(
	 NULL );

	/* Clean up
	 */
	result = fclose(
	          stream );

	stream = NULL;

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	return( 1 );

on_error:
	if( stream != NULL )
	{
		fclose(
		 stream );
	}
	return( 0 );
}

/* Tests the pfftools_output_version_fprint function
 * Returns 1 if successful or 0 if not
 */
int pff_test_tools_output_version_fprint(
     void )
{
	FILE *stream = NULL;
	int result   = 0;

	/* Initialize test
	 */
	stream = tmpfile();

	PFF_TEST_ASSERT_IS_NOT_NULL(
	 "stream",
	 stream );

	/* Test invocation of function only
	 */
	pfftools_output_version_fprint(
	 stream,
	 "test" );

	/* Test error cases
	 */
	pfftools_output_version_fprint(
	 NULL,
	 "test" );

	pfftools_output_version_fprint(
	 stream,
	 NULL );

	/* Clean up
	 */
	result = fclose(
	          stream );

	stream = NULL;

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	return( 1 );

on_error:
	if( stream != NULL )
	{
		fclose(
		 stream );
	}
	return( 0 );
}

/* Tests the pfftools_output_version_detailed_fprint function
 * Returns 1 if successful or 0 if not
 */
int pff_test_tools_output_version_detailed_fprint(
     void )
{
	FILE *stream = NULL;
	int result   = 0;

	/* Initialize test
	 */
	stream = tmpfile();

	PFF_TEST_ASSERT_IS_NOT_NULL(
	 "stream",
	 stream );

	/* Test invocation of function only
	 */
	pfftools_output_version_detailed_fprint(
	 stream,
	 "test" );

	/* Test error cases
	 */
	pfftools_output_version_detailed_fprint(
	 NULL,
	 "test" );

	pfftools_output_version_detailed_fprint(
	 stream,
	 NULL );

	/* Clean up
	 */
	result = fclose(
	          stream );

	stream = NULL;

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	return( 1 );

on_error:
	if( stream != NULL )
	{
		fclose(
		 stream );
	}
	return( 0 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc PFF_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] PFF_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc PFF_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] PFF_TEST_ATTRIBUTE_UNUSED )
#endif
{
	PFF_TEST_UNREFERENCED_PARAMETER( argc )
	PFF_TEST_UNREFERENCED_PARAMETER( argv )

	PFF_TEST_RUN(
	 "pfftools_output_initialize",
	 pff_test_tools_output_initialize )

	PFF_TEST_RUN(
	 "pfftools_output_copyright_fprint",
	 pff_test_tools_output_copyright_fprint )

	PFF_TEST_RUN(
	 "pfftools_output_version_fprint",
	 pff_test_tools_output_version_fprint )

	PFF_TEST_RUN(
	 "pfftools_output_version_detailed_fprint",
	 pff_test_tools_output_version_detailed_fprint )

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
