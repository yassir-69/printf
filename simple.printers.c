#include "main.h"

/**
 * print_characters_range - Prints a range of characters.
 * @start_addr: Starting address.
 * @stop_addr: Stopping address.
 * @exception_addr: Except address.
 *
 * Return: Number of bytes printed.
 */
int print_characters_range(char *start_addr, char *stop_addr, char *exception_addr)
{
    int byte_count = 0;

    while (start_addr <= stop_addr)
    {
        if (start_addr != exception_addr)
            byte_count += _putchar(*start_addr);
        start_addr++;
    }
    return byte_count;
}

/**
 * print_reverse_string - Prints a string in reverse.
 * @arg_list: The string.
 * @parameters: The parameters struct.
 *
 * Return: Number of bytes printed.
 */
int print_reverse_string(va_list arg_list, params_t *parameters)
{
    int length, byte_count = 0;
    char *str = va_arg(arg_list, char *);
    (void)parameters;

    if (str)
    {
        for (length = 0; *str; str++)
            length++;
        str--;
        for (; length > 0; length--, str--)
            byte_count += _putchar(*str);
    }
    return byte_count;
}

/**
 * print_rot13_string - Prints a string in ROT13.
 * @arg_list: The string.
 * @parameters: The parameters struct.
 *
 * Return: Number of bytes printed.
 */
int print_rot13_string(va_list arg_list, params_t *parameters)
{
    int i, index;
    int byte_count = 0;
    char rot13_array[] =
        "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
    char *input_string = va_arg(arg_list, char *);
    (void)parameters;

    i = 0;
    index = 0;
    while (input_string[i])
    {
        if ((input_string[i] >= 'A' && input_string[i] <= 'Z') ||
            (input_string[i] >= 'a' && input_string[i] <= 'z'))
        {
            index = input_string[i] - 65;
            byte_count += _putchar(rot13_array[index]);
        }
        else
            byte_count += _putchar(input_string[i]);
        i++;
    }
    return byte_count;
}
