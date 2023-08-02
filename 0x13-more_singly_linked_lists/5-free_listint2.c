#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @head:Pointer to the head of the list
 */
void free_listint2(listint_t **head)
{
	listint_t *temp_node;

	if (head == NULL)
		return;

	while (*head)
	{
		temp_node = (*head)->next;
		free(*head);
		*head = temp_node;
	}

	*head = NULL;
}
