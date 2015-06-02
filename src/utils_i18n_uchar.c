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

#include <unicode/uchar.h>
#include <utils_i18n_uchar.h>
#include <utils_i18n_private.h>

int i18n_uchar_get_int_property_value ( i18n_uchar32 c, i18n_uchar_uproperty_e which, int32_t *property_val )
{
	retv_if (property_val == NULL, I18N_ERROR_INVALID_PARAMETER);
	*property_val = u_getIntPropertyValue(c, which);

	return I18N_ERROR_NONE;
}

int i18n_uchar_get_ublock_code ( i18n_uchar32 c, i18n_uchar_ublock_code_e *block_val )
{
	retv_if (block_val == NULL, I18N_ERROR_INVALID_PARAMETER);
	*block_val = ublock_getCode(c);

	return I18N_ERROR_NONE;
}
