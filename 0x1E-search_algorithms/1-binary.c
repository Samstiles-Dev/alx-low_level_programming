#include "search_algos.h"

/**
 * print_arr - function to print array everytime array is halved
 * @array: array
 * @l: left index of original array
 * @r: right index of original array
 */
void print_arr(int *array, size_t l, size_t r)
{
	size_t k = 0;

	printf("Searching in array: ");
	for (k = l; k <= r; k++)
	{
		if (k != r)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
	}
}

/**
 * binary_search - search mids
 * @array: given array of ints
 * @size: size of array
 * @value: value to search for
 * Return: index at which value's found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t _mid = 0;
	size_t l = 0;
	size_t r = size - 1;

	if (!array)
		return (-1);

	while (l <= r)
	{
		print_arr(array, l, r);
		_mid = (l + r) / 2;
		if (array[_mid] == value)
			return (_mid);
		else if (array[_mid] > value)
			r = _mid - 1;
		else
			l = _mid + 1;
	}
	return (-1);
}}
