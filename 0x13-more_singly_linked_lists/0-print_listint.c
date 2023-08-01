#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t linked list
 * @h: linked list of type listint_t to be print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t number_of_nodes_314 = 0;

	while (h)
	{
		printf("%d\n", h->n);
		/*_putchar()*/
		number_of_nodes_314++;
		h = h->next;
	}

	return (number_of_nodes_314);
}
