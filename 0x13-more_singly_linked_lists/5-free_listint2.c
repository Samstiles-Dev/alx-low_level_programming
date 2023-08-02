#include "lists.h"

/**
 * free_listint2 - this function frees a linked list listint_t
 * @head: pointer to the listint_t list to be freed
 */
void free_listint2(listint_t **head)
{	
	listint_t *node_data;
	
	/* Return if the head is NULL */
	if (head == NULL) {
		return;
	}

	/*Traverse the nodes using their pointer */
	while (*head)
	{
		node_data = (*head)->next;
		free(*head);
		*head = node_data;
	}

	*head = NULL;
}
