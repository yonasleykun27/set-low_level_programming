#include "lists.h"

/**
 * dlistint_len - Calculates number of elements in a linked dlistint_t list.
 * @h: Head pointer of the list.
 *
 * Return: Elements counted.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
