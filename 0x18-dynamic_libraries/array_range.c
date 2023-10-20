#include "main.h"

/**
 * array_range - this creates an array of integers
 * @_min: _min int
 * @_max: _max int
 * Return: array of integers
 */
int *array_range(int _min, int _max)
{
	int length, i;
	int *pointer;

	if (_min > _max)
		return (NULL);
	length = _max - _min + 1;
	pointer = malloc(sizeof(int) * length);
	if (!pointer)
		return (NULL);
	for (i = 0; i < length; i++)
		pointer[i] = _min++;
	return (pointer);
}
