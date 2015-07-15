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

#include <unicode/udatpg.h>
#include <utils_i18n_udatepg.h>
#include <utils_i18n_private.h>

int i18n_udatepg_create ( const char *locale, i18n_udatepg_h *dtpg )
{
    retv_if(dtpg == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode icu_error = U_ZERO_ERROR;
    *dtpg = udatpg_open(locale, &icu_error);

    return _i18n_error_mapping(icu_error);
}

int i18n_udatepg_destroy ( i18n_udatepg_h dtpg )
{
    retv_if(dtpg == NULL, I18N_ERROR_INVALID_PARAMETER);

    udatpg_close(dtpg);

    return I18N_ERROR_NONE;
}

int i18n_udatepg_get_best_pattern ( i18n_udatepg_h dtpg, const i18n_uchar *skeleton, int32_t len, i18n_uchar *best_pattern, int32_t capacity, int32_t *best_pattern_len )
{
    retv_if(dtpg == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(skeleton == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(len < 0, I18N_ERROR_INVALID_PARAMETER);
    retv_if(capacity < 0, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode icu_error = U_ZERO_ERROR;
    *best_pattern_len = udatpg_getBestPattern(dtpg, skeleton, len, best_pattern, capacity, &icu_error);

    return _i18n_error_mapping(icu_error);
}

// Newly Added APIs

int i18n_udatepg_create_empty (i18n_udatepg_h *dtpg)
{
    if (dtpg == NULL)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    UErrorCode icu_error = U_ZERO_ERROR;
    *dtpg = (i18n_udatepg_h)udatpg_openEmpty(&icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    return i18n_error;
}

int i18n_udatepg_clone ( const i18n_udatepg_h dtpg, i18n_udatepg_h *dtpg_clone )
{
    if (dtpg == NULL || NULL == dtpg_clone)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    *dtpg_clone = (i18n_udatepg_h)udatpg_clone((UDateTimePatternGenerator *)dtpg, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    return i18n_error;
}

int32_t i18n_udatepg_get_best_pattern_with_options ( i18n_udatepg_h dtpg, const i18n_uchar *skeleton, int32_t length,
        i18n_udatepg_date_time_pattern_match_options_e options, i18n_uchar *best_pattern, int32_t capacity )
{
    if (dtpg == NULL || skeleton == NULL || length < 0 || capacity < 0)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t length_of_best_pattern = udatpg_getBestPatternWithOptions((UDateTimePatternGenerator *)dtpg, skeleton, length, options, best_pattern, capacity, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    set_last_result(i18n_error);
    return length_of_best_pattern;
}

int32_t i18n_udatepg_get_skeleton ( i18n_udatepg_h dtpg, const i18n_uchar *pattern, int32_t length,
        i18n_uchar *skeleton, int32_t capacity )
{
    if (dtpg == NULL || pattern == NULL || length < 0 || capacity < 0)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t length_of_skeleton = udatpg_getSkeleton((UDateTimePatternGenerator *)dtpg, pattern, length, skeleton, capacity, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    set_last_result(i18n_error);
    return length_of_skeleton;
}

int32_t i18n_udatepg_get_base_skeleton ( i18n_udatepg_h dtpg, const i18n_uchar *pattern, int32_t length,
        i18n_uchar *base_skeleton, int32_t capacity )
{
    if (dtpg == NULL || pattern == NULL || capacity < 0)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t length_of_skeleton = udatpg_getBaseSkeleton((UDateTimePatternGenerator *)dtpg, pattern, length, base_skeleton, capacity, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    set_last_result(i18n_error);
    return length_of_skeleton;
}

int32_t i18n_udatepg_add_pattern ( i18n_udatepg_h dtpg, const i18n_uchar *pattern, int32_t pattern_length,
        i18n_ubool override, i18n_uchar *conflicting_pattern, int32_t capacity, i18n_udatepg_date_time_pattern_conflict_e *conflict_status )
{
    if (dtpg == NULL || pattern == NULL || pattern_length < 0 || capacity < 0)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return -1;
    }
    int32_t confliction_pattern_length;
    UErrorCode icu_error = U_ZERO_ERROR;
    *conflict_status = udatpg_addPattern((UDateTimePatternGenerator *)dtpg, pattern, pattern_length, override, conflicting_pattern, capacity, &confliction_pattern_length, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    set_last_result(i18n_error);
    return confliction_pattern_length;
}

int i18n_udatepg_set_append_item_format ( i18n_udatepg_h dtpg, i18n_udatepg_date_time_pattern_field_e field,
        const i18n_uchar *value, int32_t length )
{
    if (dtpg == NULL || field < I18N_UDATEPG_ERA_FIELD || field >= I18N_UDATEPG_FIELD_COUNT
        || value == NULL || length < 0)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    udatpg_setAppendItemFormat((UDateTimePatternGenerator *)dtpg, field, value, length);
    return I18N_ERROR_NONE;
}

const i18n_uchar *i18n_udatepg_get_append_item_format ( const i18n_udatepg_h dtpg, i18n_udatepg_date_time_pattern_field_e field,
        int32_t *pattern_length )
{
    if (dtpg == NULL || field < I18N_UDATEPG_ERA_FIELD || field >= I18N_UDATEPG_FIELD_COUNT)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }

    set_last_result(I18N_ERROR_NONE);
    return udatpg_getAppendItemFormat((UDateTimePatternGenerator *)dtpg, field, pattern_length);
}

int i18n_udatepg_set_append_item_name ( i18n_udatepg_h dtpg, i18n_udatepg_date_time_pattern_field_e field,
        const i18n_uchar *value, int32_t length )
{
    if (dtpg == NULL || field < I18N_UDATEPG_ERA_FIELD || field >= I18N_UDATEPG_FIELD_COUNT
        || value == NULL || length < 0)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    udatpg_setAppendItemName((UDateTimePatternGenerator *)dtpg, field, value, length);
    return I18N_ERROR_NONE;
}

const i18n_uchar *i18n_udatepg_get_append_item_name ( const i18n_udatepg_h dtpg,
        i18n_udatepg_date_time_pattern_field_e field, int32_t *pattern_length )
{
    if (dtpg == NULL || field < I18N_UDATEPG_ERA_FIELD || field >= I18N_UDATEPG_FIELD_COUNT)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }

    set_last_result(I18N_ERROR_NONE);
    return udatpg_getAppendItemName((UDateTimePatternGenerator *)dtpg, field, pattern_length);
}

int i18n_udatepg_set_date_time_format ( const i18n_udatepg_h dtpg, const i18n_uchar *date_time_format, int32_t length )
{
    if (dtpg == NULL || date_time_format == NULL || length < 0)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    udatpg_setDateTimeFormat((UDateTimePatternGenerator *)dtpg, date_time_format, length);
    return I18N_ERROR_NONE;
}

const i18n_uchar *i18n_udatepg_get_date_time_format ( const i18n_udatepg_h dtpg, int32_t *pattern_length )
{
    if (dtpg == NULL)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }

    set_last_result(I18N_ERROR_NONE);
    return udatpg_getDateTimeFormat((UDateTimePatternGenerator *)dtpg, pattern_length);
}

int i18n_udatepg_set_decimal ( i18n_udatepg_h dtpg, const i18n_uchar *decimal, int32_t length )
{
    if (dtpg == NULL || decimal == NULL || length < 0)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    udatpg_setDecimal((UDateTimePatternGenerator *)dtpg, decimal, length);
    return I18N_ERROR_NONE;
}

const i18n_uchar *i18n_udatepg_get_decimal ( const i18n_udatepg_h dtpg, int32_t *pattern_length )
{
    if (dtpg == NULL)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }

    set_last_result(I18N_ERROR_NONE);
    return udatpg_getDecimal((UDateTimePatternGenerator *)dtpg, pattern_length);
}

int32_t i18n_udatepg_replace_field_types ( i18n_udatepg_h dtpg, const i18n_uchar *pattern, int32_t pattern_length,
        const i18n_uchar *skeleton, int32_t skeleton_length, i18n_uchar *dest,
        int32_t dest_capacity )
{
    if (dtpg == NULL || pattern == NULL || pattern_length < 0 || skeleton == NULL
        || skeleton_length < 0 || dest_capacity < 0)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t length_of_dest = udatpg_replaceFieldTypes((UDateTimePatternGenerator *)dtpg, pattern, pattern_length, skeleton, skeleton_length, dest, dest_capacity, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    set_last_result(i18n_error);
    return length_of_dest;
}

int32_t i18n_udatepg_replace_field_types_with_options ( i18n_udatepg_h dtpg, const i18n_uchar *pattern, int32_t pattern_length,
        const i18n_uchar *skeleton, int32_t skeleton_length, i18n_udatepg_date_time_pattern_match_options_e options,
        i18n_uchar *dest, int32_t dest_capacity )
{
    if (dtpg == NULL || pattern == NULL || pattern_length < 0 || skeleton == NULL
        || skeleton_length < 0 || dest_capacity < 0)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t length_of_dest = udatpg_replaceFieldTypesWithOptions((UDateTimePatternGenerator *)dtpg, pattern, pattern_length, skeleton, skeleton_length, options, dest, dest_capacity, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    set_last_result(i18n_error);
    return length_of_dest;
}

int i18n_udatepg_skeletons_create ( const i18n_udatepg_h dtpg, i18n_uenumeration_h *enumeration )
{
    if (dtpg == NULL || NULL == enumeration)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    *enumeration = udatpg_openSkeletons((const UDateTimePatternGenerator *)dtpg, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    return i18n_error;
}

int i18n_udatepg_base_skeletons_create ( const i18n_udatepg_h dtpg, i18n_uenumeration_h *enumeration )
{
    if (dtpg == NULL || NULL == enumeration)
    {
        return I18N_ERROR_INVALID_PARAMETER;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    *enumeration = udatpg_openBaseSkeletons((const UDateTimePatternGenerator *)dtpg, &icu_error);
    ERR("Error code : %d", icu_error);

    i18n_error_code_e i18n_error;
    ERR_MAPPING(icu_error, i18n_error);
    return i18n_error;
}

const i18n_uchar *i18n_udatepg_get_pattern_for_skeleton ( const i18n_udatepg_h dtpg, const i18n_uchar *skeleton,
        int32_t skeleton_length, int32_t *pattern_length )
{
    if (dtpg == NULL || skeleton == NULL || skeleton_length < 0)
    {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }

    set_last_result(I18N_ERROR_NONE);
    return udatpg_getPatternForSkeleton((const UDateTimePatternGenerator *)dtpg, skeleton, skeleton_length, pattern_length);
}
