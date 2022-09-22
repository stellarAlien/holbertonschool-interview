#include "lists.h"

#define size 1024

/**
 *check_cycle - check if linked list has cycle
 *
 * @list : head of llist
 * Return: int
 */
int check_cycle(listint_t *list)
{
	/* heir and tortoise method */
	listint_t *s, *f;

	s = list;
	f = list;
	while (s)
	{
		s = s->next;
		f = f->next->next;
		if (s == f)
			return (1);
	}
	return (0);
}
