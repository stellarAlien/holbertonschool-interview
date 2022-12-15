#include "search_algos.h"
/**
 * print_array - print the subarray
 * @array: array to print
 * @left: index to start print
 * @right: index to end print
 *
 * Return: is a void
 */
void print_array(int *array, int left, int right)
{
	printf("Searching in array: ");
	while (left < right)
	{
		printf("%i, ", array[left]);
		left++;
	}
	printf("%i\n", array[left]);
}
/**
 * recursion_binary - search for first index of
 * value in subarray in recursive way
 * @array: subarray to search in
 * @left: left bound of adday
 * @right: right bound of array
 * @value: value to find
 *
 * Return: index
 */
int recursion_binary(int *array, int left, int right, int value)
{
	int mid;

	print_array(array, left, right);
	mid = (right - left) / 2 + left;
	if (left == right)
		return (-1);
	if (array[mid] == value && array[mid - 1] != value)
		return (mid);
	if (array[mid] >= value)
		return (recursion_binary(array, left, mid, value));
	if (array[mid] <= value)
		return (recursion_binary(array, mid + 1, right, value));
	return (-1);
}
/**
 * advanced_binary - print the message
 * @array: array to find
 * @size: array length
 * @value: value to find
 *
 * Return: index
 */
int advanced_binary(int *array, size_t size, int value)
{

	if (!array)
		return (-1);

	return (recursion_binary(array, 0, size - 1, value));
}
