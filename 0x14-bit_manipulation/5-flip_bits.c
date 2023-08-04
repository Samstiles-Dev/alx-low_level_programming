#include "main.h"

/**
 * flip_bits - a function that counts the num of bits to be changed
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits to be changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	/* variable declaration */
	int num_222, count_222 = 0;
	unsigned long int current_222;
	unsigned long int exclusive_222 = n ^ m;

	for (num_222 = 63; num_222 >= 0; num_222--)
	{
		current_222 = exclusive_222 >> num_222;
		if (current_222 & 1) {
			count_222++;
		}
	}

	return (count_222);
}
