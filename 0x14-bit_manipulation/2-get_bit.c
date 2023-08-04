#include "main.h"

/**
 * get_bit - retrieves the value of a bit at a specified index in a number
 * @n: the number to retrieve the bit from
 * @index: the index of the bit to be retrieved (0-based)
 *
 * Return: the value of the specified bit at the given index,
 * or -1 if the index is invalid
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);

	bit_value = (n >> index) & 1;

	return (bit_value);
}
