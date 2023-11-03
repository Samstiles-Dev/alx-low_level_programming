#include "hash_tables.h"

/**
 * hash_table_create - create hash table given the size
 * @size: size
 * Return: pointer to table; NULL if error
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_t;
	hash_node_t **array;
	unsigned long int k = 0;

	if (size == 0)
		return (NULL);

	hash_t = malloc(sizeof(hash_table_t));
	if (!hash_t)
		return (NULL);
	array = malloc(sizeof(*array) * size);
	if (!array)
	{
		free(hash_t);
		return (NULL);
	}
	while (k < size)
	{
		array[k] = NULL;
		k++;
	}

	hash_t->size = size;
	hash_t->array = array;

	return (hash_t);
}
