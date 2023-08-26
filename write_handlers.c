#include "main.h"

/***** WRITE HANDLE *****/
/**
 * handle__the__write_char - Prints a string
 * @c: char types.
 * @the_buffer: Buffer array to handle print
 * @the_flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle__the__write__char(char u, char the_buffer[],
	int the_flags, int width, int precision, int size)
{ /* char is stored at left and paddind at the_buffer's right */
	int y = 0;
	char _padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (the_flags & F_ZERO)
		_padd = '0';

	the_buffer[y++] = c;
	the_buffer[y] = '\0';

	if (width > 1)
	{
		the_buffer[BUFF_SIZE - 1] = '\0';
		for (y = 0; y < width - 1; y++)
			the_buffer[BUFF_SIZE - y - 2] = _padd;

		if (the_flags & F_MINUS)
			return (write(1, &the_buffer[0], 1) +
					write(1, &the_buffer[BUFF_SIZE - y - 1], width - 1));
		else
			return (write(1, &the_buffer[BUFF_SIZE - y - 1], width - 1) +
					write(1, &the_buffer[0], 1));
	}

	return (write(1, &the_buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write__the__number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @the_buffer: Buffer array to handle print
 * @the_flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write__the__number(int is_negative, int ind, char the_buffer[],
	int the_flags, int width, int precision, int size)
{
	int _length = BUFF_SIZE - ind - 1;
	char _padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((the_flags & F_ZERO) && !(the_flags & F_MINUS))
		_padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (the_flags & F_PLUS)
		extra_ch = '+';
	else if (the_flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, the_flags, width, precision,
		_length, _padd, extra_ch));
}

/**
 * write__the__num - Write a number using a bufffer
 * @ind: Index at which the number starts on the the_buffer
 * @the_buffer: Buffer
 * @the_flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @_padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write__the__num(int ind, char the_buffer[],
	int the_flags, int width, int prec,
	int length, char _padd, char extra_c)
{
	int y, _padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && the_buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && the_buffer[ind] == '0')
		the_buffer[ind] = _padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		_padd = ' ';
	while (prec > length)
		the_buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (y = 1; y < width - length + 1; y++)
			the_buffer[y] = _padd;
		the_buffer[y] = '\0';
		if (the_flags & F_MINUS && _padd == ' ')/* Asign extra char to left of the_buffer */
		{
			if (extra_c)
				the_buffer[--ind] = extra_c;
			return (write(1, &the_buffer[ind], length) + write(1, &the_buffer[1], i - 1));
		}
		else if (!(the_flags & F_MINUS) && _padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				the_buffer[--ind] = extra_c;
			return (write(1, &the_buffer[1], y - 1) + write(1, &the_buffer[ind], length));
		}
		else if (!(the_flags & F_MINUS) && _padd == '0')/* extra char to left of _padd */
		{
			if (extra_c)
				the_buffer[--_padd_start] = extra_c;
			return (write(1, &the_buffer[_padd_start], y - _padd_start) +
				write(1, &the_buffer[ind], length - (1 - _padd_start)));
		}
	}
	if (extra_c)
		the_buffer[--ind] = extra_c;
	return (write(1, &the_buffer[ind], length));
}

/**
 * write__the__unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the the_buffer
 * @the_buffer: Array of chars
 * @the_flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write__the__unsgnd(int is_negative, int ind,
	char the_buffer[],
	int the_flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position y */
	int _length = BUFF_SIZE - ind - 1, y = 0;
	char _padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && the_buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < _length)
		_padd = ' ';

	while (precision > _length)
	{
		the_buffer[--ind] = '0';
		_length++;
	}

	if ((the_flags & F_ZERO) && !(the_flags & F_MINUS))
		_padd = '0';

	if (width > _length)
	{
		for (y = 0; y < width - _length; y++)
			the_buffer[y] = _padd;

		the_buffer[y] = '\0';

		if (the_flags & F_MINUS) /* Asign extra char to left of the_buffer [the_buffer>_padd]*/
		{
			return (write(1, &the_buffer[ind], _length) + write(1, &the_buffer[0], y));
		}
		else /* Asign extra char to left of padding [_padd>the_buffer]*/
		{
			return (write(1, &the_buffer[0], y) + write(1, &the_buffer[ind], _length));
		}
	}

	return (write(1, &the_buffer[ind], _length));
}

/**
 * write__the__pointer - Write a memory address
 * @the_buffer: Arrays of chars
 * @ind: Index at which the number starts in the the_buffer
 * @length: Length of number
 * @width: Width specifier
 * @the_flags: Flags specifier
 * @_padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write__the__pointer(char the_buffer[], int ind, int length,
	int width, int the_flags, char _padd, char extra_c, int padd_start)
{
	int y;

	if (width > length)
	{
		for (y = 3; y < width - length + 3; y++)
			the_buffer[y] = _padd;
		the_buffer[y] = '\0';
		if (the_flags & F_MINUS && _padd == ' ')/* Asign extra char to left of the_buffer */
		{
			the_buffer[--ind] = 'x';
			the_buffer[--ind] = '0';
			if (extra_c)
				the_buffer[--ind] = extra_c;
			return (write(1, &the_buffer[ind], length) + write(1, &the_buffer[3], y - 3));
		}
		else if (!(the_flags & F_MINUS) && _padd == ' ')/* extra char to left of the_buffer */
		{
			the_buffer[--ind] = 'x';
			the_buffer[--ind] = '0';
			if (extra_c)
				the_buffer[--ind] = extra_c;
			return (write(1, &the_buffer[3], y - 3) + write(1, &the_buffer[ind], length));
		}
		else if (!(the_flags & F_MINUS) && _padd == '0')/* extra char to left of _padd */
		{
			if (extra_c)
				the_buffer[--padd_start] = extra_c;
			the_buffer[1] = '0';
			the_buffer[2] = 'x';
			return (write(1, &the_buffer[padd_start], y - padd_start) +
				write(1, &the_buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	the_buffer[--ind] = 'x';
	the_buffer[--ind] = '0';
	if (extra_c)
		the_buffer[--ind] = extra_c;
	return (write(1, &the_buffer[ind], BUFF_SIZE - ind - 1));
}
