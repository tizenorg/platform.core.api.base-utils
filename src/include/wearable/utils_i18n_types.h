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
 *
 * Copyright (C) 1999-2012, International Business Machines
 * Corporation and others.  All Rights Reserved.
 */



#ifndef __UTILS_I18N_TYPES_H__
#define __UTILS_I18N_TYPES_H__

#include <inttypes.h>
#include <tizen.h>
#include <wchar.h>

/**
 * @file utils_i18n_types.h
 * @version 0.1
 * @brief utils_i18n_types
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_MODULE
 * @{
 */

/**
 * @brief Enumeration for error codes to replace exception handlings.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_ERROR_NONE                         = TIZEN_ERROR_NONE,                   /**< No error, no warning */
    I18N_ERROR_MISSING_RESOURCE             = TIZEN_ERROR_UTILITY_ICU | 0x01,     /**< The requested resource cannot be found */
    I18N_ERROR_INVALID_FORMAT               = TIZEN_ERROR_UTILITY_ICU | 0x02,     /**< Data format is not what is expected */
    I18N_ERROR_FILE_ACCESS                  = TIZEN_ERROR_UTILITY_ICU | 0x03,     /**< The requested file cannot be found */
    I18N_ERROR_INTERNAL_PROGRAM             = TIZEN_ERROR_UTILITY_ICU | 0x04,     /**< Indicates a bug in the library code */
    I18N_ERROR_OUT_OF_MEMORY                = TIZEN_ERROR_OUT_OF_MEMORY,          /**< Out of memory */
    I18N_ERROR_INDEX_OUTOFBOUNDS            = TIZEN_ERROR_UTILITY_ICU | 0x05,     /**< Trying to access the index that is out of bounds */
    I18N_ERROR_INVALID_CHAR_FOUND           = TIZEN_ERROR_UTILITY_ICU | 0x06,     /**< Character conversion: Unmappable input sequence. In other APIs: Invalid character */
    I18N_ERROR_BUFFER_OVERFLOW              = TIZEN_ERROR_UTILITY_ICU | 0x07,     /**< A result would not fit in the supplied buffer */
    I18N_ERROR_NOT_SUPPORTED                = TIZEN_ERROR_NOT_SUPPORTED,          /**< Requested operation is not supported in the current context */
    I18N_ERROR_COLLATOR_VERSION_MISMATCH    = TIZEN_ERROR_UTILITY_ICU | 0x08,     /**< Collator version is not compatible with the base version */
    I18N_ERROR_USELESS_COLLATOR             = TIZEN_ERROR_UTILITY_ICU | 0x09,     /**< Collator is options only and no base is specified */
    I18N_ERROR_NO_WRITE_PERMISSION          = TIZEN_ERROR_UTILITY_ICU | 0x0A,     /**< Attempt to modify read-only or constant data */
    I18N_ERROR_RESOURCE_TYPE_MISMATCH       = TIZEN_ERROR_UTILITY_ICU | 0x0B,     /**< An operation is requested over a resource that does not support it */
    I18N_ERROR_TOO_MANY_ALIASES             = TIZEN_ERROR_UTILITY_ICU | 0x0C,     /**< Too many aliases in the path to the requested resource  */
    I18N_ERROR_INVALID_PARAMETER            = TIZEN_ERROR_INVALID_PARAMETER,      /**< Invalid function parameter */
    I18N_ERROR_PERMISSION_DENIED            = TIZEN_ERROR_PERMISSION_DENIED,      /**< Permission denied */

    I18N_ERROR_MESSAGE_PARSE                = TIZEN_ERROR_UTILITY_ICU | 0x0D,     /**< Unable to parse a message (message format). @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_PARSE                        = TIZEN_ERROR_UTILITY_ICU | 0x0E,     /**< Equivalent to Java ParseException. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_TRUNCATED_CHAR_FOUND         = TIZEN_ERROR_UTILITY_ICU | 0x0F,     /**< Character conversion: Incomplete input sequence. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_ILLEGAL_CHAR_FOUND           = TIZEN_ERROR_UTILITY_ICU | 0x10,     /**< Character conversion: Illegal input sequence/combination of input units. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_INVALID_TABLE_FORMAT         = TIZEN_ERROR_UTILITY_ICU | 0x11,     /**< Conversion table file found, but corrupted. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_INVALID_TABLE_FILE           = TIZEN_ERROR_UTILITY_ICU | 0x12,     /**< Conversion table file not found. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_ILLECAL_ESCAPE_SEQUENCE      = TIZEN_ERROR_UTILITY_ICU | 0x13,     /**< ISO-2022 illlegal escape sequence. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_UNSUPPORTED_ESCAPE_SEQUENCE  = TIZEN_ERROR_UTILITY_ICU | 0x14,     /**< ISO-2022 unsupported escape sequence. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_NO_SPACE_AVAILABLE           = TIZEN_ERROR_UTILITY_ICU | 0x15,     /**< No space available for in-buffer expansion for Arabic shaping. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_CE_NOT_FOUND                 = TIZEN_ERROR_UTILITY_ICU | 0x16,     /**< Currently used only while setting variable top, but can be used generally. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_PRIMARY_TOO_LONG             = TIZEN_ERROR_UTILITY_ICU | 0x17,     /**< User tried to set variable top to a primary that is longer than two bytes. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_STATE_TOO_OLD                = TIZEN_ERROR_UTILITY_ICU | 0x18,     /**< ICU cannot construct a service from this state, as it is no longer supported. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_ENUM_OUT_OF_SYNC             = TIZEN_ERROR_UTILITY_ICU | 0x19,     /**< UEnumeration out of sync with underlying collection. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_INVARIANT_CONVERSION         = TIZEN_ERROR_UTILITY_ICU | 0x1A,     /**< Unable to convert a UChar* string to char* with the invariant converter. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_INVALID_STATE                = TIZEN_ERROR_UTILITY_ICU | 0x1B,     /**< Requested operation can not be completed with ICU in its current state. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_MALFORMED_SET                = TIZEN_ERROR_UTILITY_ICU | 0x1C,     /**< A UnicodeSet pattern is invalid. @if MOBILE (Since 2.3.1) @endif*/
    I18N_WARNING_STRING_NOT_TERMINATED      = TIZEN_ERROR_UTILITY_ICU | 0x1D,     /**< String not terminated with NULL. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_STD3_ASCII_RULES             = TIZEN_ERROR_UTILITY_ICU | 0x1E,     /**< Argument does not satisfy STD3 rules. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_UNASSIGNED                   = TIZEN_ERROR_UTILITY_ICU | 0x1F,     /**< Unassigned code points are found. @if MOBILE (Since 2.3.1) @endif*/
    I18N_WARNING_SORT_KEY_TOO_SHORT         = TIZEN_ERROR_UTILITY_ICU | 0x20,     /**< Number of levels requested in getBound is higher than the number of levels in the sort key. @if MOBILE (Since 2.3.1) @endif*/
    I18N_ERROR_UNKNOWN                      = TIZEN_ERROR_UNKNOWN,                /**< Unknown error. @if MOBILE (Since 2.3.1) @endif*/
} i18n_error_code_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UCHAR_MODULE
 * @{
 */

#define I18N_U_MASK(x)                        ((uint32_t)1<<(x)) /**< Get a single-bit bit set (a flag) from a bit number 0..31. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/

#define I18N_U_GC_CN_MASK                     I18N_U_MASK(I18N_UCHAR_U_GENERAL_OTHER_TYPES)     /**<U_GC_XX_MASK constants are bit flags corresponding to Unicode general category values. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_LU_MASK                     I18N_U_MASK(I18N_UCHAR_U_UPPERCASE_LETTER)        /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_LL_MASK                     I18N_U_MASK(I18N_UCHAR_U_LOWERCASE_LETTER)        /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_LT_MASK                     I18N_U_MASK(I18N_UCHAR_U_TITLECASE_LETTER)        /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_LM_MASK                     I18N_U_MASK(I18N_UCHAR_U_MODIFIER_LETTER)         /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_LO_MASK                     I18N_U_MASK(I18N_UCHAR_U_OTHER_LETTER)            /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_MN_MASK                     I18N_U_MASK(I18N_UCHAR_U_NON_SPACING_MARK)        /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_ME_MASK                     I18N_U_MASK(I18N_UCHAR_U_ENCLOSING_MARK)          /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_MC_MASK                     I18N_U_MASK(I18N_UCHAR_U_COMBINING_SPACING_MARK)  /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_ND_MASK                     I18N_U_MASK(I18N_UCHAR_U_DECIMAL_DIGIT_NUMBER)    /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_NL_MASK                     I18N_U_MASK(I18N_UCHAR_U_LETTER_NUMBER)           /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_NO_MASK                     I18N_U_MASK(I18N_UCHAR_U_OTHER_NUMBER)            /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_ZS_MASK                     I18N_U_MASK(I18N_UCHAR_U_SPACE_SEPARATOR)         /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_ZL_MASK                     I18N_U_MASK(I18N_UCHAR_U_LINE_SEPARATOR)          /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_ZP_MASK                     I18N_U_MASK(I18N_UCHAR_U_PARAGRAPH_SEPARATOR)     /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_CC_MASK                     I18N_U_MASK(I18N_UCHAR_U_CONTROL_CHAR)            /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_CF_MASK                     I18N_U_MASK(I18N_UCHAR_U_FORMAT_CHAR)             /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_CO_MASK                     I18N_U_MASK(I18N_UCHAR_U_PRIVATE_USE_CHAR)        /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_CS_MASK                     I18N_U_MASK(I18N_UCHAR_U_SURROGATE)               /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_PD_MASK                     I18N_U_MASK(I18N_UCHAR_U_DASH_PUNCTUATION)        /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_PS_MASK                     I18N_U_MASK(I18N_UCHAR_U_START_PUNCTUATION)       /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_PE_MASK                     I18N_U_MASK(I18N_UCHAR_U_END_PUNCTUATION)         /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_PC_MASK                     I18N_U_MASK(I18N_UCHAR_U_CONNECTOR_PUNCTUATION)   /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_PO_MASK                     I18N_U_MASK(I18N_UCHAR_U_OTHER_PUNCTUATION)       /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_SM_MASK                     I18N_U_MASK(I18N_UCHAR_U_MATH_SYMBOL)             /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_SC_MASK                     I18N_U_MASK(I18N_UCHAR_U_CURRENCY_SYMBOL)         /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_SK_MASK                     I18N_U_MASK(I18N_UCHAR_U_MODIFIER_SYMBOL)         /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_SO_MASK                     I18N_U_MASK(I18N_UCHAR_U_OTHER_SYMBOL)            /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_PI_MASK                     I18N_U_MASK(I18N_UCHAR_U_INITIAL_PUNCTUATION)     /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_PF_MASK                     I18N_U_MASK(I18N_UCHAR_U_FINAL_PUNCTUATION)       /**<Mask constant for a #i18n_uchar_category_e. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_L_MASK                      (I18N_U_GC_LU_MASK|I18N_U_GC_LL_MASK|I18N_U_GC_LT_MASK|I18N_U_GC_LM_MASK|I18N_U_GC_LO_MASK)   /**<Mask constant for multiple #i18n_uchar_category_e bits (L Letters). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_LC_MASK                     (I18N_U_GC_LU_MASK|I18N_U_GC_LL_MASK|I18N_U_GC_LT_MASK)        /**<Mask constant for multiple #i18n_uchar_category_e bits (LC Cased Letters). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_M_MASK                      (I18N_U_GC_MN_MASK|I18N_U_GC_ME_MASK|I18N_U_GC_MC_MASK)        /**<Mask constant for multiple #i18n_uchar_category_e bits (M Marks). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_N_MASK                      (I18N_U_GC_ND_MASK|I18N_U_GC_NL_MASK|I18N_U_GC_NO_MASK)        /**<Mask constant for multiple #i18n_uchar_category_e bits (N Numbers). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_Z_MASK                      (I18N_U_GC_ZS_MASK|I18N_U_GC_ZL_MASK|I18N_U_GC_ZP_MASK)        /**<Mask constant for multiple #i18n_uchar_category_e bits (Z Separators). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_C_MASK                      (I18N_U_GC_CN_MASK|I18N_U_GC_CC_MASK|I18N_U_GC_CF_MASK|I18N_U_GC_CO_MASK|I18N_U_GC_CS_MASK)        /**<Mask constant for multiple #i18n_uchar_category_e bits (C Others). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_P_MASK                      (I18N_U_GC_PD_MASK|I18N_U_GC_PS_MASK|I18N_U_GC_PE_MASK|I18N_U_GC_PC_MASK|I18N_U_GC_PO_MASK|I18N_U_GC_PI_MASK|I18N_U_GC_PF_MASK)   /**<Mask constant for multiple #i18n_uchar_category_e bits (P Punctuation). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_U_GC_S_MASK                      (I18N_U_GC_SM_MASK|I18N_U_GC_SC_MASK|I18N_U_GC_SK_MASK|I18N_U_GC_SO_MASK)         /**<Mask constant for multiple #i18n_uchar_category_e bits (S Symbols). @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif   */

#define I18N_U_NO_NUMERIC_VALUE               ((double)-123456789.)         /**<Special value that is returned by i18n_uchar_get_numeric_value()(not implemented yet) when no numeric value is defined for a code point. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif  */

#define I18N_U_GET_GC_MASK(c)                 I18N_U_MASK(u_charType(c))    /**<Get a single-bit bit set for the general category of a character. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif  */

/**
 * @brief Option value for case folding: use default mappings defined in CaseFolding.txt.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 */
#define I18N_U_FOLD_CASE_DEFAULT 0

/**
 * @brief Option value for case folding: \n
 *        Use the modified set of mappings provided in CaseFolding.txt to handle dotted I and dotless i appropriately for Turkic languages (tr, az).\n
 *        Before Unicode 3.2, CaseFolding.txt contains mappings marked with 'I' that are to be included for default mappings and excluded for the Turkic-specific mappings.\n
 *        Unicode 3.2 CaseFolding.txt instead contains mappings marked with 'T' that are to be excluded for default mappings and included for the Turkic-specific mappings.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
#define I18N_U_FOLD_CASE_EXCLUDE_SPECIAL_I 1


/**
 * @brief DONE is returned by i18n_usearch_previous() and i18n_usearch_next() after all valid matches have been returned,
 *        and by, i18n_usearch_first() and i18n_usearch_last() if there are no matches at all.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
#define I18N_USEARCH_DONE                     -1


#if !defined(U_WCHAR_IS_UTF16) && !defined(U_WCHAR_IS_UTF32)
#   ifdef __STDC_ISO_10646__
#       if (U_SIZEOF_WCHAR_T==2)
#           define U_WCHAR_IS_UTF16
#       elif (U_SIZEOF_WCHAR_T==4)
#           define  U_WCHAR_IS_UTF32
#       endif
#   elif defined __UCS2__
#       if (U_PF_OS390 <= U_PLATFORM && U_PLATFORM <= U_PF_OS400) && (U_SIZEOF_WCHAR_T==2)
#           define U_WCHAR_IS_UTF16
#       endif
#   elif defined(__UCS4__) || (U_PLATFORM == U_PF_OS400 && defined(__UTF32__))
#       if (U_SIZEOF_WCHAR_T==4)
#           define U_WCHAR_IS_UTF32
#       endif
#   elif U_PLATFORM_IS_DARWIN_BASED || (U_SIZEOF_WCHAR_T==4 && U_PLATFORM_IS_LINUX_BASED)
#       define U_WCHAR_IS_UTF32
#   elif U_PLATFORM_HAS_WIN32_API
#       define U_WCHAR_IS_UTF16
#   endif
#endif
#define U_SIZEOF_UCHAR 2

/**
 * @brief i18n_uchar.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
#if defined(UCHAR_TYPE)
    typedef UCHAR_TYPE i18n_uchar;
/* Not #elif U_HAVE_CHAR16_T -- because that is type-incompatible with pre-C++11 callers
    typedef char16_t i18n_uchar;  */
#elif U_SIZEOF_WCHAR_T==2
    typedef wchar_t i18n_uchar;
#elif defined(__CHAR16_TYPE__)
    typedef __CHAR16_TYPE__ i18n_uchar;
#else
    typedef uint16_t i18n_uchar;
#endif


/**
 * @brief i18n_uchar32.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef int32_t i18n_uchar32;
/**
 * @brief i18n_ubool.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef int8_t i18n_ubool;

/**
 * @brief Enumeration of constants for Unicode properties.
 *        The properties APIs are intended to reflect Unicode properties as defined in the Unicode Character Database (UCD) and Unicode Technical Reports (UTR).
 *        For details about the properties see http://www.unicode.org/ucd/ . For names of Unicode properties see the UCD file PropertyAliases.txt.
 *
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UCHAR_ALPHABETIC                      = 0,                                    /**<  */

    I18N_UCHAR_BINARY_START                    = I18N_UCHAR_ALPHABETIC,                /**<  */
    I18N_UCHAR_ASCII_HEX_DIGIT,                                                        /**<  */
    I18N_UCHAR_BIDI_CONTROL,                                                           /**<  */
    I18N_UCHAR_BIDI_MIRRORED,                                                          /**<  */
    I18N_UCHAR_DASH,                                                                   /**<  */
    I18N_UCHAR_DEFAULT_IGNORABLE_CODE_POINT,                                           /**<  */
    I18N_UCHAR_DEPRECATED,                                                             /**<  */
    I18N_UCHAR_DIACRITIC,                                                              /**<  */
    I18N_UCHAR_EXTENDER,                                                               /**<  */
    I18N_UCHAR_FULL_COMPOSITION_EXCLUSION,                                             /**<  */
    I18N_UCHAR_GRAPHEME_BASE,                                                          /**<  */
    I18N_UCHAR_GRAPHEME_EXTEND,                                                        /**<  */
    I18N_UCHAR_GRAPHEME_LINK,                                                          /**<  */
    I18N_UCHAR_HEX_DIGIT,                                                              /**<  */
    I18N_UCHAR_HYPHEN,                                                                 /**<  */
    I18N_UCHAR_ID_CONTINUE,                                                            /**<  */
    I18N_UCHAR_ID_START,                                                               /**<  */
    I18N_UCHAR_IDEOGRAPHIC,                                                            /**<  */
    I18N_UCHAR_IDS_BINARY_OPERATOR,                                                    /**<  */
    I18N_UCHAR_IDS_TRINARY_OPERATOR,                                                   /**<  */
    I18N_UCHAR_JOIN_CONTROL,                                                           /**<  */
    I18N_UCHAR_LOGICAL_ORDER_EXCEPTION,                                                /**<  */
    I18N_UCHAR_LOWERCASE,                                                              /**<  */
    I18N_UCHAR_MATH,                                                                   /**<  */
    I18N_UCHAR_NONCHARACTER_CODE_POINT,                                                /**<  */
    I18N_UCHAR_QUOTATION_MARK,                                                         /**<  */
    I18N_UCHAR_RADICAL,                                                                /**<  */
    I18N_UCHAR_SOFT_DOTTED,                                                            /**<  */
    I18N_UCHAR_TERMINAL_PUNCTUATION,                                                   /**<  */
    I18N_UCHAR_UNIFIED_IDEOGRAPH,                                                      /**<  */
    I18N_UCHAR_UPPERCASE,                                                              /**<  */
    I18N_UCHAR_WHITE_SPACE,                                                            /**<  */
    I18N_UCHAR_XID_CONTINUE,                                                           /**<  */
    I18N_UCHAR_XID_START,                                                              /**<  */
    I18N_UCHAR_CASE_SENSITIVE,                                                         /**<  */
    I18N_UCHAR_S_TERM,                                                                 /**<  */
    I18N_UCHAR_VARIATION_SELECTOR,                                                     /**<  */
    I18N_UCHAR_NFD_INERT,                                                              /**<  */
    I18N_UCHAR_NFKD_INERT,                                                             /**<  */
    I18N_UCHAR_NFC_INERT,                                                              /**<  */
    I18N_UCHAR_NFKC_INERT,                                                             /**<  */
    I18N_UCHAR_SEGMENT_STARTER,                                                        /**<  */
    I18N_UCHAR_PATTERN_SYNTAX,                                                         /**<  */
    I18N_UCHAR_PATTERN_WHITE_SPACE,                                                    /**<  */
    I18N_UCHAR_POSIX_ALNUM,                                                            /**<  */
    I18N_UCHAR_POSIX_BLANK,                                                            /**<  */
    I18N_UCHAR_POSIX_GRAPH,                                                            /**<  */
    I18N_UCHAR_POSIX_PRINT,                                                            /**<  */
    I18N_UCHAR_POSIX_XDIGIT,                                                           /**<  */
    I18N_UCHAR_CASED,                                                                  /**<  */
    I18N_UCHAR_CASE_IGNORABLE,                                                         /**<  */
    I18N_UCHAR_CHANGES_WHEN_LOWERCASED,                                                /**<  */
    I18N_UCHAR_CHANGES_WHEN_UPPERCASED,                                                /**<  */
    I18N_UCHAR_CHANGES_WHEN_TITLECASED,                                                /**<  */
    I18N_UCHAR_CHANGES_WHEN_CASEFOLDED,                                                /**<  */
    I18N_UCHAR_CHANGES_WHEN_CASEMAPPED,                                                /**<  */
    I18N_UCHAR_CHANGES_WHEN_NFKC_CASEFOLDED,                                           /**<  */
    I18N_UCHAR_BINARY_LIMIT,                                                           /**<  */

    I18N_UCHAR_BIDI_CLASS                      = 0x1000,                               /**<  */

    I18N_UCHAR_INT_START                       = I18N_UCHAR_BIDI_CLASS,                /**<  */
    I18N_UCHAR_BLOCK,                                                                  /**<  */
    I18N_UCHAR_CANONICAL_COMBINING_CLASS,                                              /**<  */
    I18N_UCHAR_DECOMPOSITION_TYPE,                                                     /**<  */
    I18N_UCHAR_EAST_ASIAN_WIDTH,                                                       /**<  */
    I18N_UCHAR_GENERAL_CATEGORY,                                                       /**<  */
    I18N_UCHAR_JOINING_GROUP,                                                          /**<  */
    I18N_UCHAR_JOINING_TYPE,                                                           /**<  */
    I18N_UCHAR_LINE_BREAK,                                                             /**<  */
    I18N_UCHAR_NUMERIC_TYPE,                                                           /**<  */
    I18N_UCHAR_SCRIPT,                                                                 /**<  */
    I18N_UCHAR_HANGUL_SYLLABLE_TYPE,                                                   /**<  */
    I18N_UCHAR_NFD_QUICK_CHECK,                                                        /**<  */
    I18N_UCHAR_NFKD_QUICK_CHECK,                                                       /**<  */
    I18N_UCHAR_NFC_QUICK_CHECK,                                                        /**<  */
    I18N_UCHAR_NFKC_QUICK_CHECK,                                                       /**<  */
    I18N_UCHAR_LEAD_CANONICAL_COMBINING_CLASS,                                         /**<  */
    I18N_UCHAR_TRAIL_CANONICAL_COMBINING_CLASS,                                        /**<  */
    I18N_UCHAR_GRAPHEME_CLUSTER_BREAK,                                                 /**<  */
    I18N_UCHAR_SENTENCE_BREAK,                                                         /**<  */
    I18N_UCHAR_WORD_BREAK,                                                             /**<  */
    I18N_UCHAR_BIDI_PAIRED_BRACKET_TYPE,                                               /**<  */
    I18N_UCHAR_INT_LIMIT,                                                              /**<  */

    I18N_UCHAR_GENERAL_CATEGORY_MASK           = 0x2000,                               /**<  */

    I18N_UCHAR_MASK_START                      = I18N_UCHAR_GENERAL_CATEGORY_MASK,     /**<  */
    I18N_UCHAR_MASK_LIMIT,                                                             /**<  */

    I18N_UCHAR_NUMERIC_VALUE                   = 0x3000,                               /**<  */
    I18N_UCHAR_DOUBLE_START                    = I18N_UCHAR_NUMERIC_VALUE,             /**<  */
    I18N_UCHAR_DOUBLE_LIMIT,                                                           /**<  */

    I18N_UCHAR_AGE                             = 0x4000,                               /**<  */
    I18N_UCHAR_STRING_START                    = I18N_UCHAR_AGE,                       /**<  */
    I18N_UCHAR_BIDI_MIRRORING_GLYPH,                                                   /**<  */
    I18N_UCHAR_CASE_FOLDING,                                                           /**<  */

    I18N_UCHAR_LOWERCASE_MAPPING               = 0x4004,                               /**<  */
    I18N_UCHAR_NAME,                                                                   /**<  */
    I18N_UCHAR_SIMPLE_CASE_FOLDING,                                                    /**<  */
    I18N_UCHAR_SIMPLE_LOWERCASE_MAPPING,                                               /**<  */
    I18N_UCHAR_SIMPLE_TITLECASE_MAPPING,                                               /**<  */
    I18N_UCHAR_SIMPLE_UPPERCASE_MAPPING,                                               /**<  */
    I18N_UCHAR_TITLECASE_MAPPING,                                                      /**<  */

    I18N_UCHAR_UPPERCASE_MAPPING               = 0x400C,                               /**<  */
    I18N_UCHAR_BIDI_PAIRED_BRACKET,                                                    /**<  */
    I18N_UCHAR_STRING_LIMIT,                                                           /**<  */

    I18N_UCHAR_SCRIPT_EXTENSIONS               = 0x7000,                               /**<  */
    I18N_UCHAR_OTHER_PROPERTY_START            = I18N_UCHAR_SCRIPT_EXTENSIONS,         /**<  */
    I18N_UCHAR_OTHER_PROPERTY_LIMIT,                                                   /**<  */
    I18N_UCHAR_INVALID_CODE                    = -1                                    /**<  */
} i18n_uchar_uproperty_e;

