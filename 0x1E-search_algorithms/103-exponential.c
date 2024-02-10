#include "search_algos.h"

/**
 * print_array - Prints an array contents.
 * @array: The source of the array to print.
 * @l: The left index of the array.
 * @r: The right index of the array.
 */
void print_array(int *array, size_t l, size_t r)
{
	size_t k;

	if (array)
	{
		printf("Searching in array: ");
		for (k = l; k < l + (r - l + 1); k++)
			printf("%d%s", *(array + k), k < l + (r - l) ? ", " : "\n");
	}
}

/**
 * binary_search_index1 - Searches a value in a sorted array using \
 * a binary search.
 * @array: The array to search in.
 * @l: The left index of the array.
 * @r: The right index of the array.
 * @value: The value to look for.
 *
 * Return: The first index of the value in the array, otherwise -1.
 */
int binary_search_index1(int *array, size_t l, size_t r, int value)
{
	size_t m;

	if (!array)
		return (-1);
	print_array(array, l, r);
	m = l + ((r - l) / 2);
	if (l == r)
		return (*(array + m) == value ? (int)m : -1);
	if (value < *(array + m))
	{
		return (binary_search_index1(array, l, m - 1, value));
	}
	else if (value == *(array + m))
	{
		return ((int)m);
	}
	else
	{
		return (binary_search_index1(array, m + 1, r, value));
	}
}

/**
 * exponential_search - Searches a value in a sorted array using \
 * an exponential search.
 * @array: The array to search in.
 * @size: The length of the array.
 * @value: The value to look for.
 *
 * Return: The index of the value in the array, otherwise -1.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t _low = 1, _high = 2;

	if (!array || !size)
		return (-1);
	if (size < 2)
	{
		_low = 0;
		_high = 1;
	}
	else
	{
		while (_low < size)
		{
			printf("Value checked array[%lu] = [%d]\n", _low, array[_low]);
			if (
				((array[_low] <= value) && (array[_high] >= value))
				|| ((_low * 2) >= size)
				)
				break;
			_low *= 2;
			_high = _high * 2 < size ? _high * 2 : size - 1;
		}
	}
	printf("Value found between indexes [%lu] and [%lu]\n", _low, _high);
	return (binary_search_index1(array, _low, _high, value));
}
