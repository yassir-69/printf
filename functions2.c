#include "main.h"

/***** PRINT POINTER *****/
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: An array of arguments.
 * @the_buffer: An array used to manage printing.
 * @the_flags:  Determines active indicators.
 * @the_width: the Width
 * @the_precision: Specification of precision.
 * @the_size: Specifier for size.
 * Return: Count of printed characters.
 */
int print_pointer(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size)
{
	char o__extra_c = 0, o__padd = ' ';
	int o__ind = BUFF_SIZE - 2, o__length = 2, o__padd_start = 1; /* o__length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(the_width);
	UNUSED(the_size);

	if (addrs == NULL)
		return (the_write(1, "(nil)", 5));

	the_buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(the_precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		the_buffer[o__ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		o__length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		o__padd = '0';
	if (flags & F_PLUS)
		o__extra_c = '+', o__length++;
	else if (flags & F_SPACE)
		o__extra_c = ' ', o__length++;

	o__ind++;

	/*return (write(1, &the_buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(the_buffer, o__ind, o__length,
		the_width, the_flags, o__padd, o__extra_c, o__padd_start));
}

/***** PRINT NON PRINTABLE *****/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: An array of arguments.
 * @the_buffer: An array used to manage printing.
 * @the_flags:  Determines active indicators.
 * @the_width: the Width
 * @the_precision: Specification of precision.
 * @the_size: Specifier for size.
 * Return: Count of printed characters.
 */
int print_non_printable(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size)
{
	int y = 0, o__o_ffset = 0;
	char *o__str = va_arg(types, char *);

	UNUSED(the_flags);
	UNUSED(the_width);
	UNUSED(the_precision);
	UNUSED(the_size);

	if (o__str == NULL)
		return (write(1, "(null)", 6));

	while (o__str[y] != '\0')
	{
		if (is_printable(o__str[y]))
			the_buffer[y + o__o_ffset] = o__str[y];
		else
			o__o_ffset += append_hexa_code(o__str[y], the_buffer, y + o__o_ffset);

		y++;
	}

	the_buffer[y + o__o_ffset] = '\0';

	return (write(1, the_buffer, y + o__o_ffset));
}

/***** PRINT REVERSE *****/
/**
 * print_reverse - Prints reverse string.
 * @types: An array of arguments.
 * @the_buffer: An array used to manage printing.
 * @the_flags:  Determines active indicators.
 * @the_width: the Width
 * @the_precision: Specification of precision.
 * @the_size: Specifier for size.
 * Return: Count of printed characters.
 */

int print_reverse(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size)
{
	char *o__str;
	int y, o_count = 0;

	UNUSED(the_buffer);
	UNUSED(the_flags);
	UNUSED(the_width);
	UNUSED(the_size);

	o__str = va_arg(types, char *);

	if (o__str == NULL)
	{
		UNUSED(the_precision);

		o__str = ")Null(";
	}
	for (y = 0; o__str[y]; y++)
		;

	for (y = y - 1; y >= 0; y--)
	{
		char z = o__str[y];

		write(1, &z, 1);
		o_count++;
	}
	return (o_count);
}
/***** PRINT A STRING IN ROT13 *****/
/**
 * print_rot13string - Print a string in rot13.
 * @types: An array of arguments.
 * @the_buffer: An array used to manage printing.
 * @the_flags:  Determines active indicators.
 * @the_width: the Width
 * @the_precision: Specification of precision.
 * @the_size: Specifier for size.
 * Return: Count of printed characters.
 */
int print_rot13string(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size)
{
	char x;
	char *o__str;
	unsigned int y, x;
	int o_count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	o__str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(the_flags);
	UNUSED(the_width);
	UNUSED(the_precision);
	UNUSED(the_size);

	if (o__str == NULL)
		o__str = "(AHYY)";
	for (y = 0; o__str[y]; y++)
	{
		for (x = 0; in[j]; x++)
		{
			if (in[x] == o__str[y])
			{
				x = out[x];
				write(1, &x, 1);
				o_count++;
				break;
			}
		}
		if (!in[x])
		{
			x = o__str[y];
			write(1, &x, 1);
			o_count++;
		}
	}
	return (o_count);
}
