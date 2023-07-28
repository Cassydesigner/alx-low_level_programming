#include <stdlib.h>
#include "lists.h"

/**
 * list_len - returns the no of elements
 * @h: pointer to the list_t
 *
 * Return: no of elements in h
 */
size_t list_len(const list_t *h)
{
size_t l = 0;

while (h)
{
l++;
h = h->next;
}
return (l);
}
