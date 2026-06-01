#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given index position.
 * @h: Double pointer tracking head node block address.
 * @idx: Target reference space to input structural instance.
 * @n: Value metric for target initialization field.
 *
 * Return: Address properties of the added element sequence, or NULL.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	dlistint_t *new_node, *temp = *h;

	if (idx == 0)
		return (add_dnodeint(h, n));

	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL)
		return (NULL);

	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next->prev = new_node;
	temp->next = new_node;

	return (new_node);
}
