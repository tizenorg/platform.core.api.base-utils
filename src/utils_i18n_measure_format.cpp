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

#define __STDC_LIMIT_MACROS
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils_i18n_measure_format.h>
#include <utils_i18n_private.h>
#include <utils_i18n_ustring.h>

#include <unicode/ustdio.h>
#include <unicode/measfmt.h>
#include <unicode/measunit.h>
#include <unicode/format.h>
#include <unicode/fmtable.h>
#include <unicode/locid.h>
#include <unicode/uchar.h>

// TODO czy wrapujemy konstruktory?
int i18n_measure_format_create(i18n_measure_format_h measure_format, const char *language, const char *country, i18n_umeasure_width_format_e width_format)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;
    Locale locale(language, country, 0, 0);

    *measure_format = MeasureFormat(locale, width_format, status);
    retv_if(measure_format == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_format_create_with_number_format(i18n_measure_format_h measure_format, const char *language, const char *country, i18n_umeasure_width_format_e width_format, i18n_number_format_h number_format)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;
    Locale locale(language, country, 0, 0);

    *measure_format = MeasureFormat(locale, width_format, (NumberFormat *) number_format, status);
    retv_if(measure_format == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

// TODO czy wrapujemy konstruktor kopiujący?
int i18n_measure_format_form_other(i18n_measure_format_h measure_format, const i18n_measure_format_h other)
{
    retv_if(other == NULL, I18N_ERROR_INVALID_PARAMETER);

    *measure_format = MeasureFormat((MeasureFormat *) other);

    return I18N_ERROR_NONE;
}

int i18n_measure_format_destroy(i18n_measure_format_h measure_format)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);

    delete((MeasureFormat *) measure_format);

    return I18N_ERROR_NONE;
}

int i18n_measure_format_clone(i18n_measure_format_h measure_format, i18n_format_h *clone)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);

    *clone = ((MeasureFormat *) measure_format)->clone();

    return I18N_ERROR_NONE;
}

int i18n_measure_format_format(i18n_measure_format_h measure_format, char **format_string, const i18n_formattable_h *formattable, char **appendTo, i18n_field_position_h field_position)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    UnicodeString result = ((MeasureFormat *) measure_format)->format((Formattable *) formattable, appendTo,
                            (FieldPosition *) field_position, status);

    const UChar *uchar_format = result.getTerminatedBuffer();
    retv_if(uchar_format == NULL, I18N_ERROR_INVALID_PARAMETER);

    int32_t ulen = u_strlen(uchar_format);
    retv_if(ulen <= 0, I18N_ERROR_INVALID_PARAMETER);

    *format_string = (char *) malloc(ulen + 1);
    retv_if(*format_string == NULL, I18N_ERROR_OUT_OF_MEMORY);
    u_austrcpy(*format_string, uchar_format);

    return _i18n_error_mapping(status);
}

int i18n_measure_format_parse_object(i18n_measure_format_h measure_format, char *source, const i18n_formattable_h result, i18n_field_position_h field_position)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);

    UChar uchar_source;// = result.getTerminatedBuffer();
    u_uaustrcpy(uchar_source, source);
    retv_if(uchar_source == NULL, I18N_ERROR_INVALID_PARAMETER);

    UnicodeString unicode_source;
    unicode_source.setTo(uchar_source);

    ((MeasureFormat *) measure_format)->parseObject(unicode_source, result, (FieldPosition *) field_position);

    retv_if(tid == NULL, I18N_ERROR_INVALID_PARAMETER);

    return I18N_ERROR_NONE;
}

int i18n_measure_format_format_measures(i18n_measure_format_h measure_format, i18n_measure_h *measures, i18n_measure_unit_h measure_unit, char **appendTo, i18n_field_position_h field_position)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    UnicodeString result = ((MeasureFormat *) measure_format)->formatMeasurePerUnit(measures, (MeasureUnit *) measure_unit, appendTo,
                            (FieldPosition *) field_position, status);

    const UChar *uchar_format = result.getTerminatedBuffer();
    retv_if(uchar_format == NULL, I18N_ERROR_INVALID_PARAMETER);

    int32_t ulen = u_strlen(uchar_format);
    retv_if(ulen <= 0, I18N_ERROR_INVALID_PARAMETER);

    *format_string = (char *) malloc(ulen + 1);
    retv_if(*format_string == NULL, I18N_ERROR_OUT_OF_MEMORY);
    u_austrcpy(*format_string, uchar_format);

    return _i18n_error_mapping(status);
}

int i18n_measure_format_format_measure_per_unit(i18n_measure_format_h measure_format, i18n_measure_h measure, i18n_measure_unit_h measure_unit, char **appendTo, i18n_field_position_h field_position)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    UnicodeString result = ((MeasureFormat *) measure_format)->formatMeasurePerUnit((Measure *) measure, (MeasureUnit *) measure_unit,
                            appendTo, (FieldPosition *) field_position, status);

    const UChar *uchar_format = result.getTerminatedBuffer();
    retv_if(uchar_format == NULL, I18N_ERROR_INVALID_PARAMETER);

    int32_t ulen = u_strlen(uchar_format);
    retv_if(ulen <= 0, I18N_ERROR_INVALID_PARAMETER);

    *format_string = (char *) malloc(ulen + 1);
    retv_if(*format_string == NULL, I18N_ERROR_OUT_OF_MEMORY);
    u_austrcpy(*format_string, uchar_format);

    return _i18n_error_mapping(status);
}

int i18n_measure_format_create_currency_format_from_locale(i18n_measure_format_h measure_format, const char *language, const char *country)
{
    retv_if(language == NULL || country == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;
    Locale locale(language, country, 0, 0);

    *measure_format = createCurrencyFormat(locale, status);
    retv_if(measure_format == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_format_create_currency_format(i18n_measure_format_h measure_format)
{
    retv_if(language == NULL || country == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_format = createCurrencyFormat(status);
    retv_if(measure_format == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}