/**
 * @brief Constants for Unicode blocks, see the Unicode Data file Blocks.txt.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 */
typedef enum {
    I18N_UCHAR_UBLOCK_NO_BLOCK,                                                  /**<  */
    I18N_UCHAR_UBLOCK_BASIC_LATIN,                                               /**<  */
    I18N_UCHAR_UBLOCK_LATIN_1_SUPPLEMENT,                                        /**<  */
    I18N_UCHAR_UBLOCK_LATIN_EXTENDED_A,                                          /**<  */
    I18N_UCHAR_UBLOCK_LATIN_EXTENDED_B,                                          /**<  */
    I18N_UCHAR_UBLOCK_IPA_EXTENSIONS,                                            /**<  */
    I18N_UCHAR_UBLOCK_SPACING_MODIFIER_LETTERS,                                  /**<  */
    I18N_UCHAR_UBLOCK_COMBINING_DIACRITICAL_MARKS,                               /**<  */
    I18N_UCHAR_UBLOCK_GREEK,                                                     /**<  */
    I18N_UCHAR_UBLOCK_CYRILLIC,                                                  /**<  */
    I18N_UCHAR_UBLOCK_ARMENIAN,                                                  /**<  */
    I18N_UCHAR_UBLOCK_HEBREW,                                                    /**<  */
    I18N_UCHAR_UBLOCK_ARABIC,                                                    /**<  */
    I18N_UCHAR_UBLOCK_SYRIAC,                                                    /**<  */
    I18N_UCHAR_UBLOCK_THAANA,                                                    /**<  */
    I18N_UCHAR_UBLOCK_DEVANAGARI,                                                /**<  */
    I18N_UCHAR_UBLOCK_BENGALI,                                                   /**<  */
    I18N_UCHAR_UBLOCK_GURMUKHI,                                                  /**<  */
    I18N_UCHAR_UBLOCK_GUJARATI,                                                  /**<  */
    I18N_UCHAR_UBLOCK_ORIYA,                                                     /**<  */
    I18N_UCHAR_UBLOCK_TAMIL,                                                     /**<  */
    I18N_UCHAR_UBLOCK_TELUGU,                                                    /**<  */
    I18N_UCHAR_UBLOCK_KANNADA,                                                   /**<  */
    I18N_UCHAR_UBLOCK_MALAYALAM,                                                 /**<  */
    I18N_UCHAR_UBLOCK_SINHALA,                                                   /**<  */
    I18N_UCHAR_UBLOCK_THAI,                                                      /**<  */
    I18N_UCHAR_UBLOCK_LAO,                                                       /**<  */
    I18N_UCHAR_UBLOCK_TIBETAN,                                                   /**<  */
    I18N_UCHAR_UBLOCK_MYANMAR,                                                   /**<  */
    I18N_UCHAR_UBLOCK_GEORGIAN,                                                  /**<  */
    I18N_UCHAR_UBLOCK_HANGUL_JAMO,                                               /**<  */
    I18N_UCHAR_UBLOCK_ETHIOPIC,                                                  /**<  */
    I18N_UCHAR_UBLOCK_CHEROKEE,                                                  /**<  */
    I18N_UCHAR_UBLOCK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS,                     /**<  */
    I18N_UCHAR_UBLOCK_OGHAM,                                                     /**<  */
    I18N_UCHAR_UBLOCK_RUNIC,                                                     /**<  */
    I18N_UCHAR_UBLOCK_KHMER,                                                     /**<  */
    I18N_UCHAR_UBLOCK_MONGOLIAN,                                                 /**<  */
    I18N_UCHAR_UBLOCK_LATIN_EXTENDED_ADDITIONAL,                                 /**<  */
    I18N_UCHAR_UBLOCK_GREEK_EXTENDED,                                            /**<  */
    I18N_UCHAR_UBLOCK_GENERAL_PUNCTUATION,                                       /**<  */
    I18N_UCHAR_UBLOCK_SUPERSCRIPTS_AND_SUBSCRIPTS,                               /**<  */
    I18N_UCHAR_UBLOCK_CURRENCY_SYMBOLS,                                          /**<  */
    I18N_UCHAR_UBLOCK_COMBINING_MARKS_FOR_SYMBOLS,                               /**<  */
    I18N_UCHAR_UBLOCK_LETTERLIKE_SYMBOLS,                                        /**<  */
    I18N_UCHAR_UBLOCK_NUMBER_FORMS,                                              /**<  */
    I18N_UCHAR_UBLOCK_ARROWS,                                                    /**<  */
    I18N_UCHAR_UBLOCK_MATHEMATICAL_OPERATORS,                                    /**<  */
    I18N_UCHAR_UBLOCK_MISCELLANEOUS_TECHNICAL,                                   /**<  */
    I18N_UCHAR_UBLOCK_CONTROL_PICTURES,                                          /**<  */
    I18N_UCHAR_UBLOCK_OPTICAL_CHARACTER_RECOGNITION,                             /**<  */
    I18N_UCHAR_UBLOCK_ENCLOSED_ALPHANUMERICS,                                    /**<  */
    I18N_UCHAR_UBLOCK_BOX_DRAWING,                                               /**<  */
    I18N_UCHAR_UBLOCK_BLOCK_ELEMENTS,                                            /**<  */
    I18N_UCHAR_UBLOCK_GEOMETRIC_SHAPES,                                          /**<  */
    I18N_UCHAR_UBLOCK_MISCELLANEOUS_SYMBOLS,                                     /**<  */
    I18N_UCHAR_UBLOCK_DINGBATS,                                                  /**<  */
    I18N_UCHAR_UBLOCK_BRAILLE_PATTERNS,                                          /**<  */
    I18N_UCHAR_UBLOCK_CJK_RADICALS_SUPPLEMENT,                                   /**<  */
    I18N_UCHAR_UBLOCK_KANGXI_RADICALS,                                           /**<  */
    I18N_UCHAR_UBLOCK_IDEOGRAPHIC_DESCRIPTION_CHARACTERS,                        /**<  */
    I18N_UCHAR_UBLOCK_CJK_SYMBOLS_AND_PUNCTUATION,                               /**<  */
    I18N_UCHAR_UBLOCK_HIRAGANA,                                                  /**<  */
    I18N_UCHAR_UBLOCK_KATAKANA,                                                  /**<  */
    I18N_UCHAR_UBLOCK_BOPOMOFO,                                                  /**<  */
    I18N_UCHAR_UBLOCK_HANGUL_COMPATIBILITY_JAMO,                                 /**<  */
    I18N_UCHAR_UBLOCK_KANBUN,                                                    /**<  */
    I18N_UCHAR_UBLOCK_BOPOMOFO_EXTENDED,                                         /**<  */
    I18N_UCHAR_UBLOCK_ENCLOSED_CJK_LETTERS_AND_MONTHS,                           /**<  */
    I18N_UCHAR_UBLOCK_CJK_COMPATIBILITY,                                         /**<  */
    I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A,                        /**<  */
    I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS,                                    /**<  */
    I18N_UCHAR_UBLOCK_YI_SYLLABLES,                                              /**<  */
    I18N_UCHAR_UBLOCK_YI_RADICALS,                                               /**<  */
    I18N_UCHAR_UBLOCK_HANGUL_SYLLABLES,                                          /**<  */
    I18N_UCHAR_UBLOCK_HIGH_SURROGATES,                                           /**<  */
    I18N_UCHAR_UBLOCK_HIGH_PRIVATE_USE_SURROGATES,                               /**<  */
    I18N_UCHAR_UBLOCK_LOW_SURROGATES,                                            /**<  */
    I18N_UCHAR_UBLOCK_PRIVATE_USE_AREA,                                          /**<  */
    I18N_UCHAR_UBLOCK_PRIVATE_USE,                                               /**<  */
    I18N_UCHAR_UBLOCK_CJK_COMPATIBILITY_IDEOGRAPHS,                              /**<  */

    I18N_UCHAR_UBLOCK_ALPHABETIC_PRESENTATION_FORMS,                             /**<  */
    I18N_UCHAR_UBLOCK_ARABIC_PRESENTATION_FORMS_A,                               /**<  */
    I18N_UCHAR_UBLOCK_COMBINING_HALF_MARKS,                                      /**<  */
    I18N_UCHAR_UBLOCK_CJK_COMPATIBILITY_FORMS,                                   /**<  */
    I18N_UCHAR_UBLOCK_SMALL_FORM_VARIANTS,                                       /**<  */
    I18N_UCHAR_UBLOCK_ARABIC_PRESENTATION_FORMS_B,                               /**<  */
    I18N_UCHAR_UBLOCK_SPECIALS,                                                  /**<  */
    I18N_UCHAR_UBLOCK_HALFWIDTH_AND_FULLWIDTH_FORMS,                             /**<  */
    I18N_UCHAR_UBLOCK_OLD_ITALIC,                                                /**<  */
    I18N_UCHAR_UBLOCK_GOTHIC,                                                    /**<  */
    I18N_UCHAR_UBLOCK_DESERET,                                                   /**<  */
    I18N_UCHAR_UBLOCK_BYZANTINE_MUSICAL_SYMBOLS,                                 /**<  */
    I18N_UCHAR_UBLOCK_MUSICAL_SYMBOLS,                                           /**<  */
    I18N_UCHAR_UBLOCK_MATHEMATICAL_ALPHANUMERIC_SYMBOLS,                         /**<  */
    I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B,                        /**<  */
    I18N_UCHAR_UBLOCK_CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT,                   /**<  */
    I18N_UCHAR_UBLOCK_TAGS,                                                      /**<  */
    I18N_UCHAR_UBLOCK_CYRILLIC_SUPPLEMENT,                                       /**<  */
    I18N_UCHAR_UBLOCK_CYRILLIC_SUPPLEMENTARY,                                    /**<  */
    I18N_UCHAR_UBLOCK_TAGALOG,                                                   /**<  */
    I18N_UCHAR_UBLOCK_HANUNOO,                                                   /**<  */
    I18N_UCHAR_UBLOCK_BUHID,                                                     /**<  */
    I18N_UCHAR_UBLOCK_TAGBANWA,                                                  /**<  */
    I18N_UCHAR_UBLOCK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A,                      /**<  */
    I18N_UCHAR_UBLOCK_SUPPLEMENTAL_ARROWS_A,                                     /**<  */
    I18N_UCHAR_UBLOCK_SUPPLEMENTAL_ARROWS_B,                                     /**<  */
    I18N_UCHAR_UBLOCK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B,                      /**<  */
    I18N_UCHAR_UBLOCK_SUPPLEMENTAL_MATHEMATICAL_OPERATORS,                       /**<  */
    I18N_UCHAR_UBLOCK_KATAKANA_PHONETIC_EXTENSIONS,                              /**<  */
    I18N_UCHAR_UBLOCK_VARIATION_SELECTORS,                                       /**<  */
    I18N_UCHAR_UBLOCK_SUPPLEMENTARY_PRIVATE_USE_AREA_A,                          /**<  */
    I18N_UCHAR_UBLOCK_SUPPLEMENTARY_PRIVATE_USE_AREA_B,                          /**<  */
    I18N_UCHAR_UBLOCK_LIMBU,                                                     /**<  */
    I18N_UCHAR_UBLOCK_TAI_LE,                                                    /**<  */
    I18N_UCHAR_UBLOCK_KHMER_SYMBOLS,                                             /**<  */
    I18N_UCHAR_UBLOCK_PHONETIC_EXTENSIONS,                                       /**<  */
    I18N_UCHAR_UBLOCK_MISCELLANEOUS_SYMBOLS_AND_ARROWS,                          /**<  */
    I18N_UCHAR_UBLOCK_YIJING_HEXAGRAM_SYMBOLS,                                   /**<  */
    I18N_UCHAR_UBLOCK_LINEAR_B_SYLLABARY,                                        /**<  */
    I18N_UCHAR_UBLOCK_LINEAR_B_IDEOGRAMS,                                        /**<  */
    I18N_UCHAR_UBLOCK_AEGEAN_NUMBERS,                                            /**<  */
    I18N_UCHAR_UBLOCK_UGARITIC,                                                  /**<  */
    I18N_UCHAR_UBLOCK_SHAVIAN,                                                   /**<  */
    I18N_UCHAR_UBLOCK_OSMANYA,                                                   /**<  */
    I18N_UCHAR_UBLOCK_CYPRIOT_SYLLABARY,                                         /**<  */
    I18N_UCHAR_UBLOCK_TAI_XUAN_JING_SYMBOLS,                                     /**<  */
    I18N_UCHAR_UBLOCK_VARIATION_SELECTORS_SUPPLEMENT,                            /**<  */
    I18N_UCHAR_UBLOCK_ANCIENT_GREEK_MUSICAL_NOTATION,                            /**<  */
    I18N_UCHAR_UBLOCK_ANCIENT_GREEK_NUMBERS,                                     /**<  */
    I18N_UCHAR_UBLOCK_ARABIC_SUPPLEMENT,                                         /**<  */
    I18N_UCHAR_UBLOCK_BUGINESE,                                                  /**<  */
    I18N_UCHAR_UBLOCK_CJK_STROKES,                                               /**<  */
    I18N_UCHAR_UBLOCK_COMBINING_DIACRITICAL_MARKS_SUPPLEMENT,                    /**<  */
    I18N_UCHAR_UBLOCK_COPTIC,                                                    /**<  */
    I18N_UCHAR_UBLOCK_ETHIOPIC_EXTENDED,                                         /**<  */
    I18N_UCHAR_UBLOCK_ETHIOPIC_SUPPLEMENT,                                       /**<  */
    I18N_UCHAR_UBLOCK_GEORGIAN_SUPPLEMENT,                                       /**<  */
    I18N_UCHAR_UBLOCK_GLAGOLITIC,                                                /**<  */
    I18N_UCHAR_UBLOCK_KHAROSHTHI,                                                /**<  */
    I18N_UCHAR_UBLOCK_MODIFIER_TONE_LETTERS,                                     /**<  */
    I18N_UCHAR_UBLOCK_NEW_TAI_LUE,                                               /**<  */
    I18N_UCHAR_UBLOCK_OLD_PERSIAN,                                               /**<  */
    I18N_UCHAR_UBLOCK_PHONETIC_EXTENSIONS_SUPPLEMENT,                            /**<  */
    I18N_UCHAR_UBLOCK_SUPPLEMENTAL_PUNCTUATION,                                  /**<  */
    I18N_UCHAR_UBLOCK_SYLOTI_NAGRI,                                              /**<  */
    I18N_UCHAR_UBLOCK_TIFINAGH,                                                  /**<  */
    I18N_UCHAR_UBLOCK_VERTICAL_FORMS,                                            /**<  */
    I18N_UCHAR_UBLOCK_NKO,                                                       /**<  */
    I18N_UCHAR_UBLOCK_BALINESE,                                                  /**<  */
    I18N_UCHAR_UBLOCK_LATIN_EXTENDED_C,                                          /**<  */
    I18N_UCHAR_UBLOCK_LATIN_EXTENDED_D,                                          /**<  */
    I18N_UCHAR_UBLOCK_PHAGS_PA,                                                  /**<  */
    I18N_UCHAR_UBLOCK_PHOENICIAN,                                                /**<  */
    I18N_UCHAR_UBLOCK_CUNEIFORM,                                                 /**<  */
    I18N_UCHAR_UBLOCK_CUNEIFORM_NUMBERS_AND_PUNCTUATION,                         /**<  */
    I18N_UCHAR_UBLOCK_COUNTING_ROD_NUMERALS,                                     /**<  */
    I18N_UCHAR_UBLOCK_SUNDANESE,                                                 /**<  */
    I18N_UCHAR_UBLOCK_LEPCHA,                                                    /**<  */
    I18N_UCHAR_UBLOCK_OL_CHIKI,                                                  /**<  */
    I18N_UCHAR_UBLOCK_CYRILLIC_EXTENDED_A,                                       /**<  */
    I18N_UCHAR_UBLOCK_VAI,                                                       /**<  */
    I18N_UCHAR_UBLOCK_CYRILLIC_EXTENDED_B,                                       /**<  */
    I18N_UCHAR_UBLOCK_SAURASHTRA,                                                /**<  */
    I18N_UCHAR_UBLOCK_KAYAH_LI,                                                  /**<  */
    I18N_UCHAR_UBLOCK_REJANG,                                                    /**<  */
    I18N_UCHAR_UBLOCK_CHAM,                                                      /**<  */
    I18N_UCHAR_UBLOCK_ANCIENT_SYMBOLS,                                           /**<  */
    I18N_UCHAR_UBLOCK_PHAISTOS_DISC,                                             /**<  */
    I18N_UCHAR_UBLOCK_LYCIAN,                                                    /**<  */
    I18N_UCHAR_UBLOCK_CARIAN,                                                    /**<  */
    I18N_UCHAR_UBLOCK_LYDIAN,                                                    /**<  */
    I18N_UCHAR_UBLOCK_MAHJONG_TILES,                                             /**<  */
    I18N_UCHAR_UBLOCK_DOMINO_TILES,                                              /**<  */
    I18N_UCHAR_UBLOCK_SAMARITAN,                                                 /**<  */
    I18N_UCHAR_UBLOCK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED,            /**<  */
    I18N_UCHAR_UBLOCK_TAI_THAM,                                                  /**<  */
    I18N_UCHAR_UBLOCK_VEDIC_EXTENSIONS,                                          /**<  */
    I18N_UCHAR_UBLOCK_LISU,                                                      /**<  */
    I18N_UCHAR_UBLOCK_BAMUM,                                                     /**<  */
    I18N_UCHAR_UBLOCK_COMMON_INDIC_NUMBER_FORMS,                                 /**<  */
    I18N_UCHAR_UBLOCK_DEVANAGARI_EXTENDED,                                       /**<  */
    I18N_UCHAR_UBLOCK_HANGUL_JAMO_EXTENDED_A,                                    /**<  */
    I18N_UCHAR_UBLOCK_JAVANESE,                                                  /**<  */
    I18N_UCHAR_UBLOCK_MYANMAR_EXTENDED_A,                                        /**<  */
    I18N_UCHAR_UBLOCK_TAI_VIET,                                                  /**<  */
    I18N_UCHAR_UBLOCK_MEETEI_MAYEK,                                              /**<  */
    I18N_UCHAR_UBLOCK_HANGUL_JAMO_EXTENDED_B,                                    /**<  */
    I18N_UCHAR_UBLOCK_IMPERIAL_ARAMAIC,                                          /**<  */
    I18N_UCHAR_UBLOCK_OLD_SOUTH_ARABIAN,                                         /**<  */
    I18N_UCHAR_UBLOCK_AVESTAN,                                                   /**<  */
    I18N_UCHAR_UBLOCK_INSCRIPTIONAL_PARTHIAN,                                    /**<  */
    I18N_UCHAR_UBLOCK_INSCRIPTIONAL_PAHLAVI,                                     /**<  */
    I18N_UCHAR_UBLOCK_OLD_TURKIC,                                                /**<  */
    I18N_UCHAR_UBLOCK_RUMI_NUMERAL_SYMBOLS,                                      /**<  */
    I18N_UCHAR_UBLOCK_KAITHI,                                                    /**<  */
    I18N_UCHAR_UBLOCK_EGYPTIAN_HIEROGLYPHS,                                      /**<  */
    I18N_UCHAR_UBLOCK_ENCLOSED_ALPHANUMERIC_SUPPLEMENT,                          /**<  */
    I18N_UCHAR_UBLOCK_ENCLOSED_IDEOGRAPHIC_SUPPLEMENT,                           /**<  */
    I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C,                        /**<  */
    I18N_UCHAR_UBLOCK_MANDAIC,                                                   /**<  */
    I18N_UCHAR_UBLOCK_BATAK,                                                     /**<  */
    I18N_UCHAR_UBLOCK_ETHIOPIC_EXTENDED_A,                                       /**<  */
    I18N_UCHAR_UBLOCK_BRAHMI,                                                    /**<  */
    I18N_UCHAR_UBLOCK_BAMUM_SUPPLEMENT,                                          /**<  */
    I18N_UCHAR_UBLOCK_KANA_SUPPLEMENT,                                           /**<  */
    I18N_UCHAR_UBLOCK_PLAYING_CARDS,                                             /**<  */
    I18N_UCHAR_UBLOCK_MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS,                     /**<  */
    I18N_UCHAR_UBLOCK_EMOTICONS,                                                 /**<  */
    I18N_UCHAR_UBLOCK_TRANSPORT_AND_MAP_SYMBOLS,                                 /**<  */
    I18N_UCHAR_UBLOCK_ALCHEMICAL_SYMBOLS,                                        /**<  */
    I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D,                        /**<  */
    I18N_UCHAR_UBLOCK_COUNT,                                                     /**<  */
    I18N_UCHAR_UBLOCK_INVALID_CODE = -1                                          /**<  */
} i18n_uchar_ublock_code_e;

