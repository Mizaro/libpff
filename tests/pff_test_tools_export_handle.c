/*
 * Tools export_handle type test program
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
#include <memory.h>
#include <system_string.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#if defined( HAVE_UNISTD_H )
#include <unistd.h>
#endif

#include "pff_test_libcerror.h"
#include "pff_test_macros.h"
#include "pff_test_memory.h"
#include "pff_test_unused.h"

#include "../pfftools/export_handle.h"

/* Tests the export_handle_initialize function
 * Returns 1 if successful or 0 if not
 */
int pff_test_tools_export_handle_initialize(
     void )
{
	export_handle_t *export_handle  = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;

#if defined( HAVE_PFF_TEST_MEMORY )
	int number_of_malloc_fail_tests = 1;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = export_handle_initialize(
	          &export_handle,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	PFF_TEST_ASSERT_IS_NOT_NULL(
	 "export_handle",
	 export_handle );

	PFF_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = export_handle_free(
	          &export_handle,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	PFF_TEST_ASSERT_IS_NULL(
	 "export_handle",
	 export_handle );

	PFF_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = export_handle_initialize(
	          NULL,
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

	export_handle = (export_handle_t *) 0x12345678UL;

	result = export_handle_initialize(
	          &export_handle,
	          &error );

	export_handle = NULL;

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	PFF_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_PFF_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test export_handle_initialize with malloc failing
		 */
		pff_test_malloc_attempts_before_fail = test_number;

		result = export_handle_initialize(
		          &export_handle,
		          &error );

		if( pff_test_malloc_attempts_before_fail != -1 )
		{
			pff_test_malloc_attempts_before_fail = -1;

			if( export_handle != NULL )
			{
				export_handle_free(
				 &export_handle,
				 NULL );
			}
		}
		else
		{
			PFF_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			PFF_TEST_ASSERT_IS_NULL(
			 "export_handle",
			 export_handle );

			PFF_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test export_handle_initialize with memset failing
		 */
		pff_test_memset_attempts_before_fail = test_number;

		result = export_handle_initialize(
		          &export_handle,
		          &error );

		if( pff_test_memset_attempts_before_fail != -1 )
		{
			pff_test_memset_attempts_before_fail = -1;

			if( export_handle != NULL )
			{
				export_handle_free(
				 &export_handle,
				 NULL );
			}
		}
		else
		{
			PFF_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			PFF_TEST_ASSERT_IS_NULL(
			 "export_handle",
			 export_handle );

			PFF_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_PFF_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( export_handle != NULL )
	{
		export_handle_free(
		 &export_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the export_handle_free function
 * Returns 1 if successful or 0 if not
 */
int pff_test_tools_export_handle_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = export_handle_free(
	          NULL,
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

/* Tests the export_handle_create_default_item_directory function
 * Returns 1 if successful or 0 if not
 */
int pff_test_tools_export_handle_create_default_item_directory(
     void )
{
	export_handle_t *export_handle          = NULL;
	libcerror_error_t *error                = NULL;
	system_character_t *item_directory_path = NULL;
	size_t item_directory_path_size         = 0;
	int result                              = 0;

	/* Initialize test
	 */
	result = export_handle_initialize(
	          &export_handle,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	PFF_TEST_ASSERT_IS_NOT_NULL(
	 "export_handle",
	 export_handle );

	PFF_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = export_handle_create_default_item_directory(
	          export_handle,
	          100000,
	          _SYSTEM_STRING( "Message" ),
	          7,
	          _SYSTEM_STRING( "." ),
	          1,
	          &item_directory_path,
	          &item_directory_path_size,
	          NULL,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	PFF_TEST_ASSERT_IS_NOT_NULL(
	 "item_directory_path",
	 item_directory_path );

	PFF_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Clean up
	 */
#if defined( WINAPI )
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
	RemoveDirectoryW(
	 item_directory_path );
#else
	RemoveDirectoryA(
	 item_directory_path );
#endif
#else
	rmdir(
	 item_directory_path );
#endif
	memory_free(
	 item_directory_path );

	item_directory_path = NULL;

	/* Test error cases
	 */
	result = export_handle_create_default_item_directory(
	          NULL,
	          0,
	          _SYSTEM_STRING( "Message" ),
	          7,
	          _SYSTEM_STRING( "." ),
	          1,
	          &item_directory_path,
	          &item_directory_path_size,
	          NULL,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	PFF_TEST_ASSERT_IS_NULL(
	 "item_directory_path",
	 item_directory_path );

	PFF_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = export_handle_create_default_item_directory(
	          export_handle,
	          -1,
	          _SYSTEM_STRING( "Message" ),
	          7,
	          _SYSTEM_STRING( "." ),
	          1,
	          &item_directory_path,
	          &item_directory_path_size,
	          NULL,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	PFF_TEST_ASSERT_IS_NULL(
	 "item_directory_path",
	 item_directory_path );

	PFF_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = export_handle_free(
	          &export_handle,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	PFF_TEST_ASSERT_IS_NULL(
	 "export_handle",
	 export_handle );

	PFF_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( item_directory_path != NULL )
	{
#if defined( WINAPI )
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
		RemoveDirectoryW(
		 item_directory_path );
#else
		RemoveDirectoryA(
		 item_directory_path );
#endif
#else
		rmdir(
		 item_directory_path );
#endif
		memory_free(
		 item_directory_path );
	}
	if( export_handle != NULL )
	{
		export_handle_free(
		 &export_handle,
		 NULL );
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
	 "export_handle_initialize",
	 pff_test_tools_export_handle_initialize );

	PFF_TEST_RUN(
	 "export_handle_free",
	 pff_test_tools_export_handle_free );

	PFF_TEST_RUN(
	 "export_handle_create_default_item_directory",
	 pff_test_tools_export_handle_create_default_item_directory );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
