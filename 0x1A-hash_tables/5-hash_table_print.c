#include "hash_tables.h"

/**
 * hash_table_print - A function that prints the elements in a table
 * @ht: hash table to print
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *_tmp;
	int comma = 0;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (comma == 1)
				printf(", ");
		}
		_tmp = ht->array[i];

		while (_tmp)
		{
			if (ht->array)
			{
				while (_tmp)
				{
					printf("'%s': '%s'", _tmp->key, _tmp->value);
					_tmp = _tmp->next;
					if (_tmp)
						printf(", ");
				}
				comma = 1;
			}
		}
	}
	printf("}\n");
}
