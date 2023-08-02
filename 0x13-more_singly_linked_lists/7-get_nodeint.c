#include "lists.h"

/**
 * get_nodeint_at_index - a function that returns the node at a certain index in a linked list listint_t
 * @head: a pointer to the first node in the linked list listint_t
 * @index: a pointer to the index of the node to return
 *
 * Return: pointer to the node we're looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int fyd = 0;
	listint_t *node_pointer_314 = head;

	while (node_pointer_314 && fyd < index)
	{
		node_pointer_314 = node_pointer_314->next;
		fyd++;
	}

	return (node_pointer_314 ? node_pointer_314 : NULL);
}
