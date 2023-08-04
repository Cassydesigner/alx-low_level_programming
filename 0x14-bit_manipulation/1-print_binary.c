#include "main.h"

/**
 * print_binary - prints the binary representation of a decimal number
 * @n: the decimal number to be converted and printed as binary
 */
void print_binary(unsigned long int n)
{
	int index, count = 0;
	unsigned long int current_bit;

	for (index = 63; index >= 0; index--)
{
	current_bit = n >> index;

	if (current_bit & 1)
{
	_putchar('1');
	count++;
}
else if (count)
{
	_putchar('0');
}
}
if (!count)
{
	_putchar('0');
}
}
