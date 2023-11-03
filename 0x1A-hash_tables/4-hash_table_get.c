#include "hash_tables.h"

/**
 * hash_table_get- Gets the value from a hash table
 * @ht: Table to look from
 * @key: key to look up
 * Return: value
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *_tmp;

	if (!ht || !key || strlen(key) == 0)
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	_tmp = ht->array[index];

	while (_tmp)
	{
		if (strcmp(_tmp->key, key) == 0)
			return (_tmp->value);
		_tmp = _tmp->next;
	}
	return (NULL);
}
