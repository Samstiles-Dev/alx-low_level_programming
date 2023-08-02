#include "lists.h"

/**
 * reverse_listint - a function that reverses a linked list listint_t
 * @head: a pointer to the first node in the linked list
 *
 * Return: this function returns a pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev_244 = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev_244;
		prev_244 = *head;
		*head = next;
	}

	*head = prev_244;

	return (*head);
}

