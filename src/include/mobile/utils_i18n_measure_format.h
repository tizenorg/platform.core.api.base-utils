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

int i18n_measure_format_create(i18n_measure_format_h *measure_format, const char *language, const char *country, i18n_umeasure_width_format_e width_format);
//int i18n_measure_format_create_with_number_format(i18n_measure_format_h *measure_format, const char *language, const char *country, i18n_umeasure_width_format_e width_format, i18n_number_format_h number_format);
int i18n_measure_format_from_other(i18n_measure_format_h *measure_format, const i18n_measure_format_h other);
int i18n_measure_format_destroy(i18n_measure_format_h measure_format);
int i18n_measure_format_clone(i18n_measure_format_h measure_format, i18n_format_h *clone);
int i18n_measure_format_format(i18n_measure_format_h measure_format, char **format_string, const i18n_formattable_h *formattable, char **appendTo, i18n_field_position_h field_position);
int i18n_measure_format_parse_object(i18n_measure_format_h measure_format, char *source, const i18n_formattable_h result, i18n_field_position_h field_position);
//int i18n_measure_format_format_measures(i18n_measure_h *measures, i18n_measure_unit_h measure_unit, char **appendTo, i18n_field_position_h field_position);
//int i18n_measure_format_format_measure_per_unit(i18n_measure_h measure, i18n_measure_unit_h measure_unit, char **appendTo, i18n_field_position_h field_position);
int i18n_measure_format_create_currency_format_from_locale(i18n_measure_format_h measure_format, const char *language, const char *country);
int i18n_measure_format_create_currency_format(i18n_measure_format_h measure_format);

/**
 * @}
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __UTILS_I18N_MEASURE_FORMAT_H__*/
