#include "main.h"

void print_buffer(char buffer[], int *buffer_index);

/**
 * This is _printf.c File 
 * function that produces output according to a format.
 * @format: format" usually refers to the way data is represented, displayed, or processed.
 * Return: Printing characters in C can be done using the printf function. In C,(Printed chars)
*/
int _printf(const char *format, ...){
    int index, total_printed = 0, total_chars_printed = 0;
	int current_flags, current_width, current_precision, current_size, buffer_index = 0;
	va_list args_list;
	char output_buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

    va_start(args_list, format);
    for (index = 0; format && format[index] != '\0'; index++) {
    if (format[index] != '%') {
    output_buffer[buffer_index++] = format[index];
			if (buffer_index == BUFF_SIZE)
				print_buffer(output_buffer, &buffer_index);
			/* write(1, &format[i], 1);*/
			total_chars_printed++;
    }        
    else {
        current_flags = get_flags(format, &index);
			current_width = get_width(format, &index, args_list);
			current_precision = get_precision(format, &index, args_list);
			current_size = get_size(format, &index);
			++index;
			print_buffer(output_buffer, &buffer_index);
			total_printed = handle_print(format, &index, args_list, output_buffer,
				current_flags, current_width, current_precision, current_size);
			if (total_printed == -1)
				return (-1);
			total_chars_printed += total_printed;
          }
	}

	print_buffer(output_buffer, &buffer_index);

	va_end(args_list);

	return (total_chars_printed);
}

/**
 * This is _printf.c File
 * Prints the contents of the buffer if it exists - print_buffer
 * @buffer_index: The index where the next character should be added represents the length.
 * @buffer: Collection of characters.
*/

void print_buffer(char buffer[], int *buffer_index) {
    if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
