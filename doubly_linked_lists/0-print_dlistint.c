#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - Prints all elements of a dlistint_t list.
 * @h: Head pointer of the doubly linked list.
 *
 * Return: The total number of nodes tracked.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}

	return (count);
}
