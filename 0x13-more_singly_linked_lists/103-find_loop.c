#include "lists.h"

/**
 * find_listint_loop - a function that finds the loop in a listint_t linked list
 * @head: a pointer to the listint_t linked list to be searched
 *
 * Return: this function returns the address of the node starting point or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	/* Declaration of the varibles */
	listint_t *_short = head;
	listint_t *high = head;

	if (!head)
	{
		/* Return, if not head */
		return (NULL);
	}

	while (_short && high && high->next)
	{
		high = high->next->next;
		_short = _short->next;
		if (high == _short)
		{
			_short = head;
			while (_short != high)
			{
				_short = _short->next;
				high = high->next;
			}
			return (high);
		}
	}

	return (NULL);
}
