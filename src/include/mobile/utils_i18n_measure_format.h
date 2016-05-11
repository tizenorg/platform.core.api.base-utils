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
int i18n_measure_format_create(i18n_measure_format_h *measure_format, const char *language, const char *country, i18n_umeasure_width_format_e width_format);

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
int i18n_measure_format_from_other(i18n_measure_format_h *measure_format, const i18n_measure_format_h other);

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
 * @brief Creates a polymorphic clone of the given @a clone object.
 * @since_tizen 3.0
 *
 * @param[out] measure_format  The created measure format object
 * @param[in]  other           The measure format object from which the new object is created
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_measure_format_clone(i18n_measure_format_h measure_format, i18n_format_h *clone);

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
int i18n_measure_format_create_currency_format_from_locale(i18n_measure_format_h measure_format, const char *language, const char *country);

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
int i18n_measure_format_create_currency_format(i18n_measure_format_h measure_format);

/**
 * @}
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __I18N_MEASURE_FORMAT_H__*/
