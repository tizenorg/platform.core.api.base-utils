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

#include <unicode/ubrk.h>
#include <utils_i18n_ubrk.h>
#include <utils_i18n_private.h>


int i18n_ubrk_create (i18n_ubreak_iterator_type_e type, const char *locale, const i18n_uchar *text, int32_t text_length, i18n_ubreak_iterator_h *break_iter)
{
    if (type < I18N_UBRK_CHARACTER || type > I18N_UBRK_SENTENCE || NULL == break_iter) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    if (text_length < -1) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    UErrorCode icu_error = U_ZERO_ERROR;
    *break_iter = (i18n_ubreak_iterator_h) ubrk_open((UBreakIteratorType)type, locale, text, text_length, &icu_error);
    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ubrk_create_rules (const i18n_uchar *rules, int32_t rules_length, const i18n_uchar *text, int32_t text_length, i18n_ubreak_iterator_h *break_iter, i18n_uparse_error_s *parse_err)
{
    if (rules == NULL || rules_length < -1 || text_length < -1 || break_iter == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    *break_iter = (i18n_ubreak_iterator_h) ubrk_openRules (rules, rules_length, text, text_length, (UParseError*)parse_err, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ubrk_safe_clone (const i18n_ubreak_iterator_h break_iter, void *stack_buffer, int32_t *p_buffer_size, i18n_ubreak_iterator_h *break_iter_clone)
{
    if (break_iter == NULL || break_iter_clone == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    UErrorCode icu_error = U_ZERO_ERROR;
    *break_iter_clone = (i18n_ubreak_iterator_h) ubrk_safeClone((const UBreakIterator*)break_iter, stack_buffer, p_buffer_size, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ubrk_destroy (i18n_ubreak_iterator_h break_iter)
{
    if (break_iter == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    ubrk_close((UBreakIterator*)break_iter);
    return I18N_ERROR_NONE;
}

int i18n_ubrk_set_text (i18n_ubreak_iterator_h break_iter, const i18n_uchar *text, int32_t text_length)
{
    if(text == NULL || break_iter == NULL || text_length < 0){
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    ubrk_setText((UBreakIterator*)break_iter, text, text_length, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int32_t i18n_ubrk_current (const i18n_ubreak_iterator_h break_iter)
{
    if (break_iter == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }
    set_last_result(I18N_ERROR_NONE);
    return ubrk_current ((const UBreakIterator*)break_iter);
}

int32_t i18n_ubrk_next (i18n_ubreak_iterator_h break_iter)
{
    if (break_iter == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    set_last_result(I18N_ERROR_NONE);
    return ubrk_next((UBreakIterator*)break_iter);
}

int32_t i18n_ubrk_previous (i18n_ubreak_iterator_h break_iter)
{
    if (break_iter == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    set_last_result(I18N_ERROR_NONE);
    return ubrk_previous ((UBreakIterator*)break_iter);
}

int32_t i18n_ubrk_first (i18n_ubreak_iterator_h break_iter)
{
    if (break_iter == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    set_last_result(I18N_ERROR_NONE);
    return ubrk_first ((UBreakIterator*)break_iter);
}

int32_t i18n_ubrk_last (i18n_ubreak_iterator_h break_iter)
{
    if( break_iter == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    set_last_result(I18N_ERROR_NONE);
    return ubrk_last ((UBreakIterator*)break_iter);
}

int32_t i18n_ubrk_preceding (i18n_ubreak_iterator_h break_iter, int32_t offset)
{
    if (break_iter == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    set_last_result(I18N_ERROR_NONE);
    return ubrk_preceding((UBreakIterator*)break_iter, offset);
}

int32_t i18n_ubrk_following (i18n_ubreak_iterator_h break_iter, int32_t offset)
{
    if (break_iter == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    set_last_result(I18N_ERROR_NONE);
    return ubrk_following((UBreakIterator*)break_iter, offset);
}

const char *i18n_ubrk_get_available (int32_t index)
{
    if(index < 0) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }

    set_last_result(I18N_ERROR_NONE);
    return ubrk_getAvailable(index);
}

int32_t i18n_ubrk_count_available (void)
{
    set_last_result(I18N_ERROR_NONE);
    return ubrk_countAvailable();
}

i18n_ubool i18n_ubrk_is_boundary (i18n_ubreak_iterator_h break_iter, int32_t offset)
{
    if (break_iter == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return false;
    }

    set_last_result(I18N_ERROR_NONE);
    return ubrk_isBoundary((UBreakIterator*)break_iter, offset);
}

int32_t i18n_ubrk_get_rule_status (i18n_ubreak_iterator_h break_iter)
{
    if (break_iter == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    set_last_result(I18N_ERROR_NONE);
    return ubrk_getRuleStatus((UBreakIterator*)break_iter);
}

int32_t i18n_ubrk_get_rule_status_vec (i18n_ubreak_iterator_h break_iter, int32_t *fill_in_vec, int32_t capacity)
{
    if (break_iter == NULL || capacity < 0) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_ubrk_getRuleStatusVec = ubrk_getRuleStatusVec((UBreakIterator*)break_iter, fill_in_vec, capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return result_ubrk_getRuleStatusVec;
}

const char *i18n_ubrk_get_locale_by_type (const i18n_ubreak_iterator_h break_iter, i18n_ulocale_data_locale_type_e type)
{
    if (type < I18N_ULOCALE_DATA_LOCALE_TYPE_ACTUAL_LOCALE ||
        type > I18N_ULOCALE_DATA_LOCALE_TYPE_LIMIT) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    UErrorCode icu_error = U_ZERO_ERROR;
    const char * result_ubrk_getLocaleByType = ubrk_getLocaleByType((const UBreakIterator*)break_iter, type, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return result_ubrk_getLocaleByType;
}
