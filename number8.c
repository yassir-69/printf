#include "main.h"
/**
 * convert_to_string - Converts a number to a string representation.
 * @num: The number to convert.
 * @base: The base for conversion.
 * @flags: Conversion flags.
 * @params: Parameter struct.
 *
 * Return: The converted string.
 */
char *convert_to_string(long int num, int base, int flags, params_t *params)
{
    static char *char_array;
    static char buffer[50];
    char sign = 0;
    char *ptr;
    unsigned long n = num;
    (void)params;
    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num;
        sign = '-';
    }
    char_array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';
    do
    {
        *--ptr = char_array[n % base];
        n /= base;
    } while (n != 0);
    if (sign)
        *--ptr = sign;

 return ptr;
}

/**
 * print_unsigned_integer - Prints unsigned integer numbers.
 * @arg_list: Argument pointer.
 * @parameters: The parameters struct.
 *
 * Return: Bytes printed.
 */
int print_unsigned_integer(va_list arg_list, params_t *parameters)
{
    unsigned long value;

    if (parameters->l_modifier)
        value = (unsigned long)va_arg(arg_list, unsigned long);
    else if (parameters->h_modifier)
        value = (unsigned short int)va_arg(arg_list, unsigned int);
    else
        value = (unsigned int)va_arg(arg_list, unsigned int);

    parameters->unsign = 1;
    return print_formatted_number(convert_to_string(value, 10, CONVERT_UNSIGNED, parameters), parameters);
}

/**
 * print_memory_address - Prints memory address.
 * @arg_list: Argument pointer.
 * @parameters: The parameters struct.
 *
 * Return: Bytes printed.
 */
int print_memory_address(va_list arg_list, params_t *parameters)
{

 unsigned long int address = va_arg(arg_list, unsigned long int);
    char *str;

    if (!address)
        return _puts("(nil)");

    str = convert_to_string(address, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, parameters);
    *--str = 'x';
    *--str = '0';
    return print_formatted_number(str, parameters);
}
                                                                                                                          79,1          Bot
