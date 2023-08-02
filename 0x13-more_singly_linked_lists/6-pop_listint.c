#include "lists.h"

/**
 * pop_listint - this function deletes the head node of a linked list listint_t
 * @head: a pointer to the first element in the linked list
 *
 * Return: the data inside the node elements that was deleted,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *node_data;
	int number_of_element_314;

	if (!head || !*head)
		return (0);

	number_of_element_314 = (*head)->n;
	node_data = (*head)->next;
	free(*head);
	*head = node_data;

	return (number_of_element_314);
}
