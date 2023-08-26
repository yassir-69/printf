#include "main.h"

/**
 * get__the__precision - Calculates the precision for printing
 * @for_mat: The structure or the format
 * @y: List of arguments to be printed.
 * @_list: list of arguments.
 *
 * Return: Precision.
 */
int get__the__precision(const char *for_mat, int *y, va_list _list)
{
	int curr_y = *y + 1;
	int precision = -1;

	if (for_mat[curr_y] != '.')
		return (precision);

	precision = 0;

	for (curr_y += 1; for_mat[curr_y] != '\0'; curr_y++)
	{
		if (is_digit(for_mat[curr_y]))
		{
			precision *= 10;
			precision += for_mat[curr_y] - '0';
		}
		else if (for_mat[curr_y] == '*')
		{
			curr_y++;
			precision = va_arg(_list, int);
			break;
		}
		else
			break;
	}

	*y = curr_y - 1;

	return (precision);
}
