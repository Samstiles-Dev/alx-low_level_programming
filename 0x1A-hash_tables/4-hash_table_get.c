#include "hash_tables.h"

/**
 * hash_table_get - given key, get value
 * @ht: hash table
 * @key: key
 * Return: value; or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *_tmp;

	/* find index in hash table where key is */
	/* look through linked list to find matching key for value */

	if (!ht || !key)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);

	_tmp = (ht->array)[index];
	while (_tmp != NULL && strcmp(_tmp->key, key) != 0)
		_tmp = _tmp->next;
	if (!_tmp)
		return (NULL);
	else
		return (_tmp->value);
}
