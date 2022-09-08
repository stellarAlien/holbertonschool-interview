#include "lists.h"
/**
 * is_palindrome - checks if linked list is palindrome
 *
 * @head: pointer to head of doubly linked list
 * Return: 1 if palindromeelse 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *n;
	listint_t *s, *t; /*top of stack and stack itself*/

	if (!head)
		return (1);
	n = *head;
	n = n->next;
	s = *head;
	/*will use the linked list struct as a stack*/
	while (n)
	{
		t = malloc(sizeof(listint_t));
		t->n = n->n;
		t->next = s;
		s = t;
		n = n->next;
	}
	n = *head;
	while (n->next)
	{
		if (n->n != s->n)
			return (0);
		n = n->next;
		s = s->next;
	}
	return (1);
}
