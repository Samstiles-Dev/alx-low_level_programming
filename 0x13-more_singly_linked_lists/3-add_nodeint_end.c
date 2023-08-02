#include "lists.h"

/**
 * add_nodeint_end - this function adds a node at the end of a listint_t linked list
 * @head: points to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: this returns a pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_element_314;
	listint_t *head_temp = *head;

	new_element_314 = malloc(sizeof(listint_t));
	if (!new_element_314)
		return (NULL);

	new_element_314->n = n;
	new_element_314->next = NULL;

	if (*head == NULL)
	{
		*head = new_element_314;
		return (new_element_314);
	}

	while (head_temp->next)
		head_temp = head_temp->next;

	head_temp->next = new_element_314;

	return (new_element_314);
}
