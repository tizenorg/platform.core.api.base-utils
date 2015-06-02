#include <unicode/ucol.h>
#include <utils_i18n_ucollator.h>
#include <utils_i18n_private.h>

int i18n_ucollator_destroy ( i18n_ucollator_h collator )
{
    retv_if(collator == NULL, I18N_ERROR_INVALID_PARAMETER);

	ucol_close(collator);

	return I18N_ERROR_NONE;
}

int i18n_ucollator_equal ( const i18n_ucollator_h collator, const i18n_uchar *src, int32_t src_len, const i18n_uchar *target, int32_t target_len, i18n_ubool *equal )
{
    retv_if(collator == NULL, I18N_ERROR_INVALID_PARAMETER);

	*equal = ucol_equal(collator, src, src_len, target, target_len);

	return I18N_ERROR_NONE;
}

int i18n_ucollator_create ( const char *locale, i18n_ucollator_h *collator )
{
	retv_if (collator == NULL, I18N_ERROR_INVALID_PARAMETER);

	i18n_error_code_e err = I18N_ERROR_NONE;
	*collator = ucol_open(locale, (UErrorCode*)&err);
	int result = _i18n_error_mapping(err);

	return result;
}

int i18n_ucollator_set_attribute( i18n_ucollator_h collator, i18n_ucollator_attribute_e attr, i18n_ucollator_attribute_value_e val )
{
    retv_if(collator == NULL, I18N_ERROR_INVALID_PARAMETER);

	i18n_error_code_e err = I18N_ERROR_NONE;
	ucol_setAttribute(collator, attr, val, (UErrorCode*)&err);
	int result = _i18n_error_mapping(err);

	return result;
}

int i18n_ucollator_set_strength ( i18n_ucollator_h collator, i18n_ucollator_strength_e strength )
{
    retv_if(collator == NULL, I18N_ERROR_INVALID_PARAMETER);

	ucol_setStrength(collator, strength);

	return I18N_ERROR_NONE;
}

int i18n_ucollator_str_collator ( const i18n_ucollator_h collator, const i18n_uchar *src, int32_t src_len, const i18n_uchar *target, int32_t target_len, i18n_ucollator_result_e *result )
{
    retv_if(collator == NULL, I18N_ERROR_INVALID_PARAMETER);

	*result = ucol_strcoll(collator, src, src_len, target, target_len);

	return I18N_ERROR_NONE;
}
