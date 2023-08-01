#include "lists.h"

/**
 * add_nodeint - this function adds a new node at the beginning of a listint_t linked list
 * @head: pointer to the first node in the listint_t list
 * @n: argument/data to insert in that new node
 *
 * Return: the function returns a pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_314;

	new_314 = malloc(sizeof(listint_t));
	if (!new_314)
		return (NULL);

	new_314->n = n;
	new_314->next = *head;
	*head = new_314;

	return (new_314);
}
