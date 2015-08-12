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

#include <unicode/udat.h>
#include <utils_i18n_udate.h>
#include <utils_i18n_private.h>

int i18n_udate_create ( i18n_udate_format_style_e time_style, i18n_udate_format_style_e date_style, const char *locale, const i18n_uchar *tz_id, int32_t tz_id_len, const i18n_uchar *pattern, int32_t pattern_len, i18n_udate_format_h *format )
{
    retv_if( format == NULL, I18N_ERROR_INVALID_PARAMETER );

    UErrorCode icu_error = U_ZERO_ERROR;
    *format = udat_open(time_style, date_style, locale, tz_id, tz_id_len, pattern, pattern_len, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_udate_destroy ( i18n_udate_format_h format )
{
    retv_if( format == NULL, I18N_ERROR_INVALID_PARAMETER );

    udat_close(format);
    return I18N_ERROR_NONE;
}

int i18n_udate_format_date ( const i18n_udate_format_h format, i18n_udate date_to_format, i18n_uchar *result, int32_t result_len, i18n_ufield_position_h pos, int32_t *buf_size_needed )
{
    retv_if( format == NULL || buf_size_needed == NULL, I18N_ERROR_INVALID_PARAMETER );

    UErrorCode icu_error = U_ZERO_ERROR;
    *buf_size_needed = udat_format(format, date_to_format, result, result_len, (UFieldPosition*)pos, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

// Newly Added APIs
int i18n_udate_to_calendar_date_field ( i18n_udate_format_field_e field, i18n_ucalendar_date_fields_e *date_field_type )
{
    if (date_field_type == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    switch (field) {
        case I18N_UDATE_FORMAT_TIMEZONE_LOCALIZED_GMT_OFFSET_FIELD:
        case I18N_UDATE_FORMAT_TIMEZONE_ISO_FIELD:
        case I18N_UDATE_FORMAT_TIMEZONE_ISO_LOCAL_FIELD:
        case I18N_UDATE_FORMAT_FIELD_COUNT:
            LOGE("Unsupported field");
            return I18N_ERROR_INVALID_PARAMETER;
        default:
            *date_field_type = (i18n_ucalendar_date_fields_e)udat_toCalendarDateField(field);
    }

    return I18N_ERROR_NONE;
}

int i18n_udate_clone ( const i18n_udate_format_h format, i18n_udate_format_h *format_clone )
{
    if (format == NULL || format_clone == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    *format_clone = (i18n_udate_format_h)udat_clone((const UDateFormat *)format, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_udate_parse ( const i18n_udate_format_h format, const i18n_uchar *text, int32_t text_length, int32_t *parse_pos, i18n_udate *parsed_date )
{
    if (format == NULL || text == NULL || text_length < -1 || parsed_date == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    *parsed_date = udat_parse((const UDateFormat *)format, text, text_length, parse_pos, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_udate_parse_calendar (const i18n_udate_format_h format, i18n_ucalendar_h * calendar, const i18n_uchar *text, int32_t text_length, int32_t *parse_pos )
{
    if (format == NULL || calendar == NULL || text == NULL || text_length < -1)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    udat_parseCalendar((const UDateFormat *)format, calendar, text, text_length, parse_pos, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

i18n_ubool i18n_udate_is_lenient ( const i18n_udate_format_h format )
{
    if (format == NULL)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return false;
    }

    set_last_result(I18N_ERROR_NONE);
    return udat_isLenient((const UDateFormat *)format);
}

int i18n_udate_set_lenient ( i18n_udate_format_h format, i18n_ubool is_lenient )
{
    if (format == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    udat_setLenient((UDateFormat *)format, is_lenient);
    return I18N_ERROR_NONE;
}

int i18n_udate_get_calendar ( const i18n_udate_format_h format, i18n_ucalendar_h *calendar)
{
    if (format == NULL || calendar == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    *calendar = (i18n_ucalendar_h)udat_getCalendar((const UDateFormat *)format);

    return I18N_ERROR_NONE;
}

int i18n_udate_set_calendar ( i18n_udate_format_h format, const i18n_ucalendar_h calendar_to_set )
{
    if (format == NULL || calendar_to_set == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    udat_setCalendar((UDateFormat *)format, (const UCalendar *)calendar_to_set);
    return I18N_ERROR_NONE;
}

int i18n_udate_get_number_format ( const i18n_udate_format_h format, i18n_unumber_format_h *number_format )
{
    if (format == NULL || number_format == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    set_last_result(I18N_ERROR_NONE);
    *number_format = (i18n_unumber_format_h)udat_getNumberFormat((const UDateFormat *)format);
    return I18N_ERROR_NONE;
}

int i18n_udate_set_number_format ( i18n_udate_format_h format, const i18n_unumber_format_h number_format_to_set )
{
    if (format == NULL || number_format_to_set == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    udat_setNumberFormat((UDateFormat *)format, (const UNumberFormat *)number_format_to_set);
    return I18N_ERROR_NONE;
}

const char *i18n_udate_get_available ( int32_t locale_index )
{
    if(locale_index < 0) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    set_last_result(I18N_ERROR_NONE);
    return udat_getAvailable(locale_index);
}

int32_t i18n_udate_count_available ( void )
{
    set_last_result(I18N_ERROR_NONE);
    return udat_countAvailable();
}

int i18n_udate_get_2digit_year_start ( const i18n_udate_format_h format, i18n_udate *year )
{
    if (format == NULL || year == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    *year = (i18n_udate)udat_get2DigitYearStart((const UDateFormat *)format, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_udate_set_2digit_year_start ( i18n_udate_format_h format, i18n_udate date )
{
    if (format == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    udat_set2DigitYearStart((UDateFormat *)format, date, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int32_t i18n_udate_to_pattern ( const i18n_udate_format_h format, i18n_ubool localized, i18n_uchar *result, int32_t result_length )
{
    if (format == NULL)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = udat_toPattern((const UDateFormat *)format, localized, result, result_length, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return needed_buffer_size;
}

int i18n_udate_apply_pattern ( i18n_udate_format_h format, i18n_ubool localized, const i18n_uchar *pattern, int32_t pattern_length )
{
    if (format == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    udat_applyPattern((UDateFormat *)format, localized, pattern, pattern_length);
    return I18N_ERROR_NONE;
}

int32_t i18n_udate_get_symbols ( const i18n_udate_format_h format, i18n_udate_format_symbol_type_e type, int32_t symbol_index, i18n_uchar *result, int32_t result_length )
{
    if (format == NULL || type < I18N_UDATE_FORMAT_SYMBOL_TYPE_ERAS || type > I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_SHORTER_WEEKDAYS || symbol_index < 0)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = udat_getSymbols((const UDateFormat *)format, type, symbol_index, result, result_length, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return needed_buffer_size;
}

int32_t i18n_udate_count_symbols ( const i18n_udate_format_h format, i18n_udate_format_symbol_type_e type )
{
    if (format == NULL)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    set_last_result(I18N_ERROR_NONE);
    return udat_countSymbols((const UDateFormat *)format, type);
}

int i18n_udate_set_symbols ( i18n_udate_format_h format, i18n_udate_format_symbol_type_e type, int32_t symbol_index, i18n_uchar *value, int32_t value_length )
{
    if (format == NULL || symbol_index < 0 || value_length < -1)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    udat_setSymbols((UDateFormat *)format, type, symbol_index, value, value_length, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

const char *i18n_udate_get_locale_by_type ( const i18n_udate_format_h format, i18n_ulocale_data_locale_type_e type )
{
    if (format == NULL)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    const char *locale_name = udat_getLocaleByType((const UDateFormat *)format, type, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return locale_name;
}

int i18n_udate_set_context ( i18n_udate_format_h format, i18n_udisplay_context_e value )
{
    if (format == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    udat_setContext((UDateFormat *)format, value, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}
