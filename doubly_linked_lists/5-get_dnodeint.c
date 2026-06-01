#include "lists.h"

/**
 * get_dnodeint_at_index - Identifies node position offset from list origin.
 * @head: Initial node starting connection point.
 * @index: Unsigned identifier element targeted (0-indexed).
 *
 * Return: Pointer matching index point, otherwise NULL.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;

	while (head != NULL)
	{
		if (count == index)
			return (head);
		count++;
		head = head->next;
	}

	return (NULL);
}
