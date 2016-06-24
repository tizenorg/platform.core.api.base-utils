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
