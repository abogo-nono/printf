#include "main.h"

/**
 * convert_size_unsignd - Casts a number to the specified size
 * @number: Number to be casted
 * @size: Number indicating the type to be casted
 * Return: Casted value of num
 */
long int convert_size_unsignd(unsigned long int number, int size)
{
	if (size == S_LONG)
	{
		return (number);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)number);
	}

	return ((unsigned int)number);
}
