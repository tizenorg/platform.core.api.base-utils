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

#include <unicode/ucol.h>
#include <utils_i18n_ucollator.h>
#include <utils_i18n_private.h>

int i18n_ucollator_destroy ( i18n_ucollator_h collator )
{
    retv_if(collator == NULL, I18N_ERROR_INVALID_PARAMETER);

	ucol_close(collator);

	return I18N_ERROR_NONE;
}

int i18n_ucollator_equal ( const i18n_ucollator_h collator, const i18n_uchar *src, int32_t src_len, const i18n_uchar *target, int32_t target_len, i18n_ubool *equal )
{
    retv_if(collator == NULL, I18N_ERROR_INVALID_PARAMETER);

	*equal = ucol_equal(collator, src, src_len, target, target_len);

	return I18N_ERROR_NONE;
}

int i18n_ucollator_create ( const char *locale, i18n_ucollator_h *collator )
{
	retv_if (collator == NULL, I18N_ERROR_INVALID_PARAMETER);

	i18n_error_code_e err = I18N_ERROR_NONE;
	*collator = ucol_open(locale, (UErrorCode*)&err);
	int result = _i18n_error_mapping(err);

	return result;
}

int i18n_ucollator_set_attribute( i18n_ucollator_h collator, i18n_ucollator_attribute_e attr, i18n_ucollator_attribute_value_e val )
{
    retv_if(collator == NULL, I18N_ERROR_INVALID_PARAMETER);

	i18n_error_code_e err = I18N_ERROR_NONE;
	ucol_setAttribute(collator, attr, val, (UErrorCode*)&err);
	int result = _i18n_error_mapping(err);

	return result;
}

int i18n_ucollator_set_strength ( i18n_ucollator_h collator, i18n_ucollator_strength_e strength )
{
    retv_if(collator == NULL, I18N_ERROR_INVALID_PARAMETER);

	ucol_setStrength(collator, strength);

	return I18N_ERROR_NONE;
}

int i18n_ucollator_str_collator ( const i18n_ucollator_h collator, const i18n_uchar *src, int32_t src_len, const i18n_uchar *target, int32_t target_len, i18n_ucollator_result_e *result )
{
    retv_if(collator == NULL, I18N_ERROR_INVALID_PARAMETER);

	*result = ucol_strcoll(collator, src, src_len, target, target_len);

	return I18N_ERROR_NONE;
}
