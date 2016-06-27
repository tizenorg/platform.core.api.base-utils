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

#ifndef __UTILS_I18N_MEASURE_FORMAT_H__
#define __UTILS_I18N_MEASURE_FORMAT_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_measure_format.h
 * @version 0.1
 * @brief utils_i18n_measure_format
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup CAPI_BASE_UTILS_I18N_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_MEASURE_FORMAT_MODULE MeasureFormat
 * @brief The MeasureFormat is a formatter for Measure objects.
 * @section CAPI_BASE_UTILS_I18N_MEASURE_FORMAT_MODULE_HEADER Required Header
 *       \#include <utils_i18n.h>
 *
 * @section CAPI_BASE_UTILS_I18N_MEASURE_FORMAT_MODULE_OVERVIEW Overview
 * @details
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_MEASURE_FORMAT_MODULE
 * @{
 */

/**
 * @brief Creates the measure format object using given locale.
 * @remarks The created object should be released by the caller with the
 *          i18n_measure_format_destroy() function.
 * @since_tizen 3.0
 *
 * @param[in] language         The language of the locale
 * @param[in] country          The country of the locale
 * @param[in] width            The format width
 * @param[out] measure_format  The created measure format object
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_create(const char *language, const char *country,
        i18n_umeasure_format_width_e width, i18n_measure_format_h *measure_format);

/**
 * @brief Destroys the measure format object
 * @since_tizen 3.0
 *
 * @param[in] measure_format  The measure format object to destroy
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_measure_format_destroy(i18n_measure_format_h measure_format);

/**
 * @brief Creates a polymorphic clone of the given @a measure_format object.
 * @remarks The @a clone object should be released by the caller with the
 *          i18n_measure_format_destroy() function.
 * @since_tizen 3.0
 *
 * @param[in]  measure_format  The measure format object to be cloned
 * @param[out] clone           The created measure format object
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_clone(i18n_measure_format_h measure_format, i18n_format_h *clone);

/**
 * @brief Formats an object to produce a string.
 * @remarks The obtained @a append_to string is actually a concatenation of the given input string and
 *          the result of the function (appended to the string). Actually, the @a append_to
 *          buffer is being reallocated inside the function which means that the buffer is not
 *          at the same place in memory as it was on the input. Please note that the @a append_to
 *          buffer should be released by the caller with the free() function.
 * @since_tizen 3.0
 *
 * @param[in]  measure_format  The format object
 * @param[in]  formattable     The object to format
 * @param[in/out] append_to    Output parameter to receive the result.
 *                             The result is appended to the existing contents.
 * @param[in/out]  field_position  On input: an alignment field, if desired.
 *                                 On output: the offsets of the alignment field.
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_format(i18n_measure_format_h measure_format, i18n_formattable_h formattable,
                               char **append_to, i18n_field_position_h field_position);

/**
 * @brief Parses a string to produce an object.
 * @remarks The obtained @a result object should be released by the caller
 *          with the i18n_formattable_destroy() function.
 * @since_tizen 3.0
 *
 * @param[in]  measure_format      The format object
 * @param[in]  source              The string to be parsed into an object
 * @param[in/out]  parse_position  The position to start parsing at. Upon return
 *                                 this parameter is set to the position after the
 *                                 last character successfully parsed. If the
 *                                 source is not parsed successfully, this parameter
 *                                 will remain unchanged.
 * @param[out] result              The formattable object to be set to the parse result.
 *                                 If parse fails, return contents are undefined.
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_parse_object(i18n_measure_format_h measure_format, const char *source, i18n_parse_position_h parse_position, i18n_formattable_h *result);

/**
 * @brief Gets a formatter for currency amount objects in the given locale.
 * @remarks The created object should be released by the caller with the
 *          i18n_measure_format_destroy() function.
 * @since_tizen 3.0
 *
 * @param[in] language         The language of the locale
 * @param[in] country          The country of the locale
 * @param[out] measure_format  The measure format object
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_create_currency_format_from_locale(const char *language, const char *country, i18n_measure_format_h *measure_format);

/**
 * @brief Gets a formatter for currency amount objects in the default locale.
 * @remarks The created object should be released by the caller with the
 *          i18n_measure_format_destroy() function.
 * @since_tizen 3.0
 *
 * @param[out] measure_format  The measure format object
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_create_currency_format(i18n_measure_format_h *measure_format);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __UTILS_I18N_MEASURE_FORMAT_H__*/
