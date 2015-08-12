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
#include <unicode/uchar.h>
#include <utils_i18n_uset.h>
#include <utils_i18n_private.h>

int i18n_uset_create_empty ( i18n_uset_h* set )
{
    if(set == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    *set = (i18n_uset_h)uset_openEmpty();
    return I18N_ERROR_NONE;
}

int i18n_uset_create ( i18n_uchar32 start, i18n_uchar32 end, i18n_uset_h *set)
{
    if(set == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    *set = (i18n_uset_h)uset_open(start, end);
    return I18N_ERROR_NONE;
}

int i18n_uset_create_pattern ( const i18n_uchar *pattern, int32_t pattern_length, i18n_uset_h *set )
{
    UErrorCode icu_error = U_ZERO_ERROR;
    i18n_error_code_e i18n_error;

    if (pattern == NULL || pattern_length < -1 || set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    *set = (i18n_uset_h)uset_openPattern(pattern, pattern_length, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_uset_create_pattern_options ( const i18n_uchar *pattern, int32_t pattern_length, uint32_t options, i18n_uset_h *set )
{
    UErrorCode icu_error = U_ZERO_ERROR;
    i18n_error_code_e i18n_error;

    if (pattern == NULL || pattern_length < -1 || set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    if ((options != I18N_USET_IGNORE_SPACE) && (options != I18N_USET_CASE_INSENSITIVE)) {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    *set = (i18n_uset_h)uset_openPatternOptions(pattern, pattern_length, options, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    return i18n_error;
}

int i18n_uset_destroy ( i18n_uset_h set )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_close((USet*)set);
    return I18N_ERROR_NONE;
}

int i18n_uset_clone ( const i18n_uset_h set, i18n_uset_h *set_clone )
{
    if (set == NULL || set_clone == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    *set_clone = (i18n_uset_h)uset_clone((const USet*)set);

    return I18N_ERROR_NONE;
}

i18n_ubool i18n_uset_is_frozen ( const i18n_uset_h set )
{
    set_last_result(I18N_ERROR_NONE);
    if (set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return false;
    }
    return uset_isFrozen((const USet*)set);
}

int i18n_uset_freeze ( i18n_uset_h set )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_freeze((USet*)set);
    return I18N_ERROR_NONE;
}

int i18n_uset_clone_as_thawed ( const i18n_uset_h set, i18n_uset_h *set_copy )
{
    if (set == NULL || set_copy == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    *set_copy = (i18n_uset_h)uset_cloneAsThawed((const USet*)set);

    return I18N_ERROR_NONE;
}

int i18n_uset_set ( i18n_uset_h set, i18n_uchar32 start, i18n_uchar32 end )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_set((USet*)set, start, end);
    return I18N_ERROR_NONE;
}

int32_t i18n_uset_apply_pattern ( i18n_uset_h set, const i18n_uchar *pattern, int32_t pattern_length, uint32_t options )
{
    if (set == NULL ) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }
    if (pattern == NULL || pattern_length < -1) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    if (options != I18N_USET_IGNORE_SPACE && options != I18N_USET_CASE_INSENSITIVE) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    i18n_error_code_e i18n_error;

    int32_t result_uset_applyPattern = uset_applyPattern ((USet*)set, pattern, pattern_length, options, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return result_uset_applyPattern;
}

int i18n_uset_apply_int_property_value ( i18n_uset_h set, i18n_uchar_uproperty_e prop, int32_t value )
{
    if (set == NULL) {
       return I18N_ERROR_INVALID_PARAMETER;
    }
    if ((prop < I18N_UCHAR_INT_START || prop > I18N_UCHAR_INT_LIMIT-1) &&
            (prop < I18N_UCHAR_MASK_START || prop > I18N_UCHAR_MASK_LIMIT-1)) {
       return I18N_ERROR_INVALID_PARAMETER;
    }
    if (prop != I18N_UCHAR_GENERAL_CATEGORY_MASK &&
        (value <= I18N_UCHAR_INVALID_CODE ||
        value >= I18N_UCHAR_OTHER_PROPERTY_LIMIT)) {
       return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    i18n_error_code_e i18n_error;

    uset_applyIntPropertyValue((USet *)set, prop, value, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_uset_apply_property_alias ( i18n_uset_h set, const i18n_uchar *prop, int32_t prop_length, const i18n_uchar *value, int32_t value_length )
{
    if (set == NULL) {
       return I18N_ERROR_INVALID_PARAMETER;
    }
    if (prop == NULL || prop_length < -1) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    if (value == NULL || value_length < -1) {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    i18n_error_code_e i18n_error;

    uset_applyPropertyAlias ((USet*)set, prop, prop_length, value, value_length, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;

}

i18n_ubool i18n_uset_resembles_pattern ( const i18n_uchar *pattern, int32_t pattern_length, int32_t pos )
{
    if (pattern == NULL || pattern_length < -1 || pos < 0) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return false;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_resemblesPattern(pattern, pattern_length, pos);
}

int32_t i18n_uset_to_pattern ( const i18n_uset_h set, i18n_uchar *result, int32_t result_capacity, i18n_ubool escape_unprintable )
{
    if (set == NULL || result == NULL || result_capacity < 0) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    i18n_error_code_e i18n_error;

    int32_t result_uset_toPattern = uset_toPattern((const USet*)set, result, result_capacity, escape_unprintable, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return result_uset_toPattern;
}

int i18n_uset_add ( i18n_uset_h set, i18n_uchar32 character )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_add ((USet*)set, character);
    return I18N_ERROR_NONE;
}

int i18n_uset_add_all ( i18n_uset_h set, const i18n_uset_h additional_set )
{
    if (set == NULL || additional_set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_addAll((USet *)set, (const USet*)additional_set);
    return I18N_ERROR_NONE;
}

int i18n_uset_add_range ( i18n_uset_h set, i18n_uchar32 start, i18n_uchar32 end )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_addRange((USet*)set, start, end);
    return I18N_ERROR_NONE;
}

int i18n_uset_add_string ( i18n_uset_h set, const i18n_uchar *str, int32_t str_len )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    if (str == NULL || str_len < -1) {
       return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_addString((USet*)set, str, str_len);
    return I18N_ERROR_NONE;
}

int i18n_uset_add_all_code_points ( i18n_uset_h set, const i18n_uchar *str, int32_t str_len )
{
    if(set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    if (str == NULL || str_len < -1) {
       return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_addAllCodePoints((USet*)set, str, str_len);
    return I18N_ERROR_NONE;
}

int i18n_uset_remove ( i18n_uset_h set, i18n_uchar32 character )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_remove ((USet*)set, character);
    return I18N_ERROR_NONE;
}

int i18n_uset_remove_range ( i18n_uset_h set, i18n_uchar32 start, i18n_uchar32 end )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_removeRange ((USet*)set, start, end);
    return I18N_ERROR_NONE;
}

int i18n_uset_remove_string ( i18n_uset_h set, const i18n_uchar *str, int32_t str_len )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    if (str == NULL || str_len < -1) {
       return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_removeString((USet*)set, str, str_len);
    return I18N_ERROR_NONE;
}

int i18n_uset_remove_all ( i18n_uset_h set, const i18n_uset_h remove_set )
{
    if (set == NULL || remove_set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_removeAll((USet*)set, (const USet*)remove_set);
    return I18N_ERROR_NONE;
}

int i18n_uset_retain ( i18n_uset_h set, i18n_uchar32 start, i18n_uchar32 end )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
     uset_retain((USet*)set, start, end);
     return I18N_ERROR_NONE;
}

int i18n_uset_retain_all ( i18n_uset_h set, const i18n_uset_h retain )
{
    if (set == NULL || retain == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_retainAll ((USet*)set, (const USet*)retain);
    return I18N_ERROR_NONE;
}

int i18n_uset_compact ( i18n_uset_h set )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_compact((USet*)set);
    return I18N_ERROR_NONE;
}

int i18n_uset_complement ( i18n_uset_h set )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_complement((USet*)set);
    return I18N_ERROR_NONE;
}

int i18n_uset_complement_all ( i18n_uset_h set, const i18n_uset_h complement )
{
    if (set == NULL || set == complement || complement == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_complementAll((USet*)set, (const USet*)complement);
    return I18N_ERROR_NONE;
}

int i18n_uset_clear ( i18n_uset_h set )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_clear((USet*)set);
    return I18N_ERROR_NONE;
}

int i18n_uset_destroy_over ( i18n_uset_h set, int32_t attributes )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_closeOver((USet*)set, attributes);
    return I18N_ERROR_NONE;
}

int i18n_uset_remove_all_strings ( i18n_uset_h set )
{
    if (set == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_removeAllStrings((USet*)set);
    return I18N_ERROR_NONE;
}

i18n_ubool i18n_uset_is_empty ( const i18n_uset_h set )
{
    if (set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return false;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_isEmpty((const USet*)set);
}

i18n_ubool i18n_uset_contains ( const i18n_uset_h set, i18n_uchar32 character )
{
    if (set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return false;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_contains((const USet*)set, character);
}

i18n_ubool i18n_uset_contains_range ( const i18n_uset_h set, i18n_uchar32 start, i18n_uchar32 end )
{
    if (set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return false;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_containsRange((const USet*)set, start, end);
}

i18n_ubool i18n_uset_contains_string ( const i18n_uset_h set, const i18n_uchar *str, int32_t str_len )
{
    if (set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return false;
    }
    if (str == NULL || str_len < -1) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return false;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_containsString((const USet*)set, str, str_len);
}

int32_t i18n_uset_index_of ( const i18n_uset_h set, i18n_uchar32 character )
{
    if (set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_indexOf((const USet*)set, character);
}

i18n_uchar32 i18n_uset_char_at ( const i18n_uset_h set, int32_t char_index )
{
    if (set == NULL || (char_index < 0 || char_index > uset_size((const USet*)set)-1)) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0x0;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_charAt((const USet*)set, char_index);
}

int32_t i18n_uset_size ( const i18n_uset_h set )
{
    if (set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_size((const USet*)set);
}

int32_t i18n_uset_get_item_count ( const i18n_uset_h set )
{
    if (set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_getItemCount((const USet*)set);
}

int32_t i18n_uset_get_item ( const i18n_uset_h set, int32_t item_index, i18n_uchar32 *start, i18n_uchar32 *end,
        i18n_uchar *str, int32_t str_capacity )
{
    if (set == NULL || (item_index < 0 || item_index > uset_getItemCount((const USet*)set)-1) || start == NULL || end == NULL) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }
    if ((str == NULL && str_capacity != 0) || (str != NULL && str_capacity < 0)) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    i18n_error_code_e i18n_error;

    int32_t result_uset_getItem = uset_getItem((const USet*)set, item_index, start, end, str, str_capacity, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return result_uset_getItem;
}

i18n_ubool i18n_uset_contains_all ( const i18n_uset_h set1, const i18n_uset_h set2 )
{
    if (set1 == NULL || set2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return false;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_containsAll((const USet*)set1, (const USet*)set2);
}

i18n_ubool i18n_uset_contains_all_code_points ( const i18n_uset_h set, const i18n_uchar *str, int32_t str_len )
{
    if (set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return false;
    }
    if (str == NULL || str_len < -1) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return false;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_containsAllCodePoints((const USet*)set, str, str_len);
}

i18n_ubool i18n_uset_contains_none ( const i18n_uset_h set1, const i18n_uset_h set2 )
{
    if (set1 == NULL || set2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return false;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_containsNone((const USet*)set1, (const USet*)set2);
}

i18n_ubool i18n_uset_contains_some ( const i18n_uset_h set1, const i18n_uset_h set2 )
{
    if (set1 == NULL || set2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return false;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_containsSome((const USet*)set1, (const USet*)set2);
}

int32_t i18n_uset_span ( const i18n_uset_h set, const i18n_uchar *str, int32_t length, i18n_uset_span_condition_e span_condition )
{
    if (set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    if (str == NULL || length < -1) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_span((const USet*)set, str, length, (USetSpanCondition) span_condition);
}

int32_t i18n_uset_span_back ( const i18n_uset_h set, const i18n_uchar *str, int32_t length, i18n_uset_span_condition_e span_condition )
{
    if (set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    if (str == NULL || length < -1) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }
    if (span_condition < I18N_USET_SPAN_NOT_CONTAINED ||
        span_condition > I18N_USET_SPAN_CONDITION_COUNT) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_spanBack((const USet*)set, str, length, (USetSpanCondition) span_condition);
}

int32_t i18n_uset_span_utf8 ( const i18n_uset_h set, const char *str, int32_t length, i18n_uset_span_condition_e span_condition )
{
    if (set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    if (str == NULL || length < -1) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }
    if (span_condition < I18N_USET_SPAN_NOT_CONTAINED ||
        span_condition > I18N_USET_SPAN_CONDITION_COUNT) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_spanUTF8((const USet*)set, str, length, (USetSpanCondition) span_condition);
}

int32_t i18n_uset_span_back_utf8 ( const i18n_uset_h set, const char *str, int32_t length, i18n_uset_span_condition_e span_condition )
{
    if(set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    if (str == NULL || length < -1) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }
    if (span_condition < I18N_USET_SPAN_NOT_CONTAINED ||
        span_condition > I18N_USET_SPAN_CONDITION_COUNT) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_spanBackUTF8((const USet*)set, str, length, (USetSpanCondition) span_condition);
}

i18n_ubool i18n_uset_equals ( const i18n_uset_h set1, const i18n_uset_h set2 )
{
    if (set1 == NULL || set2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return false;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_equals((const USet*)set1, (const USet*)set2);
}

int32_t i18n_uset_serialize ( const i18n_uset_h set, uint16_t *dest, int32_t dest_capacity )
{
    i18n_error_code_e i18n_error;

    if (set == NULL) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }
    if (dest == NULL || dest_capacity < 0) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_uset_serialize =  uset_serialize((const USet*)set, dest, dest_capacity, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return result_uset_serialize;
}

i18n_ubool i18n_uset_get_serialized_set ( const uint16_t *src, int32_t src_length, i18n_userialized_set_s *fill_set )
{
    if (src == NULL || src_length < 0 || fill_set == NULL) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_getSerializedSet((USerializedSet*)fill_set, src, src_length);
}

int i18n_uset_set_serialized_to_one ( i18n_uchar32 character, i18n_userialized_set_s *fill_set )
{
    if (fill_set == NULL) {
       return I18N_ERROR_INVALID_PARAMETER;
    }
    uset_setSerializedToOne((USerializedSet*)fill_set, character);
    return I18N_ERROR_NONE;
}

i18n_ubool i18n_uset_serialized_contains ( const i18n_userialized_set_s *set, i18n_uchar32 character )
{
    if (set == NULL) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_serializedContains((const USerializedSet*)set, character);
}

int32_t i18n_uset_get_serialized_range_count ( const i18n_userialized_set_s *set )
{
    if (set == NULL) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return 0;
    }
    set_last_result(I18N_ERROR_NONE);
    return uset_getSerializedRangeCount((const USerializedSet*)set);
}

i18n_ubool i18n_uset_get_serialized_range ( const i18n_userialized_set_s *set, int32_t range_index, i18n_uchar32 *p_start, i18n_uchar32 *p_end )
{
    if (set == NULL) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return false;
    }
    if (range_index < 0 || range_index > uset_getSerializedRangeCount((const USerializedSet*)set)-1) {
       set_last_result(I18N_ERROR_INVALID_PARAMETER);
       return false;
    }
    set_last_result(I18N_ERROR_NONE);
    return  uset_getSerializedRange((const USerializedSet*)set, range_index, p_start, p_end);
}
