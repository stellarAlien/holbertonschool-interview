#include "palindrome.h"
/**
 * is_palindrome - checks if int is palindrome
 *
 * @n: int to check
 * Return: int
 */
int is_palindrome(unsigned long n)
{
	unsigned long remainder, reversed = 0, aux;

	aux = n;
	while (aux != 0)
	{
		remainder = aux % 10;
		reversed = reversed * 10 + remainder;
		aux /= 10;
	}
	if (reversed != n)
	return (0);
	return (1);
}
