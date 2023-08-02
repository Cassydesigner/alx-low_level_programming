#include "lists.h"

/**
 * print_listint - prints elements of a linked list
 * @h: linked list of type listint_t to printed
 *
 * Return: no of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t nodenum = 0;

	while (h)
	{
		printf("%d\n", h->n);
		nodenum++;
		h = h->next;
	}

	return (nodenum);
}
