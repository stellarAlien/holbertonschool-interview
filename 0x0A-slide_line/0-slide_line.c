#include "slide_line.h"

/**
 * merge_left - erge lie to tghe left
 * even if numbers are sseperated by zeros and merge only 2 elements
 * @line: array of ints
 * @size: size of line
 * @i: index of number to merge
 */
void merge_left(int *line, size_t size, int i)
{
	size_t c;

	c = i + 1;
	if (c == size)
		return;
	while (c < size && line[c] == 0)
		c++;
	if (c == size || line[c] != line[i])
		return;
	line[i] *= 2;
	line[c] = 0;
}

/**
 * slide_left - groups elemnts together on the left
 * @line: array of ints
 * @size: size of line
 * @i: index of the number to slide
 */
void slide_left(int *line, size_t size, int i)
{
	size_t c;

	c = i + 1;
	while (c < size && !line[c])
		c++;
	if (c < size && line[c] != 0)
	{
		line[i] = line[c];
		line[c] = 0;
	}
}

/**
 * merge_right - merge line to the right
 * even if numbers are sseperated by zeros and merge only 2 elements
 * @line: address of the array
 * @i: index of the first number to merge
 */
void merge_right(int *line, int i)
{
	int c;

	c = i - 1;
	if (c < 0)
		return;
	while (c >= 0 && line[c] == 0)
		c--;
	if (c >= 0 && line[c] == line[i])
	{
		line[i] *= 2;
		line[c] = 0;
	}
}

/**
 * slide_right - group elements to the right
 * @line: the address of the array
 * @i: index of the number to slide
 */
void slide_right(int *line, int i)
{
	int c;

	c = i - 1;
	while (c >= 0 && !line[c])
		c--;
	if (c >= 0 && line[c] != 0)
	{
		line[i] = line[c];
		line[c] = 0;
	}
}

/**
 * slide_line - a function that slides and merges an array of integers
 * @line: address of the array
 * @size: size of the array
 * @direction: left or right
 * Return: 1 if line can slide else 0
 */
int slide_line(int *line, size_t size, int direction)
{
	int i;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (!line)
		return (0);
	if (size < 2)
		return (1);
	if (!direction)
	{
		for (i = 0; i < (int)size; i++)
			if (line[i])
				merge_left(line, size, i);
		for (i = 0; i < (int)size; i++)
			if (line[i] == 0)
				slide_left(line, size, i);
	}
	else if (direction)
	{
		for (i = (int)(size - 1); i >= 0; i--)
			if (line[i])
				merge_right(line, i);
		for (i = (int)(size - 1); i >= 0; i--)
			if (line[i] == 0)
				slide_right(line, i);
	}
	return (1);
}
