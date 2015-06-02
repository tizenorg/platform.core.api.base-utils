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

#include <unicode/unorm2.h>
#include <utils_i18n_unormalization.h>
#include <utils_i18n_private.h>

int i18n_unormalization_get_instance ( const char *package_name, const char *name, i18n_unormalization_mode_e mode,
    i18n_unormalizer_h *normalizer )
{
    i18n_error_code_e err = I18N_ERROR_NONE;
    *normalizer = unorm2_getInstance(package_name, name, mode, (UErrorCode*)&err);
    int result = _i18n_error_mapping(err);
    
    return result;    
}

int i18n_unormalization_normalize ( i18n_unormalizer_h normalizer, const i18n_uchar *src, int32_t len, i18n_uchar *dest, int32_t capacity, int32_t *len_deststr )
{
    retv_if( normalizer == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e err = I18N_ERROR_NONE;
    *len_deststr = unorm2_normalize((UNormalizer2*)normalizer, src, len, dest, capacity, (UErrorCode*)&err);
    int result = _i18n_error_mapping(err);

    return result;
}
