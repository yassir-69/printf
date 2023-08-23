#include "main.h"

/**
 * print_with_newline - Prints a string followed by a newline character.
 * @string: string of print.
 *
 * Return: Number of characters printed.
 */
int print_with_newline(char *string)
{
    char *start = string;

    while (*string)
        output_character(*string++);
    
    return (string - start);
}

/**
 * output_character - Writes the specified character to the standard output (stdout) while considering buffering..
 * @ch: character of print.
 *
 * Return: On success 1.
 * If an error occurs, the function returns -1, and the "errno" variable is adjusted accordingly.
 */
int output_character(int ch)
{
    static int buffer_index;
    static char output_buffer[OUTPUT_BUFFER_SIZE];

    if (ch == BUFFER_FLUSH || buffer_index >= OUTPUT_BUFFER_SIZE)
    {
        write(1, output_buffer, buffer_index);
        buffer_index = 0;
    }
    
    if (ch != BUFFER_FLUSH)
        output_buffer[buffer_index++] = ch;

    return (1);
}
