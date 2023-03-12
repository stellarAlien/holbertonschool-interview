#include "sort.h"

/**
 * counting_sort - couting
 * @array: array to sort
 * @size: size of array
 * @exp:  10 * i
*/
void counting_sort(int *array, size_t size, int exp)
	{
	int *output = (int *)malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(output);
}
/**
 * radix_sort - implment radix sort using counting sort
 * @array: array to sort
 * @size: size of array
*/
void radix_sort(int *array, size_t size)
{
	int max = array[0];
	int exp;
	size_t i;

	/* Find the maximum element in the array */
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);

		/* Print the current state of the array */
		for (i = 0; i < size; i++)
		{
			if (i + 1 == size)
				printf("%d ", array[i]);
			else
				printf("%d, ", array[i]);
		}
		printf("\n");
	}
}
