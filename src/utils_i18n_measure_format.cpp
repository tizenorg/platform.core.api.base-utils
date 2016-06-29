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

#include <utils_i18n_measure_format.h>
#include <utils_i18n_private.h>

#include <malloc.h>
#include <vector>
#include <unicode/measfmt.h>
#include <unicode/measure.h>

int i18n_measure_format_create(i18n_measure_format_h *measure_format, const char *language, const char *country, i18n_umeasure_format_width_e width)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;
    Locale locale(language, country, 0, 0);
    UMeasureFormatWidth icu_width = (UMeasureFormatWidth) width;

    *measure_format = new MeasureFormat(locale, icu_width, status);
    retv_if(*measure_format == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_format_destroy(i18n_measure_format_h measure_format)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);

    delete((MeasureFormat *) measure_format);

    return I18N_ERROR_NONE;
}

int i18n_measure_format_clone(i18n_measure_format_h measure_format, i18n_format_h *clone)
{
    retv_if(measure_format == NULL || clone == NULL, I18N_ERROR_INVALID_PARAMETER);

    *clone = ((MeasureFormat *) measure_format)->clone();
    retv_if(*clone == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_measure_format_format(i18n_measure_format_h measure_format, i18n_formattable_h formattable, char **append_to, i18n_field_position_h field_position)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(append_to == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(field_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;

    UnicodeString unicode_append_to(*append_to);

    UnicodeString result = ((MeasureFormat *) measure_format)->format(*((Formattable *) formattable), unicode_append_to, *((FieldPosition *) field_position), status);
    const UChar *uchar_result = result.getTerminatedBuffer();

    retv_if(uchar_result == NULL, I18N_ERROR_INVALID_PARAMETER);
    int32_t ulen = u_strlen(uchar_result);

    retv_if(ulen <= 0, I18N_ERROR_INVALID_PARAMETER);
    *append_to = (char *) malloc(ulen + 1);

    retv_if(*append_to == NULL, I18N_ERROR_OUT_OF_MEMORY);

    u_austrcpy(*append_to, uchar_result);

    return _i18n_error_mapping(status);
}

int i18n_measure_format_parse_object(i18n_measure_format_h measure_format, const char *source, i18n_parse_position_h parse_position, i18n_formattable_h *result)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(source == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(result == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(parse_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    const UnicodeString unicode_source(source);

    Formattable *f = new Formattable();

    ((MeasureFormat *) measure_format)->parseObject(unicode_source, *f, *((ParsePosition *) parse_position));

    *result = (i18n_formattable_h) f;
    retv_if(*result == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_measure_format_format_measures(i18n_measure_format_h measure_format, const i18n_measure_h *measures, int32_t measure_count, char **append_to, i18n_field_position_h field_position)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(measures == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(measure_count <= 0, I18N_ERROR_INVALID_PARAMETER);
    retv_if(append_to == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(field_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;
    UnicodeString unicode_append_to(*append_to);

    std::vector<Measure> m_array;

    for (int i = 0; i < measure_count; i++) {
        retv_if(measures[i] == NULL, I18N_ERROR_INVALID_PARAMETER);
        m_array.push_back(*((Measure *)measures[i]));
    }

    UnicodeString result = ((MeasureFormat *) measure_format)->formatMeasures(&m_array[0], measure_count, unicode_append_to, *((FieldPosition *) field_position), status);

    const UChar *uchar_result = result.getTerminatedBuffer();

    retv_if(uchar_result == NULL, I18N_ERROR_INVALID_PARAMETER);
    int32_t ulen = u_strlen(uchar_result);

    retv_if(ulen <= 0, I18N_ERROR_INVALID_PARAMETER);
    *append_to = (char *) malloc(ulen + 1);

    retv_if(*append_to == NULL, I18N_ERROR_OUT_OF_MEMORY);

    u_austrcpy(*append_to, uchar_result);

    return _i18n_error_mapping(status);
}

int i18n_measure_format_format_measures_per(i18n_measure_format_h measure_format, const i18n_measure_h *measures, int32_t measure_count, i18n_measure_unit_h per_unit, char **append_to, i18n_field_position_h field_position)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(measures == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(measure_count <= 0, I18N_ERROR_INVALID_PARAMETER);
    retv_if(append_to == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(field_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;
    UnicodeString unicode_append_to(*append_to);

    std::vector<Measure> m_array;

    for (int i = 0; i < measure_count; i++) {
        retv_if(measures[i] == NULL, I18N_ERROR_INVALID_PARAMETER);
        m_array.push_back(*((Measure *)measures[i]));
    }

    UnicodeString result = ((MeasureFormat *) measure_format)->formatMeasuresPer(&m_array[0], measure_count,*((MeasureUnit *)per_unit) , unicode_append_to, *((FieldPosition *) field_position), status);

    const UChar *uchar_result = result.getTerminatedBuffer();

    retv_if(uchar_result == NULL, I18N_ERROR_INVALID_PARAMETER);
    int32_t ulen = u_strlen(uchar_result);

    retv_if(ulen <= 0, I18N_ERROR_INVALID_PARAMETER);
    *append_to = (char *) malloc(ulen + 1);

    retv_if(*append_to == NULL, I18N_ERROR_OUT_OF_MEMORY);

    u_austrcpy(*append_to, uchar_result);

    return _i18n_error_mapping(status);
}

int i18n_measure_format_create_currency_format_from_locale(i18n_measure_format_h *measure_format, const char *language, const char *country)
{
    retv_if(measure_format == NULL || language == NULL || country == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;
    Locale locale(language, country, 0, 0);

    *measure_format = MeasureFormat::createCurrencyFormat(locale, status);
    retv_if(*measure_format == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_format_create_currency_format(i18n_measure_format_h *measure_format)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_format = MeasureFormat::createCurrencyFormat(status);
    retv_if(*measure_format == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}
