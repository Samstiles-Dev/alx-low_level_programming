#include "lists.h"

/**
 * sum_listint - a function that calculates the sum of all the data in a listint_t linked list
 * @head: a pointer to the first node in the listint_t linked list
 *
 * Return: this function returns the resulting sum
 */
int sum_listint(listint_t *head)
{
	/* declare a resulting sum variable*/
	int resulting_sum_314 = 0;
	listint_t *node_pointer_314 = head;

	while (node_pointer_314)
	{
		resulting_sum_314 += node_pointer_314->n;
		node_pointer_314 = node_pointer_314->next;
	}

	return (resulting_sum_314);
}
