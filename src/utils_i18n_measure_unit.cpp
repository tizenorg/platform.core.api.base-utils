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
#include <utils_i18n_measure_unit.h>
#include <utils_i18n_private.h>
#include <utils_i18n_ustring.h>

#include <unicode/ustdio.h>
#include <unicode/measfmt.h>
#include <unicode/measunit.h>
#include <unicode/format.h>
#include <unicode/fmtable.h>
#include <unicode/locid.h>
#include <unicode/uchar.h>

int i18n_measure_unit_create(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);

    *measure_unit = new MeasureUnit();
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_measure_unit_create_from_other(i18n_measure_unit_h *measure_unit, const i18n_measure_unit_h other)
{
    retv_if(measure_unit == NULL || other == NULL, I18N_ERROR_INVALID_PARAMETER);

    MeasureUnit other_copy = *((MeasureUnit *) other);
    *measure_unit = &other_copy;
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_measure_unit_clone(i18n_measure_unit_h measure_unit, i18n_measure_unit_h *clone)
{
    retv_if(measure_unit == NULL || clone == NULL, I18N_ERROR_INVALID_PARAMETER);

    *clone = ((MeasureUnit *) measure_unit)->clone();
    retv_if(*clone == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_measure_unit_destroy(i18n_measure_unit_h measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);

    delete((MeasureUnit *) measure_unit);
    measure_unit = NULL;

    return I18N_ERROR_NONE;
}

int i18n_measure_unit_get_type(i18n_measure_unit_h measure_unit, const char **type)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(type == NULL, I18N_ERROR_INVALID_PARAMETER);
    *type = ((MeasureUnit *) measure_unit)->getType();
    retv_if(*type == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_measure_unit_get_subtype(i18n_measure_unit_h measure_unit, const char **subtype)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(subtype == NULL, I18N_ERROR_INVALID_PARAMETER);
    *subtype = ((MeasureUnit *) measure_unit)->getType();
    retv_if(*subtype == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_measure_unit_get_available(int32_t *available, i18n_measure_unit_h **dest_array, int32_t dest_capacity)
{
    retv_if(available == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(dest_array == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(dest_capacity < 0, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    MeasureUnit *mu_array = (MeasureUnit *) malloc(dest_capacity * sizeof(MeasureUnit));
    *available = MeasureUnit::getAvailable(mu_array, dest_capacity, status);
    retv_if(available == NULL, I18N_ERROR_OUT_OF_MEMORY);

    *dest_array = new i18n_measure_unit_h[dest_capacity];
    for (int i = 0; i < dest_capacity; ++i) {
        (*dest_array)[i] = (const i18n_measure_unit_h) &mu_array[i];
    }

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_get_available_with_type(int32_t *available, const char *type, i18n_measure_unit_h **dest_array, int32_t dest_capacity)
{
    retv_if(available == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(type == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(dest_array == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(dest_capacity < 0, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    MeasureUnit *mu_array = (MeasureUnit *) malloc(dest_capacity * sizeof(MeasureUnit));
    *available = MeasureUnit::getAvailable(type, mu_array, dest_capacity, status);
    retv_if(available == NULL, I18N_ERROR_OUT_OF_MEMORY);

    *dest_array = new i18n_measure_unit_h[dest_capacity];
    for (int i = 0; i < dest_capacity; ++i) {
        (*dest_array)[i] = (const i18n_measure_unit_h) &mu_array[i];
    }

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_get_available_types(i18n_measure_unit_types_cb cb, void* user_data)
{
    retv_if(cb == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    StringEnumeration *available = MeasureUnit::getAvailableTypes(status);

    UErrorCode err = U_ZERO_ERROR;
    int32_t count = available->count(err);
    for (int i = 0; i < count; i++) {
        int32_t resultLength = 0;
        if (cb(available->next(&resultLength, err), user_data) == false ) {
            break;
        }
    }

    delete available;
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_g_force(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createGForce(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_meter_per_second_squared(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMeterPerSecondSquared(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_arc_minute(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createArcMinute(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_arc_second(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createArcSecond(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_degree(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createDegree(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_radian(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createRadian(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_acre(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createAcre(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_hectare(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createHectare(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_square_centimeter(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createSquareCentimeter(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_square_foot(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createSquareFoot(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_square_inch(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createSquareInch(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_square_kilometer(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createSquareKilometer(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_square_meter(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createSquareMeter(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_square_mile(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createSquareMile(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_square_yard(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createSquareYard(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_liter_per_kilometer(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createLiterPerKilometer(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_mile_per_gallon(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMilePerGallon(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_bit(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createBit(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_byte(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createByte(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_gigabit(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createGigabit(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_gigabyte(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createGigabyte(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilobit(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createKilobit(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilobyte(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createKilobyte(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_megabit(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMegabit(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_megabyte(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMegabyte(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_terabit(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createTerabit(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_terabyte(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createTerabyte(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_day(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createDay(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_hour(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createHour(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_microsecond(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMicrosecond(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_millisecond(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMillisecond(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_minute(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMinute(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_month(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMonth(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_nanosecond(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createNanosecond(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_second(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createSecond(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_week(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createWeek(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_year(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createYear(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_ampere(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createAmpere(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_milliampere(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMilliampere(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_ohm(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createOhm(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_volt(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createVolt(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_calorie(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createCalorie(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_foodcalorie(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createFoodcalorie(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_joule(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createJoule(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilocalorie(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createKilocalorie(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilojoule(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createKilojoule(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilowatt_hour(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createKilowattHour(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_gigahertz(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createGigahertz(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_hertz(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createHertz(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilohertz(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createKilohertz(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_megahertz(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMegahertz(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_astronomical_unit(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createAstronomicalUnit(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_centimeter(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createCentimeter(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_decimeter(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createDecimeter(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_fathom(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createFathom(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_foot(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createFoot(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_furlong(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createFurlong(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_inch(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createInch(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilometer(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createKilometer(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_light_year(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createLightYear(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_meter(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMeter(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_micrometer(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMicrometer(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_mile(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMile(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_millimeter(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMillimeter(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_nanometer(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createNanometer(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_nautical_mile(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createNauticalMile(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_parsec(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createParsec(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_picometer(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createPicometer(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_yard(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createYard(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_lux(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createLux(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_carat(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createCarat(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_gram(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createGram(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilogram(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createKilogram(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_metric_ton(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMetricTon(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_microgram(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMicrogram(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_milligram(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMilligram(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_ounce(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createOunce(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_ounce_troy(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createOunceTroy(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_pound(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createPound(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_stone(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createStone(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_ton(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createTon(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_gigawatt(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createGigawatt(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_horsepower(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createHorsepower(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilowatt(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createKilowatt(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_megawatt(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMegawatt(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_milliwatt(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMilliwatt(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_watt(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createWatt(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_hectopascal(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createHectopascal(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_inch_hg(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createInchHg(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_millibar(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMillibar(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_millimeter_of_mercury(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMillimeterOfMercury(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_pound_per_square_inch(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createPoundPerSquareInch(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_karat(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createKarat(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilometer_per_hour(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createKilometerPerHour(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_meter_per_second(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMeterPerSecond(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_mile_per_hour(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMilePerHour(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_celsius(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createCelsius(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_fahrenheit(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createFahrenheit(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kelvin(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createKelvin(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_acre_foot(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createAcreFoot(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_bushel(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createBushel(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_centiliter(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createCentiliter(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cubic_centimeter(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createCentimeter(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cubic_foot(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createCubicFoot(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cubic_inch(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createCubicInch(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cubic_kilometer(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createCubicKilometer(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cubic_meter(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createCubicMeter(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cubic_mile(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createCubicMile(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cubic_yard(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createCubicYard(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cup(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createCup(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_deciliter(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createDeciliter(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_fluid_ounce(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createFluidOunce(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_gallon(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createGallon(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_hectoliter(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createHectoliter(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_liter(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createLiter(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_megaliter(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMegaliter(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_milliliter(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createMilliliter(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_pint(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createPint(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_quart(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createQuart(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_tablespoon(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createTablespoon(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_teaspoon(i18n_measure_unit_h *measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_unit = MeasureUnit::createTeaspoon(status);
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

