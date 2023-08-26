#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @the_fmt: The structure or the format
 * @the_list: the List of arguments to be printed.
 * @the_ind: ind.
 * @the_buffer:  An array used to manage printing.
 * @the_flags: the Calculates active flags
 * @the_width: the get width.
 * @the_precision: the Precision specification
 * @the_size: the Size specifier
 * Return: 1 or 2;
 */
int handle__of__print(const char *the_fmt, int *the_ind, va_list the_list, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size)
{
	int y, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (y = 0; fmt_types[y].the_fmt != '\0'; y++)
		if (the_fmt[*ind] == fmt_types[y].the_fmt)
			return (fmt_types[y].fn(the_list, the_buffer, the_flags, width, the_precision, the_size));

	if (fmt_types[y].the_fmt == '\0')
	{
		if (the_fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (the_fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (the_fmt[*ind] != ' ' && the_fmt[*ind] != '%')
				--(*ind);
			if (the_fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &the_fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
