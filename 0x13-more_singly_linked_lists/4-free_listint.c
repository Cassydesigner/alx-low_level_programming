#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: Pointer to the head of the list
 */
void free_listint(listint_t *head)
{
	listint_t *temp_node;

	while (head)
	{
		temp_node = head->next;
		free(head);
		head = temp_node;
	}
}
