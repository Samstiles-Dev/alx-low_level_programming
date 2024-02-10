#include "search_algos.h"

/**
 * print_i - function to print index of each check
 * @array: array
 * @i: index checked
 */
void print_i(int *array, size_t i)
{
	printf("Value checked array[%lu] = [%d]\n", i, array[i]);
}

/**
 * interpolation_search - like binary search, but use idx based on formula
 * @array: given array of ints
 * @size: size of array
 * @value: value to search for
 * Return: index at which value's found
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t l = 0;
	size_t r = size - 1;
	size_t _pos;

	if (array == NULL)
		return (-1);

	_pos = l + (((double)(r - l) / (array[r] - array[l]))
		   * (value - array[l]));
	while (_pos < size)
	{
		print_i(array, _pos);
		if (array[_pos] == value)
			return (_pos);
		else if (array[_pos] < value)
			l = _pos + 1;
		else
			r = _pos - 1;
		_pos = l + (((double)(r - l) / (array[r] - array[l]))
			   * (value - array[l]));
	}
	printf("Value checked array[%lu] is out of range\n", _pos);
	return (-1);
}