/**
 * @brief Enumeration for the language directional property of a character set.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 */
typedef enum {
/*
 * Note: UCharDirection constants and their API comments are parsed by preparseucd.py.
 * It matches pairs of lines like
 * / ** <Unicode 1..3-letter Bidi_Class value> comment... * /
 * U_<[A-Z_]+> = <integer>,
 */
    I18N_UCHAR_U_LEFT_TO_RIGHT,                                      /**< L */
    I18N_UCHAR_U_RIGHT_TO_LEFT,                                      /**< R */
    I18N_UCHAR_U_EUROPEAN_NUMBER,                                    /**< EN */
    I18N_UCHAR_U_EUROPEAN_NUMBER_SEPARATOR,                          /**< ES */
    I18N_UCHAR_U_EUROPEAN_NUMBER_TERMINATOR,                         /**< ET */
    I18N_UCHAR_U_ARABIC_NUMBER,                                      /**< AN */
    I18N_UCHAR_U_COMMON_NUMBER_SEPARATOR,                            /**< CS */
    I18N_UCHAR_U_BLOCK_SEPARATOR,                                    /**< B */
    I18N_UCHAR_U_SEGMENT_SEPARATOR,                                  /**< S */
    I18N_UCHAR_U_WHITE_SPACE_NEUTRAL,                                /**< WS */
    I18N_UCHAR_U_OTHER_NEUTRAL,                                      /**< ON */
    I18N_UCHAR_U_LEFT_TO_RIGHT_EMBEDDING,                            /**< LRE */
    I18N_UCHAR_U_LEFT_TO_RIGHT_OVERRIDE,                             /**< LRO */
    I18N_UCHAR_U_RIGHT_TO_LEFT_ARABIC,                               /**< AL */
    I18N_UCHAR_U_RIGHT_TO_LEFT_EMBEDDING,                            /**< RLE */
    I18N_UCHAR_U_RIGHT_TO_LEFT_OVERRIDE,                             /**< RLO */
    I18N_UCHAR_U_POP_DIRECTIONAL_FORMAT,                             /**< PDF */
    I18N_UCHAR_U_DIR_NON_SPACING_MARK,                               /**< NSM */
    I18N_UCHAR_U_BOUNDARY_NEUTRAL,                                   /**< BN */
    I18N_UCHAR_U_CHAR_DIRECTION_COUNT                                /**<  */
} i18n_uchar_direction_e;

