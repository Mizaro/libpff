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

#if defined( WINAPI )
#include <direct.h>
#endif

#include "pff_test_libcerror.h"
#include "pff_test_macros.h"
#include "pff_test_unused.h"

#include "../pfftools/export_handle.h"
#include "../pfftools/pfftools_libcpath.h"

#define PFF_TEST_EXPORT_HANDLE_PATH	_SYSTEM_STRING( "pff_test_tools_export_handle.dir" )

/* Removes a directory created by the test
 */
void pff_test_tools_export_handle_remove_directory(
      const system_character_t *path )
{
	if( path == NULL )
	{
		return;
	}
#if defined( WINAPI )
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
	_wrmdir(
	 path );
#else
	_rmdir(
	 path );
#endif
#else
	rmdir(
	 path );
#endif
}

/* Tests that pffexport can name an item directory past 100000 items
 * Returns 1 if successful or 0 if not
 */
int pff_test_tools_export_handle_create_default_item_directory_past_100000(
     void )
{
	export_handle_t *export_handle               = NULL;
	libcerror_error_t *error                     = NULL;
	system_character_t *item_directory_path      = NULL;
	const system_character_t *expected_suffix    = _SYSTEM_STRING( "Message100001" );
	size_t expected_suffix_length                = 13;
	size_t export_path_length                    = 0;
	size_t item_directory_path_size              = 0;
	size_t item_directory_path_length            = 0;
	int result                                   = 0;
	int suffix_compare_result                    = 0;

	export_path_length = system_string_length(
	                      PFF_TEST_EXPORT_HANDLE_PATH );

#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
	result = libcpath_path_make_directory_wide(
	          PFF_TEST_EXPORT_HANDLE_PATH,
	          &error );
#else
	result = libcpath_path_make_directory(
	          PFF_TEST_EXPORT_HANDLE_PATH,
	          &error );
#endif
	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	PFF_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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

	result = export_handle_create_default_item_directory(
	          export_handle,
	          100000,
	          _SYSTEM_STRING( "Message" ),
	          7,
	          PFF_TEST_EXPORT_HANDLE_PATH,
	          export_path_length,
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

	item_directory_path_length = system_string_length(
	                              item_directory_path );

	PFF_TEST_ASSERT_GREATER_THAN_INT(
	 "item_directory_path_length",
	 (int) item_directory_path_length,
	 (int) expected_suffix_length - 1 );

	suffix_compare_result = system_string_compare(
	                         &( item_directory_path[ item_directory_path_length - expected_suffix_length ] ),
	                         expected_suffix,
	                         expected_suffix_length );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "suffix_compare_result",
	 suffix_compare_result,
	 0 );

	pff_test_tools_export_handle_remove_directory(
	 item_directory_path );

	memory_free(
	 item_directory_path );

	item_directory_path = NULL;

	result = export_handle_free(
	          &export_handle,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	pff_test_tools_export_handle_remove_directory(
	 PFF_TEST_EXPORT_HANDLE_PATH );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( item_directory_path != NULL )
	{
		pff_test_tools_export_handle_remove_directory(
		 item_directory_path );

		memory_free(
		 item_directory_path );
	}
	if( export_handle != NULL )
	{
		export_handle_free(
		 &export_handle,
		 NULL );
	}
	pff_test_tools_export_handle_remove_directory(
	 PFF_TEST_EXPORT_HANDLE_PATH );

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
	 "export_handle_create_default_item_directory_past_100000",
	 pff_test_tools_export_handle_create_default_item_directory_past_100000 );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
