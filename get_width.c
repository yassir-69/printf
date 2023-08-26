i#include "main.h"

/**
 * get__the__width - Calculates the width for printing
 * @for_mat: The structure or the format
 * @y: the List of arguments to be printed.
 * @_list: the list of arguments.
 *
 * Return: width.
 */
int get__the__width(const char *for_mat, int *y, va_list _list)
{
	int curr_y;
	int _width = 0;

	for (curr_y = *y + 1; for_mat[curr_y] != '\0'; curr_y++)
	{
		if (is_digit(for_mat[curr_y]))
		{
			_width *= 10;
			_width += for_mat[curr_y] - '0';
		}
		else if (for_mat[curr_y] == '*')
		{
			curr_y++;
			_width = va_arg(_list, int);
			break;
		}
		else
			break;
	}

	*y = curr_y - 1;

	return (_width);
}

