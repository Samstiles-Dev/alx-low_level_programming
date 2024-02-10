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
 * binary_search_index - Searches a value in a sorted array using \
 * a binary search.
 * @array: The array to search in.
 * @l: The left index of the array.
 * @r: The right index of the array.
 * @value: The value to look for.
 *
 * Return: The first index of the value in the array, otherwise -1.
 */
int binary_search_index(int *array, size_t l, size_t r, int value)
{
	size_t n;

	if (!array)
		return (-1);
	print_array(array, l, r);
	n = l + ((r - l) / 2);
	if (l == r)
		return (*(array + n) == value ? (int)n : -1);
	if (value < *(array + n))
	{
		return (binary_search_index(array, l, n, value));
	}
	else if (value == *(array + n))
	{
		if ((n > 0) && (*(array + n - 1) == value))
		{
			return (binary_search_index(array, l, n, value));
		}
		return ((int)n);
	}
	else
	{
		return (binary_search_index(array, n + 1, r, value));
	}
}

/**
 * advanced_binary - Searches a value in a sorted array using a binary search.
 * @array: The array to search in.
 * @size: The length of the array.
 * @value: The value to look for.
 *
 * Return: The first index of the value in the array, otherwise -1.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || !size)
		return (-1);
	else if ((size == 1) && (*array == value))
		return (0);
	return (binary_search_index(array, 0, size - 1, value));
}