/**
 * @brief Enumeration for Decomposition Type constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
/*
 * Note: UDecompositionType constants are parsed by preparseucd.py.
 * It matches lines like
 * U_DT_<Unicode Decomposition_Type value name>
 */
    I18N_UCHAR_U_DT_NONE,           /**< [none] */
    I18N_UCHAR_U_DT_CANONICAL,      /**< [can] */
    I18N_UCHAR_U_DT_COMPAT,         /**< [com] */
    I18N_UCHAR_U_DT_CIRCLE,         /**< [enc] */
    I18N_UCHAR_U_DT_FINAL,          /**< [fin] */
    I18N_UCHAR_U_DT_FONT,           /**< [font] */
    I18N_UCHAR_U_DT_FRACTION,       /**< [fra] */
    I18N_UCHAR_U_DT_INITIAL,        /**< [init] */
    I18N_UCHAR_U_DT_ISOLATED,       /**< [iso] */
    I18N_UCHAR_U_DT_MEDIAL,         /**< [med] */
    I18N_UCHAR_U_DT_NARROW,         /**< [nar] */
    I18N_UCHAR_U_DT_NOBREAK,        /**< [nb] */
    I18N_UCHAR_U_DT_SMALL,          /**< [sml] */
    I18N_UCHAR_U_DT_SQUARE,         /**< [sqr] */
    I18N_UCHAR_U_DT_SUB,            /**< [sub] */
    I18N_UCHAR_U_DT_SUPER,          /**< [sup] */
    I18N_UCHAR_U_DT_VERTICAL,       /**< [vert] */
    I18N_UCHAR_U_DT_WIDE,           /**< [wide] */
    I18N_UCHAR_U_DT_COUNT           /**< 18 */
} i18n_uchar_u_decomposition_type_e;

/**
 * @brief Enumeration for East Asian Width constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UCHAR_U_EA_NEUTRAL,         /**< [N] */
    I18N_UCHAR_U_EA_AMBIGUOUS,       /**< [A] */
    I18N_UCHAR_U_EA_HALFWIDTH,       /**< [H] */
    I18N_UCHAR_U_EA_FULLWIDTH,       /**< [F] */
    I18N_UCHAR_U_EA_NARROW,          /**< [Na] */
    I18N_UCHAR_U_EA_WIDE,            /**< [W] */
    I18N_UCHAR_U_EA_COUNT
} i18n_uchar_u_east_asian_width_e;

/**
 * @brief Enumeration for Unicode general category types.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UCHAR_U_UNASSIGNED,                        /**< Non-category for unassigned and non-character code points */
    I18N_UCHAR_U_GENERAL_OTHER_TYPES = 0,           /**< Cn "Other, Not Assigned (no characters in [UnicodeData.txt] have this property)" (same as #I18N_UCHAR_U_UNASSIGNED!) */
    I18N_UCHAR_U_UPPERCASE_LETTER,                  /**< Lu */
    I18N_UCHAR_U_LOWERCASE_LETTER,                  /**< Ll */
    I18N_UCHAR_U_TITLECASE_LETTER,                  /**< Lt */
    I18N_UCHAR_U_MODIFIER_LETTER,                   /**< Lm */
    I18N_UCHAR_U_OTHER_LETTER,                      /**< Lo */
    I18N_UCHAR_U_NON_SPACING_MARK,                  /**< Mn */
    I18N_UCHAR_U_ENCLOSING_MARK,                    /**< Me */
    I18N_UCHAR_U_COMBINING_SPACING_MARK,            /**< Mc */
    I18N_UCHAR_U_DECIMAL_DIGIT_NUMBER,              /**< Nd */
    I18N_UCHAR_U_LETTER_NUMBER,                     /**< Nl */
    I18N_UCHAR_U_OTHER_NUMBER,                      /**< No */
    I18N_UCHAR_U_SPACE_SEPARATOR,                   /**< Zs */
    I18N_UCHAR_U_LINE_SEPARATOR,                    /**< Zl */
    I18N_UCHAR_U_PARAGRAPH_SEPARATOR,               /**< Zp */
    I18N_UCHAR_U_CONTROL_CHAR,                      /**< Cc */
    I18N_UCHAR_U_FORMAT_CHAR,                       /**< Cf */
    I18N_UCHAR_U_PRIVATE_USE_CHAR,                  /**< Co */
    I18N_UCHAR_U_SURROGATE,                         /**< Cs */
    I18N_UCHAR_U_DASH_PUNCTUATION,                  /**< Pd */
    I18N_UCHAR_U_START_PUNCTUATION,                 /**< Ps */
    I18N_UCHAR_U_END_PUNCTUATION,                   /**< Pe */
    I18N_UCHAR_U_CONNECTOR_PUNCTUATION,             /**< Pc */
    I18N_UCHAR_U_OTHER_PUNCTUATION,                 /**< Po */
    I18N_UCHAR_U_MATH_SYMBOL,                       /**< Sm */
    I18N_UCHAR_U_CURRENCY_SYMBOL,                   /**< Sc */
    I18N_UCHAR_U_MODIFIER_SYMBOL,                   /**< Sk */
    I18N_UCHAR_U_OTHER_SYMBOL,                      /**< So */
    I18N_UCHAR_U_INITIAL_PUNCTUATION,               /**< Pi */
    I18N_UCHAR_U_FINAL_PUNCTUATION,                 /**< Pf */
    I18N_UCHAR_U_CHAR_CATEGORY_COUNT                /**< One higher than the last enum #i18n_uchar_category_e constant */
} i18n_uchar_category_e;

/**
 * @brief Enumeration for Joining Group constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
/*
 * Note: UJoiningGroup constants are parsed by preparseucd.py.
 * It matches lines like
 * U_JG_<Unicode Joining_Group value name>
 */
    I18N_UCHAR_U_JG_NO_JOINING_GROUP,                                              /**<  */
    I18N_UCHAR_U_JG_AIN,                                                           /**<  */
    I18N_UCHAR_U_JG_ALAPH,                                                         /**<  */
    I18N_UCHAR_U_JG_ALEF,                                                          /**<  */
    I18N_UCHAR_U_JG_BEH,                                                           /**<  */
    I18N_UCHAR_U_JG_BETH,                                                          /**<  */
    I18N_UCHAR_U_JG_DAL,                                                           /**<  */
    I18N_UCHAR_U_JG_DALATH_RISH,                                                   /**<  */
    I18N_UCHAR_U_JG_E,                                                             /**<  */
    I18N_UCHAR_U_JG_FEH,                                                           /**<  */
    I18N_UCHAR_U_JG_FINAL_SEMKATH,                                                 /**<  */
    I18N_UCHAR_U_JG_GAF,                                                           /**<  */
    I18N_UCHAR_U_JG_GAMAL,                                                         /**<  */
    I18N_UCHAR_U_JG_HAH,                                                           /**<  */
    I18N_UCHAR_U_JG_TEH_MARBUTA_GOAL,                                              /**<  */
    I18N_UCHAR_U_JG_HAMZA_ON_HEH_GOAL = I18N_UCHAR_U_JG_TEH_MARBUTA_GOAL,          /**<  */
    I18N_UCHAR_U_JG_HE,                                                            /**<  */
    I18N_UCHAR_U_JG_HEH,                                                           /**<  */
    I18N_UCHAR_U_JG_HEH_GOAL,                                                      /**<  */
    I18N_UCHAR_U_JG_HETH,                                                          /**<  */
    I18N_UCHAR_U_JG_KAF,                                                           /**<  */
    I18N_UCHAR_U_JG_KAPH,                                                          /**<  */
    I18N_UCHAR_U_JG_KNOTTED_HEH,                                                   /**<  */
    I18N_UCHAR_U_JG_LAM,                                                           /**<  */
    I18N_UCHAR_U_JG_LAMADH,                                                        /**<  */
    I18N_UCHAR_U_JG_MEEM,                                                          /**<  */
    I18N_UCHAR_U_JG_MIM,                                                           /**<  */
    I18N_UCHAR_U_JG_NOON,                                                          /**<  */
    I18N_UCHAR_U_JG_NUN,                                                           /**<  */
    I18N_UCHAR_U_JG_PE,                                                            /**<  */
    I18N_UCHAR_U_JG_QAF,                                                           /**<  */
    I18N_UCHAR_U_JG_QAPH,                                                          /**<  */
    I18N_UCHAR_U_JG_REH,                                                           /**<  */
    I18N_UCHAR_U_JG_REVERSED_PE,                                                   /**<  */
    I18N_UCHAR_U_JG_SAD,                                                           /**<  */
    I18N_UCHAR_U_JG_SADHE,                                                         /**<  */
    I18N_UCHAR_U_JG_SEEN,                                                          /**<  */
    I18N_UCHAR_U_JG_SEMKATH,                                                       /**<  */
    I18N_UCHAR_U_JG_SHIN,                                                          /**<  */
    I18N_UCHAR_U_JG_SWASH_KAF,                                                     /**<  */
    I18N_UCHAR_U_JG_SYRIAC_WAW,                                                    /**<  */
    I18N_UCHAR_U_JG_TAH,                                                           /**<  */
    I18N_UCHAR_U_JG_TAW,                                                           /**<  */
    I18N_UCHAR_U_JG_TEH_MARBUTA,                                                   /**<  */
    I18N_UCHAR_U_JG_TETH,                                                          /**<  */
    I18N_UCHAR_U_JG_WAW,                                                           /**<  */
    I18N_UCHAR_U_JG_YEH,                                                           /**<  */
    I18N_UCHAR_U_JG_YEH_BARREE,                                                    /**<  */
    I18N_UCHAR_U_JG_YEH_WITH_TAIL,                                                 /**<  */
    I18N_UCHAR_U_JG_YUDH,                                                          /**<  */
    I18N_UCHAR_U_JG_YUDH_HE,                                                       /**<  */
    I18N_UCHAR_U_JG_ZAIN,                                                          /**<  */
    I18N_UCHAR_U_JG_FE,                                                            /**<  */
    I18N_UCHAR_U_JG_KHAPH,                                                         /**<  */
    I18N_UCHAR_U_JG_ZHAIN,                                                         /**<  */
    I18N_UCHAR_U_JG_BURUSHASKI_YEH_BARREE,                                         /**<  */
    I18N_UCHAR_U_JG_FARSI_YEH,                                                     /**<  */
    I18N_UCHAR_U_JG_NYA,                                                           /**<  */
    I18N_UCHAR_U_JG_ROHINGYA_YEH,
    I18N_UCHAR_U_JG_COUNT                                                          /**<  */
 } i18n_uchar_u_joining_group_e;

/**
 * @brief Enumeration for Joining Type constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
/*
 * Note: i18n_uchar_u_joining_type_e constants are parsed by preparseucd.py.
 * It matches lines like
 * U_JT_<Unicode Joining_Type value name>
 */
    I18N_UCHAR_U_JT_NON_JOINING,        /**< [U] */
    I18N_UCHAR_U_JT_JOIN_CAUSING,       /**< [C] */
    I18N_UCHAR_U_JT_DUAL_JOINING,       /**< [D] */
    I18N_UCHAR_U_JT_LEFT_JOINING,       /**< [L] */
    I18N_UCHAR_U_JT_RIGHT_JOINING,      /**< [R] */
    I18N_UCHAR_U_JT_TRANSPARENT,        /**< [T] */
    I18N_UCHAR_U_JT_COUNT               /**< 6 */
} i18n_uchar_u_joining_type_e;

/**
 * @brief Enumeration for Line Break constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
/*
 * Note: i18n_uchar_u_line_break_e constants are parsed by preparseucd.py.
 * It matches lines like
 * U_LB_<Unicode Line_Break value name>
 */
    I18N_UCHAR_U_LB_UNKNOWN,                                                         /**< [XX] */
    I18N_UCHAR_U_LB_AMBIGUOUS,                                                       /**< [AI] */
    I18N_UCHAR_U_LB_ALPHABETIC,                                                      /**< [AL] */
    I18N_UCHAR_U_LB_BREAK_BOTH,                                                      /**< [B2] */
    I18N_UCHAR_U_LB_BREAK_AFTER,                                                     /**< [BA] */
    I18N_UCHAR_U_LB_BREAK_BEFORE,                                                    /**< [BB] */
    I18N_UCHAR_U_LB_MANDATORY_BREAK,                                                 /**< [BK] */
    I18N_UCHAR_U_LB_CONTINGENT_BREAK,                                                /**< [CB] */
    I18N_UCHAR_U_LB_CLOSE_PUNCTUATION,                                               /**< [CL] */
    I18N_UCHAR_U_LB_COMBINING_MARK,                                                  /**< [CM] */
    I18N_UCHAR_U_LB_CARRIAGE_RETURN,                                                 /**< [CR] */
    I18N_UCHAR_U_LB_EXCLAMATION,                                                     /**< [EX] */
    I18N_UCHAR_U_LB_GLUE,                                                            /**< [GL] */
    I18N_UCHAR_U_LB_HYPHEN,                                                          /**< [HY] */
    I18N_UCHAR_U_LB_IDEOGRAPHIC,                                                     /**< [ID] */
    I18N_UCHAR_U_LB_INSEPARABLE,                                                     /**< [IN] */
    I18N_UCHAR_U_LB_INSEPERABLE = I18N_UCHAR_U_LB_INSEPARABLE,
    I18N_UCHAR_U_LB_INFIX_NUMERIC,                                                   /**< [IS] */
    I18N_UCHAR_U_LB_LINE_FEED,                                                       /**< [LF] */
    I18N_UCHAR_U_LB_NONSTARTER,                                                      /**< [NS] */
    I18N_UCHAR_U_LB_NUMERIC,                                                         /**< [NU] */
    I18N_UCHAR_U_LB_OPEN_PUNCTUATION,                                                /**< [OP] */
    I18N_UCHAR_U_LB_POSTFIX_NUMERIC,                                                 /**< [PO] */
    I18N_UCHAR_U_LB_PREFIX_NUMERIC,                                                  /**< [PR] */
    I18N_UCHAR_U_LB_QUOTATION,                                                       /**< [QU] */
    I18N_UCHAR_U_LB_COMPLEX_CONTEXT,                                                 /**< [SA] */
    I18N_UCHAR_U_LB_SURROGATE,                                                       /**< [SG] */
    I18N_UCHAR_U_LB_SPACE,                                                           /**< [SP] */
    I18N_UCHAR_U_LB_BREAK_SYMBOLS,                                                   /**< [SY] */
    I18N_UCHAR_U_LB_ZWSPACE,                                                         /**< [ZW] */
    I18N_UCHAR_U_LB_NEXT_LINE,                                                       /**< [NL] */
    I18N_UCHAR_U_LB_WORD_JOINER,                                                     /**< [WJ] */
    I18N_UCHAR_U_LB_H2,                                                              /**< [H2] */
    I18N_UCHAR_U_LB_H3,                                                              /**< [H3] */
    I18N_UCHAR_U_LB_JL,                                                              /**< [JL] */
    I18N_UCHAR_U_LB_JT,                                                              /**< [JT] */
    I18N_UCHAR_U_LB_JV,                                                              /**< [JV] */
    I18N_UCHAR_U_LB_CLOSE_PARENTHESIS,                                               /**< [CP] */
    I18N_UCHAR_U_LB_COUNT
 } i18n_uchar_u_line_break_e;

/**
 * @brief Enumeration for Numeric Type constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
/*
 * Note: i18n_uchar_u_numeric_type_e constants are parsed by preparseucd.py.
 * It matches lines like
 * U_NT_<Unicode Numeric_Type value name>
 */
    I18N_UCHAR_U_NT_NONE,         /**< [None] */
    I18N_UCHAR_U_NT_DECIMAL,      /**< [de] */
    I18N_UCHAR_U_NT_DIGIT,        /**< [di] */
    I18N_UCHAR_U_NT_NUMERIC,      /**< [nu] */
    I18N_UCHAR_U_NT_COUNT         /**<  */
} i18n_uchar_u_numeric_type_e;

/**
 * @brief Enumeration for Hangul Syllable Type constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
/*
 * Note: i18n_uchar_u_hangul_syllable_type_e constants are parsed by preparseucd.py.
 * It matches lines like
 * U_HST_<Unicode Hangul_Syllable_Type value name>
 */
    I18N_UCHAR_U_HST_NOT_APPLICABLE,     /**< [NA] */
    I18N_UCHAR_U_HST_LEADING_JAMO,       /**< [L] */
    I18N_UCHAR_U_HST_VOWEL_JAMO,         /**< [V] */
    I18N_UCHAR_U_HST_TRAILING_JAMO,      /**< [T] */
    I18N_UCHAR_U_HST_LV_SYLLABLE,        /**< [LV] */
    I18N_UCHAR_U_HST_LVT_SYLLABLE,       /**< [LVT] */
    I18N_UCHAR_U_HST_COUNT               /**<  */
} i18n_uchar_u_hangul_syllable_type_e;

