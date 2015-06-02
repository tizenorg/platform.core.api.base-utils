#include <unicode/uchar.h>
#include <utils_i18n_uchar.h>
#include <utils_i18n_private.h>

int i18n_uchar_get_int_property_value ( i18n_uchar32 c, i18n_uchar_uproperty_e which, int32_t *property_val )
{
	retv_if (property_val == NULL, I18N_ERROR_INVALID_PARAMETER);
	*property_val = u_getIntPropertyValue(c, which);

	return I18N_ERROR_NONE;
}

int i18n_uchar_get_ublock_code ( i18n_uchar32 c, i18n_uchar_ublock_code_e *block_val )
{
	retv_if (block_val == NULL, I18N_ERROR_INVALID_PARAMETER);
	*block_val = ublock_getCode(c);

	return I18N_ERROR_NONE;
}
