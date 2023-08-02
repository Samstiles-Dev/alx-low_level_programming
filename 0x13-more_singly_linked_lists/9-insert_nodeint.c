#include "lists.h"

/**
 * insert_nodeint_at_index - this function inserts a new node in a linked list listint_t
 * @head: a pointer to the first node in the linked list listint_t
 * @idx: an index where the new node is added
 * @n: a data to insert in the new node
 *
 * Return: this function returns a pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{	
	/* declare the variables and pointers */
	unsigned int x_314;
	listint_t *new_node_314;
	listint_t *pointer_314 = *head;

	new_node_314 = malloc(sizeof(listint_t));
	if (!new_node_314 || !head)
		return (NULL);

	new_node_314->n = n;
	new_node_314->next = NULL;

	if (idx == 0)
	{
		new_node_314->next = *head;
		*head = new_node_314;
		return (new_node_314);
	}

	for (x_314 = 0; pointer_314 && x_314 < idx; x_314++)
	{
		if (x_314 == idx - 1)
		{
			new_node_314->next = temp->next;
			pointer_314->next = new_node_314;
			return (new_node_314);
		}
		else
			pointer_314 = pointer_314->next;
	}

	return (NULL);
}
