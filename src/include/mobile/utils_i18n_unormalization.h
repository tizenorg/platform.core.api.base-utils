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

#ifndef __UTILS_I18N_UNORMALIZATION_H__
#define __UTILS_I18N_UNORMALIZATION_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_unormalization.h
 * @version 0.1
 * @brief utils_i18n_unormaliztion
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup CAPI_BASE_UTILS_I18N_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_UNORMALIZATION_MODULE Unormalization
 * @brief The Unormalization module provides Unicode normalization functionality for standard unicode normalization.
 *
 * @section CAPI_BASE_UTILS_I18N_UNORMALIZATION_MODULE_HEADER Required Header
 *  \#include <utils_i18n.h>
 *
 * @section CAPI_BASE_UTILS_I18N_UNORMALIZATION_MODULE_OVERVIEW Overview
 * @details The Unormalization module provides Unicode normalization functionality for standard unicode normalization.
 * All instances of i18n_unormalizer_h are unmodifiable/immutable.
 * Instances returned by i18n_unormalization_get_instance() are singletons that must not be deleted by the caller.
 *
 * @section CAPI_BASE_UTILS_I18N_UNORMALIZATION_MODULE_SAMPLE_CODE_1 Sample Code 1
 * @brief Creates a normalizer and normalizes a unicode string
 * @code
    i18n_unormalizer_h normalizer = NULL;
    i18n_uchar src = 0xAC00;
    i18n_uchar dest[4] = {0,};
    int dest_str_len = 0;
    int i = 0;

    // gets instance for normalizer
    i18n_unormalization_get_instance( NULL, "nfc", I18N_UNORMALIZATION_DECOMPOSE, &normalizer );

    // normalizes a unicode string
    i18n_unormalization_normalize( normalizer, &src, 1, dest, 4, &dest_str_len );
    dlog_print(DLOG_INFO, LOG_TAG, "src is 0x%x\n", src );    // src is 0xAC00 (0xAC00: A Korean character combined with consonant and vowel)

    for ( i = 0; i < dest_str_len; i++ ) {
        dlog_print(DLOG_INFO, LOG_TAG, "dest[%d] is 0x%x\t", i + 1, dest[i] );    // dest[1] is 0x1100  dest[2] is 0x1161 (0x1100: consonant, 0x1161: vowel)
    }
 * @endcode
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UNORMALIZATION_MODULE
 * @{
 */

/**
 * @brief Gets a i18n_unormalizer_h which uses the specified data file and composes or decomposes text according to the specified mode.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @param[in] package_name @c NULL for ICU built-in data, otherwise application data package name.
 * @param[in] name "nfc" or "nfkc" or "nfkc_cf" or the name of the custom data file.
 * @param[in] mode The normalization mode (compose or decompose).
 * @param[out] normalizer The requested normalizer on success.
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_unormalization_get_instance (const char *package_name, const char *name, i18n_unormalization_mode_e mode, 
    i18n_unormalizer_h *normalizer);

/**
 * @brief Writes the normalized form of the source string to the destination string(replacing its contents).
 * @details The source and destination strings must be different buffers.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @param[in] normalizer i18n normalizer handle.
 * @param[in] src The source string.
 * @param[in] len The length of the source string, otherwise @c -1 if NULL-terminated.
 * @param[out] dest The destination string\n
 * Its contents are replaced with normalized @a src.
 * @param[in] capacity The number of string_uchar that can be written to @a dest
 * @param[out] len_deststr The length of the destination string
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_unormalization_normalize (i18n_unormalizer_h normalizer, const i18n_uchar *src, int32_t len, i18n_uchar *dest, int32_t capacity, int32_t *len_deststr);

#ifdef __cplusplus
}
#endif

/**
 * @}
 * @}
 */

#endif  /* __UTILS_I18N_UNORMALIZATION_H__*/
