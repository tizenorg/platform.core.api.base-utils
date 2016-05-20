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

#ifndef __UTILS_I18N_PARSE_POSITION_H__
#define __UTILS_I18N_PARSE_POSITION_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_parse_position.h
 * @version 0.1
 * @brief utils_i18n_parse_position
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup CAPI_BASE_UTILS_I18N_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_PARSE_POSITION_MODULE ParsePosition
 * @brief Parse Position is a simple class used by Format and its subclasses to keep track of the current position during parsing.
 * @section CAPI_BASE_UTILS_I18N_PARSE_POSITION_MODULE_HEADER Required Header
 *        \#include <utils_i18n.h>
 *
 * @section CAPI_BASE_UTILS_I18N_PARSE_POSITION_MODULE_OVERVIEW Overview
 * @details The i18n_format_parse_object() method in the Format classes requires
 * a Parse Position object as an argument.
 * By design, as you parse through a string with different formats, you can use
 * the same Parse Position, since the index parameter records the current position.
 * The Parse Position class is not suitable for subclassing.
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_PARSE_POSITION_MODULE
 * @{
 */

/**
 * @brief Creates a parse position object.
 * @deatils This function invokes the default constructor, the index starts with 0 as default.
 * @since_tizen 3.0
 *
 * @param[out] parse_position  The parse position object
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_parse_position_create(i18n_parse_position_h *parse_position);

/**
 * @brief Creates a parse position object.
 * @deatils This function invokes the default constructor, the index starts with 0 as default.
 * @since_tizen 3.0
 *
 * @param[out] parse_position  The parse position object
 * @param[in]  new_index       The new text offset
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_parse_position_create_with_index(i18n_parse_position_h *parse_position, int32_t new_index);

/**
 * @brief Creates a parse position object from the other parse position object.
 * @deatils Function invokes the copy constructor.
 * @since_tizen 3.0
 *
 * @param[out] parse position  The created parse position object
 * @param[in]  other           The parse position object from which the new object is created
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_parse_position_create_from_other(i18n_parse_position_h *parse_position, const i18n_parse_position_h other);

/**
 * @brief Destroys the parse position object.
 * @since_tizen 3.0
 *
 * @param[in] parse_position  The parse position object to destroy
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_parse_position_destroy(i18n_parse_position_h parse_position);

/**
 * @brief Creates a polymorphic clone of the given @a parse_position object.
 * @since_tizen 3.0
 *
 * @param[in]  parse_position  The parse position object from which the new object is created
 * @param[out] clone           The created parse position object
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_OUT_OF_MEMORY Out of memory
 */
int i18n_parse_position_clone(i18n_parse_position_h parse_position, i18n_parse_position_h *clone);

/**
 * @brief Retrieves the current parse position.
 * @details On input to a parse method, this is the index of the character
 *          at which parsing will begin; on output, it is the index of the character
 *          following the last character parsed.
 * @since_tizen 3.0
 *
 * @param[in]  parse_position  The parse position object
 * @param[out] index           The current index
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_parse_position_get_index(i18n_parse_position_h parse_position, int32_t *index);

/**
 * @brief Sets the current parse position.
 * @since_tizen 3.0
 *
 * @param[in] parse_position  The parse position object
 * @param[in] index           The new index
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_parse_position_set_index(i18n_parse_position_h *parse_position, int32_t index);

/**
 * @brief Sets the index at which a parse error occurred.
 * @details Formatters should set this before returning an error code
 *          from their parse_object() method. The default value is -1
 *          if this is not set.
 * @since_tizen 3.0
 *
 * @param[in] parse_position  The parse position object
 * @param[in] error_index     The error index
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_parse_position_set_error_index(i18n_parse_position_h *parse_position, int32_t error_index);

/**
 * @brief Retrieves the index at which an error occurred, or -1 if the error index
 *        has not been set.
 * @since_tizen 3.0
 *
 * @param[in]  parse_position  The parse position object
 * @param[out] error_index     The index at which an error occurred
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_parse_position_get_error_index(i18n_parse_position_h parse_position, int32_t *error_index);

#ifdef __cplusplus
}
#endif

#endif /* __UTILS_I18N_PARSE_POSITION_H__*/
