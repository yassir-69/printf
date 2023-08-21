#include "main.h"

/********************** PRINT UNSIGNED NUMBER **********************/

/**
 * This is PRINT UNSIGNED NUMBER in functions1.c file
 *  Prints an unsigned number - print_unsigned
 * @args_list: Collection of parameters
 * @output_buffer: Array for managing printing operations
 * @current_flags: Calculation of active indicators
 * @current_width: Width parameter or Width value
 * @current_precision: indicating the level of detail or accuracy required.
 * @current_size: Size specifier, indicating the format or dimensions of the output.
 * Return: Count of displayed characters.
 */

int print_unsigned(va_list args_list, char output_buffer[],
	int current_flags, int current_width,
	int current_precision, int current_size) {

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args_list, unsigned long int);

	num = convert_size_unsgnd(num, current_size);

	if (num == 0)
		output_buffer[i--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		output_buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, output_buffer, current_flags, current_width, current_precision, current_size));
}

/********** PRINT UNSIGNED NUMBER IN OCTAL  *************/

/**
 * This is PRINT UNSIGNED NUMBER IN OCTAL in functions1.c file
 * print_octal - Prints an unsigned number in octal notation
 * @args_list: Collection of parameters
 * @output_buffer: Array for managing printing operations
 * @current_flags: Calculation of active indicators
 * @current_width: Width parameter or Width value
 * @current_precision: indicating the level of detail or accuracy required.
 * @current_size: Size specifier, indicating the format or dimensions of the output.
 * Return: Count of displayed characters.
 */

int print_octal(va_list args_list, char output_buffer[],
	int current_flags, int current_width,
	int current_precision, int current_size) {

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args_list, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(current_width);

	num = convert_size_unsgnd(num, current_size);

	if (num == 0)
		output_buffer[i--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		output_buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (current_flags & F_HASH && init_num != 0)
		output_buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, output_buffer, current_flags, current_width, current_precision, current_size));
}

/*********** PRINT UNSIGNED NUMBER IN HEXADECIMAL ***********/

/**
 * This is PRINT UNSIGNED NUMBER IN HEXADECIMAL in functions1.c file
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @args_list: Collection of parameters
 * @output_buffer: Array for managing printing operations
 * @current_flags: Calculation of active indicators
 * @current_width: Width parameter or Width value
 * @current_precision: indicating the level of detail or accuracy required.
 * @current_size: Size specifier, indicating the format or dimensions of the output.
 * Return: Count of displayed characters.
 */

int print_hexadecimal(va_list args_list, char output_buffer[],
	int current_flags, int current_width,
	int current_precision, int current_size) {

	return (print_hexa(args_list, "0123456789abcdef", output_buffer,
		current_flags, 'x', current_width, current_precision, current_size));
}

/********** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ***********/

/**
 * This is PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL in functions1.c file
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @args_list: Collection of parameters
 * @output_buffer: Array for managing printing operations
 * @current_flags: Calculation of active indicators
 * @current_width: Width parameter or Width value
 * @current_precision: indicating the level of detail or accuracy required.
 * @current_size: Size specifier, indicating the format or dimensions of the output.
 * Return: Count of displayed characters.
 */

int print_hexa_upper(va_list args_list, char output_buffer[],
	int current_flags, int current_width,
	int current_precision, int current_size) {

	return (print_hexa(args_list, "0123456789ABCDEF", output_buffer,
		current_flags, 'X', current_width, current_precision, current_size));
}

/*********** PRINT HEXX NUM IN LOWER OR UPPER ***********/

/**
 * This is PRINT HEXX NUM IN LOWER OR UPPER in functions1.c file
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @args_list: Collection of parameters
 * @map_to: this is Array of values to map the number to
 * @output_buffer: Array for managing printing operations
 * @current_flags: Calculation of active indicators
 * @flag_ch: this is Active flags calculation
 * @current_width: Width parameter or Width value
 * @current_precision: Precision value
 * @current_size: Size specifier, indicating the format or dimensions of the output.
 * Return: Count of displayed characters.
 */

int print_hexa(va_list args_list, char map_to[], char output_buffer[],
	int current_flags, char flag_ch,
	int current_width, int current_precision, int current_size) {
        
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args_list, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(current_width);

	num = convert_size_unsgnd(num, current_size);

	if (num == 0)
		output_buffer[i--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		output_buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (current_flags & F_HASH && init_num != 0)
	{
		output_buffer[i--] = flag_ch;
		output_buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, output_buffer, current_flags, current_width, current_precision, current_size));
}
