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

#include <utils_i18n_alpha_idx.h>
#include <utils_i18n_private.h>

#include <string.h>
#include <unicode/locid.h>
#include <unicode/alphaindex.h>

int i18n_alpha_idx_create(const char *language, const char *country,
                          i18_alpha_idx_h *index)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(language == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(country == NULL, I18N_ERROR_INVALID_PARAMETER);

    Locale locale(language, country, 0, 0);
    UErrorCode status = U_ZERO_ERROR;

    *index = new AlphabeticIndex(locale, status);
    retv_if(*index == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return _i18n_error_mapping(status);
}

int i18n_alpha_idx_destroy(i18_alpha_idx_h index)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);

    delete ((AlphabeticIndex *) index);

    return I18N_ERROR_NONE;
}

int i18n_alpha_idx_add_labels(i18_alpha_idx_h index,
                              const char *language, const char *country)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(language == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(country == NULL, I18N_ERROR_INVALID_PARAMETER);

    Locale locale(language, country, 0, 0);
    UErrorCode status = U_ZERO_ERROR;

    ((AlphabeticIndex *) index)->addLabels(locale, status);

    return _i18n_error_mapping(status);
}

int i18n_alpha_idx_add_record(i18_alpha_idx_h index, const char *name,
                              const void *data)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(name == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(data == NULL, I18N_ERROR_INVALID_PARAMETER);

    const UnicodeString _name(name);
    UErrorCode status = U_ZERO_ERROR;

    ((AlphabeticIndex *) index)->addRecord(_name, data, status);

    return _i18n_error_mapping(status);
}

int i18n_alpha_idx_get_next_bucket(i18_alpha_idx_h index, bool *success)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;

    if(success != NULL)
        *success = ((AlphabeticIndex *) index)->nextBucket(status);
    else
        ((AlphabeticIndex *) index)->nextBucket(status);

    return _i18n_error_mapping(status);
}

int i18n_alpha_idx_get_next_record(i18_alpha_idx_h index, bool *success)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;

    if(success != NULL)
        *success = ((AlphabeticIndex *) index)->nextRecord(status);
    else
        ((AlphabeticIndex *) index)->nextRecord(status);

    return _i18n_error_mapping(status);
}

int i18n_alpha_idx_get_bucket_record_count(i18_alpha_idx_h index,
                                           int32_t *records_count)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(records_count == NULL, I18N_ERROR_INVALID_PARAMETER);

    *records_count = ((AlphabeticIndex *) index)->getBucketRecordCount();

    return I18N_ERROR_NONE;
}

int i18n_alpha_idx_get_bucket_label(i18_alpha_idx_h index,
                                    char **label)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(label == NULL, I18N_ERROR_INVALID_PARAMETER);

    UnicodeString _label = ((AlphabeticIndex *) index)->getBucketLabel();

    std::string _label_string;
    _label.toUTF8String(_label_string);

    *label = strdup(_label_string.c_str());

    return I18N_ERROR_NONE;
}

int i18n_alpha_idx_get_record_data(i18_alpha_idx_h index,
                                   const void **data)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(data == NULL, I18N_ERROR_INVALID_PARAMETER);

    *data = ((AlphabeticIndex *) index)->getRecordData();
    retv_if(*data == NULL, I18N_ERROR_INDEX_OUTOFBOUNDS);

    return I18N_ERROR_NONE;
}

int i18n_alpha_idx_get_inflow_label(i18_alpha_idx_h index,
                                    char **label)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(label == NULL, I18N_ERROR_INVALID_PARAMETER);

    UnicodeString _label = ((AlphabeticIndex *) index)->getInflowLabel();

    std::string _label_string;
    _label.toUTF8String(_label_string);

    *label = strdup(_label_string.c_str());

    return I18N_ERROR_NONE;
}

int i18n_alpha_idx_set_inflow_label(i18_alpha_idx_h index,
                                    const char *label)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(label == NULL, I18N_ERROR_INVALID_PARAMETER);

    const UnicodeString inflow_label(label);
    UErrorCode status = U_ZERO_ERROR;

    ((AlphabeticIndex *) index)->setInflowLabel(inflow_label, status);

    return _i18n_error_mapping(status);
}

int i18n_alpha_idx_get_overflow_label(i18_alpha_idx_h index,
                                      char **label)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(label == NULL, I18N_ERROR_INVALID_PARAMETER);

    const UnicodeString overflow_label = ((AlphabeticIndex *) index)->getOverflowLabel();

    std::string _label_string;
    overflow_label.toUTF8String(_label_string);

    *label = strdup(_label_string.c_str());

    return I18N_ERROR_NONE;
}

