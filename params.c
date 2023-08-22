#include "main.h" 

/**
 * init_params - Initializes the fields of the structure and restores the buffer to its initial state.
 * @params: Structure containing various parameters.
 * @ap: Pointer referring to the list of arguments.
 * 
 * Return: void
 */
void init_params(params_t *params, va_list ap) {
    params->unsign = 0;

    params->plus_flag = 0;
    params->space_flag = 0;
    params->hashtag_flag = 0;
    params->zero_flag = 0;
    params->minus_flag = 0;

    params->width = 0;
    params->precision = UINT_MAX;

    params->h_modifier = 0;
    params->one_modifier = 0; 
}
