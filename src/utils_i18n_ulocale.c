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

#include <unicode/uloc.h>
#include <utils_i18n_ulocale.h>
#include <utils_i18n_private.h>

int i18n_ulocale_get_default (const char **locale)
{
    retv_if (locale == NULL, I18N_ERROR_INVALID_PARAMETER);

    *locale = uloc_getDefault();

    return I18N_ERROR_NONE;
}

int i18n_ulocale_set_default (const char *locale_id)
{
    UErrorCode icu_error = U_ZERO_ERROR;
    uloc_setDefault(locale_id, &icu_error);

    return _i18n_error_mapping(icu_error);
}

int i18n_ulocale_get_language (const char *locale_id, char *language, int32_t language_capacity, int32_t *buf_size_language)
{
    retv_if(buf_size_language == NULL || language == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode icu_error = U_ZERO_ERROR;
    *buf_size_language = uloc_getLanguage(locale_id, language, language_capacity, &icu_error);

    return _i18n_error_mapping(icu_error);
}

int32_t i18n_ulocale_get_country (const char *locale_id, char *country, int32_t country_capacity, int *error)
{
    if(NULL == country || country_capacity < 0) {
        if(NULL != error) {
            *error = I18N_ERROR_INVALID_PARAMETER;
        }
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result = uloc_getCountry(locale_id, country, country_capacity, &icu_error);
    if(NULL != error) {
        *error = _i18n_error_mapping(icu_error);
    }

    return result;
}

int i18n_ulocale_get_display_name (const char *locale_id, const char *in_locale_id, i18n_uchar *result_w, int32_t max_result_size, int32_t *buf_size_display_name)
{
    retv_if(buf_size_display_name == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode icu_error = U_ZERO_ERROR;
    *buf_size_display_name = uloc_getDisplayName(locale_id, in_locale_id, result_w, max_result_size, &icu_error);

    return _i18n_error_mapping(icu_error);
}

const char* i18n_ulocale_get_available (int32_t n)
{
    if(n < 0){
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    set_last_result(I18N_ERROR_NONE);
    return uloc_getAvailable(n);
}

int32_t i18n_ulocale_count_available (void)
{
    set_last_result(I18N_ERROR_NONE);
    return uloc_countAvailable();
}

// Newly Added APIs

int32_t i18n_ulocale_get_script (const char *locale_id, char *script, int32_t script_capacity)
{
    if(NULL == script || script_capacity < 0){
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_getScript(locale_id, script, script_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

int32_t i18n_ulocale_get_variant (const char *locale_id, char *variant, int32_t variant_capacity)
{
    if(NULL == variant || variant_capacity < 0){
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_getVariant(locale_id, variant, variant_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

int32_t i18n_ulocale_get_name (const char *locale_id, char *name, int32_t name_capacity)
{
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_getName(locale_id, name, name_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

int32_t i18n_ulocale_canonicalize (const char *locale_id, char *name, int32_t name_capacity)
{
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_canonicalize(locale_id, name, name_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

const char *i18n_ulocale_get_iso3_language (const char *locale_id)
{
    set_last_result(I18N_ERROR_NONE);
    return uloc_getISO3Language(locale_id);
}

const char *i18n_ulocale_get_iso3_country (const char *locale_id)
{
    set_last_result(I18N_ERROR_NONE);
    return uloc_getISO3Country(locale_id);
}

uint32_t i18n_ulocale_get_lcid (const char *locale_id)
{
    set_last_result(I18N_ERROR_NONE);
    return uloc_getLCID(locale_id);
}

int32_t i18n_ulocale_get_display_language (const char *locale, const char *display_locale, i18n_uchar *language,
        int32_t language_capacity)
{
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_getDisplayLanguage(locale, display_locale, language, language_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

int32_t i18n_ulocale_get_display_script (const char *locale, const char *display_locale, i18n_uchar *script,
        int32_t script_capacity)
{
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_getDisplayScript(locale, display_locale, script, script_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

int32_t i18n_ulocale_get_display_country (const char *locale, const char *display_locale, i18n_uchar *country,
        int32_t country_capacity)
{
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_getDisplayCountry(locale, display_locale, country, country_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

int32_t i18n_ulocale_get_display_variant (const char *locale, const char *display_locale, i18n_uchar *variant,
        int32_t variant_capacity)
{
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_getDisplayVariant(locale, display_locale, variant, variant_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

int32_t i18n_ulocale_get_display_keyword (const char *keyword, const char *display_locale, i18n_uchar *dest,
        int32_t dest_capacity)
{
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_getDisplayKeyword(keyword, display_locale, dest, dest_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

int32_t i18n_ulocale_get_display_keyword_value (const char *locale, const char *keyword, const char *display_locale,
        i18n_uchar *dest, int32_t dest_capacity)
{
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_getDisplayKeywordValue(locale, keyword, display_locale, dest, dest_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

const char * const *i18n_ulocale_get_iso_languages (void)
{
    set_last_result(I18N_ERROR_NONE);
    return uloc_getISOLanguages();
}

const char * const *i18n_ulocale_get_iso_countries (void)
{
    set_last_result(I18N_ERROR_NONE);
    return uloc_getISOCountries();
}

int32_t i18n_ulocale_get_parent (const char *locale_id, char *parent, int32_t parent_capacity)
{
    if(NULL == parent || parent_capacity < 0){
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t len_of_loc = uloc_getParent(locale_id, parent, parent_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return len_of_loc;
}

int32_t i18n_ulocale_get_base_name (const char *locale_id, char *name, int32_t name_capacity)
{
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_getBaseName(locale_id, name, name_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

int i18n_ulocale_keywords_create (const char *locale_id, i18n_uenumeration_h *enumeration )
{
    if (NULL == enumeration){
        return I18N_ERROR_INVALID_PARAMETER;
    }
    UErrorCode icu_error = U_ZERO_ERROR;
    *enumeration = (i18n_uenumeration_h)uloc_openKeywords(locale_id, &icu_error);
    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    return i18n_error;
}

int32_t i18n_ulocale_get_keyword_value (const char *locale_id, const char *keyword_name, char *buffer,
        int32_t buffer_capacity)
{
    if(NULL == locale_id || NULL == keyword_name || NULL == buffer || buffer_capacity < 0){
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t len_of_keyword = uloc_getKeywordValue(locale_id, keyword_name, buffer, buffer_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return len_of_keyword;
}

int32_t i18n_ulocale_set_keyword_value (const char *keyword_name, const char *keyword_value, char *buffer,
        int32_t buffer_capacity)
{
    if(NULL == keyword_name || NULL == buffer || buffer_capacity < 0){
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_setKeywordValue(keyword_name, keyword_value, buffer, buffer_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

int i18n_ulocale_get_character_orientation (const char *locale_id, i18n_ulocale_layout_type_e *layout_type)
{
    if (NULL == layout_type){
        return I18N_ERROR_INVALID_PARAMETER;
    }
    UErrorCode icu_error = U_ZERO_ERROR;
    *layout_type = uloc_getCharacterOrientation(locale_id, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    return i18n_error;
}

int i18n_ulocale_get_line_orientation (const char *locale_id, i18n_ulocale_layout_type_e *layout_type)
{
    if (NULL == layout_type){
        return I18N_ERROR_INVALID_PARAMETER;
    }
    UErrorCode icu_error = U_ZERO_ERROR;
   *layout_type = uloc_getLineOrientation(locale_id, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    return i18n_error;
}

int32_t i18n_ulocale_get_locale_for_lcid (uint32_t host_id, char *locale, int32_t locale_capacity)
{
    if(NULL == locale || locale_capacity < 0){
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_getLocaleForLCID(host_id, locale, locale_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

int32_t i18n_ulocale_add_likely_subtags (const char *locale_id, char *maximized_locale_id,
        int32_t maximized_locale_id_capacity)
{
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_addLikelySubtags(locale_id, maximized_locale_id, maximized_locale_id_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

int32_t i18n_ulocale_minimize_subtags (const char *locale_id, char *minimized_locale_id,
        int32_t minimized_locale_id_capacity)
{
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t needed_buffer_size = uloc_minimizeSubtags(locale_id, minimized_locale_id, minimized_locale_id_capacity, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return needed_buffer_size;
}

int32_t i18n_ulocale_for_language_tag (const char *langtag, char *locale_id, int32_t locale_id_capacity,
        int32_t *parsed_length)
{
    if(NULL == langtag || NULL == locale_id || locale_id_capacity < 0){
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t len_of_loc = uloc_forLanguageTag(langtag, locale_id, locale_id_capacity, parsed_length, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return len_of_loc;
}

int32_t i18n_ulocale_to_language_tag (const char *locale_id, char *langtag, int32_t langtag_capacity,
        i18n_ubool strict)
{
    if(NULL == locale_id || NULL == langtag || langtag_capacity < 0){
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t len_of_loc = uloc_toLanguageTag(locale_id, langtag, langtag_capacity, strict, &icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return len_of_loc;
}
