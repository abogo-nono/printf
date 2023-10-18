#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int cpt = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsignd(num, size);

	if (num == 0)
	{
		buffer[cpt--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[cpt--] = (num % 10) + '0';
		num /= 10;
	}

	cpt++;

	return (write_unsgnd(0, cpt, buffer, flags, width, precision, size));
}
