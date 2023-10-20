#include "main.h"

/**
 * _calloc - this function allocates memory for an array, initialized to 0
 * @elem_num: number of elements
 * @mem_size: byte size of each element
 *
 * Return: void pointer to array space
 */
void *_calloc(unsigned int elem_num, unsigned int mem_size)
{
	char *pointer;

	if (!elem_num || !mem_size)
		return (NULL);
	pointer = malloc(elem_num * mem_size);
	if (!pointer)
		return (NULL);
	elem_num *= mem_size;
	while (elem_num--)
		pointer[elem_num] = 0;
	return (pointer);
}
