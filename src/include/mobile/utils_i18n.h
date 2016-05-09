/*
 * Copyright (c) 2015 Samsung Electronics Co., Ltd All Rights Reserved
 *
 *	  Licensed under the Apache License, Version 2.0 (the "License");
 *	  you may not use this file except in compliance with the License.
 *	  You may obtain a copy of the License at
 *
 *		  http://www.apache.org/licenses/LICENSE-2.0
 *
 *	  Unless required by applicable law or agreed to in writing, software
 *	  distributed under the License is distributed on an "AS IS" BASIS,
 *	  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	  See the License for the specific language governing permissions and
 *	  limitations under the License.
 */

#ifndef __UTILS_I18N_H__
#define __UTILS_I18N_H__

#include <utils_i18n_ucalendar.h>
#include <utils_i18n_udate.h>
#include <utils_i18n_udatepg.h>
#include <utils_i18n_ulocale.h>
#include <utils_i18n_unumber.h>
#include <utils_i18n_uchar.h>
#include <utils_i18n_ucollator.h>
#include <utils_i18n_unormalization.h>
#include <utils_i18n_usearch.h>
#include <utils_i18n_ustring.h>
#include <utils_i18n_timezone.h>
#include <utils_i18n_types.h>
#include <utils_i18n_uenumeration.h>
#include <utils_i18n_uset.h>
#include <utils_i18n_ubrk.h>
#include <utils_i18n_formattable.h>
#include <utils_i18n_measure_unit.h>

