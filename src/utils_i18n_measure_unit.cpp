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

// TODO czy wrapujemy konstruktory?
int i18n_measure_unit_create(i18n_measure_unit_h measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);

    const MeasureUnit *mu = MeasureUnit::MeasureUnit();
    retv_if(mu == NULL, I18N_ERROR_OUT_OF_MEMORY);

    *measure_unit = mu->clone();
    if(mu != NULL) {
        delete mu;
    }
    retv_if(measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

// TODO czy wrapujemy konstruktor kopiujący?
int i18n_measure_unit_create_form_other(i18n_measure_unit_h measure_unit, const i18n_measure_unit_h other)
{
    retv_if(other == NULL, I18N_ERROR_INVALID_PARAMETER);

    *measure_unit = MeasureUnit((MeasureUnit *) other);
    retv_if(measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_measure_unit_clone(i18n_measure_unit_h measure_unit, i18n_measure_unit_h *clone)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);

    *clone = ((MeasureFormat *) measure_unit)->clone();
    retv_if(clone == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_measure_unit_destroy(i18n_measure_unit_h measure_unit)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);

    delete((MeasureUnit *) measure_unit);

    return I18N_ERROR_NONE;
}

int i18n_measure_unit_get_type(i18n_measure_unit_h measure_unit, char **type)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    *type = ((MeasureUnit *) measure_unit)->getType();

    return I18N_ERROR_NONE;
}

int i18n_measure_unit_get_subtype(i18n_measure_unit_h measure_unit, char **subtype)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    *subtype = ((MeasureUnit *) measure_unit)->getType();

    return I18N_ERROR_NONE;
}

int i18n_measure_unit_get_available(int32_t *available, i18n_measure_unit_h *dest_array, int32_t dest_capacity)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *available = MeasureUnit::getAvailable((MeasureUnit *) dest_array, dest_capacity, status);

    return _i18n_error_mapping(status);
}

int i18n_measure_unit_get_available_with_type(int32_t *available, const char *type, i18n_measure_unit_h *dest_array, int32_t dest_capacity)
{
    retv_if(measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *available = MeasureUnit::getAvailable(type, (MeasureUnit *) dest_array, dest_capacity, status);

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

int i18n_measure_unit_create_g_force(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createGForce(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_meter_per_second_squared(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMeterPerSecondSquared(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_arc_minute(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createArcMinute(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_arc_second(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createArcSecond(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_degree(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createDegree(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_radian(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createRadian(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_revolution_angle(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createRevolutionAngle(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_acre(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createAcre(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_hectare(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createHectare(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_square_centimeter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createSquareCentimeter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_square_foot(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createSquareFoot(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_square_inch(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createSquareInch(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_square_kilometer(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createSquareKilometer(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_square_meter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createSquareMeter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_square_mile(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createSquareMile(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_square_yard(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createSquareYard(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_karat(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createKarat(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_milligram_per_deciliter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMilligramPerDeciliter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_millimole_per_liter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMillimolePerLiter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_part_per_million(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createPartPerMillion(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_liter_per_100_kilometers(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createLiterPer100Kilometers(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_liter_per_kilometer(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createLiterPerKilometer(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_mile_per_gallon(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMilePerGallon(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_mile_per_gallon_imperial(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMilePerGallonImperial(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_bit(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createBit(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_byte(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createByte(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_gigabit(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createGigabit(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_gigabyte(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createGigabyte(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilobit(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createKilobit(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilobyte(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createKilobyte(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_megabit(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMegabit(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_megabyte(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMegabyte(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_terabit(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createTerabit(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_terabyte(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createTerabyte(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_century(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCentury(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_day(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createDay(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_hour(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createHour(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_microsecond(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMicrosecond(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_millisecond(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMillisecond(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_minute(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMinute(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_month(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMonth(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_nanosecond(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createNanosecond(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_second(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createSecond(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_week(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createWeek(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_year(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createYear(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_ampere(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createAmpere(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_milliampere(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMilliampere(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_ohm(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createOhm(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_volt(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createVolt(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_calorie(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCalorie(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_foodcalorie(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createFoodcalorie(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_joule(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createJoule(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilocalorie(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createKilocalorie(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilojoule(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createKilojoule(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilowatt_hour(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createKilowattHour(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_gigahertz(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createGigahertz(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_hertz(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createHertz(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilohertz(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createKilohertz(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_megahertz(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMegahertz(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_astronomical_unit(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createAstronomicalUnit(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_centimeter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCentimeter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_decimeter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createDecimeter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_fathom(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createFathom(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_foot(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createFoot(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_furlong(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createFurlong(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_inch(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createInch(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilometer(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createKilometer(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_light_year(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createLightYear(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_meter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMeter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_micrometer(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMicrometer(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_mile(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMile(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_mile_scandinavian(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMileScandinavian(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_millimeter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMillimeter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_nanometer(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createNanometer(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_nautical_mile(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createNauticalMile(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_parsec(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createParsec(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_picometer(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createPicometer(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_yard(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createYard(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_lux(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createLux(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_carat(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCarat(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_gram(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createGram(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilogram(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createKilogram(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_metric_ton(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMetricTon(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_microgram(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMicrogram(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_milligram(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMilligram(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_ounce(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createOunce(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_ounce_troy(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createOunceTroy(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_pound(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createPound(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_stone(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createStone(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_ton(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createTon(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_gigawatt(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createGigawatt(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_horsepower(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createHorsepower(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilowatt(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createKilowatt(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_megawatt(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMegawatt(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_milliwatt(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMilliwatt(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_watt(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createWatt(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_hectopascal(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createHectopascal(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_inch_hg(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createInchHg(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_millibar(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMillibar(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_millimeter_of_mercury(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMillimeterOfMercury(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_pound_per_square_inch(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createPoundPerSquareInch(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kilometer_per_hour(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createKilometerePerHour(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_knot(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createKnot(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_meter_per_second(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMeterPerSecond(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_mile_per_hour(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMilePerHour(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_celsius(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCelsius(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_fahrenheit(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createFahrenheit(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_generic_temperature(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createGenericTemperature(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_kelvin(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createKelvin(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_acre_foot(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createAcreFoot(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_bushel(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createBushel(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_centiliter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCentiliter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cubic_centimeter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCentimeter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cubic_foot(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCubicFoot(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cubic_inch(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCubicInch(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cubic_kilometer(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCubicKilometer(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cubic_meter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCubicMeter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cubic_mile(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCubicMile(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cubic_yard(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCubicYard(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cup(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCup(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_cup_metric(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createCupMetric(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_deciliter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createDeciliter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_fluid_ounce(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createFluidOunce(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_gallon(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createGallon(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_gallon_imperial(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createGallonImperial(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_hectoliter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createHectoliter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_liter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createLiter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_megaliter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMegaliter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_milliliter(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createMilliliter(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_pint(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createPint(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_pint_metric(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createPintMetric(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_quart(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createQuart(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_tablespoon(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createTablespoon(status);
    return _i18n_error_mapping(status);
}

int i18n_measure_unit_create_teaspoon(i18n_measure_unit_h measure_unit)
{
    UErrorCode status = U_ZERO_ERROR;
    *measure_unit = MeasureUnit::createTeaspoon(status);
    return _i18n_error_mapping(status);
}

