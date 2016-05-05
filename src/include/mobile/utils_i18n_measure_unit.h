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

#ifndef __UTILS_I18N_MEASURE_H__
#define __UTILS_I18N_MEASURE_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_measure_unit.h
 * @version 0.1
 * @brief utils_i18n_measure_unit
 */

#ifdef __cplusplus
extern "C" {
#endif

int i18n_measure_unit_create(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_form_other(i18n_measure_unit_h measure_unit, const i18n_measure_unit_h other);
int i18n_measure_unit_clone(i18n_measure_unit_h measure_unit, i18n_measure_unit_h *clone);
int i18n_measure_unit_destroy(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_get_type(i18n_measure_unit_h measure_unit, char **type);
int i18n_measure_unit_get_subtype(i18n_measure_unit_h measure_unit, char **subtype);
int i18n_measure_unit_get_available(int32_t *available, i18n_measure_unit_h *dest_array, int32_t dest_capacity);
int i18n_measure_unit_get_available_with_type(int32_t *available, const char *type, i18n_measure_unit_h *dest_array, int32_t dest_capacity);
int i18n_measure_unit_get_available_types(i18n_measure_unit_types_cb cb, void* user_data);
int i18n_measure_unit_create_g_force(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_meter_per_second_squared(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_arc_minute(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_arc_second(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_degree(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_radian(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_revolution_angle(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_acre(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_hectare(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_square_centimeter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_square_foot(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_square_inch(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_square_kilometer(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_square_meter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_square_mile(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_square_yard(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_karat(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_milligram_per_deciliter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_millimole_per_liter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_part_per_million(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_liter_per_100_kilometers(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_liter_per_kilometer(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_mile_per_gallon(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_mile_per_gallon_imperial(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_bit(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_byte(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_gigabit(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_gigabyte(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_kilobit(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_kilobyte(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_megabit(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_megabyte(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_terabit(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_terabyte(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_century(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_day(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_hour(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_microsecond(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_millisecond(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_minute(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_month(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_nanosecond(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_second(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_week(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_year(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_ampere(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_milliampere(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_ohm(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_volt(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_calorie(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_foodcalorie(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_joule(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_kilocalorie(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_kilojoule(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_kilowatt_hour(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_gigahertz(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_hertz(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_kilohertz(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_megahertz(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_astronomical_unit(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_centimeter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_decimeter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_fathom(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_foot(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_furlong(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_inch(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_kilometer(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_light_year(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_meter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_micrometer(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_mile(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_mile_scandinavian(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_millimeter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_nanometer(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_nautical_mile(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_parsec(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_picometer(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_yard(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_lux(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_carat(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_gram(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_kilogram(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_metric_ton(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_microgram(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_milligram(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_ounce(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_ounce_troy(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_pound(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_stone(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_ton(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_gigawatt(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_horsepower(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_kilowatt(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_megawatt(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_milliwatt(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_watt(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_hectopascal(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_inch_hg(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_millibar(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_millimeter_of_mercury(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_pound_per_square_inch(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_kilometer_per_hour(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_knot(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_meter_per_second(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_mile_per_hour(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_celsius(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_fahrenheit(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_generic_temperature(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_kelvin(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_acre_foot(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_bushel(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_centiliter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_cubic_centimeter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_cubic_foot(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_cubic_inch(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_cubic_kilometer(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_cubic_meter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_cubic_mile(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_cubic_yard(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_cup(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_cup_metric(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_deciliter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_fluid_ounce(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_gallon(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_gallon_imperial(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_hectoliter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_liter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_megaliter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_milliliter(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_pint(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_pint_metric(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_quart(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_tablespoon(i18n_measure_unit_h measure_unit);
int i18n_measure_unit_create_teaspoon(i18n_measure_unit_h measure_unit);

/**
 * @}
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __UTILS_I18N_MEASURE_UNIT_H__*/
