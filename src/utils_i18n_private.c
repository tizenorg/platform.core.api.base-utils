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

#include <utils_i18n_private.h>

int _i18n_error_mapping ( int err )
{
    if(err == U_STRING_NOT_TERMINATED_WARNING) return I18N_WARNING_STRING_NOT_TERMINATED;
    else if(err == U_SORT_KEY_TOO_SHORT_WARNING) return I18N_WARNING_SORT_KEY_TOO_SHORT;
    else if(err <= U_ZERO_ERROR) return I18N_ERROR_NONE;

    switch (err) {
    case U_ILLEGAL_ARGUMENT_ERROR      : return I18N_ERROR_INVALID_PARAMETER;
    case U_MISSING_RESOURCE_ERROR      : return I18N_ERROR_MISSING_RESOURCE;
    case U_INVALID_FORMAT_ERROR        : return I18N_ERROR_INVALID_FORMAT;
    case U_FILE_ACCESS_ERROR           : return I18N_ERROR_FILE_ACCESS;
    case U_INTERNAL_PROGRAM_ERROR      : return I18N_ERROR_INTERNAL_PROGRAM;
    case U_MESSAGE_PARSE_ERROR         : return I18N_ERROR_MESSAGE_PARSE;
    case U_MEMORY_ALLOCATION_ERROR     : return I18N_ERROR_OUT_OF_MEMORY;
    case U_INDEX_OUTOFBOUNDS_ERROR     : return I18N_ERROR_INDEX_OUTOFBOUNDS;
    case U_PARSE_ERROR                 : return I18N_ERROR_PARSE;
    case U_INVALID_CHAR_FOUND          : return I18N_ERROR_INVALID_CHAR_FOUND;
    case U_TRUNCATED_CHAR_FOUND        : return I18N_ERROR_TRUNCATED_CHAR_FOUND;
    case U_ILLEGAL_CHAR_FOUND          : return I18N_ERROR_ILLEGAL_CHAR_FOUND;
    case U_INVALID_TABLE_FORMAT        : return I18N_ERROR_INVALID_TABLE_FORMAT;
    case U_INVALID_TABLE_FILE          : return I18N_ERROR_INVALID_TABLE_FILE;
    case U_BUFFER_OVERFLOW_ERROR       : return I18N_ERROR_BUFFER_OVERFLOW;
    case U_UNSUPPORTED_ERROR           : return I18N_ERROR_NOT_SUPPORTED;
    case U_RESOURCE_TYPE_MISMATCH      : return I18N_ERROR_RESOURCE_TYPE_MISMATCH;
    case U_ILLEGAL_ESCAPE_SEQUENCE     : return I18N_ERROR_ILLECAL_ESCAPE_SEQUENCE;
    case U_UNSUPPORTED_ESCAPE_SEQUENCE : return I18N_ERROR_UNSUPPORTED_ESCAPE_SEQUENCE;
    case U_NO_SPACE_AVAILABLE          : return I18N_ERROR_NO_SPACE_AVAILABLE;
    case U_CE_NOT_FOUND_ERROR          : return I18N_ERROR_CE_NOT_FOUND;
    case U_PRIMARY_TOO_LONG_ERROR      : return I18N_ERROR_PRIMARY_TOO_LONG;
    case U_STATE_TOO_OLD_ERROR         : return I18N_ERROR_STATE_TOO_OLD;
    case U_TOO_MANY_ALIASES_ERROR      : return I18N_ERROR_TOO_MANY_ALIASES;
    case U_ENUM_OUT_OF_SYNC_ERROR      : return I18N_ERROR_ENUM_OUT_OF_SYNC;
    case U_INVARIANT_CONVERSION_ERROR  : return I18N_ERROR_INVARIANT_CONVERSION;
    case U_INVALID_STATE_ERROR         : return I18N_ERROR_INVALID_STATE;
    case U_COLLATOR_VERSION_MISMATCH   : return I18N_ERROR_COLLATOR_VERSION_MISMATCH;
    case U_USELESS_COLLATOR_ERROR      : return I18N_ERROR_USELESS_COLLATOR;
    case U_NO_WRITE_PERMISSION         : return I18N_ERROR_NO_WRITE_PERMISSION;
    case U_MALFORMED_SET               : return I18N_ERROR_MALFORMED_SET;
    case U_IDNA_STD3_ASCII_RULES_ERROR : return I18N_ERROR_STD3_ASCII_RULES;
    case U_IDNA_UNASSIGNED_ERROR       : return I18N_ERROR_UNASSIGNED;
    default : return I18N_ERROR_UNKNOWN;
    }
}

