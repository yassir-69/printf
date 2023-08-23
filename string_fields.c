#include "main.h"

/**
 * parse_precision - Parses the precision from the format string.
 * @format_str: Format string.
 * @parameters: Parameters struct.
 * @arg_list: Argument pointer.
 *
 * Return: The new pointer after parsing the precision.
 */

char *parse_precision(char *format_str, params_t *parameters, va_list arg_list) {

    int precision_value = 0;

    if (*format_str != '.')
        return format_str;

    format_str++;

    if (*format_str == '*') {

        precision_value = va_arg(arg_list, int);
        format_str++;
    }
    else {

        while (_isdigit(*format_str))
            precision_value = precision_value * 10 + (*format_str++ - '0');
    }

    parameters->precision = precision_value;
    return format_str;
}
