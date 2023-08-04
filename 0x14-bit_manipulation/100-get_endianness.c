#include "main.h"

/**
 * get_endianness - a function that checks if a machine is little or big endian
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{	
	/* variable definition */
	unsigned int inum_222 = 1;
	char *c_222 = (char *) &inum_222;

	return (*c_222);
}
