#include "main.h"

/**
 * write_num - Write a number using a buffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padding: Padding char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padding, char extra_c)
{
	int i, padding_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
	{
		return (0);
	}

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
	{
		buffer[ind] = padding = ' ';
	}

	if (prec > 0 && prec < length)
	{
		padding = ' ';
	}

	while (prec > length)
	{
		buffer[--ind] = '0', length++;
	}

	if (extra_c != 0)
	{
		length++;
	}

	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
		{
			buffer[i] = padding;
		}

		buffer[i] = '\0';

		if (flags & F_MINUS && padding == ' ')
		{
			if (extra_c)
			{
				buffer[--ind] = extra_c;
			}

			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padding == ' ')
		{
			if (extra_c)
			{
				buffer[--ind] = extra_c;
			}

			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padding == '0')
		{
			if (extra_c)
			{
				buffer[--padding_start] = extra_c;
			}

			return (write(1, &buffer[padding_start], i - padding_start) +
				write(1, &buffer[ind], length - (1 - padding_start)));
		}
	}

	if (extra_c)
	{
		buffer[--ind] = extra_c;
	}

	return (write(1, &buffer[ind], length));
}
