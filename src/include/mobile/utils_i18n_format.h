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

#include <i18n_types.h>

int i18n_format_destroy(i18n_format_h format);
int i18n_format_clone(i18n_format_h format, i18n_format_h *clone);
int i18n_format_format(i18n_formattable_h formattable, char **append_to, char **ustring_format);
//int i18n_format_format(i18n_formattable_h formattable, char **append_to, i18n_field_position_h field_position, char **ustring_format);
//int i18n_format_format(i18n_formattable_h formattable, char **append_to, i18n_field_position_iter_h field_position_iter, char **ustring_format);
//int i18n_format_parse_object(char **source, i18n_formattable_h result, i18n_parse_position_h parse_position);
int i18n_format_parse_object(char **source, i18n_formattable_h *result);
int i18n_format_get_locale(i18n_uloc_data_locale_type_e type, char **language, char **country)
int i18n_format_get_locale_id(i18n_uloc_data_locale_type_e type, char **id)

/**
 * @}
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif	/* __I18N_FORMAT_H__*/
