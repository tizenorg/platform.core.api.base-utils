#include <unicode/unorm2.h>
#include <utils_i18n_unormalization.h>
#include <utils_i18n_private.h>

int i18n_unormalization_get_instance ( const char *package_name, const char *name, i18n_unormalization_mode_e mode,
    i18n_unormalizer_h *normalizer )
{
    i18n_error_code_e err = I18N_ERROR_NONE;
    *normalizer = unorm2_getInstance(package_name, name, mode, (UErrorCode*)&err);
    int result = _i18n_error_mapping(err);
    
    return result;    
}

int i18n_unormalization_normalize ( i18n_unormalizer_h normalizer, const i18n_uchar *src, int32_t len, i18n_uchar *dest, int32_t capacity, int32_t *len_deststr )
{
    retv_if( normalizer == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e err = I18N_ERROR_NONE;
    *len_deststr = unorm2_normalize((UNormalizer2*)normalizer, src, len, dest, capacity, (UErrorCode*)&err);
    int result = _i18n_error_mapping(err);

    return result;
}
