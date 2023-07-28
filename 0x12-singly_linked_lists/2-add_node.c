#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - This function inserts a new node at the head of a linked list.
 * @head: double pointer to the list_t list
 * @str: new string to be stored in the node
 *
 *
 * Return: The address of the new element is returned, or NULL if the operation is unsuccessful.
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_element;
	unsigned int len = 0;

	while (str[len])
		len++;

	new_element = malloc(sizeof(list_t));
	if (!new_element)
		return (NULL);

	new_element->str = strdup(str);
	new_element->len = len;
	new_element->next = (*head);
	(*head) = new_element;

	return (*head);
}
