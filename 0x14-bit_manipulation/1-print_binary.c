#include "main.h"

/**
 * print_binary - a function that prints the binary equiv of a decimal no
 * @n: the binary num to be printed
 */
void print_binary(unsigned long int n)
{
	int num_222, count_num = 0;
	unsigned long int _current_222;

	for (num_222 = 63; num_222 >= 0; num_222--)
	{
		_current_222 = n >> num_222;

		if (_current_222 & 1)
		{
			_putchar('1');
			count_num++;
		}
		else if (count_num) {
			_putchar('0');
		}
	}
	if (!count_num) {
		_putchar('0');
	}
}
