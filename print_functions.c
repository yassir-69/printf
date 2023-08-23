#include "main.h"

/**
 * print_character - Prints a character.
 * @arg_list: Argument pointer.
 * @parameters: The parameters struct.
 *
 * Return: Number of characters printed.
 */
int print_character(va_list arg_list, params_t *parameters)
{
    char pad_char = ' ';
    unsigned int pad = 1, char_sum = 0, ch = va_arg(arg_list, int);

    if (parameters->minus_flag)
        char_sum += output_character(ch);
    while (pad++ < parameters->width)
        char_sum += output_character(pad_char);
    if (!parameters->minus_flag)
        char_sum += output_character(ch);
    return char_sum;
}

/**
 * print_integer - Prints an integer.
 * @arg_list: Argument pointer.
 * @parameters: The parameters struct.
 *
 * Return: Number of characters printed.
 */
int print_integer(va_list arg_list, params_t *parameters)
{
    long num;

    if (parameters->l_modifier)
        num = va_arg(arg_list, long);
    else if (parameters->h_modifier)
        num = (short int)va_arg(arg_list, int);
    else
        num = (int)va_arg(arg_list, int);
    return print_number(convert(num, 10, 0, parameters), parameters);
}

/**
 * print_formatted_string - Prints a string.
 * @arg_list: Argument pointer.
 * @parameters: The parameters struct.
 *
 * Return: Number of characters printed.
 */
int print_formatted_string(va_list arg_list, params_t *parameters)
{
    char *str = va_arg(arg_list, char *);
    char pad_char = ' ';
    unsigned int pad = 0, str_sum = 0, i = 0, j;

    (void)parameters;
    switch ((int)(!str)) {
        case 1:
            str = NULL_STRING;
            break;
    }

    j = pad = _strlen(str);
    if (parameters->precision < pad)
        j = pad = parameters->precision;

    if (parameters->minus_flag) {
        if (parameters->precision != UINT_MAX) {
            for (i = 0; i < pad; i++)
                str_sum += output_character(*str++);
        } else {
            str_sum += print_string(str);
        }
    }

    while (j++ < parameters->width)
        str_sum += output_character(pad_char);

    if (!parameters->minus_flag) {
        if (parameters->precision != UINT_MAX) {
            for (i = 0; i < pad; i++)
                str_sum += output_character(*str++);
        } else {
            str_sum += print_string(str);
        }
    }

    return str_sum;
}

/**
 * print_percent_sign - Prints a percent sign.
 * @arg_list: Argument pointer.
 * @parameters: The parameters struct.
 *
 * Return: Number of characters printed.
 */
int print_percent_sign(va_list arg_list, params_t *parameters)
{
    (void)arg_list;
    (void)parameters;
    return output_character('%');
}

/**
 * print_custom_S - Custom format specifier for printing special characters.
 * @arg_list: Argument pointer.
 * @parameters: The parameters struct.
 *
 * Return: Number of characters printed.
 */
int print_custom_S(va_list arg_list, params_t *parameters)
{
    char *str = va_arg(arg_list, char *);
    char *hex;
    int sum = 0;

    if ((int)(!str))
        return print_string(NULL_STRING, parameters);

    for (; *str; str++) {
        if ((*str > 0 && *str < 32) || *str >= 127) {
            sum += output_character('\\');
            sum += output_character('x');
            hex = convert(*str, 16, 0, parameters);
            if (!hex[1])
                sum += output_character('0');
            sum += print_string(hex);
        } else {
            sum += output_character(*str);
        }
    }

    return sum;
}
