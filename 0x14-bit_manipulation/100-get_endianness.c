#include "main.h"

/**
 * get_endianness - determines if a machine follows
 * little or big endian byte order
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	unsigned int index = 1;
	char *c = (char *) &index;

	return (*c);
}
