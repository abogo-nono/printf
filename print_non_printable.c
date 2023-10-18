#include "main.h"

/**
 * print_non_printable - Prints ascii codes in hexadecimal of
 * non printable chars
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int cpt = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[cpt] != '\0')
	{
		if (is_printable(str[cpt]))
		{
			buffer[cpt + offset] = str[cpt];
		}
		else
		{
			offset += append_hexadecimal_code(str[cpt], buffer, cpt + offset);
		}

		cpt++;
	}

	buffer[cpt + offset] = '\0';

	return (write(1, buffer, cpt + offset));
}
