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

#ifndef __UTILS_I18N_UCHAR_H__
#define __UTILS_I18N_UCHAR_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_uchar.h
 * @version 0.1
 * @brief utils_i18n
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup CAPI_BASE_UTILS_I18N_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_UCHAR_MODULE Uchar
 * @brief The Uchar module provides low-level access to the Unicode Character Database.
 *
 * @section CAPI_BASE_UTILS_I18N_UCHAR_MODULE_HEADER Required Header
 *  \#include <utils_i18n.h>
 *
 * @section CAPI_BASE_UTILS_I18N_UCHAR_MODULE_OVERVIEW Overview
 * @details The Uchar module provides low-level access to the Unicode Character Database.
 *
 * @section CAPI_BASE_UTILS_I18N_UCHAR_MODULE_SAMPLE_CODE_1 Sample Code 1
 * @brief Gets the property value of 'east asian width' among an enumerated property,
 * and the unicode allocation block that contains the character.
 * @code
    int ret = I18N_ERROR_NONE;
    i18n_uchar32 code_point = 0;
    int property_value = 0;
    i18n_uchar_u_east_asian_width_e east_asian_width = I18N_UCHAR_U_EA_NEUTRAL;
    i18n_uchar_ublock_code_e block_code = I18N_UCHAR_UBLOCK_NO_BLOCK;

    // How to get the east asian width type for 's'
    code_point = 0x73;    // 's'
    ret = i18n_uchar_get_int_property_value(code_point, I18N_UCHAR_EAST_ASIAN_WIDTH, &property_value);
    if (ret != I18N_ERROR_NONE) {
        dlog_print(DLOG_INFO, LOG_TAG, "Error occured!!\n");
    } else {
        east_asian_width = (i18n_uchar_u_east_asian_width_e)property_value;
        dlog_print(DLOG_INFO, LOG_TAG, "East Asian Width Type for ( %.4x ) is ( %d )\n", code_point, east_asian_width);
        // East Asian Width Type for ( 0073 ) is ( 4 ) which is I18N_UCHAR_U_EA_NARROW
    }

    // How to get the block code for 's'
    ret = i18n_uchar_get_ublock_code(code_point, &block_code);
    if (ret != I18N_ERROR_NONE) {
        dlog_print(DLOG_INFO, LOG_TAG, "Error occured!!\n");
    } else {
        dlog_print(DLOG_INFO, LOG_TAG, "block name for ( %.4x ) is ( %d )\n", code_point, block_code);
        // block code for ( 0073 ) is ( 1 ) which is I18N_UCHAR_UBLOCK_BASIC_LATIN
    }

    // How to get the east asian width type for 'sung' as ideographs
    code_point = 0x661F;    // 'sung' as ideographs
    ret = i18n_uchar_get_int_property_value(code_point, I18N_UCHAR_EAST_ASIAN_WIDTH, &property_value);
    if (ret != I18N_ERROR_NONE) {
        dlog_print(DLOG_INFO, LOG_TAG, "Error occured!!\n");
    } else {
        east_asian_width = (i18n_uchar_u_east_asian_width_e)property_value;
        dlog_print(DLOG_INFO, LOG_TAG, "East Asian Width Type for ( %.4x ) is ( %d )\n", code_point, east_asian_width);
        // East Asian Width Type for ( 661f ) is ( 5 ) which is I18N_UCHAR_U_EA_WIDE
    }

    // How to get the block code for 'sung' as ideographs
    ret = i18n_uchar_get_ublock_code(code_point, &block_code);
    if (ret != I18N_ERROR_NONE) {
        dlog_print(DLOG_INFO, LOG_TAG, "Error occured!!\n");
    } else {
        dlog_print(DLOG_INFO, LOG_TAG, "block name for ( %.4x ) is ( %d )\n", code_point, block_code);
        // block code for ( 661f ) is ( 71 ) which is I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS
    }

    // How to get the east asian width type for 'sung' as hangul
    code_point = 0xC131;    // 'sung' as hangul
    ret = i18n_uchar_get_int_property_value(code_point, I18N_UCHAR_EAST_ASIAN_WIDTH, &property_value);
    if (ret != I18N_ERROR_NONE) {
        dlog_print(DLOG_INFO, LOG_TAG, "Error occured!!\n");
    } else {
        east_asian_width = (i18n_uchar_u_east_asian_width_e)property_value;
        dlog_print(DLOG_INFO, LOG_TAG, "East Asian Width Type for ( %.4x ) is ( %d )\n", code_point, east_asian_width);
        // East Asian Width Type for ( c131 ) is ( 5 ) which is I18N_UCHAR_U_EA_WIDE
    }

    // How to get the block code for 'sung' as hangul
    ret = i18n_uchar_get_ublock_code(code_point, &block_code);
    if (ret != I18N_ERROR_NONE) {
        dlog_print(DLOG_INFO, LOG_TAG, "Error occured!!\n");
    } else {
        dlog_print(DLOG_INFO, LOG_TAG, "block name for ( %.4x ) is ( %d )\n", code_point, block_code);
        // block code for ( c131 ) is ( 74 ) which is I18N_UCHAR_UBLOCK_HANGUL_SYLLABLES
    }
  
 * @endcode
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UCHAR_MODULE
 * @{
 */

/**
 * @brief Gets the property value for an enumerated property for a code point.
 * @details
 *     <code>
 *     int property_value;\n
 *     #i18n_uchar_u_east_asian_width_e east_asian_width;\n
 *     #i18n_uchar_get_int_property_value (c, #I18N_UCHAR_EAST_ASIAN_WIDTH, &property_value);\n
 *     east_asian_width = (#i18n_uchar_u_east_asian_width_e)property_value;\n
 *
 *     int property_value;\n
 *     bool is_ideographic;\n
 *     #i18n_uchar_get_int_property_value(c, #I18N_UCHAR_IDEOGRAPHIC, &property_value);\n
 *     is_ideographic = (bool)property_value;\n
 *     </code>
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @param[in] c The code point to test.
 * @param[in] which The #i18n_uchar_uproperty_e selector constant, identifies which property to check \n
 * Must be #I18N_UCHAR_BINARY_START<=which<#I18N_UCHAR_BINARY_LIMIT
 * or #I18N_UCHAR_INT_START<=which<#I18N_UCHAR_INT_LIMIT
 * or #I18N_UCHAR_MASK_START<=which<#I18N_UCHAR_MASK_LIMIT.
 * @param[out] property_val The numeric value that is directly the property value or,
 * for enumerated properties, corresponds to the numeric value of the enumerated
 * constant of the respective property value enumeration type (cast to enum type if necessary)\n
 * Returns @c 0 or @c 1 (for false/true) for binary Unicode properties\n
 * Returns a bit-mask for mask properties \n
 * Returns @c 0 if 'which' is out of bounds or if the Unicode version does not have data for the property at all, or not for this code point.
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_uchar_get_int_property_value ( i18n_uchar32 c, i18n_uchar_uproperty_e which, int32_t *property_val );

/**
 * @brief Gets the Unicode allocation block that contains the character.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @param[in] c The code point to test
 * @param[out] block_val The block value for the code point
 *
 * @retval #I18N_ERROR_NONE  Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_uchar_get_ublock_code ( i18n_uchar32 c, i18n_uchar_ublock_code_e *block_val );

#ifdef __cplusplus
}
#endif

/**
 * @}
 * @}
 */

#endif  /* __UTILS_I18N_UCHAR_H__*/
