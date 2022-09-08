#include "lists.h"
#define ARRAY_SIZE 2048
/**
 * is_palindrome - function that checks if a singly linked list is a palindrome
 * @head: Pointer to the head of the list
 * Return: 1 if it is palindrome or 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *n = *head;
	int array[ARRAY_SIZE];
	int i = 0, j = 0, mid = 0;

	if (head == NULL || (n != NULL && n->next == NULL))
		return (1);
	while (n != NULL)
	{
		array[i] = n->n;
		n = n->next;
		i++;
	}
	i--;
	mid = i / 2;
	for (; i >= mid && j <= mid; i--, j++)
	{
		if (array[j] != array[i])
			return (0);
		i--, j++;
	}
	return (1);
}
