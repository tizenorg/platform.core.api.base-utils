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
 * @brief The i18n module contains uchar, ucollator, unormalization, usearch, ustring, ucalendar, udate, udatepg, ulocale and unumber.
 *     This module provides flexible generation of number or date format patterns and helps you format and parse dates/number for any locale.
 * @section CAPI_BASE_UTILS_I18N_MODULE_HEADER Required Header
 *  \#include <utils_i18n.h>
 * @section CAPI_BASE_UTILS_I18N_MODULE_OVERVIEW Overview
 * <table>
 * <tr>
 *    <th>API</th>
 *    <th>Description</th>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>The Timezone module represents a time zone offset, and also figures out daylight savings.</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE</td>
 *    <td>Ucollator module performs locale-sensitive string comparison. It builds searching and sorting routines for natural language text and provides correct sorting orders for most locales.</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCHAR_MODULE</td>
 *    <td>Uchar module provides low-level access to the Unicode Character Database.</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UNORMALIZATION_MODULE</td>
 *    <td>Unormalization module provides Unicode normalization functionality for standard unicode normalization.</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USEARCH_MODULE</td>
 *    <td>Usearch module provides language-sensitive text searching based on the comparison rules defined in a ucollator data struct.</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>Ustring module provides general unicode string handling.</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>Ucalendar is used for converting between a i18n_udate type and a set of integer fields
         such as #I18N_UCALENDAR_YEAR, #I18N_UCALENDAR_MONTH, #I18N_UCALENDAR_DATE, #I18N_UCALENDAR_HOUR, and so on.</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *    <td>Udate module consists of functions that convert dates and times from their 
             internal representations to textual form and back again in a language-independent manner.</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *    <td> Udatepg module provides flexible generation of date format patterns, like "yy-MM-dd". </td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *    <td>A ulocale represents a specific geographical, political, or cultural region. </td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *    <td>Unumber helps you format and parse numbers for any locale.</td>
 * </tr>
 * </table>
 *
 * @section CAPI_BASE_UTILS_I18N_MODULE_MAPPING_TABLE Mapping Table
 * <table>
 * <tr>
 *    <th>Module</th>
 *    <th>Native API</th>
 *    <th>ICU API</th>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_create_unknown</td>
 *    <td>getUnknown</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_create_gmt</td>
 *    <td>getGMT</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_create</td>
 *    <td>createTimeZone</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_destroy</td>
 *    <td></td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_foreach_timezone_id_by_region</td>
 *    <td>createTimeZoneIDEnumeration</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_foreach_timezone_id</td>
 *    <td>createEnumeration</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_foreach_timezone_id_with_offset</td>
 *    <td>createEnumeration</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_foreach_timezone_id_by_country</td>
 *    <td>createEnumeration</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_count_equivalent_ids</td>
 *    <td>countEquivalentIDs</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_get_equivalent_id</td>
 *    <td>getEquivalentID</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_create_default</td>
 *    <td>createDefault</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_set_default</td>
 *    <td>setDefault</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_get_tzdata_version</td>
 *    <td>getTZDataVersion</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_get_region</td>
 *    <td>getRegion</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_get_offset_with_date</td>
 *    <td>getOffset</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_set_raw_offset</td>
 *    <td>setRawOffset</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_get_raw_offset</td>
 *    <td>getRawOffset</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_get_id</td>
 *    <td>getID</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_set_id</td>
 *    <td>setID</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_get_display_name</td>
 *    <td>getDisplayName</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_get_display_name_with_locale</td>
 *    <td>getDisplayName</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_get_display_name_with_type</td>
 *    <td>getDisplayName</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_get_display_name_with_type_locale</td>
 *    <td>getDisplayName</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_use_daylight_time</td>
 *    <td>useDaylightTime</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_in_daylight_time</td>
 *    <td>inDaylightTime</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_has_same_rule</td>
 *    <td>hasSameRules</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_clone</td>
 *    <td>clone</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE</td>
 *    <td>#i18n_timezone_get_dst_savings</td>
 *    <td>getDSTSavings</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_set_default_timezone</td>
 *    <td>ucal_setDefaultTimeZone</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_get_now</td>
 *    <td>ucal_getNow</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_create</td>
 *    <td>ucal_open</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_destroy</td>
 *    <td>ucal_close</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_clone</td>
 *    <td>ucal_clone</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_get_timezone_displayname</td>
 *    <td>ucal_getTimeZoneDisplayName</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_is_in_daylight_time</td>
 *    <td>ucal_inDaylightTime</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_set</td>
 *    <td>ucal_set</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_set_attribute</td>
 *    <td>ucal_setAttribute</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_get_attribute</td>
 *    <td>ucal_getAttribute</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_get_milliseconds</td>
 *    <td>ucal_getMillis</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_set_milliseconds</td>
 *    <td>ucal_setMillis</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_set_date_time</td>
 *    <td>ucal_setDateTime</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_is_equivalent_to</td>
 *    <td>ucal_equivalentTo</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_add</td>
 *    <td>ucal_add</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE</td>
 *    <td>#i18n_ucalendar_get</td>
 *    <td>ucal_get</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCHAR_MODULE</td>
 *    <td>#i18n_uchar_get_int_property_value</td>
 *    <td>u_getIntpropertyValue</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCHAR_MODULE</td>
 *    <td>#i18n_uchar_get_ublock_code</td>
 *    <td>ublock_getCode</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE</td>
 *    <td>#i18n_ucollator_create</td>
 *    <td>ucol_open</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE</td>
 *    <td>#i18n_ucollator_destroy</td>
 *    <td>ucol_close</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE</td>
 *    <td>#i18n_ucollator_str_collator</td>
 *    <td>ucol_strcoll</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE</td>
 *    <td>#i18n_ucollator_equal</td>
 *    <td>ucol_equal</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE</td>
 *    <td>#i18n_ucollator_set_strength</td>
 *    <td>ucol_setStrength</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE</td>
 *    <td>#i18n_ucollator_set_attribute</td>
 *    <td>ucol_setAttribute</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *    <td>#i18n_udate_create</td>
 *    <td>udat_open</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *    <td>#i18n_udate_destroy</td>
 *    <td>udat_close</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UDATE_MODULE</td>
 *    <td>#i18n_udate_format_date</td>
 *    <td>udat_format</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *    <td>#i18n_udatepg_create</td>
 *    <td>udatpg_open</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *    <td>#i18n_udatepg_destroy</td>
 *    <td>udatpg_close</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UDATEPG_MODULE</td>
 *    <td>#i18n_udatepg_get_best_pattern</td>
 *    <td>udatpg_getBestPattern</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *    <td>#i18n_ulocale_get_default</td>
 *    <td>uloc_getDefault</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *    <td>#i18n_ulocale_set_default</td>
 *    <td>uloc_setDefault</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *    <td>#i18n_ulocale_get_language</td>
 *    <td>uloc_getLanguage</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *    <td>#i18n_ulocale_get_country</td>
 *    <td>uloc_getCountry</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *    <td>#i18n_ulocale_get_display_name</td>
 *    <td>uloc_getDisplayName</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *    <td>#i18n_ulocale_get_available</td>
 *    <td>uloc_getAvailable</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_ULOCALE_MODULE</td>
 *    <td>#i18n_ulocale_count_available</td>
 *    <td>uloc_countAvailable</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UNORMALIZATION_MODULE</td>
 *    <td>#i18n_unormalization_get_instance</td>
 *    <td>unorm2_getInstance</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UNORMALIZATION_MODULE</td>
 *    <td>#i18n_unormalization_normalize</td>
 *    <td>unorm2_normalize</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *    <td>#i18n_unumber_create</td>
 *    <td>unum_open</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *    <td>#i18n_unumber_destroy</td>
 *    <td>unum_close</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_UNUMBER_MODULE</td>
 *    <td>#i18n_unumber_get_symbol</td>
 *    <td>unum_getSymbol</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USEARCH_MODULE</td>
 *    <td>#i18n_usearch_create</td>
 *    <td>usearch_open</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USEARCH_MODULE</td>
 *    <td>#i18n_usearch_destroy</td>
 *    <td>usearch_close</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USEARCH_MODULE</td>
 *    <td>#i18n_usearch_get_matched_text</td>
 *    <td>usearch_getMatchedText</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USEARCH_MODULE</td>
 *    <td>#i18n_usearch_get_collator</td>
 *    <td>usearch_getCollator</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USEARCH_MODULE</td>
 *    <td>#i18n_usearch_first</td>
 *    <td>usearch_first</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_get_length</td>
 *    <td>u_strlen</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_count_char32</td>
 *    <td>u_countChar32</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_has_more_char32_than</td>
 *    <td>u_strHasMoreChar32Than</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_cat</td>
 *    <td>u_strcat</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_cat_n</td>
 *    <td>u_strncat</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_string</td>
 *    <td>u_strstr</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_find_first</td>
 *    <td>u_strFindFirst</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_char</td>
 *    <td>u_strchr</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_char32</td>
 *    <td>u_strchr32</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_r_string</td>
 *    <td>u_strrstr</td>
 * </tr> 
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_find_last</td>
 *    <td>u_strFindLast</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_r_char</td>
 *    <td>u_strrchr</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_r_char32</td>
 *    <td>u_strrchr32</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_pbrk</td>
 *    <td>u_strpbrk</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_cspn</td>
 *    <td>u_strcspn</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_spn</td>
 *    <td>u_strspn</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_tokenizer_r</td>
 *    <td>u_strtok_r</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_compare</td>
 *    <td>u_strcmp</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_compare_code_point_order</td>
 *    <td>u_strcmpCodePointOrder</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_compare_binary_order</td>
 *    <td>u_strCompare</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_case_compare_with_length</td>
 *    <td>u_strCaseCompare</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_compare_n</td>
 *    <td>u_strncmp</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_compare_n_code_point_order</td>
 *    <td>u_strncmpCodePointOrder</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_case_compare</td>
 *    <td>u_strcasecmp</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_case_compare_n</td>
 *    <td>u_strncasecmp</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_mem_case_compare</td>
 *    <td>u_memcasecmp</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_copy</td>
 *    <td>u_strcpy</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_copy_n</td>
 *    <td>u_strncpy</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_copy_ua</td>
 *    <td>u_uastrcpy</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_copy_ua_n</td>
 *    <td>u_uastrncpy</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_copy_au</td>
 *    <td>u_austrcpy</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_copy_au_n</td>
 *    <td>u_austrncpy</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_mem_copy</td>
 *    <td>u_memcpy</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_mem_move</td>
 *    <td>u_memmove</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_mem_set</td>
 *    <td>u_memset</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_mem_compare</td>
 *    <td>u_memcmp</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_mem_compare_code_point_order</td>
 *    <td>u_memcmpCodePointOrder</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_mem_char</td>
 *    <td>u_memchr</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_mem_char32</td>
 *    <td>u_memchr32</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_mem_r_char</td>
 *    <td>u_memrchr</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_mem_r_char32</td>
 *    <td>u_memrchr32</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_unescape</td>
 *    <td>u_unescape</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_unescape_at</td>
 *    <td>u_unescapeAt</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_to_upper</td>
 *    <td>u_strToUpper</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_to_lower</td>
 *    <td>u_strToLower</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_to_title</td>
 *    <td>u_strToTitle</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_fold_case</td>
 *    <td>u_strFoldCase</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_to_WCS</td>
 *    <td>u_strToWCS</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_from_WCS</td>
 *    <td>u_strFromWCS</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_to_UTF8</td>
 *    <td>u_strToUTF8</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_from_UTF8</td>
 *    <td>u_strFromUTF8</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_to_UTF8_with_sub</td>
 *    <td>u_strToUTF8WithSub</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_from_UTF8_with_sub</td>
 *    <td>u_strFromUTF8WithSub</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_from_UTF8_lenient</td>
 *    <td>u_strFromUTF8Lenient</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_to_UTF32</td>
 *    <td>u_strToUTF32</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_from_UTF32</td>
 *    <td>u_strFromUTF32</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_to_UTF32_with_sub</td>
 *    <td>u_strToUTF32WithSub</td>
 * </tr>
 * <tr>
 *    <td>@ref CAPI_BASE_UTILS_I18N_USTRING_MODULE</td>
 *    <td>#i18n_ustring_from_UTF32_with_sub</td>
 *    <td>u_strFromUTF32WithSub</td>
 * </tr>
 * </table>
 */
 
#ifdef __cplusplus
}
#endif

#endif    /* __UTILS_I18N_H__*/
