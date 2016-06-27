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

#include <utils_i18n_parse_position.h>
#include <utils_i18n_private.h>

#include <unicode/parsepos.h>

int i18n_parse_position_create(i18n_parse_position_h *parse_position)
{
    retv_if(parse_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    *parse_position = new ParsePosition();
    retv_if(*parse_position == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_parse_position_create_with_index(int32_t new_index, i18n_parse_position_h *parse_position)
{
    retv_if(parse_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    *parse_position = new ParsePosition(new_index);
    retv_if(*parse_position == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_parse_position_destroy(i18n_parse_position_h parse_position)
{
    retv_if(parse_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    delete((ParsePosition *) parse_position);

    return I18N_ERROR_NONE;
}

int i18n_parse_position_clone(i18n_parse_position_h parse_position, i18n_parse_position_h *clone)
{
    retv_if(parse_position == NULL || clone == NULL, I18N_ERROR_INVALID_PARAMETER);

    *clone = ((ParsePosition *) parse_position)->clone();
    retv_if(*clone == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_parse_position_get_index(i18n_parse_position_h parse_position, int32_t *index)
{
    retv_if(parse_position == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);

    *index = ((ParsePosition *) parse_position)->getIndex();

    return I18N_ERROR_NONE;
}

int i18n_parse_position_set_index(i18n_parse_position_h parse_position, int32_t index)
{
    retv_if(parse_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    ((ParsePosition *) parse_position)->setIndex(index);

    return I18N_ERROR_NONE;
}

int i18n_parse_position_set_error_index(i18n_parse_position_h parse_position, int32_t error_index)
{
    retv_if(parse_position == NULL, I18N_ERROR_INVALID_PARAMETER);

    ((ParsePosition *) parse_position)->setErrorIndex(error_index);

    return I18N_ERROR_NONE;
}

int i18n_parse_position_get_error_index(i18n_parse_position_h parse_position, int32_t *error_index)
{
    retv_if(parse_position == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(error_index == NULL, I18N_ERROR_INVALID_PARAMETER);

    *error_index = ((ParsePosition *) parse_position)->getErrorIndex();

    return I18N_ERROR_NONE;
}
