#include "main.h"

/**
 * is_digit - Checks if character is a digit.
 * @ch: The character to check.
 *
 * Return: 1 if digit, 0 otherwise.
 */
int is_digit(int ch)
{
    return (ch >= '0' && ch <= '9');
}

/**
 * string_length - Returns the length of a string.
 * @str: The string whose length to check.
 *
 * Return: Integer length of the string.
 */
int string_length(char *str)
{
    int length = 0;

    while (*str++)
        length++;
    return (length);
}

/**
 * print_formatted_number - Prints a number with options.
 * @number_str: The base number as a string.
 * @parameters: The parameter struct.
 *
 * Return: Number of characters printed.
 */
int print_formatted_number(char *number_str, params_t *parameters)
{
    unsigned int i = string_length(number_str);
    int is_negative = (!parameters->unsign && *number_str == '-');

    if (!parameters->precision && *number_str == '0' && !number_str[1])
        number_str = "";
    if (is_negative)
    {
        number_str++;
        i--;
    }
    if (parameters->precision != UINT_MAX)
        while (i++ < parameters->precision)
            *--number_str = '0';
    if (is_negative)
        *--number_str = '-';

    if (!parameters->minus_flag)
        return (print_number_right_shift(number_str, parameters));
    else
        return (print_number_left_shift(number_str, parameters));
}

/**
 * print_number_right_shift - Prints a number with options.
 * @number_str: The base number as a string.
 * @parameters: The parameter struct.
 *
 * Return: Number of characters printed.
 */
int print_number_right_shift(char *number_str, params_t *parameters)
{
    unsigned int char_count = 0, is_negative, negative2, i = string_length(number_str);
    char pad_char = ' ';

    if (parameters->zero_flag && !parameters->minus_flag)
        pad_char = '0';
    is_negative = negative2 = (!parameters->unsign && *number_str == '-');
    if (is_negative && i < parameters->width && pad_char == '0' && !parameters->minus_flag)
        number_str++;
    else
        is_negative = 0;

    if ((parameters->plus_flag && !negative2) || (!parameters->plus_flag && parameters->space_flag && !negative2))
        i++;

    if (is_negative && pad_char == '0')
        char_count += output_character('-');

    if (parameters->plus_flag && !negative2 && pad_char == '0' && !parameters->unsign)
        char_count += output_character('+');
    else if (!parameters->plus_flag && parameters->space_flag && !negative2 && !parameters->unsign && parameters->zero_flag)
        char_count += output_character(' ');

    while (i++ < parameters->width)
        char_count += output_character(pad_char);

    if (is_negative && pad_char == ' ')
        char_count += output_character('-');

    if (parameters->plus_flag && !negative2 && pad_char == ' ' && !parameters->unsign)
        char_count += output_character('+');
    else if (!parameters->plus_flag && parameters->space_flag && !negative2 && !parameters->unsign && !parameters->zero_flag)
        char_count += output_character(' ');

    char_count += print_string(number_str);

    return char_count;
}

/**
 * print_number_left_shift - Prints a number with options.
 * @number_str: The base number as a string.
 * @parameters: The parameter struct.
 *
 * Return: Number of characters printed.
 */
int print_number_left_shift(char *number_str, params_t *parameters)
{
    unsigned int char_count = 0, is_negative, negative2, i = string_length(number_str);
    char pad_char = ' ';

    if (parameters->zero_flag && !parameters->minus_flag)
        pad_char = '0';
OBOBOB    is_negative = negative2 = (!parameters->unsign && *number_str == '-');
    if (is_negative && i < parameters->width && pad_char == '0' && !parameters->minus_flag)
        number_str++;
    else
        is_negative = 0;

    if (parameters->plus_flag && !negative2 && !parameters->unsign)
        char_count += output_character('+'), i++;
OBOBOB    else if (parameters->space_flag && !negative2 && !parameters->unsign)
        char_count += output_character(' '), i++;

    char_count += print_string(number_str);
OBOBOB
    while (i++ < parameters->width)
        char_count += output_character(pad_char);

    return char_count;
}