/**
 * @brief Enumeration for Sentence Break constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
/*
 * Note: i18n_uchar_u_sentence_break_e constants are parsed by preparseucd.py.
 * It matches lines like
 * U_SB_<Unicode Sentence_Break value name>
 */
    I18N_UCHAR_U_SB_OTHER,         /**< [XX] */
    I18N_UCHAR_U_SB_ATERM,         /**< [AT] */
    I18N_UCHAR_U_SB_CLOSE,         /**< [CL] */
    I18N_UCHAR_U_SB_FORMAT,        /**< [FO] */
    I18N_UCHAR_U_SB_LOWER,         /**< [LO] */
    I18N_UCHAR_U_SB_NUMERIC,       /**< [NU] */
    I18N_UCHAR_U_SB_OLETTER,       /**< [LE] */
    I18N_UCHAR_U_SB_SEP,           /**< [SE] */
    I18N_UCHAR_U_SB_SP,            /**< [SP] */
    I18N_UCHAR_U_SB_STERM,         /**< [ST] */
    I18N_UCHAR_U_SB_UPPER,         /**< [UP] */
    I18N_UCHAR_U_SB_CR,            /**< [CR] */
    I18N_UCHAR_U_SB_EXTEND,        /**< [EX] */
    I18N_UCHAR_U_SB_LF,            /**< [LF] */
    I18N_UCHAR_U_SB_SCONTINUE,     /**< [SC] */
    I18N_UCHAR_U_SB_COUNT          /**<  */
} i18n_uchar_u_sentence_break_e;

/**
 * @brief Enumeration for Word Break constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
/*
 * Note: i18n_uchar_u_word_break_values_e constants are parsed by preparseucd.py.
 * It matches lines like
 * U_WB_<Unicode Word_Break value name>
 */
    I18N_UCHAR_U_WB_OTHER,              /**< [XX] */
    I18N_UCHAR_U_WB_ALETTER,            /**< [LE] */
    I18N_UCHAR_U_WB_FORMAT,             /**< [FO] */
    I18N_UCHAR_U_WB_KATAKANA,           /**< [KA] */
    I18N_UCHAR_U_WB_MIDLETTER,          /**< [ML] */
    I18N_UCHAR_U_WB_MIDNUM,             /**< [MN] */
    I18N_UCHAR_U_WB_NUMERIC,            /**< [NU] */
    I18N_UCHAR_U_WB_EXTENDNUMLET,       /**< [EX] */
    I18N_UCHAR_U_WB_CR,                 /**< [CR] */
    I18N_UCHAR_U_WB_EXTEND,             /**< [Extend] */
    I18N_UCHAR_U_WB_LF,                 /**< [LF] */
    I18N_UCHAR_U_WB_MIDNUMLET,          /**< [MB] */
    I18N_UCHAR_U_WB_NEWLINE,            /**< [NL] */
    I18N_UCHAR_U_WB_COUNT               /**<  */
} i18n_uchar_u_word_break_values_e;

/**
 * @brief Enumeration for Grapheme Cluster Break constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
/*
 * Note: i18n_uchar_u_grapheme_cluster_break_e constants are parsed by preparseucd.py.
 * It matches lines like
 * U_GCB_<Unicode Grapheme_Cluster_Break value name>
 */
    I18N_UCHAR_U_GCB_OTHER,                    /**< [XX] */
    I18N_UCHAR_U_GCB_CONTROL,                  /**< [CN] */
    I18N_UCHAR_U_GCB_CR,                       /**< [CR] */
    I18N_UCHAR_U_GCB_EXTEND,                   /**< [EX] */
    I18N_UCHAR_U_GCB_L,                        /**< [L] */
    I18N_UCHAR_U_GCB_LF,                       /**< [LF] */
    I18N_UCHAR_U_GCB_LV,                       /**< [LV] */
    I18N_UCHAR_U_GCB_LVT,                      /**< [LVT] */
    I18N_UCHAR_U_GCB_T,                        /**< [T] */
    I18N_UCHAR_U_GCB_V,                        /**< [V] */
    I18N_UCHAR_U_GCB_SPACING_MARK,             /**< [SM] */
    I18N_UCHAR_U_GCB_PREPEND,                  /**< [PP] */
    I18N_UCHAR_UCHAR_U_GCB_COUNT               /**<  */
} i18n_uchar_u_grapheme_cluster_break_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE
 * @{
 */

/**
 * @brief Structure representing a collator object instance.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void *i18n_ucollator_h;

/**
 * @brief Enumeration for attributes that collation service understands.
 *        All the attributes can take #I18N_UCOLLATOR_DEFAULT value, as well as the values specific to each one.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UCOLLATOR_FRENCH_COLLATION,                                            /**< Attribute for direction of secondary weights - used in Canadian French. Acceptable values are #I18N_UCOLLATOR_ON, which results in secondary weights being considered backwards, and #I18N_UCOLLATOR_OFF which treats secondary weights in the order they appear */
    I18N_UCOLLATOR_ALTERNATE_HANDLING,                                          /**< Attribute for handling variable elements. Acceptable values are #I18N_UCOLLATOR_NON_IGNORABLE (default) which treats all the codepoints with non-ignorable primary weights in the same way, and #I18N_UCOLLATOR_SHIFTED which causes codepoints with primary weights that are equal or below the variable top value to be ignored at the primary level and moved to the quaternary level */
    I18N_UCOLLATOR_CASE_FIRST,                                                  /**< Controls the ordering of upper and lower case letters. Acceptable values are #I18N_UCOLLATOR_OFF (default), which orders upper and lower case letters in accordance to their tertiary weights, #I18N_UCOLLATOR_UPPER_FIRST which forces upper case letters to sort before lower case letters, and #I18N_UCOLLATOR_LOWER_FIRST which does the opposite */
    I18N_UCOLLATOR_CASE_LEVEL,                                                  /**< Controls whether an extra case level (positioned before the third level) is generated or not. Acceptable values are #I18N_UCOLLATOR_OFF (default), when case level is not generated, and #I18N_UCOLLATOR_ON which causes the case level to be generated. Contents of the case level are affected by the value of the #I18N_UCOLLATOR_CASE_FIRST attribute. A simple way to ignore accent differences in a string is to set the strength to #I18N_UCOLLATOR_PRIMARY and enable case level */
    I18N_UCOLLATOR_NORMALIZATION_MODE,                                          /**< Controls whether the normalization check and necessary normalizations are performed. When set to #I18N_UCOLLATOR_OFF (default) no normalization check is performed. The correctness of the result is guaranteed only if the input data is in so-called FCD form (see users manual for more info). When set to #I18N_UCOLLATOR_ON, an incremental check is performed to see whether the input data is in the FCD form. If the data is not in the FCD form, incremental NFD normalization is performed */
    I18N_UCOLLATOR_DECOMPOSITION_MODE = I18N_UCOLLATOR_NORMALIZATION_MODE,      /**< An alias for the #I18N_UCOLLATOR_NORMALIZATION_MODE attribute */
    I18N_UCOLLATOR_STRENGTH,                                                    /**< The strength attribute. Can be either #I18N_UCOLLATOR_PRIMARY, #I18N_UCOLLATOR_SECONDARY, #I18N_UCOLLATOR_TERTIARY, #I18N_UCOLLATOR_QUATERNARY, or #I18N_UCOLLATOR_IDENTICAL. The usual strength for most locales (except Japanese) is tertiary. Quaternary strength is useful when combined with shifted setting for the alternate handling attribute and for JIS X 4061 collation, when it is used to distinguish between Katakana and Hiragana. Otherwise, quaternary level is affected only by the number of non-ignorable code points in the string. Identical strength is rarely useful, as it amounts to codepoints of the NFD form of the string */
    I18N_UCOLLATOR_NUMERIC_COLLATION = I18N_UCOLLATOR_STRENGTH + 2,             /**< When turned on, this attribute makes substrings of digits that are sort according to their numeric values. This is a way to get '100' to sort AFTER '2'. Note that the longest digit substring that can be treated as a single unit is 254 digits (not counting leading zeros). If a digit substring is longer than that, the digits beyond the limit will be treated as a separate digit substring. A "digit" in this sense is a code point with General_Category=Nd, which does not include circled numbers, roman numerals, and so on. Only a contiguous digit substring is considered, that is, non-negative integers without separators. There is no support for plus/minus signs, decimals, exponents, and so on */
    I18N_UCOLLATOR_ATTRIBUTE_COUNT                                              /**< The number of i18n_ucollator_attribute_e constants */
} i18n_ucollator_attribute_e;

/**
 * @brief Enumeration containing attribute values for controlling collation behavior.
 *        Here are all the allowable values. Not every attribute can take every value.
 *        The only universal value is #I18N_UCOLLATOR_DEFAULT, which resets the attribute value to the predefined value for that locale.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UCOLLATOR_DEFAULT           = -1,                          /**< Accepted by most attributes */
    I18N_UCOLLATOR_PRIMARY           = 0,                           /**< Primary collation strength */
    I18N_UCOLLATOR_SECONDARY         = 1,                           /**< Secondary collation strength */
    I18N_UCOLLATOR_TERTIARY          = 2,                           /**< Tertiary collation strength */
    I18N_UCOLLATOR_DEFAULT_STRENGTH  = I18N_UCOLLATOR_TERTIARY,     /**< Default collation strength */
    I18N_UCOLLATOR_CE_STRENGTH_LIMIT,
    I18N_UCOLLATOR_QUATERNARY        = 3,                           /**< Quaternary collation strength */
    I18N_UCOLLATOR_IDENTICAL         = 15,                          /**< Identical collation strength */
    I18N_UCOLLATOR_STRENGTH_LIMIT,

    I18N_UCOLLATOR_OFF               = 16,                          /**< Turn the feature off - works for #I18N_UCOLLATOR_FRENCH_COLLATION, #I18N_UCOLLATOR_CASE_LEVEL & #I18N_UCOLLATOR_DECOMPOSITION_MODE */
    I18N_UCOLLATOR_ON                = 17,                          /**< Turn the feature on - works for #I18N_UCOLLATOR_FRENCH_COLLATION, #I18N_UCOLLATOR_CASE_LEVEL & #I18N_UCOLLATOR_DECOMPOSITION_MODE */

    I18N_UCOLLATOR_SHIFTED           = 20,                          /**< Valid for #I18N_UCOLLATOR_ALTERNATE_HANDLING. Alternate handling will be shifted. */
    I18N_UCOLLATOR_NON_IGNORABLE     = 21,                          /**< Valid for #I18N_UCOLLATOR_ALTERNATE_HANDLING. Alternate handling will be non ignorable. */
    I18N_UCOLLATOR_LOWER_FIRST       = 24,                          /**< Valid for #I18N_UCOLLATOR_CASE_FIRST - lower case sorts before upper case. */
    I18N_UCOLLATOR_UPPER_FIRST       = 25,                          /**< Upper case sorts before lower case. */
    I18N_UCOLLATOR_ATTRIBUTE_VALUE_COUNT
} i18n_ucollator_attribute_value_e;

/**
 * @brief Enumeration in which the base letter represents a primary difference. Set comparison level to #I18N_UCOLLATOR_PRIMARY to ignore secondary and tertiary differences. Use this to set the strength of an #i18n_ucollator_h. Example of primary difference, "abc" < "abd"
 *        Diacritical differences on the same base letter represent a secondary difference. Set comparison level to #I18N_UCOLLATOR_SECONDARY to ignore tertiary differences. Use this to set the strength of an #i18n_ucollator_h. Example of secondary difference, "&auml;" >> "a".
 *        Uppercase and lowercase versions of the same character represent a tertiary difference. Set comparison level to #I18N_UCOLLATOR_TERTIARY to include all comparison differences. Use this to set the strength of an #i18n_ucollator_h. Example of tertiary difference, "abc" <<< "ABC".
 *        Two characters are considered "identical" when they have the same unicode spellings. #I18N_UCOLLATOR_IDENTICAL. For example, "&auml;" == "&auml;".
 *        #i18n_ucollator_strength_e is also used to determine the strength of sort keys generated from #i18n_ucollator_h. These values can now be found in the #i18n_ucollator_attribute_value_e enum.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef i18n_ucollator_attribute_value_e i18n_ucollator_strength_e;

/**
 * @brief Enumeration for source and target string comparison result.
 *        #I18N_UCOLLATOR_LESS is returned if the source string is compared to be less than the target string in the {@link i18n_ucollator_str_collator() } method.
 *        #I18N_UCOLLATOR_EQUAL is returned if the source string is compared to be equal to the target string in the {@link i18n_ucollator_str_collator() } method.
 *        #I18N_UCOLLATOR_GREATER is returned if the source string is compared to be greater than the target string in the {@link #i18n_ucollator_str_collator() } method.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UCOLLATOR_EQUAL     = 0,    /**< string a == string b */
    I18N_UCOLLATOR_GREATER   = 1,    /**< string a > string b */
    I18N_UCOLLATOR_LESS      = -1    /**< string a < string b */
} i18n_ucollator_result_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UNORMALIZATION_MODULE
 * @{
 */


/**
 * @brief i18n_unormalizer_h.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 */

typedef const void* i18n_unormalizer_h;

/**
 * @brief Enumeration of constants for normalization modes.
 *        For details about standard Unicode normalization forms and about the algorithms which are also used with custom mapping tables see http://www.unicode.org/unicode/reports/tr15/
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UNORMALIZATION_COMPOSE,              /**< Decomposition followed by composition. Same as standard NFC when using an "nfc" instance. Same as standard NFKC when using an "nfkc" instance.
                                                   For details about standard Unicode normalization forms see http://www.unicode.org/unicode/reports/tr15/ */
    I18N_UNORMALIZATION_DECOMPOSE,            /**< Map and reorder canonically. Same as standard NFD when using an "nfc" instance. Same as standard NFKD when using an "nfkc" instance.
                                                   For details about standard Unicode normalization forms see http://www.unicode.org/unicode/reports/tr15/ */
    I18N_UNORMALIZATION_FCD,                  /**< "Fast C or D" form. If a string is in this form, then further decomposition without reordering would yield the same form as DECOMPOSE.
                                                   Text in "Fast C or D" form can be processed efficiently with data tables that are "canonically closed",
                                                   that is, that provide equivalent data for equivalent text, without having to be fully normalized.
                                                   Not a standard Unicode normalization form. Not a unique form: Different FCD strings can be canonically equivalent.
                                                   For details see http://www.unicode.org/notes/tn5/#FCD  */
    I18N_UNORMALIZATION_COMPOSE_CONTIGUOUS    /**< Compose only contiguously. Also known as "FCC" or "Fast C Contiguous". The result will often but not always be in NFC.
                                                   The result will conform to FCD which is useful for processing. Not a standard Unicode normalization form.
                                                   For details see http://www.unicode.org/notes/tn5/#FCC  */
} i18n_unormalization_mode_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_USEARCH_MODULE
 * @{
 */

/**
 * @brief i18n_usearch_h.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void* i18n_usearch_h;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE
 * @{
 */

/**
 * @brief i18n_ucalendar_h.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void* i18n_ucalendar_h;

/**
 * @brief The time zone ID reserved for unknown time zone.
 * @since_tizen 2.3.1
 */
#define I18N_UCALENDAR_UNKNOWN_ZONE_ID "Etc/Unknown"

/**
 * @brief Enumeration for possible fields in an #i18n_ucalendar_h.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UCALENDAR_ERA,                                 /**< Field number indicating the era, e.g., AD or BC in the Gregorian (Julian) calendar */
    I18N_UCALENDAR_YEAR,                                /**< Field number indicating the year */
    I18N_UCALENDAR_MONTH,                               /**< Field number indicating the month. This is a calendar-specific value. \n The first month of the year is JANUARY;
                                                             the last depends on the number of months in a year */
    I18N_UCALENDAR_WEEK_OF_YEAR,                        /**< Field number indicating the week number within the current year. \n
                                                             The first week of the year, as defined by the #I18N_UCALENDAR_FIRST_DAY_OF_WEEK and #I18N_UCALENDAR_MINIMAL_DAYS_IN_FIRST_WEEK attributes, has value 1.
                                                             Subclasses define the value of #I18N_UCALENDAR_WEEK_OF_YEAR for days before the first week of the year */
    I18N_UCALENDAR_WEEK_OF_MONTH,                       /**< Field number indicating the week number within the current month. \n
                                                             The first week of the month, as defined by the #I18N_UCALENDAR_FIRST_DAY_OF_WEEK and #I18N_UCALENDAR_MINIMAL_DAYS_IN_FIRST_WEEK attributes, has value 1.
                                                             Subclasses define the value of WEEK_OF_MONTH for days before the first week of the month */
    I18N_UCALENDAR_DATE,                                /**< Field number indicating the day of the month.  \n This is a synonym for DAY_OF_MONTH. The first day of the month has value 1  */
    I18N_UCALENDAR_DAY_OF_YEAR,                         /**< Field number indicating the day number within the current year. \n The first day of the year has value 1. */
    I18N_UCALENDAR_DAY_OF_WEEK,                         /**< Field number indicating the day of the week.   \n
                                                             This field takes values "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", and "Saturday" */
    I18N_UCALENDAR_DAY_OF_WEEK_IN_MONTH,                /**< Field number indicating the ordinal number of the day of the week within the current month.  \n
                                                             Together with the "day of week" field, this uniquely specifies a day within a month.
                                                             "day of month" 1 through 7 always correspond to "day of week in month" 1; 8 through 15 correspond to "day of week in month" 2, and so on.
                                                             "day of week in month" 0 indicates the week before "day of week in month" 1.
                                                             Negative values count back from the end of the month, so the last Sunday of a month is specified as "day of week" = "Sunday",
                                                             "day of week in month" = -1. Because negative values count backward they will usually be aligned differently within the month than positive values.
                                                             For example, if a month has 31 days, "day of week in month" -1 will overlap "day of week in month" 5 and the end of 4 */
    I18N_UCALENDAR_AM_PM,                               /**< Field number indicating whether the "hour" is before or after noon.  \n E.g., at 10:04:15.250 PM the AM_PM is PM */
    I18N_UCALENDAR_HOUR,                                /**< Field number indicating the hour of the morning or afternoon.  \n "hour" is used for the 12-hour clock. E.g., at 10:04:15.250 PM the "Hour" is 10 */
    I18N_UCALENDAR_HOUR_OF_DAY,                         /**< Field number indicating the hour of the day.  \n "Hour of day" is used for the 24-hour clock. E.g., at 10:04:15.250 PM the "Hour of day" is 22 */
    I18N_UCALENDAR_MINUTE,                              /**< Field number indicating the minute within the hour.  \n E.g., at 10:04:15.250 PM the #I18N_UCALENDAR_MINUTE is 4 */
    I18N_UCALENDAR_SECOND,                              /**< Field number indicating the second within the minute.  \n E.g., at 10:04:15.250 PM the #I18N_UCALENDAR_SECOND is 15 */
    I18N_UCALENDAR_MILLISECOND,                         /**< Field number indicating the millisecond within the second.  \n E.g., at 10:04:15.250 PM the #I18N_UCALENDAR_MILLISECOND is 250 */
    I18N_UCALENDAR_ZONE_OFFSET,                         /**< Field number indicating the raw offset from GMT in milliseconds  */
    I18N_UCALENDAR_DST_OFFSET,                          /**< Field number indicating the daylight savings offset in milliseconds  */
    I18N_UCALENDAR_YEAR_WOY,                            /**< Field number indicating the extended year corresponding to the #I18N_UCALENDAR_WEEK_OF_YEAR field. \n
                                                             This may be one greater or less than the value of #I18N_UCALENDAR_EXTENDED_YEAR */
    I18N_UCALENDAR_DOW_LOCAL,                           /**< Field number indicating the localized day of the week. \n
                                                             This will be a value from 1 to 7 inclusive, with 1 being the localized first day of the week */
    I18N_UCALENDAR_EXTENDED_YEAR,                       /**< Year of this calendar system, encompassing all supra-year fields. \n
                                                             For example, in Gregorian/Julian calendars, positive Extended Year values indicate years AD, 1 BC = 0 extended, 2 BC = -1 extended, and so on */
    I18N_UCALENDAR_JULIAN_DAY,                          /**< Field number indicating the modified Julian day number. \n
                                                             This is different from the conventional Julian day number in two regards.
                                                             First, it demarcates days at local zone midnight, rather than noon GMT. Second, it is a local number; that is, it depends on the local time zone.
                                                             It can be thought of as a single number that encompasses all the date-related fields */
    I18N_UCALENDAR_MILLISECONDS_IN_DAY,                 /**< Ranges from 0 to 23:59:59.999 (regardless of DST). \n
                                                             This field behaves exactly like a composite of all time-related fields, not including the zone fields.
                                                             As such, it also reflects discontinuities in those fields on DST transition days. On a day of DST onset, it will jump forward.
                                                             On a day of DST cessation, it will jump backward.
                                                             This reflects the fact that it must be combined with the DST offset field to obtain a unique local time value */
    I18N_UCALENDAR_IS_LEAP_MONTH,                       /**< Whether or not the current month is a leap month (0 or 1) */
    I18N_UCALENDAR_FIELD_COUNT,                         /**< Number of enumerators */
    I18N_UCALENDAR_DAY_OF_MONTH = I18N_UCALENDAR_DATE   /**< Field number indicating the day of the month.  \n This is a synonym for #I18N_UCALENDAR_DATE. The first day of the month has value 1 */
} i18n_ucalendar_date_fields_e;

