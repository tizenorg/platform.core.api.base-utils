/*
 * Copyright (c) 2015 Samsung Electronics Co., Ltd All Rights Reserved
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#ifndef __UTILS_I18N_UCOLLATOR_H__
#define __UTILS_I18N_UCOLLATOR_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_ucollator.h
 * @version 0.1
 * @brief utils_i18n_ucollator
 */

#ifdef __cplusplus
extern "C" {
# endif

/**
 * @ingroup CAPI_BASE_UTILS_I18N_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE Ucollator
 * @brief The Ucollator module performs locale-sensitive string comparison.
 *
 * @section CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE_HEADER Required Header
 *  \#include <utils_i18n.h>
 *
 * @section CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE_OVERVIEW Overview
 * @details The Ucollator module performs locale-sensitive string comparison. It builds searching and sorting routines for natural language text and provides correct sorting orders for most locales supported.
 *
 * @section CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE_SAMPLE_CODE_1 Sample Code 1
 * @brief Converts two different byte strings to two different unicode strings and compares the unicode strings to check if the strings are equal to each other.
 * @code
    i18n_uchar uchar_src[64] = {0,};
    i18n_uchar uchar_target[64] = {0,};
    char *src = "tizen";
    char *target = "bada";
    int uchar_src_len = 0;
    int uchar_target_len = 0;
    i18n_ucollator_h coll = NULL;
    i18n_ubool result = NULL;

    i18n_ustring_from_UTF8( uchar_src, 64, NULL, src, -1 );
    i18n_ustring_from_UTF8( uchar_target, 64, NULL, target, -1 );

    // creates a collator
    i18n_ucollator_create( "en_US", &coll );

    // sets strength for coll
    i18n_ucollator_set_strength( coll, I18N_UCOLLATOR_PRIMARY );

    // compares uchar_src with uchar_target
    i18n_ustring_get_length( uchar_src, &uchar_src_len );
    i18n_ustring_get_length( uchar_target, &uchar_target_len );
    i18n_ucollator_equal( coll, uchar_src, uchar_src_len, uchar_target, uchar_target_len, &result );
    dlog_print(DLOG_INFO, LOG_TAG, "%s %s %s\n", src, result == 1 ? "is equal to" : "is not equal to", target );    // tizen is not equal to bada

    // destroys the collator
    i18n_ucollator_destroy( coll );
 * @endcode
 * @section CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE_SAMPLE_CODE_2 Sample Code 2
 * @brief Sorts in ascending order on the given data using string_ucollator
 * @code
    i18n_ucollator_h coll = NULL;
    char *src[3] = { "cat", "banana", "airplane" };
    char *tmp = NULL;
    i18n_uchar buf_01[16] = {0,};
    i18n_uchar buf_02[16] = {0,};
    i18n_ucollator_result_e result = I18N_UCOLLATOR_EQUAL;
    int i = 0, j = 0;
    int ret = I18N_ERROR_NONE;
    int buf_01_len = 0, buf_02_len = 0;

    for ( i = 0; i < sizeof( src ) / sizeof( src[0] ); i++ ) {
        dlog_print(DLOG_INFO, LOG_TAG, "%s\n", src[i] );
    }    // cat    banana    airplane

    // creates a collator
    ret = i18n_ucollator_create( "en_US", &coll );

    // compares and sorts in ascending order
    if ( ret == I18N_ERROR_NONE ) {
        i18n_ucollator_set_strength( coll, I18N_UCOLLATOR_TERTIARY );
        for ( i = 0; i < 2; i++ ) {
            for ( j = 0; j < 2 - i; j++ ) {
                i18n_ustring_copy_ua( buf_01, src[j] );
                i18n_ustring_copy_ua( buf_02, src[j+1] );
                i18n_ustring_get_length( buf_01, &buf_01_len );
                i18n_ustring_get_length( buf_02, &buf_02_len );
                // compares buf_01 with buf_02
                i18n_ucollator_str_collator( coll, buf_01, buf_01_len, buf_02, buf_02_len, &result );
                if ( result == I18N_UCOLLATOR_GREATER ) {
                    tmp = src[j];
                    src[j] = src[j+1];
                    src[j+1] = tmp;
                }
            }
        }
    }
    // destroys the collator
    i18n_ucollator_destroy( coll );    // deallocate memory for collator

    for ( i = 0; i < sizeof( src ) / sizeof( src[0] ); i++ ) {
        dlog_print(DLOG_INFO, LOG_TAG, "%s\n", src[i] );
    }    // ariplane    banana    cat
 * @endcode
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE
 * @{
 */

/**
 * @brief Creates a i18n_ucollator_h for comparing strings.
 * @details The i18n_ucollator_h is used in all the calls to the Collation service.\n
 * After finished, collator must be disposed off by calling {@link #i18n_ucollator_destroy()}.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 * @remarks Must release @a collator using i18n_ucollator_destroy().
 *
 * @param[in] locale The locale containing the required collation rules\n
 * Special values for locales can be passed in - if @c NULL is passed for the locale, the default locale collation rules will be used \n
 * If empty string ("") or "root" is passed, UCA rules will be used.
 * @param[out] collator i18n_ucollator_h, otherwise @c 0 if an error occurs
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @see i18n_ucollator_destroy()
 */
int i18n_ucollator_create ( const char *locale, i18n_ucollator_h *collator );

/**
 * @brief Closes a i18n_ucollator_h.
 * @details Once closed, a string_ucollator_h should not be used. Every an open collator should be closed. Otherwise, a memory leak will result.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @param[in] collator The i18n_ucollator_h to close
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @see i18n_ucollator_create()
 */
int i18n_ucollator_destroy ( i18n_ucollator_h collator );

/**
 * @brief Compares two strings.
 * @details The strings will be compared using the options already specified.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @param[in] collator The i18n_ucollator_h containing the comparison rules
 * @param[in] src The source string
 * @param[in] src_len The length of the source, otherwise @c -1 if null-terminated
 * @param[in] target The target string.
 * @param[in] target_len The length of the target, otherwise @c -1 if null-terminated
 * @param[out] result The result of comparing the strings \n
 * One of #I18N_UCOLLATOR_EQUAL, #I18N_UCOLLATOR_GREATER, or #I18N_UCOLLATOR_LESS
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @see i18n_ucollator_equal()
 */
int i18n_ucollator_str_collator ( const i18n_ucollator_h collator, const i18n_uchar *src, int32_t src_len, const i18n_uchar *target, int32_t target_len, i18n_ucollator_result_e *result );

/**
 * @brief Compares two strings for equality.
 * @details This function is equivalent to {@link #i18n_ucollator_str_collator()}.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @param[in] collator The i18n_ucollator_h containing the comparison rules
 * @param[in] src The source string
 * @param[in] src_len The length of the source, otherwise @c -1 if null-terminated
 * @param[in] target The target string
 * @param[in] target_len The length of the target, otherwise @c -1 if null-terminated
 * @param[out] equal If @c true source is equal to target, otherwise @c false
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @see i18n_ucollator_str_collator()
 */
int i18n_ucollator_equal ( const i18n_ucollator_h collator, const i18n_uchar *src, int32_t src_len, const i18n_uchar *target, int32_t target_len, i18n_ubool *equal );

/**
 * @brief Sets the collation strength used in a collator.
 * @details The strength influences how strings are compared.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @param[in] collator The i18n_collator_h to set.
 * @param[in] strength The desired collation strength.\n
 *     One of #i18n_ucollator_strength_e
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ucollator_set_strength ( i18n_ucollator_h collator, i18n_ucollator_strength_e strength );

/**
 * @brief Sets a universal attribute setter.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @param[in] collator The i18n_collator_h containing attributes to be changed
 * @param[in] attr The attribute type
 * @param[in] val The attribute value
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ucollator_set_attribute ( i18n_ucollator_h collator, i18n_ucollator_attribute_e attr, i18n_ucollator_attribute_value_e val );

#ifdef __cplusplus
}
#endif

/**
 * @}
 * @}
 */

#endif	/* __UTILS_I18N_UCOLLATOR_H__*/