int i18n_alpha_idx_set_overflow_label(i18_alpha_idx_h index,
                                      const char *label)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(label == NULL, I18N_ERROR_INVALID_PARAMETER);

    const UnicodeString overflow_label(label);
    UErrorCode status = U_ZERO_ERROR;

    ((AlphabeticIndex *) index)->setOverflowLabel(overflow_label, status);

    return _i18n_error_mapping(status);
}

int i18n_alpha_idx_get_underflow_label(i18_alpha_idx_h index,
                                       char **label)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(label == NULL, I18N_ERROR_INVALID_PARAMETER);

    const UnicodeString overflow_label = ((AlphabeticIndex *) index)->getOverflowLabel();

    std::string _label_string;
    overflow_label.toUTF8String(_label_string);

    *label = strdup(_label_string.c_str());

    return I18N_ERROR_NONE;
}

int i18n_alpha_idx_set_underflow_label(i18_alpha_idx_h index,
                                       const char *label)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(label == NULL, I18N_ERROR_INVALID_PARAMETER);

    const UnicodeString underflow_label(label);
    UErrorCode status = U_ZERO_ERROR;

    ((AlphabeticIndex *) index)->setOverflowLabel(underflow_label, status);

    return _i18n_error_mapping(status);
}

int i18n_alpha_idx_get_max_label_count(i18_alpha_idx_h index,
                                       int32_t *max_label_count)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(max_label_count == NULL, I18N_ERROR_INVALID_PARAMETER);

    *max_label_count = ((AlphabeticIndex *) index)->getMaxLabelCount();

    return I18N_ERROR_NONE;
}

int i18n_alpha_idx_set_max_label_count(i18_alpha_idx_h index,
                                       int32_t max_label_count)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;

    ((AlphabeticIndex *) index)->setMaxLabelCount(max_label_count, status);

    return _i18n_error_mapping(status);
}

int i18n_alpha_idx_clear_records(i18_alpha_idx_h index)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;

    ((AlphabeticIndex *) index)->clearRecords(status);

    return _i18n_error_mapping(status);
}

int i18n_alpha_idx_get_bucket_count(i18_alpha_idx_h index,
                                    int32_t *bucket_count)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(bucket_count == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;

    *bucket_count = ((AlphabeticIndex *) index)->getBucketCount(status);

    return _i18n_error_mapping(status);
}

int i18n_alpha_idx_get_record_count(i18_alpha_idx_h index,
                                    int32_t *record_count)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(record_count == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;

    *record_count = ((AlphabeticIndex *) index)->getRecordCount(status);

    return _i18n_error_mapping(status);
}

int i18n_alpha_idx_get_bucket_index(i18_alpha_idx_h index,
                                    const char *item_name,
                                    int32_t *bucket_index)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(item_name == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(bucket_index == NULL, I18N_ERROR_INVALID_PARAMETER);

    UnicodeString _item_name(item_name);
    UErrorCode status = U_ZERO_ERROR;

    *bucket_index = ((AlphabeticIndex *) index)->getBucketIndex(_item_name, status);

    return _i18n_error_mapping(status);
}

int i18n_alpha_idx_get_current_bucket_index(i18_alpha_idx_h index,
                                            int32_t *bucket_index)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(bucket_index == NULL, I18N_ERROR_INVALID_PARAMETER);

    *bucket_index = ((AlphabeticIndex *) index)->getBucketIndex();

    return I18N_ERROR_NONE;
}

int i18n_alpha_idx_get_bucket_label_type(i18_alpha_idx_h index,
                                         i18_alpha_idx_label_type_e *type)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(type == NULL, I18N_ERROR_INVALID_PARAMETER);

    *type = (i18_alpha_idx_label_type_e) ((AlphabeticIndex *) index)->getBucketLabelType();

    return I18N_ERROR_NONE;
}

int i18n_alpha_idx_get_record_name(i18_alpha_idx_h index,
                                   char **record_name)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(record_name == NULL, I18N_ERROR_INVALID_PARAMETER);

    const UnicodeString _record_name = ((AlphabeticIndex *) index)->getRecordName();

    std::string _record_name_string;
    _record_name.toUTF8String(_record_name_string);

    *record_name = strdup(_record_name_string.c_str());

    if(_record_name.isEmpty()) {
        return I18N_ERROR_INDEX_OUTOFBOUNDS;
    }

    return I18N_ERROR_NONE;
}

int i18n_alpha_idx_reset_bucket_iter(i18_alpha_idx_h index)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status = U_ZERO_ERROR;

    ((AlphabeticIndex *) index)->resetBucketIterator(status);

    return _i18n_error_mapping(status);
}

int i18n_alpha_idx_reset_record_iter(i18_alpha_idx_h index)
{
    retv_if(index == NULL, I18N_ERROR_INVALID_PARAMETER);

    ((AlphabeticIndex *) index)->resetRecordIterator();

    return I18N_ERROR_NONE;
}
