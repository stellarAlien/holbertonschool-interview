#include "lists.h"
/**
 *check_cycle - check if linked list has cycle
 *
 * @list : head of llist
 * Return: int
 */
int check_cycle(listint_t *list)
{

	listint_t *p;

	if (!list)
		return (0);
	if (!list->next)
		return (1);
	p = list->next;
	while (p)
	{
		if (p == list)
			return (1);
		p = p->next;
	}
	return (0);
}
