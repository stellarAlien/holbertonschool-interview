#include "sort.h"

#include <stddef.h>

/**
 * swap - swaps to array values
 *
 * @x: child
 * @y: parent
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * heapify - heapifies an array
 * @array: the array to sort
 * @size: array size
 * @calcsize: array size
 * @idx: index of the root
 */
void heapify(int *array, size_t size, size_t calcsize, int idx)
{
	int root = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;
	int n = (int)size;

	if (left < n && array[left] > array[root])
		root = left;
	if (right < n && array[right] > array[root])
		root = right;
	if (root != idx)
	{
		swap(&array[idx], &array[root]);
		print_array(array, calcsize);
		heapify(array, n, calcsize, root);
	}
}

/**
 * heap_sort - sorts an array using heap sort
 * @array: the array to sort
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, size, i);
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, size, 0);
	}
}
