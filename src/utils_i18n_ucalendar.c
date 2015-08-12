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

#include <unicode/ucal.h>
#include <utils_i18n_ucalendar.h>
#include <utils_i18n_private.h>

int i18n_ucalendar_create ( const i18n_uchar *zone_id, int32_t len, const char *locale, i18n_ucalendar_type_e type, i18n_ucalendar_h *calendar )
{
    retv_if(calendar == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    *calendar = ucal_open(zone_id, len, locale, type, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ucalendar_destroy ( i18n_ucalendar_h calendar )
{
    retv_if(calendar == NULL, I18N_ERROR_INVALID_PARAMETER);

    ucal_close(calendar);
    return I18N_ERROR_NONE;
}

int i18n_ucalendar_clone ( const i18n_ucalendar_h cal, i18n_ucalendar_h *identical_to_cal )
{
    retv_if(cal == NULL || identical_to_cal == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    *identical_to_cal =  ucal_clone(cal, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ucalendar_add ( i18n_ucalendar_h calendar, i18n_ucalendar_date_fields_e field, int32_t amount )
{
    retv_if(calendar == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    ucal_add(calendar, field, amount, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ucalendar_is_equivalent_to ( const i18n_ucalendar_h calendar1, const i18n_ucalendar_h calendar2, i18n_ubool *equiv )
{
    retv_if(equiv == NULL || calendar1 == NULL || calendar2 == NULL, I18N_ERROR_INVALID_PARAMETER);

    *equiv = ucal_equivalentTo(calendar1, calendar2);
    return I18N_ERROR_NONE;
}

int i18n_ucalendar_get_milliseconds ( const i18n_ucalendar_h calendar, i18n_udate *date )
{
    retv_if(calendar == NULL || date == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    *date = ucal_getMillis(calendar, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ucalendar_get ( const i18n_ucalendar_h calendar, i18n_ucalendar_date_fields_e field, int32_t *val )
{
    retv_if(calendar == NULL || val == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    *val = ucal_get(calendar, field, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ucalendar_get_attribute ( i18n_ucalendar_h calendar, i18n_ucalendar_attribute_e attr, int32_t *val)
{
    retv_if(calendar == NULL || val == NULL, I18N_ERROR_INVALID_PARAMETER);

    *val = ucal_getAttribute(calendar, attr);
    return I18N_ERROR_NONE;
}

int i18n_ucalendar_get_timezone_displayname ( const i18n_ucalendar_h calendar, i18n_ucalendar_displayname_type_e type, const char *locale,
    i18n_uchar *result, int32_t result_len, int32_t *buf_size_needed )
{
    retv_if(calendar == NULL || result == NULL || buf_size_needed == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    *buf_size_needed = ucal_getTimeZoneDisplayName(calendar, type, locale, result, result_len, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    
    return i18n_error;
}

int i18n_ucalendar_is_in_daylight_time ( const i18n_ucalendar_h calendar, i18n_ubool *is_in )
{
    retv_if(calendar == NULL || is_in == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    *is_in = ucal_inDaylightTime(calendar, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ucalendar_set ( i18n_ucalendar_h cal, i18n_ucalendar_date_fields_e field, int32_t val )
{
    retv_if(cal == NULL, I18N_ERROR_INVALID_PARAMETER);

    ucal_set(cal, field, val);
    return I18N_ERROR_NONE;
}

int i18n_ucalendar_set_attribute ( i18n_ucalendar_h calendar, i18n_ucalendar_attribute_e attr, int32_t val )
{
    retv_if(calendar == NULL, I18N_ERROR_INVALID_PARAMETER);

    ucal_setAttribute(calendar, attr, val);
    return I18N_ERROR_NONE;
}

int i18n_ucalendar_set_date_time ( i18n_ucalendar_h calendar, int32_t year, int32_t month, int32_t date, int32_t hour, int32_t min, int32_t sec )
{
    retv_if(calendar == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    ucal_setDateTime(calendar, year, month, date, hour, min, sec, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ucalendar_set_milliseconds ( i18n_ucalendar_h calendar, i18n_udate milliseconds )
{
    retv_if(calendar == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    ucal_setMillis(calendar, milliseconds, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ucalendar_set_default_timezone ( const i18n_uchar *zone_id )
{
    retv_if(zone_id == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    ucal_setDefaultTimeZone(zone_id, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int32_t i18n_ucalendar_get_field_difference ( i18n_ucalendar_h calendar, i18n_udate target, i18n_ucalendar_date_fields_e field, i18n_error_code_e *status )
{
    if(calendar == NULL)
    {
        if(NULL != status) {
            *status = I18N_ERROR_INVALID_PARAMETER;
        }
        return 0;
    }

    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result = ucal_getFieldDifference(calendar, target, field, &icu_error);

    if(NULL != status) {
        ERR_MAPPING(icu_error, *status);
        I18N_ERR(*status);
    }

    return result;
}

int i18n_ucalendar_get_now ( i18n_udate *date )
{
    retv_if(date == NULL, I18N_ERROR_INVALID_PARAMETER);

    *date = ucal_getNow();
    return I18N_ERROR_NONE;
}

// Newly Added APIs
int i18n_ucalendar_timezone_id_enumeration_create ( i18n_system_timezone_type_e zone_type, const char *region, const int32_t *raw_offset, i18n_uenumeration_h *enumeration )
{
    if(region == NULL || enumeration == NULL){
        return I18N_ERROR_INVALID_PARAMETER;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    *enumeration = (i18n_uenumeration_h)ucal_openTimeZoneIDEnumeration (zone_type, region, raw_offset, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ucalendar_timezones_create (i18n_uenumeration_h *enumeration)
{
    if(enumeration == NULL){
        return I18N_ERROR_INVALID_PARAMETER;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    *enumeration = (i18n_uenumeration_h)ucal_openTimeZones(&icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ucalendar_country_timezones_create (const char *country, i18n_uenumeration_h *enumeration)
{
    if (country == NULL || enumeration == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    *enumeration = (i18n_uenumeration_h)ucal_openCountryTimeZones(country, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int32_t i18n_ucalendar_get_default_timezone (i18n_uchar *result, int32_t result_capacity)
{
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_ucal_getDefaultTimeZone = ucal_getDefaultTimeZone(result, result_capacity, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);
    set_last_result(i18n_error);
    return result_ucal_getDefaultTimeZone;
}

int i18n_ucalendar_set_timezone ( i18n_ucalendar_h calendar, const i18n_uchar *zone_id, int32_t length)
{
    if (calendar == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    ucal_setTimeZone(calendar, zone_id, length, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int32_t i18n_ucalendar_get_timezone_id (const  i18n_ucalendar_h calendar, i18n_uchar *result, int32_t result_length)
{
    if (calendar == NULL || result == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_ucal_getTimeZoneID = ucal_getTimeZoneID(calendar, result, result_length, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return result_ucal_getTimeZoneID;
}

int i18n_ucalendar_set_gregorian_change ( i18n_ucalendar_h calendar, i18n_udate date)
{
    if (calendar == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    ucal_setGregorianChange(calendar, date, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;

}

int i18n_ucalendar_get_gregorian_change ( const  i18n_ucalendar_h calendar, i18n_udate *date)
{
    if (calendar == NULL || date == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    *date = ucal_getGregorianChange(calendar, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

const char * i18n_ucalendar_get_available ( int32_t locale_index )
{
    if (locale_index < 0) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }

    set_last_result(I18N_ERROR_NONE);
    return ucal_getAvailable(locale_index);
}

int32_t i18n_ucalendar_count_available ( void )
{
    set_last_result(I18N_ERROR_NONE);
    return ucal_countAvailable();
}

int i18n_ucalendar_set_date ( i18n_ucalendar_h calendar, int32_t year, int32_t month, int32_t date)
{
    if (calendar == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    ucal_setDate(calendar, year, month, date, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ucalendar_roll ( i18n_ucalendar_h calendar, i18n_ucalendar_date_fields_e field, int32_t amount)
{
    if (calendar == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    ucal_roll(calendar, field, amount, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

i18n_ubool i18n_ucalendar_is_set ( const i18n_ucalendar_h calendar, i18n_ucalendar_date_fields_e field )
{
    if (calendar == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return false;
    }

    set_last_result(I18N_ERROR_NONE);
    return ucal_isSet (calendar, field);
}
int i18n_ucalendar_clear_field ( i18n_ucalendar_h calendar, i18n_ucalendar_date_fields_e field )
{
    if (calendar == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    ucal_clearField (calendar, field);
    return I18N_ERROR_NONE;
}

int i18n_ucalendar_clear ( i18n_ucalendar_h calendar )
{
    if (calendar == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    ucal_clear(calendar);
    return I18N_ERROR_NONE;
}

int32_t i18n_ucalendar_get_limit ( const i18n_ucalendar_h calendar, i18n_ucalendar_date_fields_e field, i18n_ucalendar_limit_type_e type)
{
    if (calendar == NULL || field < I18N_UCALENDAR_ERA || field >= I18N_UCALENDAR_FIELD_COUNT) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

    i18n_error_code_e i18n_error = I18N_ERROR_NONE;
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_ucal_getLimit = ucal_getLimit(calendar, field, type, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);

    return result_ucal_getLimit;
}

const char *i18n_ucalendar_get_locale_by_type ( const i18n_ucalendar_h calendar, i18n_ulocale_data_locale_type_e type )
{
    if (calendar == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    const char *result_ucal_getLocaleByType = ucal_getLocaleByType(calendar, type, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return result_ucal_getLocaleByType;
}

const char *i18n_ucalendar_get_tz_data_version (void)
{
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    const char *result_ucal_getTZDataVersion = ucal_getTZDataVersion(&icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return result_ucal_getTZDataVersion;
}

int32_t i18n_ucalendar_get_canonical_timezone_id ( const i18n_uchar *id, int32_t length, i18n_uchar *result, int32_t result_capacity,  i18n_ubool *is_system_id )
{
    if (id == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_ucal_getCanonicalTimeZoneID = ucal_getCanonicalTimeZoneID(id, length, result, result_capacity, is_system_id, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return result_ucal_getCanonicalTimeZoneID ;
}

const char *i18n_ucalendar_get_type ( const i18n_ucalendar_h calendar )
{
    if (calendar == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    const char *result_ucal_getType = ucal_getType(calendar, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return result_ucal_getType;
}

int i18n_ucalendar_get_keyword_values_for_locale ( const char *key, const char *locale,  i18n_ubool commonly_used, i18n_uenumeration_h * enumeration )
{
    if (key == NULL || enumeration == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    *enumeration = (i18n_uenumeration_h )ucal_getKeywordValuesForLocale(key, locale, commonly_used, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int i18n_ucalendar_get_day_of_week_type ( const i18n_ucalendar_h calendar, i18n_ucalendar_days_of_week_e day_of_week, i18n_ucalendar_weekday_type_e *weekday_type )
{
    if (calendar == NULL || weekday_type == NULL) {
        return I18N_ERROR_INVALID_PARAMETER;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    *weekday_type = ucal_getDayOfWeekType(calendar, day_of_week, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    return i18n_error;
}

int32_t i18n_ucalendar_get_weekend_transition ( const i18n_ucalendar_h calendar, i18n_ucalendar_days_of_week_e day_of_week )
{
    if (calendar == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    int32_t result_ucal_getWeekendTransition = ucal_getWeekendTransition(calendar, day_of_week, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return result_ucal_getWeekendTransition;
}

i18n_ubool i18n_ucalendar_is_weekend ( i18n_ucalendar_h calendar, i18n_udate date )
{
    if (calendar == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    i18n_ubool result_ucal_isWeekend = ucal_isWeekend(calendar, date, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return result_ucal_isWeekend;
}

i18n_ubool i18n_ucalendar_get_timezone_transition_date ( const i18n_ucalendar_h calendar, i18n_utimezone_transition_type_e type, i18n_udate *transition)
{
    if (calendar == NULL || transition == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    i18n_error_code_e i18n_error;
    UErrorCode icu_error = U_ZERO_ERROR;
    i18n_ubool result_ucal_getTimeZoneTransitionDate = ucal_getTimeZoneTransitionDate(calendar, type, transition, &icu_error);
    ERR_MAPPING(icu_error, i18n_error);
    I18N_ERR(i18n_error);

    set_last_result(i18n_error);
    return result_ucal_getTimeZoneTransitionDate;
}