/**
 * @brief Enumeration for possible months in an #i18n_ucalendar_h.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UCALENDAR_TRADITIONAL,                             /**< Despite the name, #I18N_UCALENDAR_TRADITIONAL designates the locale's default calendar, which may be the Gregorian calendar or some other calendar */
    I18N_UCALENDAR_DEFAULT = I18N_UCALENDAR_TRADITIONAL,    /**< A better name for #I18N_UCALENDAR_TRADITIONAL  */
    I18N_UCALENDAR_GREGORIAN                                /**< Unambiguously designates the Gregorian calendar for the locale */
} i18n_ucalendar_type_e;

/**
 * @brief Enumeration for possible months in an #i18n_ucalendar_h.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UCALENDAR_JANUARY,         /**< January */
    I18N_UCALENDAR_FEBRUARY,        /**< February */
    I18N_UCALENDAR_MARCH,           /**< March */
    I18N_UCALENDAR_APRIL,           /**< April */
    I18N_UCALENDAR_MAY,             /**< May */
    I18N_UCALENDAR_JUNE,            /**< June */
    I18N_UCALENDAR_JULY,            /**< July */
    I18N_UCALENDAR_AUGUST,          /**< August */
    I18N_UCALENDAR_SEPTEMBER,       /**< September */
    I18N_UCALENDAR_OCTOBER,         /**< October */
    I18N_UCALENDAR_NOVEMBER,        /**< November */
    I18N_UCALENDAR_DECEMBER         /**< December */
} i18n_ucalendar_months_e;

/**
 * @brief Enumeration for possible formats of an #i18n_ucalendar_h's display name.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UCALENDAR_STANDARD,          /**< Standard display name */
    I18N_UCALENDAR_SHORT_STANDARD,    /**< Short standard display name */
    I18N_UCALENDAR_DST,               /**< Daylight savings display name */
    I18N_UCALENDAR_SHORT_DST          /**< Short daylight savings display name */
} i18n_ucalendar_displayname_type_e;

/**
 * @brief Enumeration for types of #i18n_ucalendar_h attributes.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UCALENDAR_LENIENT,                       /**< Lenient parsing */
    I18N_UCALENDAR_FIRST_DAY_OF_WEEK,             /**< First day of the week */
    I18N_UCALENDAR_MINIMAL_DAYS_IN_FIRST_WEEK     /**< Minimum number of days in the first week */
} i18n_ucalendar_attribute_e;

/**
 * @brief System time zone type constants.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UCALENDAR_ZONE_TYPE_ANY,                   /**< Any system zones. */
    I18N_UCALENDAR_ZONE_TYPE_CANONICAL,             /**< Canonical system zones. */
    I18N_UCALENDAR_ZONE_TYPE_CANONICAL_LOCATION     /**< Canonical system zones associated with actual locations. */
} i18n_system_timezone_type_e;

/**
 * @brief Possible limit values for an #i18n_ucalendar_h.
 * @since_tizen 2.3.1
 */
typedef enum {
    I18N_UCALENDAR_MINIMUM,             /**< Minimum value */
    I18N_UCALENDAR_MAXIMUM,             /**< Maximum value */
    I18N_UCALENDAR_GREATEST_MINIMUM,    /**< Greatest minimum value */
    I18N_UCALENDAR_LEAST_MAXIMUM,       /**< Least maximum value */
    I18N_UCALENDAR_ACTUAL_MINIMUM,      /**< Actual minimum value */
    I18N_UCALENDAR_ACTUAL_MAXIMUM       /**< Actual maximum value */
} i18n_ucalendar_limit_type_e;

/**
 * @brief Weekday types, as returned by i18n_ucalendar_get_day_of_week_type().
 * @since_tizen 2.3.1
 */
typedef enum {
    I18N_UCALENDAR_WEEKDAY,           /**< Designates a full weekday (no part of the day is included in the weekend). */
    I18N_UCALENDAR_WEEKEND,           /**< Designates a full weekend day (the entire day is included in the weekend). */
    I18N_UCALENDAR_WEEKEND_ONSET,     /**< Designates a day that starts as a weekday and transitions to the weekend.
                                           Call i18n_ucalendar_get_weekend_transition() to get the time of transition. */
    I18N_UCALENDAR_WEEKEND_CEASE,     /**< Designates a day that starts as the weekend and transitions to a weekday.
                                           Call i18n_ucalendar_get_weekend_transition() to get the time of transition. */
} i18n_ucalendar_weekday_type_e;

/**
 * @brief Useful constants for days of week.
 * @details Note: Calendar day-of-week is 1-based. Clients who create locale resources for the field of first-day-of-week should be aware of this.
 *          For instance, in US locale, first-day-of-week is set to 1, i.e., #I18N_UCALENDAR_SUNDAY. Possible days of the week in an #i18n_ucalendar_h.
 * @since_tizen 2.3.1
 */
typedef enum  {
    I18N_UCALENDAR_SUNDAY = 1,    /**< Sunday */
    I18N_UCALENDAR_MONDAY,        /**< Monday */
    I18N_UCALENDAR_TUESDAY,       /**< Tuesday */
    I18N_UCALENDAR_WEDNESDAY,     /**< Wednesday */
    I18N_UCALENDAR_THURSDAY,      /**< Thursday */
    I18N_UCALENDAR_FRIDAY,        /**< Friday */
    I18N_UCALENDAR_SATURDAY       /**< Saturday */
} i18n_ucalendar_days_of_week_e;

/**
 * @brief Time zone transition types for i18n_ucalendar_get_timezone_transition_date().
 * @since_tizen 2.3.1
 *
 * @see i18n_ucalendar_get_timezone_transition_date()
 */
typedef enum {
    I18N_UCALENDAR_TZ_TRANSITION_NEXT,                   /**< Get the next transition after the current date, i.e. excludes the current date  */
    I18N_UCALENDAR_TZ_TRANSITION_NEXT_INCLUSIVE,         /**< Get the next transition on or after the current date, i.e. may include the current date */
    I18N_UCALENDAR_TZ_TRANSITION_PREVIOUS,               /**< Get the previous transition before the current date, i.e. excludes the current date */
    I18N_UCALENDAR_TZ_TRANSITION_PREVIOUS_INCLUSIVE,     /**< Get the previous transition on or before the current date, i.e. may include the current date */
} i18n_utimezone_transition_type_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UDATE_MODULE
 * @{
 */

/**
 * @brief Date and Time data type. \n This is a primitive data type that holds the date and time as the number of milliseconds since 1970-jan-01, 00:00 UTC. UTC leap seconds are ignored.
 */

/**
 * @brief Date and Time data type.
 * @details This is a primitive data type that holds the date and time as the number of milliseconds since 1970-jan-01, 00:00 UTC. UTC leap seconds are ignored.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef double i18n_udate;

/**
 * @brief A date formatter.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void *i18n_udate_format_h;

/**
 * @brief A struct representing a range of text containing a specific field.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef struct {
    int32_t field;              /**< The field. */
    int32_t beginIndex;         /**< The start of the text range containing field.*/
    int32_t endIndex;           /**< The limit of the text range containing field.*/
} i18n_ufield_position_s;

/**
 * @brief Handle to struct representing a range of text containing a specific field.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef i18n_ufield_position_s* i18n_ufield_position_h;

/**
 * @brief Enumeration for the possible date/time format styles.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UDATE_FULL,                                                         /**< Full style */
    I18N_UDATE_LONG,                                                         /**< Long style */
    I18N_UDATE_MEDIUM,                                                       /**< Medium style */
    I18N_UDATE_SHORT,                                                        /**< Short style */
    I18N_UDATE_DEFAULT           = I18N_UDATE_MEDIUM,                        /**< Default style */
    I18N_UDATE_RELATIVE          = (1 << 7),                                 /**< Bitfield for relative date */
    I18N_UDATE_FULL_RELATIVE     = I18N_UDATE_FULL   | I18N_UDATE_RELATIVE,  /**< #I18N_UDATE_FULL | #I18N_UDATE_RELATIVE */
    I18N_UDATE_LONG_RELATIVE     = I18N_UDATE_LONG   | I18N_UDATE_RELATIVE,  /**< #I18N_UDATE_LONG | #I18N_UDATE_RELATIVE */
    I18N_UDATE_MEDIUM_RELATIVE   = I18N_UDATE_MEDIUM | I18N_UDATE_RELATIVE,  /**< #I18N_UDATE_MEDIUM | #I18N_UDATE_RELATIVE */
    I18N_UDATE_SHORT_RELATIVE    = I18N_UDATE_SHORT  | I18N_UDATE_RELATIVE,  /**< #I18N_UDATE_SHORT | #I18N_UDATE_RELATIVE */
    I18N_UDATE_NONE              = -1,                                       /**< No style */
    I18N_UDATE_PATTERN           = -2                                        /**< Use the pattern given in the parameter to i18n_udate_create(). */
} i18n_udate_format_style_e;

/**
 * @brief Enumeration for format fields.
 * @since_tizen 2.3.1
 */
typedef enum {
    I18N_UDATE_FORMAT_ERA_FIELD,                           /**< Era field */
    I18N_UDATE_FORMAT_YEAR_FIELD,                          /**< Year field */
    I18N_UDATE_FORMAT_MONTH_FIELD,                         /**< Month field */
    I18N_UDATE_FORMAT_DATE_FIELD,                          /**< Date field */
    I18N_UDATE_FORMAT_HOUR_OF_DAY1_FIELD,                  /**< Hour of day1 field */
    I18N_UDATE_FORMAT_HOUR_OF_DAY0_FIELD,                  /**< Hour of day0 field */
    I18N_UDATE_FORMAT_MINUTE_FIELD,                        /**< Minute field */
    I18N_UDATE_FORMAT_SECOND_FIELD,                        /**< Second field */
    I18N_UDATE_FORMAT_FRACTIONAL_SECOND_FIELD,             /**< Fractional second field */
    I18N_UDATE_FORMAT_DAY_OF_WEEK_FIELD,                   /**< Day of week field */
    I18N_UDATE_FORMAT_DAY_OF_YEAR_FIELD,                   /**< Day of year field */
    I18N_UDATE_FORMAT_DAY_OF_WEEK_IN_MONTH_FIELD,          /**< Day of week in month field */
    I18N_UDATE_FORMAT_WEEK_OF_YEAR_FIELD,                  /**< Week of year field */
    I18N_UDATE_FORMAT_WEEK_OF_MONTH_FIELD,                 /**< Week of month field */
    I18N_UDATE_FORMAT_AM_PM_FIELD,                         /**< a.m. / p.m. field */
    I18N_UDATE_FORMAT_HOUR1_FIELD,                         /**< Hour1 field */
    I18N_UDATE_FORMAT_HOUR0_FIELD,                         /**< Hour0 field */
    I18N_UDATE_FORMAT_TIMEZONE_FIELD,                      /**< Timezone field */
    I18N_UDATE_FORMAT_YEAR_WOY_FIELD,                      /**< Year woy field */
    I18N_UDATE_FORMAT_DOW_LOCAL_FIELD,                     /**< Dow local field */
    I18N_UDATE_FORMAT_EXTENDED_YEAR_FIELD,                 /**< Extended year field */
    I18N_UDATE_FORMAT_JULIAN_DAY_FIELD,                    /**< Julian day field */
    I18N_UDATE_FORMAT_MILLISECONDS_IN_DAY_FIELD,           /**< Milliseconds in day field */
    I18N_UDATE_FORMAT_TIMEZONE_RFC_FIELD,                  /**< Timezone RFC field */
    I18N_UDATE_FORMAT_TIMEZONE_GENERIC_FIELD,              /**< Timezone generic field */
    I18N_UDATE_FORMAT_STANDALONE_DAY_FIELD,                /**< Standalone day field */
    I18N_UDATE_FORMAT_STANDALONE_MONTH_FIELD,              /**< Standalone month field */
    I18N_UDATE_FORMAT_QUARTER_FIELD,                       /**< Quarter field */
    I18N_UDATE_FORMAT_STANDALONE_QUARTER_FIELD,            /**< Standalone quarter field */
    I18N_UDATE_FORMAT_TIMEZONE_SPECIAL_FIELD,              /**< Timezone special field */
    I18N_UDATE_FORMAT_YEAR_NAME_FIELD,                     /**< Year name field */
    I18N_UDATE_FORMAT_TIMEZONE_LOCALIZED_GMT_OFFSET_FIELD, /**< Timezone localized gmt offset field */
    I18N_UDATE_FORMAT_TIMEZONE_ISO_FIELD,                  /**< Timezone ISO field */
    I18N_UDATE_FORMAT_TIMEZONE_ISO_LOCAL_FIELD,            /**< Timezone ISO local field */
    I18N_UDATE_FORMAT_FIELD_COUNT                          /**< Field count */
} i18n_udate_format_field_e;

