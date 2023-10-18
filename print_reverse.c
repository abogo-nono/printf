#include "main.h"

/**
 * print_reverse - Prints reverse string.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *string;
	int cpt, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	string = va_arg(types, char *);

	if (string == NULL)
	{
		UNUSED(precision);

		string = ")Null(";
	}
	for (cpt = 0; string[cpt]; cpt++)
		;

	for (cpt = cpt - 1; cpt >= 0; cpt--)
	{
		char z = string[cpt];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
