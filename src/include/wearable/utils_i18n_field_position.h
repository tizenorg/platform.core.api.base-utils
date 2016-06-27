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

#ifndef __UTILS_I18N_FIELD_POSITION_H__
#define __UTILS_I18N_FIELD_POSITION_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_field_position.h
 * @version 0.1
 * @brief utils_i18n_field_position
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup CAPI_BASE_UTILS_I18N_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_FIELD_POSITION_MODULE FieldPosition
 * @brief Field Position is a simple type used by Format module and its submodules to identify fields in formatted output.
 * @section CAPI_BASE_UTILS_I18N_FIELD_POSITION_MODULE_HEADER Required Header
 *        \#include <utils_i18n.h>
 *
 * @section CAPI_BASE_UTILS_I18N_FIELD_POSITION_MODULE_OVERVIEW Overview
 * @details Fields are identified by constants, whose names typically end with _FIELD,
 * defined in the various submodules of Format. Field position keeps track of the position
 * of the field within the formatted output with two indices: the index of the first
 * character of the field and the index of the last character of the field. One version
 * of the format function in the various Format modules requires a Field Position object
 * as an argument. You use this format function to perform partial formatting or to get
 * information about the formatted output (such as the position of a field).
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_FIELD_POSITION_MODULE
 * @{
 */

/**
 * @brief Creates a field position object with a non-specified field.
 * @deatils This function invokes the default constructor.
 * @since_tizen 3.0
 *
 * @param[out] field_position The field position object
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_field_position_create(i18n_field_position_h *field_position);

/**
 * @brief Creates a field position object for the given field.
 * @deatils Fields are identified by constants, whose names typically end with _FIELD,
 *          in the various subclasses of Format.
 * @since_tizen 3.0
 *
 * @param[out] field_position The field position object
 * @param[in] field The field value
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_field_position_create_for_field(i18n_field_position_h *field_position, int32_t field);

/**
 * @brief Creates a field position object from the other field position object.
 * @deatils Fields are identified by constants, whose names typically end with _FIELD,
 *          in the various subclasses of Format.
 * @deatils Function invokes the copy constructor.
 * @since_tizen 3.0
 *
 * @param[out] field position  The created field position object
 * @param[in]  other           The field position object from which the new object is created
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_field_position_create_from_other(i18n_field_position_h *field_position, const i18n_field_position_h other);

/**
 * @brief Destroys the field position object.
 * @since_tizen 3.0
 *
 * @param[in] field_position  The field position object to destroy
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_field_position_destroy(i18n_field_position_h field_position);

/**
 * @brief Creates a clone of the given @a field_position object.
 * @since_tizen 3.0
 *
 * @param[in]  field_position  The field position object from which the new object is created
 * @param[out] clone           The created field position object
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_field_position_clone(i18n_field_position_h field_position, i18n_field_position_h *clone);

/**
 * @brief Retrieves the field identifier.
 * @since_tizen 3.0
 *
 * @param[in]  field_position  The field_position object
 * @param[out] field           The field identifier
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_field_position_get_field(i18n_field_position_h field_position, int32_t *field);

/**
 * @brief Retrieves the index of the first character in the requested field.
 * @since_tizen 3.0
 *
 * @param[in]  field_position  The field position object
 * @param[out] begin_index     The index of the first character in the requested field
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_field_position_get_begin_index(i18n_field_position_h field_position, int32_t *begin_index);

/**
 * @brief Retrieves the index of the character following the last character in the requested field.
 * @since_tizen 3.0
 *
 * @param[in]  field_position  The field position object
 * @param[out] end_index       The index of the character following the last character
 *                             in the requested field
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_field_position_get_end_index(i18n_field_position_h field_position, int32_t *end_index);

/**
 * @brief Sets the field.
 * @since_tizen 3.0
 *
 * @param[in] field_position  The field_position object
 * @param[in]  field             The new value of the field
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_field_position_set_field(i18n_field_position_h field_position, int32_t field);

/**
 * @brief Sets the begin index.
 * @since_tizen 3.0
 *
 * @param[in] field_position  The field_position object
 * @param[in]  begin_index     The new value of the begin index
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_field_position_set_begin_index(i18n_field_position_h field_position, int32_t begin_index);

/**
 * @brief Sets the end index.
 * @since_tizen 3.0
 *
 * @param[in] field_position  The field_position object
 * @param[in]  end_position    The new value of the end index
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_field_position_set_end_index(i18n_field_position_h field_position, int32_t end_index);

#ifdef __cplusplus
}
#endif

#endif /* __UTILS_I18N_FIELD_POSITION_H__*/
