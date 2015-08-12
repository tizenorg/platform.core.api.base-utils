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

#ifndef __UTILS_I18N_PRIVATE_H__
#define __UTILS_I18N_PRIVATE_H__

#include <stdbool.h>
#include <dlog.h>
#include <utils_i18n_types.h>
#include <unicode/utypes.h>

/**
 * @file utils_i18n_private.h
 * @brief utils_i18n_private
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "BASE_UTILS"

#define I18N_ERR(ret) do { \
    if (ret != I18N_ERROR_NONE) { \
        LOGE("err(%d): %s", ret, get_error_message(ret)); \
    } \
} while (0)

#define ERR(fmt, arg...) LOGE(fmt, ##arg)

#define ret_if(expr) do { \
    if (expr) { \
        ERR("(%s)", #expr); \
        return; \
    } \
} while (0)

#define retv_if(expr, val) do { \
    if (expr) { \
        ERR("(%s)", #expr); \
        return (val); \
    } \
} while (0)

#define retm_if(expr, fmt, arg...) do { \
    if (expr) { \
        ERR(fmt, ##arg); \
        return; \
    } \
} while (0)

#define retvm_if(expr, val, fmt, arg...) do { \
    if (expr) { \
        ERR(fmt, ##arg); \
        return (val); \
    } \
} while (0)

#define retex_if(expr, val, fmt, arg...) do { \
      if(expr) { \
         ERR(fmt, ##arg); \
         val; \
         goto CATCH; \
      } \
} while (0);

#define ERR_MAPPING_REVERSE(BASE_UTILS_ERROR, ICU_ERROR) ICU_ERROR = \
    (UErrorCode)_i18n_error_mapping_reverse((int)BASE_UTILS_ERROR)

#define ERR_MAPPING(ICU_ERROR, BASE_UTILS_ERROR) BASE_UTILS_ERROR = \
    (i18n_error_code_e)_i18n_error_mapping((int)ICU_ERROR)

int _i18n_error_mapping ( int err );
int _i18n_error_mapping_reverse ( int err );

#ifdef __cplusplus
}
#endif

#endif  /* __UTILS_I18N_PRIVATE_H__*/
