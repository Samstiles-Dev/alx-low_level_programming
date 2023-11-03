#include "hash_tables.h"

/**
 * hash_table_delete - this Deletes a hash table
 * @ht: hash table
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned int i;
	hash_node_t *_tmp, *next;

	if (!ht)
		return;
	for (i = 0; i < ht->size; i++)
	{
		_tmp = ht->array[i];
		while (_tmp)
		{
			next = _tmp->next;
			free(_tmp->key);
			free(_tmp->value);
			free(_tmp);
			_tmp = next;
		}
	}
	free(ht->array);
	free(ht);
}
