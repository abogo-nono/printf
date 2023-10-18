#include "main.h"

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @index: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: width specifier
 * @flags: Flags specifier
 * @padding: Char representing the padding
 * @extra_c: Char representing extra char
 * @padding_start: Index at which padding should start
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int index, int length,
	int width, int flags, char padding, char extra_c, int padding_start)
{
	int cpt;

	if (width > length)
	{
		for (cpt = 3; cpt < width - length + 3; cpt++)
			buffer[cpt] = padding;
		buffer[cpt] = '\0';
		if (flags & F_MINUS && padding == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], cpt - 3));
		}
		else if (!(flags & F_MINUS) && padding == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[3], cpt - 3) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padding == '0')
		{
			if (extra_c)
				buffer[--padding_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padding_start], cpt - padding_start) +
				write(1, &buffer[index], length - (1 - padding_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

