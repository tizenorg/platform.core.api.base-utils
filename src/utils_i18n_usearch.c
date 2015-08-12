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

#include <unicode/usearch.h>
#include <utils_i18n.h>
#include <utils_i18n_private.h>

int i18n_usearch_destroy ( i18n_usearch_h searchiter )
{
    retv_if ( searchiter == NULL, I18N_ERROR_INVALID_PARAMETER );

    usearch_close ( searchiter );

    return I18N_ERROR_NONE;
}

int i18n_usearch_first ( i18n_usearch_h strsrch, int32_t *index_first )
{
    retv_if ( strsrch == NULL || index_first == NULL, I18N_ERROR_INVALID_PARAMETER );
    UErrorCode err = U_ZERO_ERROR;
    *index_first = usearch_first ( strsrch, &err );
    int result = _i18n_error_mapping ( err );
    I18N_ERR(result);

    return result;
}

int i18n_usearch_get_collator ( const i18n_usearch_h strsrch, i18n_ucollator_h *collator )
{
    retv_if ( strsrch == NULL || collator == NULL, I18N_ERROR_INVALID_PARAMETER );
    *collator = usearch_getCollator ( strsrch );

    return I18N_ERROR_NONE;
}

int i18n_usearch_get_matched_text ( const i18n_usearch_h strsrch, i18n_uchar *result_w, int32_t result_capacity, int32_t *len_matched_text )
{
    UErrorCode err = U_ZERO_ERROR;
    *len_matched_text = usearch_getMatchedText ( strsrch, result_w, result_capacity, &err );
    int result = _i18n_error_mapping ( err );
    I18N_ERR(result);

    return result;
}

int i18n_usearch_create ( const i18n_uchar *pattern, int32_t pattern_len, const i18n_uchar *text,
        int32_t text_len, const char *locale, i18n_ubreak_iterator_s *break_iter, i18n_usearch_h *search_iter )
{
    retv_if ( search_iter == NULL, I18N_ERROR_INVALID_PARAMETER );
    i18n_error_code_e err = I18N_ERROR_NONE;
    *search_iter = usearch_open ( pattern, pattern_len, text, text_len, locale, (UBreakIterator*)break_iter, (UErrorCode*)&err );
    int result = _i18n_error_mapping ( err );

    return result;
}

int i18n_usearch_create_new ( const i18n_uchar *pattern, int32_t pattern_len, const i18n_uchar *text,
        int32_t text_len, const char *locale, i18n_ubreak_iterator_h break_iter, i18n_usearch_h *search_iter )
{
    retv_if ( search_iter == NULL, I18N_ERROR_INVALID_PARAMETER );
    UErrorCode icu_error = U_ZERO_ERROR;
    *search_iter = (i18n_usearch_h)usearch_open(pattern, pattern_len, text, text_len, locale, (UBreakIterator*)break_iter, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}
