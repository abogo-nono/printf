#include "main.h"

/**
 * append_hexadecimal_code - Append ascci in hexadecimal code to buffer
 * @buffer: An array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexadecimal_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexadecimal format code is always 2 digits long */
	if (ascii_code < 0)
	{
		ascii_code *= -1;
	}

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}
