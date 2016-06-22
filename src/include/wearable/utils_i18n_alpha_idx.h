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

#ifndef __UTILS_I18N_ALPHA_IDX_H__
#define __UTILS_I18N_ALPHA_IDX_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_alpha_idx.h
 * @version 0.1
 * @brief utils_i18n_alpha_idx
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup CAPI_BASE_UTILS_I18N_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_ALPHA_IDX_MODULE AlphabeticIndex
 * @brief AlphabeticIndex supports the creation of a UI index appropriate for a given language.
 * @section CAPI_BASE_UTILS_I18N_ALPHA_IDX_MODULE_HEADER Required Header
 *          \#include <utils_i18n.h>
 *
 * @section CAPI_BASE_UTILS_I18N_ALPHA_IDX_MODULE_OVERVIEW Overview
 * @details The module can generate a list of labels for use as a UI "index",
 *          that is, a list of clickable characters (or character sequences)
 *          that allow the user to see a segment (bucket) of a larger "target" list.
 *          That is, each label corresponds to a bucket in the target list, where
 *          everything in the bucket is greater than or equal to the character
 *          (according to the locale's collation). Strings can be added to the index;
 *          they will be in sorted order in the right bucket.
 *          The module also supports having buckets for strings before the first (underflow),
 *          after the last (overflow), and between scripts (inflow). For example,
 *          if the index is constructed with labels for Russian and English,
 *          Greek characters would fall into an inflow bucket between the other two scripts.
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_ALPHA_IDX_MODULE
 * @{
 */

/**
 * @brief Creates an alphabetic index object for the specified locale.
 * @remarks The created object should be released by the caller with the
 *          #i18n_alpha_idx_destroy() function.
 *
 * @param[in] language The language of the locale
 * @param[in] country  The country of the locale
 * @param[out] index   The created alphabetic index object
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_alpha_idx_create(const char *language, const char *country,
                          i18_alpha_idx_h *index);

/**
 * @brief Destroys the alphabetic index object.
 *
 * @param[in] index The alphabetic index to be destroyed
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_destroy(i18_alpha_idx_h index);

/**
 * @brief Adds the index characters from a specified locale to the index.
 *
 * @param[in] index    Label will be added to this alphabetic index
 * @param[in] language The language of the locale
 * @param[in] country  The country of the locale
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_add_labels(i18_alpha_idx_h index, const char *language,
                              const char *country);

/**
 * @brief Adds the record to the alphabetic index.
 *
 * @param[in] index Record will be added to this alphabetic index
 * @param[in] name  The display name for the record
 * @param[in] data  An optional pointer to user data associated with this item
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_add_record(i18_alpha_idx_h index, const char *name,
                              const void *data);

/**
 * @brief Sets the next bucket as current bucket in the index.
 *
 * @param[in] index    The alphabetic index, which contains buckets
 * @param[out] success A flag set to @c true if the iteration succeeded,
 *                     or @c false at the end of iteration.
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_next_bucket(i18_alpha_idx_h index, bool *success);

/**
 * @brief Sets the next record as current record in current bucket of the index.
 * @details When i18n_alpha_idx_next_bucket() is called, record iteration is reset
 *          to just before the first record in the new bucket.
 *
 * @param[in] index    The alphabetic index, which contains buckets with records
 * @param[out] success A flag set to @c true if the iteration succeeded,
 *                     or @c false at the end of iteration.
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_next_record(i18_alpha_idx_h index, bool *success);

/**
 * @brief Gets the number of <name, data> records in the current bucket.
 *
 * @param[in] index      The alphabetic index, which contains buckets with records
 * @param[out] n_records Number of <name, data> records in the current bucket
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_get_bucket_record_count(i18_alpha_idx_h index, int32_t *records_count);

/**
 * @brief Gets the name of the label of the current bucket in alphabetic index.
 * @remarks The obtained label should be released by the caller with the free() function.
 *
 * @param[in] index  The alphabetic index, which contains buckets
 * @param[out] label The name of the label of the current bucket
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_get_bucket_label(i18_alpha_idx_h index, char **label);

/**
 * @brief Gets the data pointer of the current record in current bucket in alphabetic index.
 *
 * @param[in] index The alphabetic index, which contains buckets with records
 * @param[out] data The data pointer of the current record
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_INDEX_OUTOFBOUNDS Trying to access the index that is out of bounds
 */
int i18n_alpha_idx_get_record_data(i18_alpha_idx_h index, void **data);

/**
 * @brief Gets the default label used for abbreviated buckets between other index characters.
 * @details For example, consider the labels when Latin and Greek are used: X Y Z ... &#x0391; &#x0392;
 *          &#x0393;.
 * @remarks The obtained label should be released by the caller with the free() function.
 *
 * @param[in] index  The alphabetic index, which contains buckets with records
 * @param[out] label The default label used for abbreviated bucket between other index characters
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_get_inflow_label(i18_alpha_idx_h index, char **label);

/**
 * @brief Sets the default label used for abbreviated buckets between other index characters.
 * @details An inflow label will be automatically inserted if two otherwise-adjacent label characters
 *          are from different scripts, e.g. Latin and Cyrillic, and a third script,
 *          e.g. Greek, sorts between the two. The default inflow character is an ellipsis (...)
 *
 * @param[in] index The alphabetic index, which contains buckets with records
 * @param[in] label The default label used for abbreviated bucket between other index characters
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_set_inflow_label(i18_alpha_idx_h index, const char *label);

/**
 * @brief Gets the special label used for items that sort after the last normal label,
 *        and that would not otherwise have an appropriate label.
 * @remarks The obtained label should be released by the caller with the free() function.
 *
 * @param[in] index  The alphabetic index, which contains buckets with records
 * @param[out] label The special label used for items that sort after the last normal label
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_get_overflow_label(i18_alpha_idx_h index, char **label);

/**
 * @brief Sets the special label used for items that sort after the last normal label,
 *        and that would not otherwise have an appropriate label.
 *
 * @param[in] index The alphabetic index, which contains buckets with records
 * @param[in] label The special label used for items that sort after the last normal label
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_set_overflow_label(i18_alpha_idx_h index, const char *label);

/**
 * @brief Gets the special label used for items that sort before the first normal label,
 *        and that would not otherwise have an appropriate label.
 * @remarks The obtained label should be released by the caller with the free() function.
 *
 * @param[in] index  The alphabetic index, which contains buckets with records
 * @param[out] label The special label used for items that sort before the first normal label
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_get_underflow_label(i18_alpha_idx_h index, char **label);

/**
 * @brief Sets the special label used for items that sort before the first normal label,
 *        and that would not otherwise have an appropriate label.
 *
 * @param[in] index The alphabetic index, which contains buckets with records
 * @param[in] label The special label used for items that sort before the first normal label
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_set_underflow_label(i18_alpha_idx_h index, const char *label);

/**
 * @brief Gets the limit on the number of labels permitted in the index.
 *
 * @param[in] index            The alphabetic index, which contains buckets with records
 * @param[out] max_label_count The maximum number of labels
 *
 * @return @c 0 on success, otherwise a negative error value
 */
int i18n_alpha_idx_get_max_label_count(i18_alpha_idx_h index, int32_t *max_label_count);

/**
 * @brief Gets the limit on the number of labels permitted in the index.
 *
 * @param[in] index           The alphabetic index, which contains buckets with records
 * @param[in] max_label_count The maximum number of labels
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_set_max_label_count(i18_alpha_idx_h index, int32_t max_label_count);

/**
 * @brief Remove all records from the index.
 * @details The set of Buckets, which define the headings under which records are classified,
 *          is not altered.
 *
 * @param[in] index The alphabetic index, which contains buckets with records
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_clear_records(i18_alpha_idx_h index);

/**
 * @brief Gets the number of labels in this index.
 *
 * @param[in] index         The alphabetic index, which contains buckets with records
 * @param[out] bucket_count The number of labels in this index, including any under,
 *                          over or inflow labels
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_get_bucket_count(i18_alpha_idx_h index, int32_t *bucket_count);

/**
 * @brief Gets the total number of records in this index, that is, the number of
 *        <name, data> pairs added.
 *
 * @param[in] index         The alphabetic index, which contains buckets with records
 * @param[out] record_count The number of records in this index, that is,
 *                          the total number of (name, data) items added with
 *                          i18n_alpha_idx_add_record()
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_get_record_count(i18_alpha_idx_h index, int32_t *record_count);

/**
 * @brief Given the name of a record, returns the zero-based index of the bucket
 *        in which the item should appear.
 *
 * @param[in] index         The alphabetic index, which contains buckets with records
 * @param[in] item_name     The name whose bucket position in the index is to be determined
 * @param[out] bucket_index The bucket number for this name
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_get_bucket_index(i18_alpha_idx_h index, const char *item_name, int32_t *bucket_index);

/**
 * @brief Gets the zero based index of the current bucket of this index.
 *
 * @param[in] index         The alphabetic index, which contains buckets with records
 * @param[out] bucket_index The number of current bucket
 *
 * @return @c 0 on success, otherwise a negative error value
 */
int i18n_alpha_idx_get_current_bucket_index(i18_alpha_idx_h index, int32_t *bucket_index);

/**
 * @brief Gets the type of the label for the current bucket.
 *
 * @param[in] index The alphabetic index, which contains buckets with records
 * @param[out] type The alphabetic index label type
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_get_bucket_label_type(i18_alpha_idx_h index,
                                                i18_alpha_idx_label_type_e *type);

/**
 * @brief Gets the name of the current record.
 * @details Returns NULL if the Record iteration position is before first or after the last.
 * @remarks The obtained record_name should be released by the caller with the free() function.
 *
 * @param[in] index        The alphabetic index, which contains buckets with records
 * @param[out] record_name The name of the current index item
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_INDEX_OUTOFBOUNDS Trying to access the index that is out of bounds
 */
int i18n_alpha_idx_get_record_name(i18_alpha_idx_h index, char **record_name);

/**
 * @brief Resets the bucket iteration for this index.
 * @details The next call to i18n_alpha_idx_next_bucket() will restart the iteration at the first label.
 *
 * @param[in] index The alphabetic index, which contains buckets with records
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_reset_bucket_iter(i18_alpha_idx_h index);

/**
 * @brief Resets the record iteration for this index.
 * @details The next call to i18n_alpha_idx_next_record() will restart the iteration at the first label.
 *
 * @param[in] index The alphabetic index, which contains buckets with records
 *
 * @return @c 0 on success, otherwise a negative error value
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_alpha_idx_reset_record_iter(i18_alpha_idx_h index);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __UTILS_I18N_ALPHA_IDX_H__ */
