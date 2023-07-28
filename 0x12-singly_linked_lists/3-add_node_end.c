#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - this function adds a new node at the end of a linked list
 * @head: double pointer to the list_t list
 * @str: string to be stored in the new node
 *
 * Return: this function returns an address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_element_1;
	list_t *temp_1 = *head;
	unsigned int len = 0;

	while (str[len])
		len++;

	new_element_1 = malloc(sizeof(list_t));
	if (!new_element_1)
		return (NULL);

	new_element_1->str = strdup(str);
	new_element_1->len = len;
	new_element_1->next = NULL;

	if (*head == NULL)
	{
		*head = new_element_1;
		return (new_element_1);
	}

	while (temp_1->next)
		temp_1 = temp_1->next;

	temp_1->next = new_element_1;

	return (new_element_1);
}
