#include "lists.h"

/**
 *check_cycle - check if linked list has cycle
 *
 * @list : head of llist
 * Return: int
 */
int check_cycle(listint_t *list)
{
	listint_t *s, *f;

	s = list;
	f = list;
	while (s && f)
	{
		s = s->next;
		f = f->next->next;
		if (s == f)
			return (1);
	}
	return (0);
}
