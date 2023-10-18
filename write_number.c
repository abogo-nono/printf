#include "main.h"

/**
 * write_number - Prints a string
 * @is_negative: List of arguments
 * @index: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char padding = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		padding = '0';
	}

	if (is_negative)
	{
		extra_ch = '-';
	}

	else if (flags & F_PLUS)
	{
		extra_ch = '+';
	}

	else if (flags & F_SPACE)
	{
		extra_ch = ' ';
	}

	return (write_num(index, buffer, flags, width, precision,
		length, padding, extra_ch));
}
