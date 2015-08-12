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

#include <stdio.h>
#include <unicode/unum.h>
#include <utils_i18n_unumber.h>
#include <utils_i18n_private.h>

int i18n_unumber_create (i18n_unumber_format_style_e style, const i18n_uchar *pattern, int32_t pattern_len, const char *locale, i18n_uparse_error_s *parse_err, i18n_unumber_format_h *num_format)
{
    retv_if (num_format == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode icu_error = U_ZERO_ERROR;
    *num_format = unum_open(style, pattern, pattern_len, locale, (UParseError*)parse_err, &icu_error);

    return _i18n_error_mapping(icu_error);
}

int i18n_unumber_destroy (i18n_unumber_format_h fmt)
{
    retv_if(fmt == NULL, I18N_ERROR_INVALID_PARAMETER);

    unum_close(fmt);

    return I18N_ERROR_NONE;
}

int i18n_unumber_get_symbol (const i18n_unumber_format_h fmt, i18n_unumber_format_symbol_e symbol, i18n_uchar *buffer, int32_t size, int32_t *len_symbol)
{
    retv_if(fmt == NULL || len_symbol == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode icu_error = U_ZERO_ERROR;
    *len_symbol = unum_getSymbol(fmt, symbol, buffer, size, &icu_error);

    return _i18n_error_mapping(icu_error);
}

// Newly Added APIs

int i18n_unumber_clone(const i18n_unumber_format_h fmt, i18n_unumber_format_h *fmt_clone)
{
    if(fmt == NULL || NULL == fmt_clone) {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    *fmt_clone = (i18n_unumber_format_h)unum_clone(fmt, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    return i18n_error;
}

int32_t i18n_unumber_format (const i18n_unumber_format_h fmt, int32_t number, i18n_uchar *result, int32_t result_length, i18n_ufield_position_s *pos, i18n_error_code_e *status)
{
    if(NULL == fmt) {
        if(NULL != status) {
            *status = I18N_ERROR_INVALID_PARAMETER;
        }
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_unum_format = unum_format (fmt, number, (UChar*)result, result_length, (UFieldPosition*)pos, &icu_error);
    if(NULL != status) {
        ERR_MAPPING(icu_error, *status);
        I18N_ERR(*status);
    }
    return result_unum_format;
}

int32_t i18n_unumber_format_int64 (const i18n_unumber_format_h fmt, int64_t number, i18n_uchar *result, int32_t result_length, i18n_ufield_position_h pos)
{
    if(fmt == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_unum_formatInt64 = unum_formatInt64 (fmt, number, result, result_length, (UFieldPosition*)pos, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    set_last_result(i18n_error);
    I18N_ERR(i18n_error);
    return result_unum_formatInt64;
}

int32_t i18n_unumber_format_double (const i18n_unumber_format_h fmt, double number, i18n_uchar *result, int32_t result_length, i18n_ufield_position_h pos)
{
    if(fmt == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_unum_formatDouble = unum_formatDouble(fmt, number, result, result_length, (UFieldPosition*)pos, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return result_unum_formatDouble;
}

int32_t i18n_unumber_format_decimal (const i18n_unumber_format_h fmt, const char *number, int32_t length, i18n_uchar *result, int32_t result_length, i18n_ufield_position_h pos)
{
    if(fmt == NULL || number == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_unum_formatDecimal = unum_formatDecimal (fmt, number, length, result, result_length, (UFieldPosition*)pos, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return result_unum_formatDecimal;
}

int32_t i18n_unumber_format_double_currency (const i18n_unumber_format_h fmt, double number, i18n_uchar *currency, i18n_uchar *result, int32_t result_length, i18n_ufield_position_h pos)
{
    if(fmt == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_unum_formatDoubleCurrency = unum_formatDoubleCurrency (fmt, number, currency, result, result_length, (UFieldPosition*)pos, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return result_unum_formatDoubleCurrency;
}

int32_t i18n_unumber_parse (const i18n_unumber_format_h fmt, const i18n_uchar *text, int32_t text_length, int32_t *parse_pos)
{
    if(fmt == NULL || text == NULL || text_length < -1) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_unum_parse = unum_parse (fmt, text, text_length, parse_pos, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return result_unum_parse;
}

int64_t i18n_unumber_parse_int64 (const i18n_unumber_format_h fmt, const i18n_uchar *text, int32_t text_length, int32_t *parse_pos)
{
    if(fmt == NULL || text == NULL || text_length < -1) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int64_t result_unum_parseInt64 = unum_parseInt64 (fmt, text, text_length, parse_pos, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return result_unum_parseInt64;
}

double i18n_unumber_parse_double (const i18n_unumber_format_h fmt, const i18n_uchar *text, int32_t text_length, int32_t *parse_pos)
{
    if(fmt == NULL || text == NULL || text_length < -1) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    double result_unum_parseDouble = unum_parseDouble (fmt, text, text_length, parse_pos, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return result_unum_parseDouble;
}

int32_t i18n_unumber_parse_decimal (const i18n_unumber_format_h fmt, const i18n_uchar *text, int32_t text_length, int32_t *parse_pos, char *out_buf, int32_t out_buf_length)
{
    if(fmt == NULL || text == NULL || text_length < -1 || out_buf == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_unum_parseDecimal = unum_parseDecimal (fmt, text, text_length, parse_pos, out_buf, out_buf_length, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return result_unum_parseDecimal;
}

double i18n_unumber_parse_double_currency (const i18n_unumber_format_h fmt, const i18n_uchar *text, int32_t text_length, int32_t *parse_pos, i18n_uchar *currency)
{
    if(fmt == NULL || text == NULL || text_length < -1 || currency == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_unum_parseDoubleCurrency = unum_parseDoubleCurrency (fmt, text, text_length, parse_pos, currency, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return result_unum_parseDoubleCurrency;
}

int i18n_unumber_apply_pattern (i18n_unumber_format_h format, i18n_ubool localized, const i18n_uchar *pattern, int32_t pattern_length, i18n_uparse_error_s* parse_error)
{
    if(format == NULL || pattern == NULL || pattern_length < -1) {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    unum_applyPattern (format, localized, pattern, pattern_length, (UParseError*)parse_error, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

const char *i18n_unumber_get_available (int32_t locale_index)
{
    if(locale_index < 0) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }

    set_last_result(I18N_ERROR_NONE);
    return unum_getAvailable(locale_index);
}

int32_t i18n_unumber_count_available (void)
{
    set_last_result(I18N_ERROR_NONE);
    return unum_countAvailable();
}

int32_t i18n_unumber_get_attribute (const i18n_unumber_format_h fmt, i18n_unumber_format_attribute_e attr)
{
    if(fmt == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    set_last_result(I18N_ERROR_NONE);
    return unum_getAttribute(fmt, attr);
}

int i18n_unumber_set_attribute (i18n_unumber_format_h fmt, i18n_unumber_format_attribute_e attr, int32_t new_value)
{
    if(fmt == NULL || attr == I18N_UNUMBER_ROUNDING_INCREMENT) {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    unum_setAttribute(fmt, attr, new_value);
    return I18N_ERROR_NONE;
}

double i18n_unumber_get_double_attribute (const i18n_unumber_format_h fmt, i18n_unumber_format_attribute_e attr)
{
    if(fmt == NULL || I18N_UNUMBER_ROUNDING_INCREMENT != attr) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    set_last_result(I18N_ERROR_NONE);
    return unum_getDoubleAttribute (fmt, attr);
}

int i18n_unumber_set_double_attribute (i18n_unumber_format_h fmt, i18n_unumber_format_attribute_e attr, double new_value)
{
    if(fmt == NULL || attr != I18N_UNUMBER_ROUNDING_INCREMENT) {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    unum_setDoubleAttribute(fmt, attr, new_value);
    return I18N_ERROR_NONE;
}

int32_t i18n_unumber_get_text_attribute (const i18n_unumber_format_h fmt, i18n_unumber_format_text_attribute_e tag, i18n_uchar *result, int32_t result_length)
{
    if(fmt == NULL) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_unum_getTextAttribute = unum_getTextAttribute (fmt, tag, result, result_length, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return result_unum_getTextAttribute;
}

int i18n_unumber_set_text_attribute (const i18n_unumber_format_h fmt, i18n_unumber_format_text_attribute_e tag, const i18n_uchar *new_value, int32_t new_value_length)
{
    if(fmt == NULL || new_value == NULL || new_value_length < -1) {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    unum_setTextAttribute((UNumberFormat*)fmt, tag, new_value, new_value_length, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    return i18n_error;
}

int32_t i18n_unumber_to_pattern (const i18n_unumber_format_h fmt, i18n_ubool is_pattern_localized, i18n_uchar *result, int32_t result_length)
{
    if(fmt == NULL) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_unum_toPattern = unum_toPattern(fmt, is_pattern_localized, result, result_length, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return result_unum_toPattern;
}

int i18n_unumber_set_symbol (i18n_unumber_format_h fmt, i18n_unumber_format_symbol_e symbol, const i18n_uchar *value, int32_t length)
{
    if(fmt == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    unum_setSymbol(fmt, symbol, value, length, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    return i18n_error;
}

const char *i18n_unumber_get_locale_by_type (const i18n_unumber_format_h fmt, i18n_ulocale_data_locale_type_e type)
{
    if(fmt == NULL) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    const char *result_unum_getLocaleByType = unum_getLocaleByType (fmt, type, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return result_unum_getLocaleByType;
}
