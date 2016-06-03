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
 *»       \#include <utils_i18n.h>
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
 * @since_tizen 3.0
 *
 * @param[out] measure_format  The created measure format object
 * @param[in] language         The language of the locale
 * @param[in] country          The country of the locale
 * @param[in] width_format     The format width
 *
 * @return Error code. Error codes not listed below are described in #i18n_error_code_e
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_create(i18n_measure_format_h *measure_format, const char *language, const char *country, i18n_umeasure_format_width_e width_format);

/**
 * @brief Creates the measure format object from the other measure format object.
 * @deatils Function invokes the copy constructor.
 * @since_tizen 3.0
 *
 * @param[out] measure_format  The created measure format object
 * @param[in]  other           The measure format object from which the new object is created
 *
 * @return Error code. Error codes not listed below are described in #i18n_error_code_e
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_create_from_other(i18n_measure_format_h *measure_format, const i18n_measure_format_h other);

/**
 * @brief Destroys the measure format object
 * @since_tizen 3.0
 *
 * @param[in] measure_format  The measure format object to destroy
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_measure_format_destroy(i18n_measure_format_h measure_format);

/**
 * @brief Creates a polymorphic clone of the given @a measure_format object.
 * @since_tizen 3.0
 *
 * @param[in]  measure_format  The measure format object from which the new object is created
 * @param[out] clone           The created measure format object
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_clone(i18n_measure_format_h measure_format, i18n_format_h *clone);

/**
 * @brief Formats an object to produce a string.
 * @since_tizen 3.0
 *
 * @param[in]  measure_format  The format object
 * @param[in]  formattable     The object to format
 * @param[out] append_to       Output parameter to receive result. Result is appended to existing contents
 * @param[in]  field_position  The field position
 *
 * @return Error code. Error codes not listed below are described in #i18n_error_code_e
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_format(i18n_measure_format_h measure_format, i18n_formattable_h formattable, char **append_to, i18n_field_position_h field_position);

/**
 * @brief Parses a string to produce an object.
 * @since_tizen 3.0
 *
 * @param[in]  measure_format  The format object
 * @param[in]  source          The string to be parsed into an object
 * @param[out] result          The formattable object to be set to the parse result. If parse fails,
 *                             return contents are undefined.
 * @param[in]  parse_position  The parse position
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_parse_object(i18n_measure_format_h measure_format, char *source, i18n_formattable_h *result, i18n_parse_position_h parse_position);

/**
 * @brief Formats measure objects to produce a string.
 * @details An example of such a formatted string is 3 meters, 3.5 centimeters.
 * @reamrks Measure objects appear in the formatted string in the same order they appear
 *          in the @a measures array.
 * @since_tizen 3.0
 *
 * @param[in]  measure_format  The format object
 * @param[in]  measures        The array of measure objects
 * @param[in]  measure_count   The number of measure objects
 * @param[out] append_to       Output parameter to receive result. Result is appended to existing contents
 * @param[in]  field_position  The field position
 *
 * @return Error code. Error codes not listed below are described in #i18n_error_code_e
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_format_measures(i18n_measure_format_h measure_format, i18n_measure_h *measures, int32_t measure_count, char **append_to, i18n_field_position_h field_position);

/**
 * @brief Formats measure objects to produce a string adding a per unit.
 * @details An example of such a formatted string is 3 meters, 3.5 centimeters per second.
 * @since_tizen 3.0
 *
 * @param[in]  measure_format  The format object
 * @param[in]  measures        The array of measure objects
 * @param[in]  measure_count   The number of measure objects
 * @param[in]  measure_unit    The per unit. In the example formatted string, it is i18n_measure_unit_create_second(measure_unit)
 * @param[out] append_to       Output parameter to receive result. Result is appended to existing contents
 * @param[in]  field_position  The field position
 *
 * @return Error code. Error codes not listed below are described in #i18n_error_code_e
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_format_measures_per(i18n_measure_format_h measure_format, i18n_measure_h *measures, int32_t measure_count, i18n_measure_unit_h measure_unit, char **append_to, i18n_field_position_h field_position);

/**
 * @brief Gets a formatter for currency amount objects in the given locale.
 * @since_tizen 3.0
 *
 * @param[out] measure_format  The measure format object
 * @param[in] language          The language of the locale
 * @param[in] country           The country of the locale
 *
 * @return Error code. Error codes not listed below are described in #i18n_error_code_e
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_create_currency_format_from_locale(i18n_measure_format_h *measure_format, const char *language, const char *country);

/**
 * @brief Gets a formatter for currency amount objects in the default locale.
 * @since_tizen 3.0
 *
 * @param[out] measure_format  The measure format object
 *
 * @return Error code. Error codes not listed below are described in #i18n_error_code_e
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_create_currency_format(i18n_measure_format_h *measure_format);

/**
 * @}
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __UTILS_I18N_MEASURE_FORMAT_H__*/