/**
 * @brief Enumeration for symbol types.
 * @since_tizen 2.3.1
 */
typedef enum {
    I18N_UDATE_FORMAT_SYMBOL_TYPE_ERAS,                        /**< Eras */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_MONTHS,                      /**< Months */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_SHORT_MONTHS,                /**< Short months */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_WEEKDAYS,                    /**< Weekdays */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_SHORT_WEEKDAYS,              /**< Short weekdays */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_AM_PMS,                      /**< AM PMs */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_LOCALIZED_CHARS,             /**< Localized chars */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_ERA_NAMES,                   /**< Era names */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_NARROW_MONTHS,               /**< Narrow months */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_NARROW_WEEKDAYS,             /**< Narrow weekdays */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_MONTHS,           /**< Standalone months */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_SHORT_MONTHS,     /**< Standalone short months */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_NARROW_MONTHS,    /**< Standalone narrow months */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_WEEKDAYS,         /**< Standalone weekdays */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_SHORT_WEEKDAYS,   /**< Standalone short weekdays */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_NARROW_WEEKDAYS,  /**< Standalone narrow weekdays */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_QUARTERS,                    /**< Quarters */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_SHORT_QUARTERS,              /**< Short quarters */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_QUARTERS,         /**< Standalone quarters */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_SHORT_QUARTERS,   /**< Standalone short quarters */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_SHORTER_WEEKDAYS,            /**< Shorter weekdays */
    I18N_UDATE_FORMAT_SYMBOL_TYPE_STANDALONE_SHORTER_WEEKDAYS, /**< Standalone shorter weekdays */
} i18n_udate_format_symbol_type_e;

/**
 * @brief Display context types, for getting values of a particular setting.
 * @details Note, the specific numeric values are internal and may change.
 * @since_tizen 2.3.1

 */
typedef enum{
    I18N_UDISPCTX_TYPE_DIALECT_HANDLING,        /**<Type to retrieve the dialect handling setting, e.g. UDISPCTX_STANDARD_NAMES or UDISPCTX_DIALECT_NAMES.   */
    I18N_UDISPCTX_TYPE_CAPITALIZATION,          /**<Type to retrieve the capitalization context setting, e.g. UDISPCTX_CAPITALIZATION_NONE, UDISPCTX_CAPITALIZATION_FOR_MIDDLE_OF_SENTENCE, UDISPCTX_CAPITALIZATION_FOR_BEGINNING_OF_SENTENCE, etc.   */
#ifndef U_HIDE_DRAFT_API
    I18N_UDISPCTX_TYPE_DISPLAY_LENGTH           /**<Type to retrieve the display length setting, e.g. UDISPCTX_LENGTH_FULL, UDISPCTX_LENGTH_SHORT.  */
#endif /* U_HIDE_DRAFT_API */
} i18n_udisplay_context_type_e;

/**
 * @brief Enumeration for display context.
 * @since_tizen 2.3.1
 */
typedef enum {
    I18N_UDISPLAY_CONTEXT_STANDARD_NAMES                           = (I18N_UDISPCTX_TYPE_DIALECT_HANDLING<<8) + 0, /**< Standard names */
    I18N_UDISPLAY_CONTEXT_DIALECT_NAMES                            = (I18N_UDISPCTX_TYPE_DIALECT_HANDLING<<8) + 1, /**< Dialect names */
    I18N_UDISPLAY_CONTEXT_CAPITALIZATION_NONE                      = (I18N_UDISPCTX_TYPE_CAPITALIZATION<<8) + 0,   /**< Capitalization: None */
    I18N_UDISPLAY_CONTEXT_CAPITALIZATION_FOR_MIDDLE_OF_SENTENCE    = (I18N_UDISPCTX_TYPE_CAPITALIZATION<<8) + 1,   /**< Capitalization: For middle of sentence */
    I18N_UDISPLAY_CONTEXT_CAPITALIZATION_FOR_BEGINNING_OF_SENTENCE = (I18N_UDISPCTX_TYPE_CAPITALIZATION<<8) + 2,   /**< Capitalization: For beginning of sentence */
    I18N_UDISPLAY_CONTEXT_CAPITALIZATION_FOR_UI_LIST_OR_MENU       = (I18N_UDISPCTX_TYPE_CAPITALIZATION<<8) + 3,   /**< Capitalization: For UI list or menu */
    I18N_UDISPLAY_CONTEXT_CAPITALIZATION_FOR_STANDALONE            = (I18N_UDISPCTX_TYPE_CAPITALIZATION<<8) + 4,   /**< Capitalization: For standalone */
} i18n_udisplay_context_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UDATEPG_MODULE
 * @{
 */

/**
 * @brief Handle for a date/time pattern generator object.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void* i18n_udatepg_h;

/**
 * @brief Enumeration for field number constants for i18n_udatepg_get_append_item_format() and similar functions.
 * @details These constants are separate from #i18n_udate_format_field_e despite semantic overlap because some fields are merged for the date/time pattern generator.
 * @since_tizen 2.3.1
 */
typedef enum {
    I18N_UDATEPG_ERA_FIELD,                  /**< Era field */
    I18N_UDATEPG_YEAR_FIELD,                 /**< Year field */
    I18N_UDATEPG_QUARTER_FIELD,              /**< Quarter field */
    I18N_UDATEPG_MONTH_FIELD,                /**< Month field */
    I18N_UDATEPG_WEEK_OF_YEAR_FIELD,         /**< Week of year field */
    I18N_UDATEPG_WEEK_OF_MONTH_FIELD,        /**< Week of month field */
    I18N_UDATEPG_WEEKDAY_FIELD,              /**< Weekday field */
    I18N_UDATEPG_DAY_OF_YEAR_FIELD,          /**< Day of year field */
    I18N_UDATEPG_DAY_OF_WEEK_IN_MONTH_FIELD, /**< Day of week in month field */
    I18N_UDATEPG_DAY_FIELD,                  /**< Day field */
    I18N_UDATEPG_DAYPERIOD_FIELD,            /**< Day period field */
    I18N_UDATEPG_HOUR_FIELD,                 /**< Hour field */
    I18N_UDATEPG_MINUTE_FIELD,               /**< Minute field */
    I18N_UDATEPG_SECOND_FIELD,               /**< Second field */
    I18N_UDATEPG_FRACTIONAL_SECOND_FIELD,    /**< Fractional second field */
    I18N_UDATEPG_ZONE_FIELD,                 /**< Zone field */
    I18N_UDATEPG_FIELD_COUNT                 /**< Field count */
} i18n_udatepg_date_time_pattern_field_e;

/**
 * @brief Enumeration for masks to control forcing the length of specified fields in the returned pattern to match those in the skeleton (when this would not happen otherwise).\n
 * @details These may be combined to force the length of multiple fields.
 *          Used with i18n_udatepg_get_best_pattern_with_options(), i18n_udatepg_replace_field_types_with_options().
 * @since_tizen 2.3.1
 */
typedef enum {
    I18N_UDATEPG_MATCH_NO_OPTIONS        = 0,                                   /**< No options */
    I18N_UDATEPG_MATCH_HOUR_FIELD_LENGTH = 1 << I18N_UDATEPG_HOUR_FIELD,        /**< Hour field length */
    I18N_UDATEPG_MATCH_ALL_FIELDS_LENGTH = (1 << I18N_UDATEPG_FIELD_COUNT) - 1, /**< All fields length */
} i18n_udatepg_date_time_pattern_match_options_e;

/**
 * @brief Enumeration for status return values from i18n_udatepg_add_pattern().
 * @since_tizen 2.3.1
 */
typedef enum {
    I18N_UDATEPG_NO_CONFLICT,    /**< No conflict */
    I18N_UDATEPG_BASE_CONFLICT,  /**< Base conflict */
    I18N_UDATEPG_CONFLICT,       /**< Conflict */
    I18N_UDATEPG_CONFLICT_COUNT, /**< Number of status return values */
} i18n_udatepg_date_time_pattern_conflict_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UNUMBER_MODULE
 * @{
 */

/**
 * @brief A number formatter.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void* i18n_unumber_format_h;

/**
 * @brief Definition of context length.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
#define I18N_U_PARSE_CONTEXT_LEN 16

/**
 * @brief Struct used to returned detailed information about parsing errors.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef struct {
    int32_t    line;                                    /**< The line on which the error occured. */
    int32_t    offset;                                  /**< The character offset to the error */
    i18n_uchar preContext[I18N_U_PARSE_CONTEXT_LEN];    /**< Textual context before the error */
    i18n_uchar postContext[I18N_U_PARSE_CONTEXT_LEN];   /**< The error itself and/or textual context after the error */
} i18n_uparse_error_s;

/**
 * @brief Enumeration for the possible number format styles.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UNUMBER_PATTERN_DECIMAL      = 0,  /**< Decimal format defined by a pattern string */
    I18N_UNUMBER_DECIMAL              = 1,  /**< Decimal format ("normal" style) */
    I18N_UNUMBER_CURRENCY,                  /**< Currency format with a currency symbol, e.g., "$1.00" */
    I18N_UNUMBER_PERCENT,                   /**< Percent format */
    I18N_UNUMBER_SCIENTIFIC,                /**< Scientific format */
    I18N_UNUMBER_SPELLOUT,                  /**< Spellout rule-based format */
    I18N_UNUMBER_ORDINAL,                   /**< Ordinal rule-based format */
    I18N_UNUMBER_DURATION,                  /**< Duration rule-based format */
    I18N_UNUMBER_NUMBERING_SYSTEM,          /**< Numbering system rule-based format */
    I18N_UNUMBER_PATTERN_RULEBASED,         /**< Rule-based format defined by a pattern string */
    I18N_UNUMBER_CURRENCY_ISO,              /**< Currency format with an ISO currency code, e.g., "USD1.00" */
    I18N_UNUMBER_CURRENCY_PLURAL,           /**< Currency format with a pluralized currency name, e.g., "1.00 US dollar" and "3.00 US dollars" */

    I18N_UNUMBER_FORMAT_STYLE_COUNT   = I18N_UNUMBER_CURRENCY_PLURAL + 2,   /**< One more than the highest number format style constant */
    I18N_UNUMBER_DEFAULT              = I18N_UNUMBER_DECIMAL,               /**< Default format */
    I18N_UNUMBER_IGNORE               = I18N_UNUMBER_PATTERN_DECIMAL        /**< Alias for #I18N_UNUMBER_PATTERN_DECIMAL */
 } i18n_unumber_format_style_e;

/**
 * @brief Enumeration of constants for specifying a number format symbol.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_UNUMBER_DECIMAL_SEPARATOR_SYMBOL            = 0,       /**< The decimal separator */
    I18N_UNUMBER_GROUPING_SEPARATOR_SYMBOL           = 1,       /**< The grouping separator */
    I18N_UNUMBER_PATTERN_SEPARATOR_SYMBOL            = 2,       /**< The pattern separator */
    I18N_UNUMBER_PERCENT_SYMBOL                      = 3,       /**< The percent sign */
    I18N_UNUMBER_ZERO_DIGIT_SYMBOL                   = 4,       /**< Zero */
    I18N_UNUMBER_DIGIT_SYMBOL                        = 5,       /**< Character representing a digit in the pattern.*/
    I18N_UNUMBER_MINUS_SIGN_SYMBOL                   = 6,       /**< The minus sign */
    I18N_UNUMBER_PLUS_SIGN_SYMBOL                    = 7,       /**< The plus sign */
    I18N_UNUMBER_CURRENCY_SYMBOL                     = 8,       /**< The currency symbol */
    I18N_UNUMBER_INTL_CURRENCY_SYMBOL                = 9,       /**< The international currency symbol */
    I18N_UNUMBER_MONETARY_SEPARATOR_SYMBOL           = 10,      /**< The monetary separator */
    I18N_UNUMBER_EXPONENTIAL_SYMBOL                  = 11,      /**< The exponential symbol */
    I18N_UNUMBER_PERMILL_SYMBOL                      = 12,      /**< Per mill symbol */
    I18N_UNUMBER_PAD_ESCAPE_SYMBOL                   = 13,      /**< Escape padding character */
    I18N_UNUMBER_INFINITY_SYMBOL                     = 14,      /**< Infinity symbol */
    I18N_UNUMBER_NAN_SYMBOL                          = 15,      /**< NAN symbol */
    I18N_UNUMBER_SIGNIFICANT_DIGIT_SYMBOL            = 16,      /**< Significant digit symbol */
    I18N_UNUMBER_MONETARY_GROUPING_SEPARATOR_SYMBOL  = 17,      /**< The monetary grouping separator */
    I18N_UNUMBER_ONE_DIGIT_SYMBOL                    = 18,      /**< One */
    I18N_UNUMBER_TWO_DIGIT_SYMBOL                    = 19,      /**< Two */
    I18N_UNUMBER_THREE_DIGIT_SYMBOL                  = 20,      /**< Three */
    I18N_UNUMBER_FOUR_DIGIT_SYMBOL                   = 21,      /**< Four */
    I18N_UNUMBER_FIVE_DIGIT_SYMBOL                   = 22,      /**< Five */
    I18N_UNUMBER_SIX_DIGIT_SYMBOL                    = 23,      /**< Six */
    I18N_UNUMBER_SEVEN_DIGIT_SYMBOL                  = 24,      /**< Seven */
    I18N_UNUMBER_EIGHT_DIGIT_SYMBOL                  = 25,      /**< Eight */
    I18N_UNUMBER_NINE_DIGIT_SYMBOL                   = 26,      /**< Nine */
    I18N_UNUMBER_FORMAT_SYMBOL_COUNT                 = 27       /**< Number of enumerators */
 } i18n_unumber_format_symbol_e;

/**
 * @brief Enumeration for the possible unumber_format numeric attributes.
 * @since_tizen 2.3.1
 */
typedef enum {
    I18N_UNUMBER_PARSE_INT_ONLY,                   /**< Parse integers only */
    I18N_UNUMBER_GROUPING_USED,                    /**< Use grouping separator */
    I18N_UNUMBER_DECIMAL_ALWAYS_SHOWN,             /**< Always show decimal point */
    I18N_UNUMBER_MAX_INTEGER_DIGITS,               /**< Maximum integer digits */
    I18N_UNUMBER_MIN_INTEGER_DIGITS,               /**< Minimum integer digits */
    I18N_UNUMBER_INTEGER_DIGITS,                   /**< Integer digits */
    I18N_UNUMBER_MAX_FRACTION_DIGITS,              /**< Maximum fraction digits */
    I18N_UNUMBER_MIN_FRACTION_DIGITS,              /**< Minimum fraction digits */
    I18N_UNUMBER_FRACTION_DIGITS,                  /**< Fraction digits */
    I18N_UNUMBER_MULTIPLIER,                       /**< Multiplier */
    I18N_UNUMBER_GROUPING_SIZE,                    /**< Grouping size */
    I18N_UNUMBER_ROUNDING_MODE,                    /**< Rounding Mode */
    I18N_UNUMBER_ROUNDING_INCREMENT,               /**< Rounding increment */
    I18N_UNUMBER_FORMAT_WIDTH,                     /**< The width to which the output of format() is padded */
    I18N_UNUMBER_PADDING_POSITION,                 /**< The position at which padding will take place */
    I18N_UNUMBER_SECONDARY_GROUPING_SIZE,          /**< Secondary grouping size */
    I18N_UNUMBER_SIGNIFICANT_DIGITS_USED,          /**< Use significant digits */
    I18N_UNUMBER_MIN_SIGNIFICANT_DIGITS,           /**< Minimum significant digits */
    I18N_UNUMBER_MAX_SIGNIFICANT_DIGITS,           /**< Maximum significant digits */
    I18N_UNUMBER_LENIENT_PARSE,                    /**< Lenient parse mode used by rule-based formats */
    I18N_UNUM_SCALE = I18N_UNUMBER_LENIENT_PARSE + 2,           /**< Scale, which adjusts the position of the decimal point when formatting.
                                                                    Amounts will be multiplied by 10 ^ (scale) before they are formatted. The default value for the scale is 0 ( no adjustment ).
                                                                    Example: setting the scale to 3, 123 formats as "123,000"
                                                                    Example: setting the scale to -4, 123 formats as "0.0123" */
    I18N_UNUM_FORMAT_FAIL_IF_MORE_THAN_MAX_DIGITS  = 0x1000,    /**< If 1, specifies that if setting the "max integer digits" attribute would truncate a value, set an error status rather than silently truncating.
                                                                    For example, formatting the value 1234 with 4 max int digits would succeed, but formatting 12345 would fail.
                                                                    There is no effect on parsing. Default: 0 (not set) */
    I18N_UNUM_PARSE_NO_EXPONENT,                                /**< If this attribute is set to 1, specifies that, if the pattern doesn't contain an exponent,
                                                                    the exponent will not be parsed. If the pattern does contain an exponent, this attribute has no effect.
                                                                    Has no effect on formatting. Default: 0 (unset) */
} i18n_unumber_format_attribute_e;

