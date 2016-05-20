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
#include <utils_i18n_field_position.h>
#include <utils_i18n_private.h>
#include <utils_i18n_ustring.h>

#include <unicode/ustdio.h>
#include <unicode/fieldpos.h>

int i18n_field_position_create(i18n_field_position_h *field_position)
{
    retv_if(field_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    *field_position = new FieldPosition();
    retv_if(*field_position == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_field_position_create_for_field(i18n_field_position_h *field_position, int32_t field)
{
    retv_if(field_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    *field_position = new FieldPosition(field);
    retv_if(*field_position == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}


int i18n_field_position_create_from_other(i18n_field_position_h *field_position, const i18n_field_position_h other)
{
    retv_if(field_position == NULL || other == NULL, I18N_ERROR_INVALID_PARAMETER);

    FieldPosition other_copy = *((FieldPosition *) other);
    *field_position = &other_copy;
    retv_if(*field_position == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_field_position_destroy(i18n_field_position_h field_position)
{
    retv_if(field_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    delete((FieldPosition *) field_position);

    return I18N_ERROR_NONE;
}

int i18n_field_position_clone(i18n_field_position_h field_position, i18n_field_position_h *clone)
{
    retv_if(field_position == NULL || clone == NULL, I18N_ERROR_INVALID_PARAMETER);

    *clone = ((FieldPosition *) field_position)->clone();
    retv_if(*clone == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_field_position_get_field(i18n_field_position_h field_position, int32_t *field)
{
    retv_if(field_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    *field = ((FieldPosition *) field_position)->getField();

    return I18N_ERROR_NONE;
}

int i18n_field_position_get_begin_index(i18n_field_position_h field_position, int32_t *begin_index)
{
    retv_if(field_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    *begin_index = ((FieldPosition *) field_position)->getBeginIndex();

    return I18N_ERROR_NONE;
}

int i18n_field_position_get_end_index(i18n_field_position_h field_position, int32_t *end_index)
{
    retv_if(field_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    *end_index = ((FieldPosition *) field_position)->getEndIndex();

    return I18N_ERROR_NONE;
}

int i18n_field_position_set_field(i18n_field_position_h *field_position, int32_t field)
{
    retv_if(field_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    ((FieldPosition *) field_position)->setField(field);

    return I18N_ERROR_NONE;
}

int i18n_field_position_set_begin_index(i18n_field_position_h *field_position, int32_t begin_index)
{
    retv_if(field_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    ((FieldPosition *) field_position)->setBeginIndex(begin_index);

    return I18N_ERROR_NONE;
}

int i18n_field_position_set_end_index(i18n_field_position_h *field_position, int32_t end_index)
{
    retv_if(field_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    ((FieldPosition *) field_position)->setEndIndex(end_index);

    return I18N_ERROR_NONE;
}
