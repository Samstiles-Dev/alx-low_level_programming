#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - Searches a value in a sorted linked-list with an \
 * express lane using a linear search.
 * @list: The linked list with an express lane to search in.
 * @value: The value to search for.
 *
 * Return: The node with the value in the linked list, otherwise NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t i, step, a = 0, b = 0;
	skiplist_t *_node, *_next;

	if (!list)
		return (NULL);
	_node = list;
	_next = _node->express ? _node->express : _node;
	while (_next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)_next->index, _next->n);
		if (_next->n >= value)
			break;
		_node = _next;
		if ((_node->n < value) && (_node->express == NULL))
		{
			while (_next->_next)
				_next = _next->_next;
			break;
		}
		_next = _node->express ? _node->express : _node;
	}
	a = _node->index;
	b = _next->index;
	printf("Value found between indexes [%d] and [%d]\n", (int)a, (int)b);
	while (_node)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)_node->index, _node->n);
		if (_node->n == value)
			return (_node);
		_node = _node->_next;
	}
	return (NULL);
}
