#include "hash_tables.h"

/**
 * hash_table_set - adds a new node to the table
 * @ht: hash table to add new node to
 * @key: key
 * @value: value
 * Return: 1, if successful, 0 if it fails
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *_tmp;
	unsigned long int index;

	if (!ht || !key || !*key || !value)
	{
		return (0);
	}

	index = key_index((unsigned char *)key, ht->size);
	_tmp = ht->array[index];
	while (_tmp)
	{
		if (strcmp(_tmp->key, key) == 0)
		{
			free(_tmp->value);
			_tmp->value = strdup(value);
			return (1);
		}
		_tmp = _tmp->next;
	}
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
