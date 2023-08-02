#include "lists.h"

/**
 * free_listint_safe - a function that frees a listint_t linked list
 * @h: a pointer to the first node in the listint_t linked list
 *
 * Return: number of elements in the freed linked list
 */
size_t free_listint_safe(listint_t **h)
{
	/* Declaration of variables */
	size_t lenght_244 = 0;
	listint_t *temp_244;

	if (!h || !*h)
	{
		return (0);
	}

	while (*h)
	{
		lenght_244 = *h - (*h)->next;
		if (lenght_244 > 0)
		{
			temp_244 = (*h)->next;
			free(*h);
			*h = temp_244;
			lenght_244++;
		}
		else
		{
			free(*h);
			*h = NULL;
			lenght_244++;
			break;
		}
	}

	*h = NULL;

	return (lenght_244);
}
