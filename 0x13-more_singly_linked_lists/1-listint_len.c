#include "lists.h"

/**
 * listint_len - it returns the no of elements
 * @h: linked list of type listint_t to traverse
 *
 * Return: no of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t nodenum = 0;

	while (h)
	{
		nodenum++;
		h = h->next;
	}

	return (nodenum);
}
