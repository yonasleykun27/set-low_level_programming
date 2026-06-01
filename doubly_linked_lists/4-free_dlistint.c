#include "lists.h"

/**
 * free_dlistint - Completely deallocates memory spaces of a dlistint_t list.
 * @head: Start pointing address of the targeted block tracking.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
