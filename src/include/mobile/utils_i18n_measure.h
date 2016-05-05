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

#ifndef __UTILS_I18N_MEASURE_H__
#define __UTILS_I18N_MEASURE_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_measure.h
 * @version 0.1
 * @brief utils_i18n_measure
 */

#ifdef __cplusplus
extern "C" {
#endif

int i18n_measure_create(i18n_measure_h *measure, const i18n_formattable_h formattable, i18n_measure_unit_h measure_unit);
int i18n_measure_create_form_other(i18n_measure_h *measure, const i18n_measure_h other);
int i18n_measure_clone(i18n_measure_h measure, i18n_measure_h *clone);
int i18n_measure_destroy(i18n_measure_h measure);
int i18n_measure_get_number(i18n_measure_h measure, i18n_formattable_h *formattable);
int i18n_measure_get_unit(i18n_measure_h measure, i18n_measure_unit_h *measure_unit);

/**
 * @}
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __I18N_MEASURE_H__*/
