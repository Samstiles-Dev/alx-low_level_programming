#include "main.h"

/**
 * *_realloc - allocates a memory block using malloc and free.
 * @pointer: pointer to memory allocated with malloc(former_size).
 * @former_size: size in bytes, of the allocated space for pointer
 * @latest_size: size in bytes of the new memory block.
 *
 * Return: NULL if latest_size = 0 and pointer is not NULL.
 */
void *_realloc(void *pointer, unsigned int former_size, unsigned int latest_size)
{
	void *p;
	unsigned int i;

	if (latest_size == former_size)
		return (pointer);
	if (latest_size == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}
	if (pointer == NULL)
	{
		p = malloc(latest_size);
		if (p == NULL)
			return (NULL);
		return (p);
	}
	if (latest_size > former_size)
	{
		p = malloc(latest_size);
		if (p == NULL)
			return (NULL);
		for (i = 0; i < former_size && i < latest_size; i++)
			*((char *)p + i) = *((char *)pointer + i);
		free(pointer);
	}
	return (p);
}