int _i18n_error_mapping_reverse ( int err )
{
    switch (err) {
    case I18N_ERROR_NONE                        : return U_ZERO_ERROR;
    case I18N_ERROR_INVALID_PARAMETER           : return U_ILLEGAL_ARGUMENT_ERROR;
    case I18N_ERROR_MISSING_RESOURCE            : return U_MISSING_RESOURCE_ERROR;
    case I18N_ERROR_INVALID_FORMAT              : return U_INVALID_FORMAT_ERROR;
    case I18N_ERROR_FILE_ACCESS                 : return U_FILE_ACCESS_ERROR;
    case I18N_ERROR_INTERNAL_PROGRAM            : return U_INTERNAL_PROGRAM_ERROR;
    case I18N_ERROR_MESSAGE_PARSE               : return U_MESSAGE_PARSE_ERROR;
    case I18N_ERROR_OUT_OF_MEMORY               : return U_MEMORY_ALLOCATION_ERROR;
    case I18N_ERROR_INDEX_OUTOFBOUNDS           : return U_INDEX_OUTOFBOUNDS_ERROR;
    case I18N_ERROR_PARSE                       : return U_PARSE_ERROR;
    case I18N_ERROR_INVALID_CHAR_FOUND          : return U_INVALID_CHAR_FOUND;
    case I18N_ERROR_TRUNCATED_CHAR_FOUND        : return U_TRUNCATED_CHAR_FOUND;
    case I18N_ERROR_ILLEGAL_CHAR_FOUND          : return U_ILLEGAL_CHAR_FOUND;
    case I18N_ERROR_INVALID_TABLE_FORMAT        : return U_INVALID_TABLE_FORMAT;
    case I18N_ERROR_INVALID_TABLE_FILE          : return U_INVALID_TABLE_FILE;
    case I18N_ERROR_BUFFER_OVERFLOW             : return U_BUFFER_OVERFLOW_ERROR;
    case I18N_ERROR_NOT_SUPPORTED               : return U_UNSUPPORTED_ERROR;
    case I18N_ERROR_RESOURCE_TYPE_MISMATCH      : return U_RESOURCE_TYPE_MISMATCH;
    case I18N_ERROR_ILLECAL_ESCAPE_SEQUENCE     : return U_ILLEGAL_ESCAPE_SEQUENCE;
    case I18N_ERROR_UNSUPPORTED_ESCAPE_SEQUENCE : return U_UNSUPPORTED_ESCAPE_SEQUENCE;
    case I18N_ERROR_NO_SPACE_AVAILABLE          : return U_NO_SPACE_AVAILABLE;
    case I18N_ERROR_CE_NOT_FOUND                : return U_CE_NOT_FOUND_ERROR;
    case I18N_ERROR_PRIMARY_TOO_LONG            : return U_PRIMARY_TOO_LONG_ERROR;
    case I18N_ERROR_STATE_TOO_OLD               : return U_STATE_TOO_OLD_ERROR;
    case I18N_ERROR_TOO_MANY_ALIASES            : return U_TOO_MANY_ALIASES_ERROR;
    case I18N_ERROR_ENUM_OUT_OF_SYNC            : return U_ENUM_OUT_OF_SYNC_ERROR;
    case I18N_ERROR_INVARIANT_CONVERSION        : return U_INVARIANT_CONVERSION_ERROR;
    case I18N_ERROR_INVALID_STATE               : return U_INVALID_STATE_ERROR;
    case I18N_ERROR_COLLATOR_VERSION_MISMATCH   : return U_COLLATOR_VERSION_MISMATCH;
    case I18N_ERROR_USELESS_COLLATOR            : return U_USELESS_COLLATOR_ERROR;
    case I18N_ERROR_NO_WRITE_PERMISSION         : return U_NO_WRITE_PERMISSION;
    case I18N_ERROR_MALFORMED_SET               : return U_MALFORMED_SET;
    case I18N_ERROR_STD3_ASCII_RULES            : return U_IDNA_STD3_ASCII_RULES_ERROR;
    case I18N_WARNING_STRING_NOT_TERMINATED     : return U_STRING_NOT_TERMINATED_WARNING;
    case I18N_ERROR_UNASSIGNED                  : return U_IDNA_UNASSIGNED_ERROR;
    case I18N_WARNING_SORT_KEY_TOO_SHORT        : return U_SORT_KEY_TOO_SHORT_WARNING;
    default : return U_STANDARD_ERROR_LIMIT;
    }
}
