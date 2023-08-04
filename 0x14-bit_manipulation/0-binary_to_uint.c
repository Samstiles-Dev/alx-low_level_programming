#include "main.h"

/**
 * binary_to_uint - this function converts a binary no to unsigned int
 * @b: a string argument that contains the binary no
 *
 * Return: the function returns the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	/* variable declaration */ 
	int num_221;
	unsigned int decimal_numeber_32 = 0;

	if (!b)
	{
		return (0);
	}

	for (num_221 = 0; b[num_221]; num_221++)
	{
		if (b[num_221] < '0' || b[num_221] > '1')
		{
			return (0);
		}
		decimal_numeber_32 = 2 * decimal_numeber_32 + (b[num_221] - '0');
	}

	return (decimal_numeber_32);
}
