#include "lists.h"

/**
 * delete_dnodeint_at_index - Drops a chosen link segment relative to index.
 * @head: Pointer reference to structural head location.
 * @index: Absolute position coordinate identifying data index layout.
 *
 * Return: 1 if operation completes seamlessly, otherwise -1.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;

	if (index == 0)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	while (temp != NULL && i < index)
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL)
		return (-1);

	temp->prev->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = temp->prev;

	free(temp);
	return (1);
}
