#include "search_algos.h"
/**
* binary_search - searches for a value in a sorted array of integers
* @array: Pointers of the first element of the array
* @size: number of elements in the array
* @value: value to be searched for
*
* Return: index where value is located, or -1 if it is not found
*/

int binary_search(int *array, size_t size, int value)
{
	size_t i, _left, _right;

	if (array == NULL)
		return (-1);

	for (_left = 0, _right = size - 1; _right >= _left;)
	{
		printf("Searching in array: ");
		for (i = _left; i < _right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = _left + (_right - _left) / 2;
		if (array[i] == value)
			return (i);
		if (array[i] > value)
			_right = i - 1;
		else
			_left = i + 1;
	}

	return (-1);
}
