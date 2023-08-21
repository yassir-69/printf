#include "main.h"

/********************** PRINT CHAR **********************/

/**
 * this is PRINT CHAR in function.c file
 * print_char - Prints a char
 * @arg_list: Collection of parameters
 * @output_buffer: Array for managing printing operations
 * @format_flags: Determines active indicators
 * @field_width: Breadth or Width 
 * @precision: Accurate detail requirement
 * @length_modifier: specifier
 * Return: Count of characters displayed
 */

int print_char(va_list arg_list, char output_buffer[],
	int format_flags, int field_width, int precision, int length_modifier) {

	char character = va_arg(arg_list, int);
	return (handle_write_char(character, output_buffer, format_flags, field_width, precision, length_modifier));
}

/********************** PRINT A STRING **********************/
/**
 * this is PRINT A STRING in function.c file
 * print_string - Prints a string
 * @arg_list: Collection of parameters
 * @output_buffer: Array for managing printing operations
 * @format_flags: Determines active indicators
 * @field_width: Breadth or Width 
 * @precision: Accurate detail requirement
 * @length_modifier: specifier
 * Return: Count of characters displayed
 */

int print_string(va_list arg_list, char output_buffer[],
	int format_flags, int field_width, int precision, int length_modifier) {

	int str_length = 0, i;
	char *str = va_arg(arg_list, char *);

	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(field_width);
	UNUSED(precision);
	UNUSED(length_modifier);
	if (str == NULL) {

		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[str_length] != '\0')
		str_length++;

	if (precision >= 0 && precision < str_length)
		str_length = precision;

	if (field_width > str_length) {

		if (format_flags & F_MINUS)
		{
			write(1, &str[0], str_length);
			for (i = field_width - str_length; i > 0; i--)
				write(1, " ", 1);
			return (field_width);
		}
		else
		{
			for (i = field_width - str_length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], str_length);
			return (field_width);
		}
	}

	return (write(1, str, str_length));
}

/********************** PRINT PERCENT SIGN **********************/
/**
 * this is PRINT PERCENT SIGN in function.c file
 * print_percent - Prints a percent sign
 * @arg_list: Collection of parameters
 * @output_buffer: Array for managing printing operations
 * @format_flags: Determines active indicators
 * @field_width: Breadth or Width 
 * @precision: Accurate detail requirement
 * @length_modifier: specifier
 * Return: Count of characters displayed
 */

int print_percent(va_list arg_list, char output_buffer[],
	int format_flags, int field_width, int precision, int length_modifier) {

	UNUSED(arg_list);
	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(field_width);
	UNUSED(precision);
	UNUSED(length_modifier);
	return (write(1, "%%", 1));
}

/********************** PRINT INT **********************/
/**
 * this is PRINT INT in function.c file
 * print_int - Print int
 * @arg_list: Collection of parameters
 * @output_buffer: Array for managing printing operations
 * @format_flags: Determines active indicators
 * @field_width: Breadth or Width 
 * @precision: Accurate detail requirement
 * @length_modifier: specifier
 * Return: Count of characters displayed
 */

int print_int(va_list arg_list, char output_buffer[],
	int format_flags, int field_width, int precision, int length_modifier) {

	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(arg_list, long int);
	unsigned long int num;

	n = convert_size_number(n, length_modifier);

	if (n == 0)
		output_buffer[i--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0) {

		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0) {

		output_buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, output_buffer, format_flags, field_width, precision, length_modifier));
}

/********************** PRINT BINARY **********************/
/**
 * this is PRINT BINARY in function.c file
 * print_binary - Prints an unsigned number
 * @arg_list: Collection of parameters
 * @output_buffer: Array for managing printing operations
 * @format_flags: Determines active indicators
 * @field_width: Breadth or Width 
 * @precision: Accurate detail requirement
 * @length_modifier: specifier
 * Return: Count of characters displayed
 */
 
int print_binary(va_list arg_list, char output_buffer[],
	int format_flags, int field_width, int precision, int length_modifier) {

	unsigned int n, m, i, sum;
	unsigned int binary_digits[32];
	int count;

	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(field_width);
	UNUSED(precision);
	UNUSED(length_modifier);

	n = va_arg(arg_list, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	binary_digits[0] = n / m;
	for (i = 1; i < 32; i++) {

		m /= 2;
		binary_digits[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++) {

		sum += binary_digits[i];
		if (sum || i == 31) {

			char binary_char = '0' + binary_digits[i];

			write(1, &binary_char, 1);
			count++;
		}
	}
	return (count);
}
