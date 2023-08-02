#include "lists.h"

/**
 * delete_nodeint_at_index - a function that deletes a node in a linked list using an index
 * @head: a pointer to the first element in the linked list
 * @index: index of the node to delete
 *
 * Return: 1, or -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp_244 = *head;
	listint_t *current = NULL;
	unsigned int i_244 = 0;

	if (*head == NULL)
	{	
		/* Empty list, cannot delete */
		return (-1);
	}

	if (index == 0)
	{	
		/* Deleting the head node */
		*head = (*head)->next;
		free(temp_244);
		return (1);
	}

	/* Traverse to find the previous node */
	while (i_244 < index - 1)
	{
		if (!temp_244 || !(temp_244->next))
		{
			/* Index out of bounds, cannot delete */
			return (-1);
		}
		temp_244 = temp_244->next;
		i_244++;
	}

	/* Delete the node */
	current = temp_244->next;
	temp_244->next = current->next;
	free(current);

	return (1);
}