/**
 * @file utils_i18n.h
 * @version 0.1
 * @brief utils_i18n
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup CAPI_BASE_UTILS_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_MODULE i18n
 * @brief The i18n module contains uchar, ucollator, unormalization, usearch, ustring, ucalendar, udate, udatepg, ulocale, unumber, formattable
 *     and measure unit..
 *	   This module provides flexible generation of number or date format patterns and helps you format and parse dates/number for any locale.
 * The i18n module provides various features based on data from ICU. The following table shows the version of ICU used in each Tizen platform.
 * <table>
 *	<tr>
 *	 <td>Tizen 2.3, 2.3.1, 2.4</td>
 *	 <td>ICU 51</td>
 *	 <td>CLDR 23</td>
 *	 <td>Unicode 6.2</td>
 *	</tr>
 * </table>
 * @section CAPI_BASE_UTILS_I18N_MODULE_HEADER Required Header
 *	\#include <utils_i18n.h>
 * @section CAPI_BASE_UTILS_I18N_MODULE_OVERVIEW Overview
 * <table>
 * <tr>
 *	  <th>API</th>
 *	  <th>Description</th>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>The Timezone module represents a time zone offset, and also figures out daylight savings.</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UENUMERATION_MODULE</td>
 *	  <td>UEnumeration defines functions for handling String Enumeration.</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>Ubrk module defines methods for finding the location of boundaries in text.</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE</td>
 *	  <td>Ucollator module performs locale-sensitive string comparison. It builds searching and sorting routines for natural language text and provides correct sorting orders for most locales.</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCHAR_MODULE</td>
 *	  <td>Uchar module provides low-level access to the Unicode Character Database.</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNORMALIZATION_MODULE</td>
 *	  <td>Unormalization module provides Unicode normalization functionality for standard unicode normalization.</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USEARCH_MODULE</td>
 *	  <td>Usearch module provides language-sensitive text searching based on the comparison rules defined in a ucollator data struct.</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>Uset module allows to specify a subset of character used in strings.</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>Ustring module provides general unicode string handling.</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>Ucalendar is used for converting between a i18n_udate type and a set of integer fields
		 such as #I18N_UCALENDAR_YEAR, #I18N_UCALENDAR_MONTH, #I18N_UCALENDAR_DATE, #I18N_UCALENDAR_HOUR, and so on.</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>Udate module consists of functions that convert dates and times from their
			 internal representations to textual form and back again in a language-independent manner.</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td> Udatepg module provides flexible generation of date format patterns, like "yy-MM-dd". </td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>A ulocale represents a specific geographical, political, or cultural region. </td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>Unumber helps you format and parse numbers for any locale.</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>Formattable interconverts between the primitive numeric types (double, long, etc.) as well as #i18n_udate and char string..</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>The MeasureUnit module contains unit such as length, mass, volume, currency, etc..</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_MODULE</td>
 *	  <td>The MeasureUnit module contains unit such as length, mass, volume, currency, etc..</td>
 * </tr>
 * </table>
 *
 * @section CAPI_BASE_UTILS_I18N_MODULE_MAPPING_TABLE Mapping Table
 * <table>
 * <tr>
 *	  <th>Module</th>
 *	  <th>Native API</th>
 *	  <th>ICU API</th>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_create_unknown</td>
 *	  <td>getUnknown</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_create_gmt</td>
 *	  <td>getGMT</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_create</td>
 *	  <td>createTimeZone</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_destroy</td>
 *	  <td></td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_foreach_timezone_id_by_region</td>
 *	  <td>createTimeZoneIDEnumeration</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_foreach_timezone_id</td>
 *	  <td>createEnumeration</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_foreach_timezone_id_with_offset</td>
 *	  <td>createEnumeration</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_foreach_timezone_id_by_country</td>
 *	  <td>createEnumeration</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_count_equivalent_ids</td>
 *	  <td>countEquivalentIDs</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_get_equivalent_id</td>
 *	  <td>getEquivalentID</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_create_default</td>
 *	  <td>createDefault</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_set_default</td>
 *	  <td>setDefault</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_get_tzdata_version</td>
 *	  <td>getTZDataVersion</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_get_region</td>
 *	  <td>getRegion</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_get_offset_with_date</td>
 *	  <td>getOffset</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_set_raw_offset</td>
 *	  <td>setRawOffset</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_get_raw_offset</td>
 *	  <td>getRawOffset</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_get_id</td>
 *	  <td>getID</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_set_id</td>
 *	  <td>setID</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_get_display_name</td>
 *	  <td>getDisplayName</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_get_display_name_with_locale</td>
 *	  <td>getDisplayName</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_get_display_name_with_type</td>
 *	  <td>getDisplayName</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_get_display_name_with_type_locale</td>
 *	  <td>getDisplayName</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_use_daylight_time</td>
 *	  <td>useDaylightTime</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_has_same_rule</td>
 *	  <td>hasSameRules</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_clone</td>
 *	  <td>clone</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *	  <td>#i18n_timezone_get_dst_savings</td>
 *	  <td>getDSTSavings</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UENUMERATION_MODULE</td>
 *	  <td>#i18n_uenumeration_destroy</td>
 *	  <td>uenum_close</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UENUMERATION_MODULE</td>
 *	  <td>#i18n_uenumeration_count</td>
 *	  <td>uenum_count</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UENUMERATION_MODULE</td>
 *	  <td>#i18n_uenumeration_unext</td>
 *	  <td>uenum_unext</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UENUMERATION_MODULE</td>
 *	  <td>#i18n_uenumeration_next</td>
 *	  <td>uenum_next</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UENUMERATION_MODULE</td>
 *	  <td>#i18n_uenumeration_reset</td>
 *	  <td>uenum_reset</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UENUMERATION_MODULE</td>
 *	  <td>#i18n_uenumeration_uchar_strings_enumeration_create</td>
 *	  <td>uenum_openUCharStringsEnumeration</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UENUMERATION_MODULE</td>
 *	  <td>#i18n_uenumeration_char_strings_enumeration_create</td>
 *	  <td>uenum_openCharStringsEnumeration</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_create</td>
 *	  <td>ubrk_open</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_create_rules</td>
 *	  <td>ubrk_openRules</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_safe_clone</td>
 *	  <td>ubrk_safeClone</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_destroy</td>
 *	  <td>ubrk_close</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_set_text</td>
 *	  <td>ubrk_setText</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_current</td>
 *	  <td>ubrk_current</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_next</td>
 *	  <td>ubrk_next</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_preceding</td>
 *	  <td>ubrk_preceding</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_previous</td>
 *	  <td>ubrk_previous</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_first</td>
 *	  <td>ubrk_first</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_last</td>
 *	  <td>ubrk_last</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_following</td>
 *	  <td>ubrk_following</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_get_available</td>
 *	  <td>ubrk_getAvailable</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_count_available</td>
 *	  <td>ubrk_countAvailable</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_is_boundary</td>
 *	  <td>ubrk_isBoundary</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_get_rule_status</td>
 *	  <td>ubrk_getRuleStatus</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_get_rule_status_vec</td>
 *	  <td>ubrk_getRuleStatusVec</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UBRK_MODULE</td>
 *	  <td>#i18n_ubrk_get_locale_by_type</td>
 *	  <td>ubrk_getLocaleByType</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_set_default_timezone</td>
 *	  <td>ucal_setDefaultTimeZone</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_now</td>
 *	  <td>ucal_getNow</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_create</td>
 *	  <td>ucal_open</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_destroy</td>
 *	  <td>ucal_close</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_clone</td>
 *	  <td>ucal_clone</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_timezone_displayname</td>
 *	  <td>ucal_getTimeZoneDisplayName</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_is_in_daylight_time</td>
 *	  <td>ucal_inDaylightTime</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_set</td>
 *	  <td>ucal_set</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_set_attribute</td>
 *	  <td>ucal_setAttribute</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_attribute</td>
 *	  <td>ucal_getAttribute</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_milliseconds</td>
 *	  <td>ucal_getMillis</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_set_milliseconds</td>
 *	  <td>ucal_setMillis</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_set_date_time</td>
 *	  <td>ucal_setDateTime</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_is_equivalent_to</td>
 *	  <td>ucal_equivalentTo</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_add</td>
 *	  <td>ucal_add</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get</td>
 *	  <td>ucal_get</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_clear</td>
 *	  <td>ucal_clear</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_clear_field</td>
 *	  <td>ucal_clearField</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_count_available</td>
 *	  <td>ucal_countAvailable</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_country_timezones_create</td>
 *	  <td>ucal_openCountryTimeZones</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_available</td>
 *	  <td>ucal_getAvailable</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_canonical_timezone_id</td>
 *	  <td>ucal_getCanonicalTimeZoneID</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_day_of_week_type</td>
 *	  <td>ucal_getDayOfWeekType</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_default_timezone</td>
 *	  <td>ucal_getDefaultTimeZone</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_field_difference</td>
 *	  <td>ucal_getFieldDifference</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_gregorian_change</td>
 *	  <td>ucal_getGregorianChange</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_keyword_values_for_locale</td>
 *	  <td>ucal_getKeywordValuesForLocale</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_limit</td>
 *	  <td>ucal_getLimit</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_locale_by_type</td>
 *	  <td>ucal_getLocaleByType</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_timezone_id</td>
 *	  <td>ucal_getTimeZoneID</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_timezone_transition_date</td>
 *	  <td>ucal_getTimeZoneTransitionDate</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_type</td>
 *	  <td>ucal_getType</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_tz_data_version</td>
 *	  <td>ucal_getTZDataVersion</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_get_weekend_transition</td>
 *	  <td>ucal_getWeekendTransition</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_is_set</td>
 *	  <td>ucal_isSet</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_is_weekend</td>
 *	  <td>ucal_isWeekend</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_roll</td>
 *	  <td>ucal_roll</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_set_date</td>
 *	  <td>ucal_setDate</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_set_gregorian_change</td>
 *	  <td>ucal_setGregorianChange</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_set_timezone</td>
 *	  <td>ucal_setTimeZone</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_timezones_create</td>
 *	  <td>ucal_openTimeZones</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *	  <td>#i18n_ucalendar_timezone_id_enumeration_create</td>
 *	  <td>ucal_openTimeZoneIDEnumeration</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCHAR_MODULE</td>
 *	  <td>#i18n_uchar_get_int_property_value</td>
 *	  <td>u_getIntpropertyValue</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCHAR_MODULE</td>
 *	  <td>#i18n_uchar_get_ublock_code</td>
 *	  <td>ublock_getCode</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE</td>
 *	  <td>#i18n_ucollator_create</td>
 *	  <td>ucol_open</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE</td>
 *	  <td>#i18n_ucollator_destroy</td>
 *	  <td>ucol_close</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE</td>
 *	  <td>#i18n_ucollator_str_collator</td>
 *	  <td>ucol_strcoll</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE</td>
 *	  <td>#i18n_ucollator_equal</td>
 *	  <td>ucol_equal</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE</td>
 *	  <td>#i18n_ucollator_set_strength</td>
 *	  <td>ucol_setStrength</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE</td>
 *	  <td>#i18n_ucollator_set_attribute</td>
 *	  <td>ucol_setAttribute</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_create</td>
 *	  <td>udat_open</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_destroy</td>
 *	  <td>udat_close</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_format_date</td>
 *	  <td>udat_format</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_apply_pattern</td>
 *	  <td>udat_applyPattern</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_clone</td>
 *	  <td>udat_clone</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_count_available</td>
 *	  <td>udat_countAvailable</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_count_symbols</td>
 *	  <td>udat_countSymbols</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_get_2digit_year_start</td>
 *	  <td>udat_get2DigitYearStart</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_get_available</td>
 *	  <td>udat_getAvailable</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_get_calendar</td>
 *	  <td>udat_getCalendar</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_get_locale_by_type</td>
 *	  <td>udat_getLocaleByType</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_get_number_format</td>
 *	  <td>udat_getNumberFormat</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_get_symbols</td>
 *	  <td>udat_getSymbols</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_is_lenient</td>
 *	  <td>udat_isLenient</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_parse</td>
 *	  <td>udat_parse</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_parse_calendar</td>
 *	  <td>udat_parseCalendar</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_set_2digit_year_start</td>
 *	  <td>udat_set2DigitYearStart</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_set_calendar</td>
 *	  <td>udat_setCalendar</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_set_context</td>
 *	  <td>udat_setContext</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_set_lenient</td>
 *	  <td>udat_setLenient</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_set_number_format</td>
 *	  <td>udat_setNumberFormat</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_set_symbols</td>
 *	  <td>udat_setSymbols</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_to_calendar_date_field</td>
 *	  <td>udat_toCalendarDateField</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *	  <td>#i18n_udate_to_pattern</td>
 *	  <td>udat_toPattern</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_create</td>
 *	  <td>udatpg_open</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_destroy</td>
 *	  <td>udatpg_close</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_get_best_pattern</td>
 *	  <td>udatpg_getBestPattern</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_add_pattern</td>
 *	  <td>udatpg_addPattern</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_base_skeletons_create</td>
 *	  <td>udatpg_openBaseSkeletons</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_clone</td>
 *	  <td>udatpg_clone</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_create_empty</td>
 *	  <td>udatpg_openEmpty</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_get_append_item_format</td>
 *	  <td>udatpg_getAppendItemFormat</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_get_append_item_name</td>
 *	  <td>udatpg_getAppendItemName</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_get_base_skeleton</td>
 *	  <td>udatpg_getBaseSkeleton</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_get_best_pattern_with_options</td>
 *	  <td>udatpg_getBestPatternWithOptions</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_get_date_time_format</td>
 *	  <td>udatpg_getDateTimeFormat</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_get_decimal</td>
 *	  <td>udatpg_getDecimal</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_get_pattern_for_skeleton</td>
 *	  <td>udatpg_getPatternForSkeleton</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_get_skeleton</td>
 *	  <td>udatpg_getSkeleton</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_replace_field_types</td>
 *	  <td>udatpg_replaceFieldTypes</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_replace_field_types_with_options</td>
 *	  <td>udatpg_replaceFieldTypesWithOptions</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_set_append_item_format</td>
 *	  <td>udatpg_setAppendItemFormat</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_set_append_item_name</td>
 *	  <td>udatpg_setAppendItemName</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_set_date_time_format</td>
 *	  <td>udatpg_setDateTimeFormat</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_set_decimal</td>
 *	  <td>udatpg_setDecimal</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *	  <td>#i18n_udatepg_skeletons_create</td>
 *	  <td>udatpg_openSkeletons</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_default</td>
 *	  <td>uloc_getDefault</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_set_default</td>
 *	  <td>uloc_setDefault</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_language</td>
 *	  <td>uloc_getLanguage</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_country</td>
 *	  <td>uloc_getCountry</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_display_name</td>
 *	  <td>uloc_getDisplayName</td>
 * </tr>
 *
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_add_likely_subtags</td>
 *	  <td>uloc_addLikelySubtags</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_canonicalize</td>
 *	  <td>uloc_canonicalize</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_for_language_tag</td>
 *	  <td>uloc_forLanguageTag</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_base_name</td>
 *	  <td>uloc_getBaseName</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_character_orientation</td>
 *	  <td>uloc_getCharacterOrientation</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_display_country</td>
 *	  <td>uloc_getDisplayCountry</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_display_keyword</td>
 *	  <td>uloc_getDisplayKeyword</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_display_keyword_value</td>
 *	  <td>uloc_getDisplayKeywordValue</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_display_language</td>
 *	  <td>uloc_getDisplayLanguage</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_display_script</td>
 *	  <td>uloc_getDisplayScript</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_display_variant</td>
 *	  <td>uloc_getDisplayVariant</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_iso3_country</td>
 *	  <td>uloc_getISO3Country</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_iso3_language</td>
 *	  <td>uloc_getISO3Language</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_iso_countries</td>
 *	  <td>uloc_getISOCountries</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_iso_languages</td>
 *	  <td>uloc_getISOLanguages</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_keyword_value</td>
 *	  <td>uloc_getKeywordValue</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_lcid</td>
 *	  <td>uloc_getLCID</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_line_orientation</td>
 *	  <td>uloc_getLineOrientation</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_locale_for_lcid</td>
 *	  <td>uloc_getLocaleForLCID</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_name</td>
 *	  <td>uloc_getName</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_parent</td>
 *	  <td>uloc_getParent</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_script</td>
 *	  <td>uloc_getScript</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_variant</td>
 *	  <td>uloc_getVariant</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_keywords_create</td>
 *	  <td>uloc_openKeywords</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_minimize_subtags</td>
 *	  <td>uloc_minimizeSubtags</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_set_keyword_value</td>
 *	  <td>uloc_setKeywordValue</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_to_language_tag</td>
 *	  <td>uloc_toLanguageTag</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_get_available</td>
 *	  <td>uloc_getAvailable</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *	  <td>#i18n_ulocale_count_available</td>
 *	  <td>uloc_countAvailable</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNORMALIZATION_MODULE</td>
 *	  <td>#i18n_unormalization_get_instance</td>
 *	  <td>unorm2_getInstance</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNORMALIZATION_MODULE</td>
 *	  <td>#i18n_unormalization_normalize</td>
 *	  <td>unorm2_normalize</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_create</td>
 *	  <td>unum_open</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_destroy</td>
 *	  <td>unum_close</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_get_symbol</td>
 *	  <td>unum_getSymbol</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_apply_pattern</td>
 *	  <td>unum_applyPattern</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_clone</td>
 *	  <td>unum_clone</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_count_available</td>
 *	  <td>unum_countAvailable</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_format</td>
 *	  <td>unum_format</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_format_decimal</td>
 *	  <td>unum_formatDecimal</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_format_double</td>
 *	  <td>unum_formatDouble</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_format_double_currency</td>
 *	  <td>unum_formatDoubleCurrency</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_format_int64</td>
 *	  <td>unum_formatInt64</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_get_attribute</td>
 *	  <td>unum_getAttribute</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_get_available</td>
 *	  <td>unum_getAvailable</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_get_double_attribute</td>
 *	  <td>unum_getDoubleAttribute</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_get_locale_by_type</td>
 *	  <td>unum_getLocaleByType</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_get_text_attribute</td>
 *	  <td>unum_getTextAttribute</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_parse</td>
 *	  <td>unum_parse</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_parse_decimal</td>
 *	  <td>unum_parseDecimal</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_parse_double</td>
 *	  <td>unum_parseDouble</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_parse_double_currency</td>
 *	  <td>unum_parseDoubleCurrency</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_parse_int64</td>
 *	  <td>unum_parseInt64</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_set_attribute</td>
 *	  <td>unum_setAttribute</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_set_double_attribute</td>
 *	  <td>unum_setDoubleAttribute</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_set_symbol</td>
 *	  <td>unum_setSymbol</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_set_text_attribute</td>
 *	  <td>unum_setTextAttribute</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *	  <td>#i18n_unumber_to_pattern</td>
 *	  <td>unum_toPattern</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USEARCH_MODULE</td>
 *	  <td>#i18n_usearch_create_new</td>
 *	  <td>usearch_open</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USEARCH_MODULE</td>
 *	  <td>#i18n_usearch_destroy</td>
 *	  <td>usearch_close</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USEARCH_MODULE</td>
 *	  <td>#i18n_usearch_get_matched_text</td>
 *	  <td>usearch_getMatchedText</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USEARCH_MODULE</td>
 *	  <td>#i18n_usearch_get_collator</td>
 *	  <td>usearch_getCollator</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USEARCH_MODULE</td>
 *	  <td>#i18n_usearch_first</td>
 *	  <td>usearch_first</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_create_empty</td>
 *	  <td>uset_openEmpty</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_create</td>
 *	  <td>uset_open</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_create_pattern</td>
 *	  <td>uset_openPattern</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_create_pattern_options</td>
 *	  <td>uset_openPatternOptions</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_destroy</td>
 *	  <td>uset_close</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_clone</td>
 *	  <td>uset_clone</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_is_frozen</td>
 *	  <td>uset_isFrozen</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_freeze</td>
 *	  <td>uset_freeze</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_clone_as_thawed</td>
 *	  <td>uset_cloneAsThawed</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_set</td>
 *	  <td>uset_set</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_apply_pattern</td>
 *	  <td>uset_applyPattern</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_apply_int_property_value</td>
 *	  <td>uset_applyIntPropertyValue</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_apply_property_alias</td>
 *	  <td>uset_applyPropertyAlias</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_resembles_pattern</td>
 *	  <td>uset_resemblesPattern</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_to_pattern</td>
 *	  <td>uset_toPattern</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_add</td>
 *	  <td>uset_add</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_add_all</td>
 *	  <td>uset_addAll</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_add_range</td>
 *	  <td>uset_addRange</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_add_string</td>
 *	  <td>uset_addString</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_add_all_code_points</td>
 *	  <td>uset_addAllCodePoints</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_remove</td>
 *	  <td>uset_remove</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_remove_range</td>
 *	  <td>uset_removeRange</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_remove_string</td>
 *	  <td>uset_removeString</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_remove_all</td>
 *	  <td>uset_removeAll</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_retain</td>
 *	  <td>uset_retain</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_retain_all</td>
 *	  <td>uset_retainAll</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_compact</td>
 *	  <td>uset_compact</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_complement</td>
 *	  <td>uset_complement</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_complement_all</td>
 *	  <td>uset_complementAll</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_clear</td>
 *	  <td>uset_clear</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_destroy_over</td>
 *	  <td>uset_closeOver</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_remove_all_strings</td>
 *	  <td>uset_removeAllStrings</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_is_empty</td>
 *	  <td>uset_isEmpty</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_contains</td>
 *	  <td>uset_contains</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_contains_range</td>
 *	  <td>uset_containsRange</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_contains_string</td>
 *	  <td>uset_containsString</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_index_of</td>
 *	  <td>uset_indexOf</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_char_at</td>
 *	  <td>uset_charAt</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_size</td>
 *	  <td>uset_size</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_get_item_count</td>
 *	  <td>uset_getItemCount</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_get_item</td>
 *	  <td>uset_getItem</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_contains_all</td>
 *	  <td>uset_containsAll</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_contains_all_code_points</td>
 *	  <td>uset_containsAllCodePoints</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_contains_none</td>
 *	  <td>uset_containsNone</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_contains_some</td>
 *	  <td>uset_containsSome</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_span</td>
 *	  <td>uset_span</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_span_back</td>
 *	  <td>uset_spanBack</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_span_utf8</td>
 *	  <td>uset_spanUTF8</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_span_back_utf8</td>
 *	  <td>uset_spanBackUTF8</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_equals</td>
 *	  <td>uset_equals</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_serialize</td>
 *	  <td>uset_serialize</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_get_serialized_set</td>
 *	  <td>uset_getSerializedSet</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_set_serialized_to_one</td>
 *	  <td>uset_setSerializedToOne</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_serialized_contains</td>
 *	  <td>uset_serializedContains</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_get_serialized_range_count</td>
 *	  <td>uset_getSerializedRangeCount</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USET_MODULE</td>
 *	  <td>#i18n_uset_get_serialized_range</td>
 *	  <td>uset_getSerializedRange</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_get_length</td>
 *	  <td>u_strlen</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_count_char32</td>
 *	  <td>u_countChar32</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_has_more_char32_than</td>
 *	  <td>u_strHasMoreChar32Than</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_cat</td>
 *	  <td>u_strcat</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_cat_n</td>
 *	  <td>u_strncat</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_string</td>
 *	  <td>u_strstr</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_find_first</td>
 *	  <td>u_strFindFirst</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_char</td>
 *	  <td>u_strchr</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_char32</td>
 *	  <td>u_strchr32</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_r_string</td>
 *	  <td>u_strrstr</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_find_last</td>
 *	  <td>u_strFindLast</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_r_char</td>
 *	  <td>u_strrchr</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_r_char32</td>
 *	  <td>u_strrchr32</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_pbrk</td>
 *	  <td>u_strpbrk</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_cspn</td>
 *	  <td>u_strcspn</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_spn</td>
 *	  <td>u_strspn</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_tokenizer_r</td>
 *	  <td>u_strtok_r</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_compare</td>
 *	  <td>u_strcmp</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_compare_code_point_order</td>
 *	  <td>u_strcmpCodePointOrder</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_compare_binary_order</td>
 *	  <td>u_strCompare</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_case_compare_with_length</td>
 *	  <td>u_strCaseCompare</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_compare_n</td>
 *	  <td>u_strncmp</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_compare_n_code_point_order</td>
 *	  <td>u_strncmpCodePointOrder</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_case_compare</td>
 *	  <td>u_strcasecmp</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_case_compare_n</td>
 *	  <td>u_strncasecmp</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_mem_case_compare</td>
 *	  <td>u_memcasecmp</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_copy</td>
 *	  <td>u_strcpy</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_copy_n</td>
 *	  <td>u_strncpy</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_copy_ua</td>
 *	  <td>u_uastrcpy</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_copy_ua_n</td>
 *	  <td>u_uastrncpy</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_copy_au</td>
 *	  <td>u_austrcpy</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_copy_au_n</td>
 *	  <td>u_austrncpy</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_mem_copy</td>
 *	  <td>u_memcpy</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_mem_move</td>
 *	  <td>u_memmove</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_mem_set</td>
 *	  <td>u_memset</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_mem_compare</td>
 *	  <td>u_memcmp</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_mem_compare_code_point_order</td>
 *	  <td>u_memcmpCodePointOrder</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_mem_char</td>
 *	  <td>u_memchr</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_mem_char32</td>
 *	  <td>u_memchr32</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_mem_r_char</td>
 *	  <td>u_memrchr</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_mem_r_char32</td>
 *	  <td>u_memrchr32</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_unescape</td>
 *	  <td>u_unescape</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_unescape_at</td>
 *	  <td>u_unescapeAt</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_to_upper</td>
 *	  <td>u_strToUpper</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_to_lower</td>
 *	  <td>u_strToLower</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_to_title_new</td>
 *	  <td>u_strToTitle</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_fold_case</td>
 *	  <td>u_strFoldCase</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_to_WCS</td>
 *	  <td>u_strToWCS</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_from_WCS</td>
 *	  <td>u_strFromWCS</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_to_UTF8</td>
 *	  <td>u_strToUTF8</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_from_UTF8</td>
 *	  <td>u_strFromUTF8</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_to_UTF8_with_sub</td>
 *	  <td>u_strToUTF8WithSub</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_from_UTF8_with_sub</td>
 *	  <td>u_strFromUTF8WithSub</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_from_UTF8_lenient</td>
 *	  <td>u_strFromUTF8Lenient</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_to_UTF32</td>
 *	  <td>u_strToUTF32</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_from_UTF32</td>
 *	  <td>u_strFromUTF32</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_to_UTF32_with_sub</td>
 *	  <td>u_strToUTF32WithSub</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *	  <td>#i18n_ustring_from_UTF32_with_sub</td>
 *	  <td>u_strFromUTF32WithSub</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_create_default</td>
 *    <td>Formattable()</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_create_with_udate</td>
 *    <td>Formattable(UDate d, ISDATE flag)</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_create_with_double</td>
 *    <td>Formattable(double d)</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_create_with_long</td>
 *    <td>Formattable(int32_t l)</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_create_with_int64</td>
 *    <td>Formattable(int64_t ll)</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_create_with_char_string</td>
 *    <td>Formattable(const char* strToCopy)</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_create_with_formattable_array</td>
 *    <td>Formattable(const Formattable* arrayToCopy, int32_t count)</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_create_with_formattable</td>
 *    <td>Formattable(const Formattable&)</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_destroy</td>
 *    <td>delete</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_adopt_array</td>
 *    <td>Formattable::adoptArray</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_clone</td>
 *    <td>Formattable::clone</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_get_array</td>
 *    <td>Formattable::getArray</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_get_date</td>
 *    <td>Formattable::getDate</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_get_double</td>
 *    <td>Formattable::getDouble</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_get_int64</td>
 *    <td>Formattable::getInt64</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_get_long</td>
 *    <td>Formattable::getLong</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_get_string</td>
 *    <td>Formattable::getString</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_get_type</td>
 *    <td>Formattable::getType</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_is_numeric</td>
 *    <td>Formattable::isNumeric</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_not_equal</td>
 *    <td>Formattable::operator!=</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_equal</td>
 *    <td>Formattable::operator==</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_element_at</td>
 *    <td>Formattable::operator[]</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_set_array</td>
 *    <td>Formattable::setArray</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_set_date</td>
 *    <td>Formattable::setDate</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_set_double</td>
 *    <td>Formattable::setDouble</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_set_int64</td>
 *    <td>Formattable::setInt64</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_set_long</td>
 *    <td>Formattable::setLong</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_FORMATTABLE_MODULE</td>
 *    <td>#i18n_formattable_set_string</td>
 *    <td>Formattable::setString</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create</td>
 *	  <td>MeasureUnit</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_form_other</td>
 *	  <td>MeasureUnit</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_clone</td>
 *	  <td>clone</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_destroy</td>
 *	  <td>~MeasureUnit</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_clone</td>
 *	  <td>~MeasureUnit</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_get_type</td>
 *	  <td>getType</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_get_subtype</td>
 *	  <td>getSubype</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_get_available</td>
 *	  <td>getAvailable</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_get_available_with_type</td>
 *	  <td>getAvailable</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_get_available_types</td>
 *	  <td>getAvailableTypes</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_g_force</td>
 *	  <td>createGForce</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_meter_per_second_squared</td>
 *	  <td>createMeterPerSecondSquared</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_arc_minute</td>
 *	  <td>createArcMinute</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_arc_second</td>
 *	  <td>createArcSecond</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_degree</td>
 *	  <td>createDegree</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_radian</td>
 *	  <td>createRadian</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_revolution_angle</td>
 *	  <td>createRevolutionAngle</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_acre</td>
 *	  <td>createAcre</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_hectare</td>
 *	  <td>createHectare</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_square_centimeter</td>
 *	  <td>createSquareCentimeter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_square_foot</td>
 *	  <td>createSquareFoot</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_square_inch</td>
 *	  <td>createSquareInch</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_square_kilometer</td>
 *	  <td>createSquareKilometer</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_square_meter</td>
 *	  <td>createSquareMeter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_square_mile</td>
 *	  <td>createSquareMile</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_square_yard</td>
 *	  <td>createSquareYard</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_karat</td>
 *	  <td>createKarat</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_milligram_per_deciliter</td>
 *	  <td>createMilligramPerDeciliter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_millimole_per_liter</td>
 *	  <td>createMillimolePerLiter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_part_per_million</td>
 *	  <td>createPartPerMillion</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_liter_per_100_kilometers</td>
 *	  <td>createLiterPer100Kilometers</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_liter_per_kilometer</td>
 *	  <td>createLiterPerKilometer</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_mile_per_gallon</td>
 *	  <td>createMilePerGallon</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_mile_per_gallon_imperial</td>
 *	  <td>createMilePerGallonImperial</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_bit</td>
 *	  <td>createBit</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_byte</td>
 *	  <td>createByte</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_gigabit</td>
 *	  <td>createGigabit</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_gigabyte</td>
 *	  <td>createGigabyte</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_kilobit</td>
 *	  <td>createKilobit</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_kilobyte</td>
 *	  <td>createKilobyte</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_megabit</td>
 *	  <td>createMegabit</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_megabyte</td>
 *	  <td>createMegabyte</td>
 * </tr>
 * <tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_terabit</td>
 *	  <td>createTerabit</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_terabyte</td>
 *	  <td>createTerabyte</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_century</td>
 *	  <td>createCentury</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_day</td>
 *	  <td>createDay</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_hour</td>
 *	  <td>createHour</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_microsecond</td>
 *	  <td>createMicrosecond</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_millisecond</td>
 *	  <td>createMillisecond</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_minute</td>
 *	  <td>createMinute</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_month</td>
 *	  <td>createMonth</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_nanosecond</td>
 *	  <td>createNanosecond</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_second</td>
 *	  <td>createSecond</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_week</td>
 *	  <td>createWeek</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_year</td>
 *	  <td>createYear</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_ampere</td>
 *	  <td>createAmpere</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_milliampere</td>
 *	  <td>createMilliampere</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_ohm</td>
 *	  <td>createOhm</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_volt</td>
 *	  <td>createVolt</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_calorie</td>
 *	  <td>createCalorie</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_foodcalorie</td>
 *	  <td>createFoodcalorie</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_joule</td>
 *	  <td>createJoule</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_kilocalorie</td>
 *	  <td>createKilocalorie</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_kilojoule</td>
 *	  <td>createKilojoule</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_kilowatt_hour</td>
 *	  <td>createKilowattHour</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_gigahertz</td>
 *	  <td>createGigahertz</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_hertz</td>
 *	  <td>createHertz</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_kilohertz</td>
 *	  <td>createKilohertz</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_megahertz</td>
 *	  <td>createMegahertz</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_astronomical_unit</td>
 *	  <td>createAstronomicalUnit</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_centimeter</td>
 *	  <td>createCentimeter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_decimeter</td>
 *	  <td>createDecimeter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_fathom</td>
 *	  <td>createFathom</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_foot</td>
 *	  <td>createFoot</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_furlong</td>
 *	  <td>createFurlong</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_inch</td>
 *	  <td>createInch</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_kilometer</td>
 *	  <td>createKilometer</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_light_year</td>
 *	  <td>createLightYear</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_meter</td>
 *	  <td>createMeter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_micrometer</td>
 *	  <td>createMicrometer</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_mile</td>
 *	  <td>createMile</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_mile_scandinavian</td>
 *	  <td>createMileScandinavian</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_millimeter</td>
 *	  <td>createMillimeter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_nanometer</td>
 *	  <td>createNanometer</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_nautical_mile</td>
 *	  <td>createNauticalMile</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_parsec</td>
 *	  <td>createParsec</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_picometer</td>
 *	  <td>createPicometer</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_yard</td>
 *	  <td>createYard</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_lux</td>
 *	  <td>createLux</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_carat</td>
 *	  <td>createCarat</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_gram</td>
 *	  <td>createGram</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_kilogram</td>
 *	  <td>createKilogram</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_metric_ton</td>
 *	  <td>createMetricTon</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_microgram</td>
 *	  <td>createMicrogram</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_milligram</td>
 *	  <td>createMilligram</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_ounce</td>
 *	  <td>createOunce</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_ounce_troy</td>
 *	  <td>createOunceTroy</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_pound</td>
 *	  <td>createPound</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_stone</td>
 *	  <td>createStone</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_ton</td>
 *	  <td>createTon</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_gigawatt</td>
 *	  <td>createGigawatt</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_horsepower</td>
 *	  <td>createHorsepower</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_kilowatt</td>
 *	  <td>createKilowatt</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_megawatt</td>
 *	  <td>createMegawatt</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_milliwatt</td>
 *	  <td>createMilliwatt</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_watt</td>
 *	  <td>createWatt</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_hectopascal</td>
 *	  <td>createHectopascal</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_inch_hg</td>
 *	  <td>createInchHg</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_millibar</td>
 *	  <td>createMillibar</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_millimeter_of_mercury</td>
 *	  <td>createMillimeterOfMercury</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_pound_per_square_inch</td>
 *	  <td>createPoundPerSquareInch</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_kilometer_per_hour</td>
 *	  <td>createKilometerPerHour</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_knot</td>
 *	  <td>createKnot</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_meter_per_second</td>
 *	  <td>createMeterPerSecond</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_mile_per_hour</td>
 *	  <td>createMilePerHour</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_celsius</td>
 *	  <td>createCelsius</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_fahrenheit</td>
 *	  <td>createFahrenheit</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_generic_temperature</td>
 *	  <td>createGenericTemperature</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_kelvin</td>
 *	  <td>createKelvin</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_acre_foot</td>
 *	  <td>createAcreFoot</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_bushel</td>
 *	  <td>createBushel</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_centiliter</td>
 *	  <td>createCentiliter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_cubic_centimeter</td>
 *	  <td>createCubicCentimeter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_cubic_foot</td>
 *	  <td>createCubicFoot</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_cubic_inch</td>
 *	  <td>createCubicInch</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_cubic_kilometer</td>
 *	  <td>createCubicKilometer</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_cubic_meter</td>
 *	  <td>createCubicMeter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_cubic_mile</td>
 *	  <td>createCubicMile</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_cubic_yard</td>
 *	  <td>createCubicYard</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_cup</td>
 *	  <td>createCup</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_cup_metric</td>
 *	  <td>createCupMetric</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_deciliter</td>
 *	  <td>createDeciliter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_fluid_ounce</td>
 *	  <td>createFluidOunce</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_gallon</td>
 *	  <td>createGallon</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_gallon_imperial</td>
 *	  <td>createGallonImperial</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_hectoliter</td>
 *	  <td>createHectoliter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_liter</td>
 *	  <td>createLiter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_megaliter</td>
 *	  <td>createMegaliter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_milliliter</td>
 *	  <td>createMilliliter</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_pint</td>
 *	  <td>createPint</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_pint_metric</td>
 *	  <td>createPintMetric</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_quart</td>
 *	  <td>createQuart</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_tablespoon</td>
 *	  <td>createTablespoon</td>
 * </tr>
 * <tr>
 *	  <td>@ref CAPI_BASE_UTILS_I18N_MEASURE_UNIT_MODULE</td>
 *	  <td>#i18n_measure_unit_create_teaspoon</td>
 *	  <td>createTeaspoon</td>
 * </tr>
 * </table>
 */

#ifdef __cplusplus
}
#endif

#endif	  /* __UTILS_I18N_H__*/
