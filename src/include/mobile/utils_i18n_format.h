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

#ifndef __UTILS_I18N_FORMAT_H__
#define __UTILS_I18N_FORMAT_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_format.h
 * @version 0.1
 * @brief utils_i18n_format
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup CAPI_BASE_UTILS_I18N_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_FORMAT_MODULE Format
 * @brief The Timezone module represents the base class for all formats.
 * @section CAPI_BASE_UTILS_I18N_FORMAT_MODULE_HEADER Required Header
 *	\#include <utils_i18n.h>
 *
 * @section CAPI_BASE_UTILS_I18N_FORMAT_MODULE_OVERVIEW Overview
 * @details The Format module specifies the protocol for classes which convert other objects or values,\n
 * such as numeric values and dates, and their string representations.\n
 * In some cases these representations may be localized or contain localized characters or strings.\n
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_FORMAT_MODULE
 * @{
 */

/**
 * @brief Destroys the format object.
 * @details Function invokes the object destructor.
 * @since_tizen 3.0
 *
 * @param[in] format  The format object to destroy
 *
 * @retval #I18N_ERROR_NONE Successful
 */
int i18n_format_destroy(i18n_format_h format);

/**
 * @brief Creates a polymorphic clone of the given @a format object.
 * @details The caller is responsible for deleting the result when done.
 * @since_tizen 3.0
 *
 * @param[in]  format  The format object from which the new object is created
 * @param[out] clone   The created format object
 *
 * @retval #I18N_ERROR_NONE Successful
 */
int i18n_format_clone(i18n_format_h format, i18n_format_h *clone);

/**
 * @brief Formats an object to produce a string.
 * @details This is a convenience method which calls the pure virtual parseObject() method.
 * @since_tizen 3.0
 *
 * @param[in] format       The format object
 * @param[in] formattable  The object to format
 * @param[out] append_to   Output parameter to receive result. Result is appended to existing contents
 * @param[out] ustring_format  Reference to @a append_to parameter
 *
 * @return Error code. Error codes not listed below are described in #i18n_error_code_e
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_format_format(i18n_formattable_h format, i18n_formattable_h formattable, char *append_to, char *ustring_format);

/**
 * @brief Parses a string to produce an object.
 * @details The caller is responsible for deleting the result when done.
 * @since_tizen 3.0
 *
 * @param[in] format       The format object
 * @param[in] source   The string to be parsed into an object
 * @param[out] result  The formattable object to be set to the parse result. If parse fails,
 *                     return contents are undefined.
 *
 * @return Error code. Error codes not listed below are described in #i18n_error_code_e
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_format_parse_object(i18n_formattable_h format, char *source, i18n_formattable_h *result);

/**
 * @brief Gets the locale for the given format object.
 * @details You can choose between valid and actual locale.
 * @since_tizen 3.0
 *
 * @param[in] format     The format object
 * @param[in] type       The type of the locale we're looking for (valid or actual)
 * @param[out] language  The obtained locale's ISO-639 language code
 * @param[out] country   The obtained locale's ISO-3166 country code
 *
 * @return Error code. Error codes not listed below are described in #i18n_error_code_e
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_format_get_locale(i18n_format_h format, i18n_uloc_data_locale_type_e type, const char **language, const char **country);

/**
 * @}
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif	/* __UTILS_I18N_FORMAT_H__*/
