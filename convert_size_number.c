#include "main.h"

/**
 * convert_size_number - Casts a number to the specified size
 * @number: The number to be casted.
 * @size: The number indicating the type to be casted.
 * Return: The casted value of num
 */
long int convert_size_number(long int number, int size)
{
	if (size == S_LONG)
	{
		return (number);

	}
	else if (size == S_SHORT)
	{
		return ((short)number);
	}

	return ((int)number);
}
