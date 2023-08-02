#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - this function Counts the number of unique nodes in a looped listint_t linked list.
 * @head: a pointer to the head of the listint_t linked list to check.
 *
 * Return: If the list is not looped - 0.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoise_244, *hare_244;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
	{
		/* Returns, if Null */
		return (0);
	}

	tortoise_244 = head->next;
	hare_244 = (head->next)->next;

	while (hare_244)
	{
		if (tortoise_244 == hare_244)
		{
			tortoise_244 = head;
			while (tortoise_244 != hare_244)
			{
				nodes++;
				tortoise_244 = tortoise_244->next;
				hare_244 = hare_244->next;
			}

			tortoise_244 = tortoise_244->next;
			while (tortoise_244 != hare_244)
			{
				nodes++;
				tortoise_244 = tortoise_244->next;
			}

			return (nodes);
		}

		tortoise_244 = tortoise_244->next;
		hare_244 = (hare_244->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - a function that Prints a listint_t linked list.
 * @head: A pointer to the head of the listint_t linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{	
	/* Nodes Declaration */
	size_t num_nodes, nodes_index = 0;

	num_nodes = looped_listint_len(head);

	if (num_nodes == 0)
	{
		for (; head != NULL; num_nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (nodes_index = 0; nodes_index < num_nodes; nodes_index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (num_nodes);
}
