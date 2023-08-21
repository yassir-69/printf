#include "main.h"

/***  PRINT CHAR ***/

/**
 * print_char - Prints a char
 * @types: this is List a of arguments
 * @buffer: and this about Buffer array to handle print
 * @flags:  this function  Calculates active flags
 * @width: this is function Width
 * @precision: and this function about  Precision specification
 * @size: this function Size specifier
 * Return: this is Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char p = va_arg(types, int);

	return (handle_write_char(p, buffer, flags, width, precision, size));
}

/*** PRINT A STRING ***/

/**
 * print_string - Prints a string
 * @types: it's function about List a of arguments
 * @buffer: it's function about Buffer array to handle print
 * @flags: it's function about Calculates active flags
 * @width: it's function about get width.
 * @precision: it's function about Precision specification
 * @size: it's function about Size specifier
 * Return: this is Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size) {

	int extent = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL){

		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		extent++;

	if (precision >= 0 && precision < length)
		extent = precision;

	if (width > extent) {

		if (flags & F_MINUS)
		{
			write(1, &str[0], extent);
			for (i = width - extent; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - extent; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], extent);
			return (width);
		}
	}

	return (write(1, str, extent));

/*** PRINT PERCENT SIGN ***/

/**
 * print_percent - Prints a percent sign
 * @types: it's function about Lista of arguments
 * @buffer: it's function about Buffer array to handle print
 * @flags: it's function about Calculates active flags
 * @width: it's function about get width.
 * @precision: it's function about Precision specification
 * @size: it's function about Size specifier
 * Return: it's function about Number of chars printed
 */

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size) {

	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/*** PRINT INT ***/

/**
 * print_int - Print int
 * @types: it's function about Lista of arguments
 * @buffer: it's function about Buffer array to handle print
 * @flags: it's function about Calculates active flags
 * @width: it's function about get width.
 * @precision: it's function about Precision specification
 * @size: it's function about Size specifier
 * Return: it's function about Number of chars printed
 */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int p = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[p--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[p--] = (num % 10) + '0';
		num /= 10;
	}

	p++;

	return (write_number(is_negative, p, buffer, flags, width, precision, size));
}

/*** PRINT BINARY ***/

/**
 * print_binary - Prints an unsigned number
 * @types: it's function about Lista of arguments
 * @buffer: it's function about Buffer array to handle print
 * @flags: it's function about Calculates active flags
 * @width: it's function about get width.
 * @precision: it's function about Precision specification
 * @size: it's function about Size specifier
 * Return: it's function about Numbers of char printed.
 */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size) {

	unsigned int n, m, p, sum;
	unsigned int a[32];
	int counte;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (p = 1; p < 32; p++)
	{
		m /= 2;
		a[p] = (n / m) % 2;
	}
	for (p = 0, sum = 0, counte = 0; p < 32; p++)
	{
		sum += a[p];
		if (sum || p == 31)
		{
			char z = '0' + a[p];

			write(1, &z, 1);
			counte++;
		}
	}
	return (counte);
}

