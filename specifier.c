#include "main.h"

/**
 * find_specifier_function - Finds the appropriate format function.
 * @format_char: The format character.
 *
 * Return: The corresponding function pointer.
 */
int (*find_specifier_function(char *format_char))(va_list ap, params_t *params)
{
    specifier_t specifiers[] = {
        {"c", print_char},
        {"d", print_int},
        {"i", print_int},
        {"s", print_string},
        {"%", print_percent},
        {"b", print_binary},
        {"o", print_octal},
        {"u", print_unsigned},
        {"x", print_hex},
        {"X", print_HEX},
        {"p", print_address},
        {"S", print_custom_string},
        {"r", print_reverse},
        {"R", print_rot13_string},
        {NULL, NULL}
    };
    int i = 0;

    while (specifiers[i].specifier)
    {
        if (*format_char == specifiers[i].specifier[0])
        {
            return specifiers[i].function;
        }
        i++;
    }
    return NULL;
}

/**
 * get_print_function - Gets the format function for a specifier.
 * @format_char: The format character.
 * @ap: Argument pointer.
 * @params: The parameters struct.
 *
 * Return: The corresponding function pointer.
 */
int get_print_function(char *format_char, va_list ap, params_t *params)
{
    int (*func)(va_list, params_t *) = find_specifier_function(format_char);

    if (func)
        return func(ap, params);
    return 0;
}

/**
 * find_flag - Finds and applies a flag.
 * @format_char: The format character.
 * @params: The parameters struct.
 *
 * Return: 1 if flag was found, 0 otherwise.
 */
int find_flag(char *format_char, params_t *params)
{
    int found = 0;

    switch (*format_char)
    {
        case '+':
            found = params->plus_flag = 1;
            break;
        case ' ':
            found = params->space_flag = 1;
            break;
        case '#':
            found = params->hashtag_flag = 1;
            break;
        case '-':
            found = params->minus_flag = 1;
            break;
        case '0':
            found = params->zero_flag = 1;
            break;
    }
    return found;
}

/**
 * find_modifier - Finds and applies a modifier.
 * @format_char: The format character.
 * @params: The parameters struct.
 *
 * Return: 1 if modifier was found, 0 otherwise.
 */
int find_modifier(char *format_char, params_t *params)
{
    int found = 0;

    switch (*format_char)
    {
        case 'h':
            found = params->h_modifier = 1;
            break;
        case 'l':
            found = params->l_modifier = 1;
            break;
    }
    return found;
}

/**
 * extract_width - Extracts the width from the format string.
 * @format_char: The format character.
 * @params: The parameters struct.
 * @ap: Argument pointer.
 *
 * Return: New pointer position.
 */
char *extract_width(char *format_char, params_t *params, va_list ap)
{
    int width = 0;

    if (*format_char == '*')
    {
        width = va_arg(ap, int);
        format_char++;
    }
    else
    {
        while (_isdigit(*format_char))
        {
            width = width * 10 + (*format_char - '0');
            format_char++;
        }
    }
    params->width = width;
    return format_char;
}
