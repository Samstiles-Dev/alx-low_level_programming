#include "lists.h"

/**
 * free_listint - this function frees the linked list
 * @head: listint_t list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *head_data;

	while (head)
	{
		head_data = head->next;
		free(head);
		head = head_data;
	}
}
