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
#include <utils_i18n_measure.h>
#include <utils_i18n_private.h>
#include <utils_i18n_ustring.h>

#include <unicode/ustdio.h>
#include <unicode/measure.h>
#include <unicode/measunit.h>
#include <unicode/measfmt.h>
#include <unicode/format.h>
#include <unicode/fmtable.h>
#include <unicode/locid.h>
#include <unicode/uchar.h>

int i18n_measure_create(i18n_measure_h *measure, const i18n_formattable_h formattable, i18n_measure_unit_h measure_unit)
{
    retv_if(measure == NULL || formattable == NULL || measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;

    *measure = new Measure(*((Formattable *) formattable), (MeasureUnit *) measure_unit, status);
    retv_if(*measure == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_measure_create_from_other(i18n_measure_h *measure, const i18n_measure_h other)
{
    retv_if(measure == NULL || other == NULL, I18N_ERROR_INVALID_PARAMETER);

    MeasureUnit other_copy = *((Measure *) other);
    *measure = &other_copy;
    retv_if(*measure == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_measure_clone(i18n_measure_h measure, i18n_measure_h *clone)
{
    retv_if(measure == NULL || clone == NULL, I18N_ERROR_INVALID_PARAMETER);

    *clone = ((Measure *) measure)->clone();
    retv_if(*clone == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_measure_destroy(i18n_measure_h measure)
{
    retv_if(measure == NULL, I18N_ERROR_INVALID_PARAMETER);

    delete((Measure *) measure);

    return I18N_ERROR_NONE;
}

int i18n_measure_get_number(i18n_measure_h measure, i18n_formattable_h *formattable)
{
    retv_if(measure == NULL || formattable == NULL, I18N_ERROR_INVALID_PARAMETER);

    Formattable frmttbl = ((Measure *) measure)->getNumber();
    *formattable = frmttbl.clone();
    retv_if(*formattable == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_measure_get_unit(i18n_measure_h measure, i18n_measure_unit_h *measure_unit)
{
    retv_if(measure == NULL || measure_unit == NULL, I18N_ERROR_INVALID_PARAMETER);

    MeasureUnit mu = ((Measure *) measure)->getUnit();
    *measure_unit = mu.clone();
    retv_if(*measure_unit == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}
