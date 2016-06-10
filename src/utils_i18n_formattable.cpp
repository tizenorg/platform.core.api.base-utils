/*
 * Copyright (c) 2016 Samsung Electronics Co., Ltd All Rights Reserved
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

#include <stdlib.h>

#include <utils_i18n_formattable.h>
#include <utils_i18n_private.h>
#include <unicode/fmtable.h>

int i18n_formattable_create_default(i18n_formattable_h *formattable)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);

    *formattable = new Formattable();
    retv_if(*formattable == NULL, I18N_ERROR_UNKNOWN);

    return I18N_ERROR_NONE;
}

int i18n_formattable_create_with_udate(i18n_udate date, i18n_formattable_h *formattable)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);

    *formattable = new Formattable(date, Formattable::kIsDate);
    retv_if(*formattable == NULL, I18N_ERROR_UNKNOWN);

    return I18N_ERROR_NONE;
}

int i18n_formattable_create_with_double(double d, i18n_formattable_h *formattable)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);

    *formattable = new Formattable(d);
    retv_if(*formattable == NULL, I18N_ERROR_UNKNOWN);

    return I18N_ERROR_NONE;
}

int i18n_formattable_create_with_long(int32_t l, i18n_formattable_h *formattable)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);

    *formattable = new Formattable(l);
    retv_if(*formattable == NULL, I18N_ERROR_UNKNOWN);

    return I18N_ERROR_NONE;
}

int i18n_formattable_create_with_int64(int64_t ll, i18n_formattable_h *formattable)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);

    *formattable = new Formattable(ll);
    retv_if(*formattable == NULL, I18N_ERROR_UNKNOWN);

    return I18N_ERROR_NONE;
}

int i18n_formattable_create_with_char_string(const char *str_to_copy, i18n_formattable_h *formattable)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);

    *formattable = new Formattable(str_to_copy);
    retv_if(*formattable == NULL, I18N_ERROR_UNKNOWN);

    return I18N_ERROR_NONE;
}

int i18n_formattable_create_with_formattable_array(const i18n_formattable_h *array_to_copy, int32_t count, i18n_formattable_h *formattable)
{
    retv_if(array_to_copy == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(count < 0, I18N_ERROR_INVALID_PARAMETER);
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);

    Formattable *f_array = new Formattable[count];

    for(int i=0;i<count;i++)
    {
        retv_if(array_to_copy[i] == NULL, I18N_ERROR_INVALID_PARAMETER);
        f_array[i] = *((Formattable *)array_to_copy[i]);
    }

    *formattable = new Formattable(f_array, count);

    delete[] f_array;

    retv_if(*formattable == NULL, I18N_ERROR_UNKNOWN);

    return I18N_ERROR_NONE;
}

int i18n_formattable_create_with_formattable(const i18n_formattable_h formattable_to_copy, i18n_formattable_h *formattable)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(formattable_to_copy == NULL, I18N_ERROR_INVALID_PARAMETER);

    Formattable formattable_copy = *((Formattable *)formattable_to_copy);

    *formattable = &formattable_copy;

    retv_if(*formattable == NULL, I18N_ERROR_UNKNOWN);

    return I18N_ERROR_NONE;
}

int i18n_formattable_destroy(i18n_formattable_h formattable)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);

    delete ((Formattable *)formattable);

    formattable = NULL;

    return I18N_ERROR_NONE;
}

int i18n_formattable_adopt_array(i18n_formattable_h formattable, i18n_formattable_h *array, int32_t count)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(array == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(count < 0, I18N_ERROR_INVALID_PARAMETER);

    Formattable *f_array = new Formattable[count];

    for(int i=0;i<count;i++)
    {
        retv_if(array[i] == NULL, I18N_ERROR_INVALID_PARAMETER);
        f_array[i] = *((Formattable *)array[i]);
    }

    ((Formattable *) formattable)->adoptArray(f_array, count);

    return I18N_ERROR_NONE;
}

int i18n_formattable_clone(i18n_formattable_h formattable, i18n_formattable_h *clone)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(clone == NULL, I18N_ERROR_INVALID_PARAMETER);

    *clone = ((Formattable *) formattable)->clone();
    retv_if(*clone == NULL, I18N_ERROR_UNKNOWN);

    return I18N_ERROR_NONE;
}

int i18n_formattable_get_array(i18n_formattable_h formattable, i18n_formattable_h **array, int32_t *count)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(array == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(count == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;
    const Formattable *f_array = ((Formattable *) formattable)->getArray(*count, status);

    *array = (i18n_formattable_h *)malloc(*count * sizeof(i18n_formattable_h));

    for(int i=0;i<*count;i++)
    {
        (*array)[i] = (const i18n_formattable_h) &f_array[i];
    }

    return _i18n_error_mapping(status);
}

int i18n_formattable_get_date(i18n_formattable_h formattable, i18n_udate *date)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(date == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;
    *date = (i18n_udate) ((Formattable *) formattable)->getDate(status);

    return _i18n_error_mapping(status);
}

int i18n_formattable_get_double(i18n_formattable_h formattable, double *value)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(value == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;
    *value = ((Formattable *) formattable)->getDouble(status);

    return _i18n_error_mapping(status);
}

int i18n_formattable_get_int64(i18n_formattable_h formattable, int64_t *value)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(value == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;
    *value = ((Formattable *) formattable)->getInt64(status);

    return _i18n_error_mapping(status);
}

int i18n_formattable_get_long(i18n_formattable_h formattable, int32_t *value)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(value == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;
    *value = ((Formattable *) formattable)->getLong(status);

    return _i18n_error_mapping(status);
}

int i18n_formattable_get_string(i18n_formattable_h formattable, char **value)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(value == NULL, I18N_ERROR_INVALID_PARAMETER);

    *value = NULL;

    UnicodeString result;
    UErrorCode status = U_ZERO_ERROR;
    ((Formattable *) formattable)->getString(result, status);

    const UChar *uchar_result = result.getTerminatedBuffer();
    retv_if(uchar_result == NULL, I18N_ERROR_INVALID_FORMAT);

    int32_t ulen = u_strlen(uchar_result);
    retv_if(ulen <= 0, I18N_ERROR_UNKNOWN);

    *value = (char *) malloc(ulen + 1);
    retv_if(*value == NULL, I18N_ERROR_UNKNOWN);

    u_austrcpy(*value, uchar_result);

    return _i18n_error_mapping(status);
}

int i18n_formattable_get_type(i18n_formattable_h formattable, i18n_formattable_type_e *type)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(type == NULL, I18N_ERROR_INVALID_PARAMETER);

    *type = (i18n_formattable_type_e) ((Formattable *) formattable)->getType();

    return I18N_ERROR_NONE;
}

int i18n_formattable_is_numeric(i18n_formattable_h formattable, bool *is_numeric)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(is_numeric == NULL, I18N_ERROR_INVALID_PARAMETER);

    *is_numeric = (bool) ((Formattable *) formattable)->isNumeric();

    return I18N_ERROR_NONE;
}

int i18n_formattable_not_equal(i18n_formattable_h formattable, i18n_formattable_h other, bool *not_equal)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(other == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(not_equal == NULL, I18N_ERROR_INVALID_PARAMETER);

    *not_equal = (bool) (((Formattable *) formattable) != ((Formattable *) other));

    return I18N_ERROR_NONE;
}

int i18n_formattable_equal(i18n_formattable_h formattable, i18n_formattable_h other, bool *equal)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(other == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(equal == NULL, I18N_ERROR_INVALID_PARAMETER);

    *equal = (bool) (((Formattable *) formattable) == ((Formattable *) other));

    return I18N_ERROR_NONE;
}

int i18n_formattable_element_at(i18n_formattable_h formattable, int32_t index, i18n_formattable_h *element)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(index < 0, I18N_ERROR_INDEX_OUTOFBOUNDS);
    retv_if(element == NULL, I18N_ERROR_INVALID_PARAMETER);

    int32_t count;
    UErrorCode status = U_ZERO_ERROR;
    ((Formattable *) formattable)->getArray(count, status);

    retv_if(status == U_INVALID_FORMAT_ERROR, I18N_ERROR_INVALID_FORMAT);
    retv_if(index >= count, I18N_ERROR_INDEX_OUTOFBOUNDS);

    *element = (i18n_formattable_h) &((Formattable *) formattable)[index];

    return _i18n_error_mapping(status);
}

int i18n_formattable_set_array(i18n_formattable_h formattable, const i18n_formattable_h *array, int32_t count)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(array == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(count < 0, I18N_ERROR_INVALID_PARAMETER);

    Formattable *f_array = new Formattable[count];

    for(int i=0;i<count;i++)
    {
        retv_if(array[i] == NULL, I18N_ERROR_INVALID_PARAMETER);
        f_array[i] = *((Formattable *)array[i]);
    }

    ((Formattable *) formattable)->setArray(f_array, count);

    delete[] f_array;

    return I18N_ERROR_NONE;
}

int i18n_formattable_set_date(i18n_formattable_h formattable, i18n_udate d)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);

    ((Formattable *) formattable)->setDate(d);

    return I18N_ERROR_NONE;
}

int i18n_formattable_set_double(i18n_formattable_h formattable, double d)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);

    ((Formattable *) formattable)->setDouble(d);

    return I18N_ERROR_NONE;
}

int i18n_formattable_set_int64(i18n_formattable_h formattable, int64_t ll)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);

    ((Formattable *) formattable)->setInt64(ll);

    return I18N_ERROR_NONE;
}

int i18n_formattable_set_long(i18n_formattable_h formattable, int32_t l)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);

    ((Formattable *) formattable)->setLong(l);

    return I18N_ERROR_NONE;
}

int i18n_formattable_set_string(i18n_formattable_h formattable, const char *string_to_copy)
{
    retv_if(formattable == NULL, I18N_ERROR_INVALID_PARAMETER);

    const UnicodeString stringToCopy(string_to_copy);
    ((Formattable *) formattable)->setString(stringToCopy);

    return I18N_ERROR_NONE;
}
