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

#include <unicode/uenum.h>
#include <utils_i18n_uenumeration.h>
#include <utils_i18n_private.h>

int i18n_uenumeration_destroy ( i18n_uenumeration_h enumeration )
{
    if (enumeration == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    uenum_close((UEnumeration *)enumeration);
    return I18N_ERROR_NONE;
}

int32_t i18n_uenumeration_count ( i18n_uenumeration_h enumeration )
{
    if (enumeration == NULL)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t number_of_elements = uenum_count((UEnumeration *)enumeration, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    set_last_result(i18n_error);
    return number_of_elements;
}

const i18n_uchar *i18n_uenumeration_unext ( i18n_uenumeration_h enumeration, int32_t *result_length )
{
    if (enumeration == NULL)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    const UChar *ustring = uenum_unext((UEnumeration *)enumeration, result_length, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    set_last_result(i18n_error);
    return ustring;
}

const char *i18n_uenumeration_next ( i18n_uenumeration_h enumeration, int32_t *result_length )
{
    if (enumeration == NULL)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    const char *string = uenum_next((UEnumeration *)enumeration, result_length, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    set_last_result(i18n_error);
    return string;
}

int i18n_uenumeration_reset ( i18n_uenumeration_h enumeration )
{
    if (enumeration == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    uenum_reset((UEnumeration *)enumeration, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    return i18n_error;
}

int i18n_uenumeration_uchar_strings_enumeration_create ( const i18n_uchar *const strings[], int32_t count, i18n_uenumeration_h *enumeration )
{
    if (count < 0 || NULL == enumeration)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    *enumeration = uenum_openUCharStringsEnumeration(strings, count, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    return i18n_error;
}

int i18n_uenumeration_char_strings_enumeration_create ( const char *const strings[], int32_t count, i18n_uenumeration_h *enumeration )
{
    if (count < 0 || NULL == enumeration)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    *enumeration = (i18n_uenumeration_h)uenum_openCharStringsEnumeration(strings, count, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    return i18n_error;
}
