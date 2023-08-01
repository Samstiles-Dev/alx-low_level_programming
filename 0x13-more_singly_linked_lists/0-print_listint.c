#include "lists.h"

/**
 * print_listint - this prints all the elements of a listint_t linked list
 * @h: a linked list of type listint_t to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t number_of_nodes = 0;

	while (h)
	{
		printf("%d\n", h->n);
		/*_putchar()*/
		number_of_nodes++;
		h = h->next;
	}

	return (number_of_nodes);
}
