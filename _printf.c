#include "main.h"

void print__the__buffer(char the_buffer[], int *the_buff_ind);

/**
 * _printf - Print function.
 * @format: The structure or the format
 * Return: Displayed characters.
 */
int _printf(const char *format, ...)
{
    int y, the_pri_nted = 0, the_pri_chars = 0;
	int the_flags, the_width, the_precision, the_size, the_buff_ind = 0;
	va_list the_list;
	char the_buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(the_list, format);

	for (y = 0; format && format[y] != '\0'; y++)
	{
		if (format[y] != '%')
		{
			the_buffer[the_buff_ind++] = format[y];
			if (the_buff_ind == BUFF_SIZE)
				print__the__buffer(the_buffer, &the_buff_ind);
/* write(1, &format[y], 1);*/
			the_pri_chars++;
		}
		else
		{
			print__the__buffer(the_buffer, &the_buff_ind);
			the_flags = get__the__flags(format, &y);
			the_width = get__the__width(format, &y, the_list);
			the_precision = get__the__precision(format, &y, the_list);
			the_size = get__the__size(format, &y);
			++y;
			the_pri_nted = handle__the__print(format, &y, the_list, the_buffer,
				the_flags, the_width, the_precision, the_size);
			if (the_pri_nted == -1)
				return (-1);
			the_pri_chars += the_pri_nted;
		}
	}

	print__the__buffer(the_buffer, &the_buff_ind);

	va_end(the_list);

	return (the_pri_chars);
}

/**
 * print__the__buffer - If the buffer exists, it will display the content.
 * @the_buffer: the Array of chars
 * @the_buff_ind: The position where the next character will be added, indicating the size.
 */
void print__the__buffer(char the_buffer[], int *the_buff_ind)
{
	    if (*the_buff_ind > 0)
	        write(1, &the_buffer[0], *the_buff_ind);

	    *the_buff_ind = 0;
}

