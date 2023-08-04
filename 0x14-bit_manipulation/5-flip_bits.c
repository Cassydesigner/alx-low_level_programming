#include "main.h"

/**
 * flip_bits - calculates the number of bits that need to be flipped
 *             to convert one number to another.
 * @n: the first number.
 * @m: the second number.
 *
 * Return: the number of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int index, count = 0;
	unsigned long int current_bit;
	unsigned long int xor_result = n ^ m;

	for (index = 63; index >= 0; index--)
{
	current_bit = xor_result >> index;
	if (current_bit & 1)
		count++;
}

return (count);
}
