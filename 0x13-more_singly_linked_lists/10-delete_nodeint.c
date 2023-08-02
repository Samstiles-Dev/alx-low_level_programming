10-delete_nodeint.c

#include "lists.h"

/**
 * delete_nodeint_at_index - a function that deletes a node in a linked list using the index
 * @head: a pointer to the first element in the linked list
 * @index: an index of the node to be deleted
 *
 * Return: 1, or -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *rem_314 = *head;
	listint_t *current_314 = NULL;
	unsigned int _i_314 = 0;

	if (*head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		*head = (*head)->next;
		free(rem_314);
		return (1);
	}

	while (_i_314 < index - 1)
	{
		if (!rem_314 || !(rem_314->next))
			return (-1);
		rem_314 = rem_314->next;
		_i_314++;
	}


	current_314 = rem_314->next;
	rem_314->next = current_314->next;
	free(current_314);

	return (1);
}
