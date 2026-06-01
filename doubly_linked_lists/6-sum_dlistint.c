#include "lists.h"

/**
 * sum_dlistint - Returns sum totals parsed from numerical fields.
 * @head: Entry reference tracking pointer value.
 *
 * Return: Aggregated addition block calculation (0 if list is empty).
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
