#include "hash_tables.h"

/**
 * shash_table_create - create sorted hash table given size
 *
 * @size: size of the shash table
 * Return: the created shash table, or NULL if function fails
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	shash_node_t **array;
	unsigned long int k;

	table = malloc(sizeof(shash_table_t));
	if (table == NULL)
		return (NULL);

	array = malloc(sizeof(shash_node_t *) * size);
	if (array == NULL)
		return (NULL);

	for (k = 0; k < size; k++)
		array[k] = NULL;

	table->array = array;
	table->size = size;
	table->shead = NULL;
	table->stail = NULL;

	return (table);
}

/**
 * add_n_shash - Inserts a node at the start of a hash at a specified index.
 *
 * @h: head of the shash linked list
 * @key: key of the shash
 * @value: value to store
 * Return: created node
 */
shash_node_t *add_n_shash(shash_node_t **h, const char *key, const char *value)
{
	shash_node_t *tmp;

	tmp = *h;

	while (tmp != NULL)
	{
		if (strcmp(key, tmp->key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (tmp);
		}
		tmp = tmp->next;
	}

	tmp = malloc(sizeof(shash_node_t));

	if (tmp == NULL)
		return (NULL);

	tmp->key = strdup(key);
	tmp->value = strdup(value);
	tmp->next = *h;

	*h = tmp;

	return (tmp);
}

/**
 * add_i_shash - inserts a node on the DLL of the shash table
 *
 * @ht: pointer to the table
 * @new: new node to add
 * Return: no return
 */
void add_i_shash(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *_tmp1, *_tmp2;
	int ret;

	_tmp1 = _tmp2 = ht->shead;

	while (_tmp1 != NULL)
	{
		ret = strcmp(new->key, _tmp1->key);
		if (ret == 0)
		{
			return;
		}
		else if (ret < 0)
		{
			new->sprev = _tmp1->sprev;

			if (_tmp1->sprev)
				_tmp1->sprev->snext = new;
			else
				ht->shead = new;

			_tmp1->sprev = new;
			new->snext = _tmp1;

			return;
		}
		_tmp2 = _tmp1;
		_tmp1 = _tmp1->snext;
	}

	new->sprev = _tmp2;
	new->snext = NULL;

	if (ht->shead)
		_tmp2->snext = new;
	else
		ht->shead = new;

	ht->stail = new;
}

/**
 * shash_table_set - insets a hash (key, value) to a given shash table
 *
 * @ht: pointer to the shash table
 * @key: key of the shash
 * @value: value to store
 * Return: 1 if successes, 0 if fails
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int k_index;
	shash_node_t *new;

	if (ht == NULL)
		return (0);

	if (key == NULL || *key == '\0')
		return (0);

	k_index = key_index((unsigned char *)key, ht->size);

	new = add_n_shash(&(ht->array[k_index]), key, value);

	if (new == NULL)
		return (0);

	add_i_shash(ht, new);

	return (1);
}

/**
 * shash_table_get - Obtains a value linked to a specific key.
 *
 * @ht: pointer to the shash table
 * @key: key of the shash
 * Return: value of the shash.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int k_index;
	shash_node_t *tmp;

	if (ht == NULL)
		return (NULL);

	if (key == NULL || *key == '\0')
		return (NULL);

	k_index = key_index((unsigned char *)key, ht->size);

	tmp = ht->array[k_index];

	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints the keys and values of the shash table
 *
 * @ht: pointer to the shash table
 * Return: no return
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char *sep;

	if (ht == NULL)
		return;

	printf("{");
	sep = "";

	tmp = ht->shead;

	while (tmp != NULL)
	{
		printf("%s'%s': '%s'", sep, tmp->key, tmp->value);
		sep = ", ";
		tmp = tmp->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - Displays the keys and values stored in the hash table.
 * in reverse
 *
 * @ht: pointer to the shash table
 * Return: no return
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char *sep;

	if (ht == NULL)
		return;

	printf("{");
	sep = "";

	tmp = ht->stail;

	while (tmp != NULL)
	{
		printf("%s'%s': '%s'", sep, tmp->key, tmp->value);
		sep = ", ";
		tmp = tmp->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - deletes a shash table
 *
 * @ht: pointer to the shash table
 * Return: no return
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int k;
	shash_node_t *_tmp1;
	shash_node_t *_tmp2;

	if (ht == NULL)
		return;

	for (k = 0; k < ht->size; k++)
	{
		_tmp1 = ht->array[k];
		while ((_tmp2 = _tmp1) != NULL)
		{
			_tmp1 = _tmp1->next;
			free(_tmp2->key);
			free(_tmp2->value);
			free(_tmp2);
		}
	}
	free(ht->array);
	free(ht);
}
