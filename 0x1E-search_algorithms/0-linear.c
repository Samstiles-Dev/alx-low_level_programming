#include "search_algos.h"

/**
  * linear_search - Linear_search algorithm on an array function
  * @array: Array to be search from
  * @size: Array size
  * @value: integer to search for in array
  * Return: Index where value was found
  */

int linear_search(int *array, size_t size, int value)
{
	size_t k = 0;

	if (!array || size == 0)
		return (-1);

	while (k < size)
	{
		printf("Value checked array[%lu] = [%d]\n", k, array[k]);
		if (array[k] == value)
			return (k);
		k++;
	}

	return (-1);
}
