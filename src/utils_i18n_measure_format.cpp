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
#include <utils_i18n_measure_format.h>
#include <utils_i18n_private.h>
#include <utils_i18n_ustring.h>

#include <unicode/ustdio.h>
#include <unicode/measfmt.h>
#include <unicode/measunit.h>
#include <unicode/format.h>
#include <unicode/fmtable.h>
#include <unicode/locid.h>
#include <unicode/uchar.h>

int i18n_measure_format_create(i18n_measure_format_h *measure_format, const char *language, const char *country, i18n_umeasure_width_format_e width_format)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;
    Locale locale(language, country, 0, 0);

    *measure_format = MeasureFormat::MeasureFormat(locale, width_format, status);
    retv_if(measure_format == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_format_create_from_other(i18n_measure_format_h *measure_format, const i18n_measure_format_h other)
{
    retv_if(measure_format == NULL || other == NULL, I18N_ERROR_INVALID_PARAMETER);

    *measure_format = MeasureFormat::MeasureFormat((MeasureFormat *) other);
    retv_if(measure_format == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_measure_format_destroy(i18n_measure_format_h measure_format)
{
    retv_if(measure_format == NULL, I18N_ERROR_INVALID_PARAMETER);

    delete((MeasureFormat *) measure_format);

    return I18N_ERROR_NONE;
}

int i18n_measure_format_clone(i18n_measure_format_h measure_format, i18n_format_h *clone)
{
    retv_if(measure_format == NULL || clone == NULL, I18N_ERROR_INVALID_PARAMETER);

    *clone = ((MeasureFormat *) measure_format)->clone();
    retv_if(clone == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_measure_format_create_currency_format_from_locale(i18n_measure_format_h *measure_format, const char *language, const char *country)
{
    retv_if(measure_format == NULL || language == NULL || country == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;
    Locale locale(language, country, 0, 0);

    *measure_format = MeasureFormat::createCurrencyFormat(locale, status);
    retv_if(*measure_format == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_format_create_currency_format(i18n_measure_format_h *measure_format)
{
    retv_if((measure_format == NULL || language == NULL || country == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure_format = MeasureFormat::createCurrencyFormat(status);
    retv_if(*measure_format == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}
