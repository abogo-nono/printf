#include "main.h"

/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsignd(number, size);

	if (number == 0)
	{
		buffer[i--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && init_number != 0)
	{
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