/**
 * @brief The possible #i18n_unumber_format_h text attributes.
 * @since_tizen 2.3.1
 */
typedef enum {
    I18N_UNUMBER_POSITIVE_PREFIX,               /**< Positive prefix */
    I18N_UNUMBER_POSITIVE_SUFFIX,               /**< Positive suffix */
    I18N_UNUMBER_NEGATIVE_PREFIX,               /**< Negative prefix */
    I18N_UNUMBER_NEGATIVE_SUFFIX,               /**< Negative suffix */
    I18N_UNUMBER_PADDING_CHARACTER,             /**< The character used to pad to the format width */
    I18N_UNUMBER_CURRENCY_CODE,                 /**< The ISO currency code */
    I18N_UNUMBER_DEFAULT_RULESET,               /**< The default rule set, such as "%spellout-numbering-year:", "%spellout-cardinal:", "%spellout-ordinal-masculine-plural:", "%spellout-ordinal-feminine:", or "%spellout-ordinal-neuter:".
                                                     The available public rulesets can be listed using i18n_unumber_get_text_attribute() with #I18N_UNUMBER_PUBLIC_RULESETS. This is only available with rule-based formatters */
    I18N_UNUMBER_PUBLIC_RULESETS,               /**< The public rule sets. This is only available with rule-based formatters. This is a read-only attribute.
                                                     The public rulesets are returned as a single string, with each ruleset name delimited by ';' (semicolon).
                                                     See the CLDR LDML spec for more information about RBNF rulesets: http://www.unicode.org/reports/tr35/tr35-numbers.html#Rule-Based_Number_Formatting */
} i18n_unumber_format_text_attribute_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_ULOCALE_MODULE
 * @{
 */

#define I18N_ULOCALE_CHINESE                   "zh"         /**< Useful constant for zh. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_ENGLISH                   "en"         /**< Useful constant for en. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_FRENCH                    "fr"         /**< Useful constant for fr. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_GERMAN                    "de"         /**< Useful constant for de. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_ITALIAN                   "it"         /**< Useful constant for it. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_JAPANESE                  "ja"         /**< Useful constant for ja. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_KOREAN                    "ko"         /**< Useful constant for ko. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_SIMPLIFIED_CHINESE        "zh_CN"      /**< Useful constant for zh_CN. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_TRADITIONAL_CHINESE       "zh_TW"      /**< Useful constant for zh_TW. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_CANADA                    "en_CA"      /**< Useful constant for en_CA. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_CANADA_FRENCH             "fr_CA"      /**< Useful constant for fr_CA. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_CHINA                     "zh_CN"      /**< Useful constant for zh_CN. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_PRC                       "zh_CN"      /**< Useful constant for zh_CN. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_FRANCE                    "fr_FR"      /**< Useful constant for fr_FR. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_GERMANY                   "de_DE"      /**< Useful constant for de_DE. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_ITALY                     "it_IT"      /**< Useful constant for it_IT. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_JAPAN                     "ja_JP"      /**< Useful constant for ja_JP. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_KOREA                     "ko_KR"      /**< Useful constant for ko_KR. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_TAIWAN                    "zh_TW"      /**< Useful constant for zh_TW. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_UK                        "en_GB"      /**< Useful constant for en_GB. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/
#define I18N_ULOCALE_US                        "en_US"      /**< Useful constant for en_US. @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif*/

/**
 * @brief Enumeration for the 'out_result' parameter return value
 * @since_tizen 2.3.1
 *
 * @see i18n_ulocale_accept_language_from_http()
 * @see i18n_ulocale_accept_language()
 */
typedef enum {
  I18N_ULOCALE_ACCEPT_FAILED   = 0,  /**< No exact match was found */
  I18N_ULOCALE_ACCEPT_VALID    = 1,  /**< An exact match was found */
  I18N_ULOCALE_ACCEPT_FALLBACK = 2,  /**< A fallback was found, for example,
                                          accept list contained 'ja_JP' which matched available locale 'ja' */
} i18n_ulocale_accept_result_e;

/**
 * @brief Enumeration for data locale types.
 * @since_tizen 2.3.1
 */
typedef enum {
    I18N_ULOCALE_DATA_LOCALE_TYPE_ACTUAL_LOCALE, /**< Actual locale */
    I18N_ULOCALE_DATA_LOCALE_TYPE_VALID_LOCALE,  /**< Valid locale */
    I18N_ULOCALE_DATA_LOCALE_TYPE_LIMIT = 3,     /**< Locale type limit */
} i18n_ulocale_data_locale_type_e;

/**
 * @brief Enumeration for the return value for the character and line orientation functions.
 * @since_tizen 2.3.1
 */
typedef enum {
  I18N_ULOCALE_LAYOUT_LTR     = 0,  /**< Left-to-right */
  I18N_ULOCALE_LAYOUT_RTL     = 1,  /**< Right-to-left */
  I18N_ULOCALE_LAYOUT_TTB     = 2,  /**< Top-to-bottom */
  I18N_ULOCALE_LAYOUT_BTT     = 3,  /**< Bottom-to-top */
  I18N_ULOCALE_LAYOUT_UNKNOWN       /**< Unknown       */
} i18n_ulocale_layout_type_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_USTRING_MODULE
 * @{
 */

/**
 * @brief Callback function for i18n_ustring_unescape_at() that returns a character of the source text given an offset and a context pointer.\n
 *        The context pointer will be whatever is passed into i18n_ustring_unescape_at().
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @param[in]   offset      pointer to the offset that will be passed to i18n_ustring_unescape_at().
 * @param[in]   context     an opaque pointer passed directly into i18n_ustring_unescape_at()
 *
 * @retval  character   the character represented by the escape sequence at offset
 *
 * @see #i18n_ustring_unescape_at()
 */
typedef i18n_uchar(* i18n_ustring_unescape_char_at_cb)(int32_t offset, void *context);

/**
 * @brief Option value for case folding: use default mappings defined in CaseFolding.txt.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
#define I18N_USTRING_U_FOLD_CASE_DEFAULT 0


/**
 * @brief Option bit i18n_ustring_case_compare_with_length(), i18n_ustring_case_compare(), etc: Compare strings in code point order instead of code unit order.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
#define I18N_USTRING_U_COMPARE_CODE_POINT_ORDER  0x8000

/**
 * @brief Option value for case folding: \n
 * Use the modified set of mappings provided in CaseFolding.txt to handle dotted I and dotless i appropriately for Turkic languages (tr, az).\n
 * Before Unicode 3.2, CaseFolding.txt contains mappings marked with 'I' that are to be included for default mappings and excluded for the Turkic-specific mappings.\n
 * Unicode 3.2 CaseFolding.txt instead contains mappings marked with 'T' that are to be excluded for default mappings and included for the Turkic-specific mappings.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
#define I18N_USTRING_U_FOLD_CASE_EXCLUDE_SPECIAL_I 1

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE
 * @{
 */

/**
 * @brief handle for object that represents a time zone offset, and also figures out daylight savings..
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void* i18n_timezone_h;

/**
 * @brief Callback function for i18n_timezone_foreach_timezone_id(), i18n_timezone_foreach_timezone_id_with_offset(), and i18n_timezone_foreach_timezone_id_by_country()
 *        that returns an enumeration over all recognized time zone IDs.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 *
 * @param[in] timezone_id   time zone ID
 * @param[in] user_data     the user data passed to the callback function
 *
 * @return @c true to continue with the next iteration of the loop, otherwise @c false to break out of the loop.
 *
 * @see i18n_ustring_unescape_at()
 */
typedef bool (*i18n_timezone_id_cb)(const char *timezone_id, void* user_data);

/**
 * @brief Enumeration for use with i18n_timezone_get_display_name(), i18n_timezone_get_display_name_with_locale(), and i18n_timezone_get_display_name_with_type().
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef enum {
    I18N_TIMEZONE_DISPLAY_TYPE_SHORT = 1,           /**< Selector for short display name */
    I18N_TIMEZONE_DISPLAY_TYPE_LONG,                /**< Selector for long display name */
    I18N_TIMEZONE_DISPLAY_TYPE_SHORT_GENERIC,       /**< Selector for short generic display name */
    I18N_TIMEZONE_DISPLAY_TYPE_LONG_GENERIC,        /**< Selector for long generic display name */
    I18N_TIMEZONE_DISPLAY_TYPE_SHORT_GMT,           /**< Selector for short display name derived */
    I18N_TIMEZONE_DISPLAY_TYPE_LONG_GMT,            /**< Selector for long display name derived from time zone offset */
    I18N_TIMEZONE_DISPLAY_TYPE_SHORT_COMMONLY_USED, /**< Selector for short display name derived from the time zone's fallback name */
    I18N_TIMEZONE_DISPLAY_TYPE_GENERIC_LOCATION     /**< Selector for long display name derived from the time zone's fallback name */
}i18n_timezone_display_type_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UBRK_MODULE
 * @{
 */

/**
 * @brief i18n_ubreak_iterator_s.
 * @since_tizen @if MOBILE 2.3 @elseif WEARABLE 2.3.1 @endif
 */
typedef void* i18n_ubreak_iterator_s;

/**
 * @brief i18n_ubreak_iterator_h.
 * @since_tizen 2.3.1
 */
typedef void* i18n_ubreak_iterator_h;

/**
 * @brief A recommended size (in bytes) for the memory buffer to be passed to i18n_ubrk_safe_clone().
 * @since_tizen 2.3.1
 */
#define I18N_U_BRK_SAFECLONE_BUFFERSIZE 528

/**
 * @brief Value indicating all text boundaries have been returned.
 * @since_tizen 2.3.1
 */
#define I18N_UBRK_DONE   ((int32_t) -1)

/**
 * @brief The possible types of text boundaries.
 * @since_tizen 2.3.1
 *
 */
typedef enum {
    I18N_UBRK_CHARACTER = 0,     /**< Character breaks */
    I18N_UBRK_WORD      = 1,     /**< Word breaks */
    I18N_UBRK_LINE      = 2,     /**< Line breaks */
    I18N_UBRK_SENTENCE  = 3,     /**< Sentence breaks */
} i18n_ubreak_iterator_type_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_USET_MODULE
 * @{
 */

/**
 * @brief An #i18n_uset_h handle.
 * @details Use the @c i18n_uset_* API to manipulate. Create with @c i18n_uset_create*, and destroy with i18n_uset_destroy().
 * @since_tizen 2.3.1
 */
typedef void *i18n_uset_h;

/**
 * @brief Capacity of #i18n_userialized_set_s::static_array.
 *        Enough for any single-code point set.
 * @since_tizen 2.3.1
 *
 * @see #i18n_userialized_set_s
 */
#define I18N_USET_SERIALIZED_STATIC_ARRAY_CAPACITY 8

/**
 * @brief  A serialized form of a Unicode set.
 * @since_tizen 2.3.1
 */
typedef struct {
    const uint16_t *array;                                                        /**< The serialized Unicode Set. */
    int32_t         bmp_length;                                                   /**< The length of the array that contains BMP characters. */
    int32_t         length;                                                       /**< The total length of the array. */
    uint16_t        static_array[I18N_USET_SERIALIZED_STATIC_ARRAY_CAPACITY];     /**< A small buffer for the array to reduce memory allocations. */
} i18n_userialized_set_s;


/**
 * @brief Enumeration for span conditions.
 * @since_tizen 2.3.1
 *
 * @see i18n_uset_span()
 * @see i18n_uset_span_back()
 * @see i18n_uset_span_utf8()
 * @see i18n_uset_span_back_utf8()
 */
typedef enum {
    I18N_USET_SPAN_NOT_CONTAINED = 0,   /**< Continue a span() while there is no set element at the current position.
                                             Stops before the first set element (character or string).
                                             (For code points only, this is like while contains(current)==false).

                                             When span() returns, the substring between where it started and the position
                                             it returned consists only of characters that are not in the set,
                                             and none of its strings overlap with the span. */
    I18N_USET_SPAN_CONTAINED = 1,       /**< Continue a span() while there is a set element at the current position.
                                             (For characters only, this is like while contains(current)==true).

                                             When span() returns, the substring between where it started and the position
                                             it returned consists only of set elements (characters or strings) that are in the set.

                                             If a set contains strings, then the span will be the longest substring
                                             matching any of the possible concatenations of set elements (characters or strings).
                                             (There must be a single, non-overlapping concatenation of characters or strings.)
                                             This is equivalent to a POSIX regular expression for (OR of each set element). */
    I18N_USET_SPAN_SIMPLE = 2,          /**< Continue a span() while there is a set element at the current position.
                                             (For characters only, this is like while contains(current)==true).

                                             When span() returns, the substring between where it started and the position
                                             it returned consists only of set elements (characters or strings) that are in the set.

                                             If a set only contains single characters, then this is the same
                                             as #I18N_USET_SPAN_CONTAINED.

                                             If a set contains strings, then the span will be the longest substring
                                             with a match at each position with the longest single set element (character or string). */
    I18N_USET_SPAN_CONDITION_COUNT      /**< One more than the last span condition.  */
} i18n_uset_span_condition_e;


/**
 * @brief Enumeration for bitmask values to be passed to i18n_uset_pattern_options_create() or i18n_uset_apply_pattern() taking an option parameter.
 * @since_tizen 2.3.1
 */
enum {
    I18N_USET_IGNORE_SPACE = 1,         /**< Ignore white space within patterns unless quoted or escaped. */
    I18N_USET_CASE_INSENSITIVE = 2,     /**< Enable case insensitive matching.
                                             E.g., "[ab]" with this flag will match 'a', 'A', 'b', and 'B'.
                                             "[^ab]" with this flag will match all except 'a', 'A', 'b', and 'B'.
                                             This performs a full closure over case mappings, e.g. U+017F for s.

                                             The resulting set is a superset of the input for the code points but not for the strings.
                                             It performs a case mapping closure of the code points and adds full case folding strings for the code points,
                                             and reduces strings of the original set to their full case folding equivalents.

                                             This is designed for case-insensitive matches, for example in regular expressions.
                                             The full code point case closure allows checking of an input character directly against the closure set.
                                             Strings are matched by comparing the case-folded form from the closure
                                             set with an incremental case folding of the string in question.

                                             The closure set will also contain single code points if the original
                                             set contained case-equivalent strings (like U+00DF for "ss" or "Ss" etc.).
                                             This is not necessary (that is, redundant) for the above matching method
                                             but results in the same closure sets regardless of whether the original
                                             set contained the code point or a string. */

    I18N_USET_ADD_CASE_MAPPINGS = 4     /**< Enable case insensitive matching.
                                             E.g., "[ab]" with this flag will match 'a', 'A', 'b', and 'B'.
                                             "[^ab]" with this flag will match all except 'a', 'A', 'b', and 'B'.
                                             This adds the lower-, title-, and uppercase mappings as well as the case folding of each existing element in the set. */
};

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UENUMERATION_MODULE
 * @{
 */

/**
 * @brief Structure representing an enumeration.
 * @details For usage in C programs.
 * @since_tizen 2.3.1
 */
typedef void* i18n_uenumeration_h;

/**
 * @}
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif	/* __UTILS_I18N_TYPES_H__*/
