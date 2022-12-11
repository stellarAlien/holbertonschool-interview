#include "sort.h"

#include <stddef.h>

/**
 * swap - swaps to array values
 *
 * @array: array to print after swap
 * @x: child
 * @y: parent
 * @size: size of array
 */
void swap(int *array, int *x, int *y, size_t size)
{
	int temp = *x;
	*x = *y;
	*y = temp;
	print_array(array, size);
}

/**
 * heapify - the sift down
 * @array: the array to sort
 * @size: array size
 * @printsize: array size
 * @idx: index of the root
 */
void heapify(int *array, size_t size, size_t printsize, int idx)
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
		print_array(array, printsize);
		heapify(array, n, printsize, root);
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
		swap(array, &array[0], &array[i], size);
		heapify(array, i, size, 0);
	}
}
