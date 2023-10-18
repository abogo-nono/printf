#include "main.h"

/**
 * print_int - Print int
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(types, long int);
	unsigned long int number;

	n = convert_size_number(n, size);

	if (n == 0)
	{
		buffer[i--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)n;

	if (n < 0)
	{
		number = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (write_number(is_neg, i, buffer, flags, width, precision, size));
}
