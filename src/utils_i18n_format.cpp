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

#include <utils_i18n_format.h>
#include <utils_i18n_private.h>

#include <unicode/format.h>
#include <malloc.h>

int i18n_format_destroy(i18n_format_h format)
{
    retv_if(format == NULL, I18N_ERROR_INVALID_PARAMETER);

    delete((Format *) format);

    return I18N_ERROR_NONE;
}

int i18n_format_clone(i18n_format_h format, i18n_format_h *clone)
{
    retv_if(format == NULL || clone == NULL, I18N_ERROR_INVALID_PARAMETER);

    *clone = ((Format *) format)->clone();
    retv_if(*clone == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_format_format(i18n_format_h format, i18n_formattable_h formattable, char **append_to)
{
    retv_if(format == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(append_to == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    UnicodeString unicode_append_to(*append_to);

    UnicodeString result = ((Format *) format)->format(*((Formattable *)formattable), unicode_append_to, status);
    const UChar *uchar_result = result.getTerminatedBuffer();

    retv_if(uchar_result == NULL, I18N_ERROR_INVALID_PARAMETER);
    int32_t ulen = u_strlen(uchar_result);

    retv_if(ulen <= 0, I18N_ERROR_INVALID_PARAMETER);
    *append_to = (char *) malloc(ulen + 1);

    retv_if(*append_to == NULL, I18N_ERROR_OUT_OF_MEMORY);

    u_austrcpy(*append_to, uchar_result);

    return _i18n_error_mapping(status);
}

int i18n_format_parse_object(i18n_format_h format, const char *source, i18n_formattable_h *result)
{
    retv_if(format == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(source == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(result == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;
    const UnicodeString unicode_source(source);

    Formattable *f = new Formattable();

    ((Format *) format)->parseObject(unicode_source, *f, status);

    *result = (i18n_formattable_h)f;

    return _i18n_error_mapping(status);
}

int i18n_format_get_locale(i18n_format_h format, i18n_uloc_data_locale_type_e type,
        const char **language, const char **country)
{
    retv_if(format == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(type < I18N_ULOC_ACTUAL_LOCALE || type > I18N_ULOC_REQUESTED_LOCALE, I18N_ERROR_INVALID_PARAMETER);
    retv_if(language == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(country == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;
    ULocDataLocaleType icu_type = (ULocDataLocaleType) type;

    Locale locale = ((Format *) format)->getLocale(icu_type, status);

    *language = strdup(locale.getLanguage());
    retv_if(*language == NULL, I18N_ERROR_OUT_OF_MEMORY);

    *country = strdup(locale.getCountry());
    retv_if(*country == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}
