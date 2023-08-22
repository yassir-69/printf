#include <stdio.h>    
#include <stdarg.h>   
#include <unistd.h>   
#include "main.h"   

#define BUFF_SIZE 1024 

// Function prototypes (replace with actual prototypes)
int get_flags(const char *format, int *index);
int get_width(const char *format, int *index, va_list args);
int get_precision(const char *format, int *index, va_list args);
int get_size(const char *format, int *index);
int handle_print(const char *format, int *index, va_list args, char buffer[], int flags, int width, int precision, int size);

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: Format in the context of the C programming language refers to the specifications used in functions
 * Return: Number of characters that have been outputted.
 */
int _printf(const char *format, ...) {
    int i, printed = 0, printed_chars = 0;
    int flags, width, precision, size, buff_ind = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return -1;

    va_start(list, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            printed_chars++;
        } else {
            print_buffer(buffer, &buff_ind);
            flags = get_flags(format, &i);
            width = get_width(format, &i, list);
            precision = get_precision(format, &i, list);
            size = get_size(format, &i);
            ++i;
            printed = handle_print(format, &i, list, buffer, flags, width, precision, size);
            if (printed == -1) {
                va_end(list);
                return -1;
            }
            printed_chars += printed;
        }
    }

    print_buffer(buffer, &buff_ind);
    va_end(list);

    return printed_chars;
}

/**
 * print_buffer - Displays the contents of the buffer if it is present.
 * @buffer: Sequence of characters in an array.
 * @buff_ind: The index where the next character is to be added, which signifies the length.
 */
void print_buffer(char buffer[], int *buff_ind) {
    if (*buff_ind > 0 && *buff_ind <= BUFF_SIZE) {
        write(1, buffer, *buff_ind);
        *buff_ind = 0;
    }
}
