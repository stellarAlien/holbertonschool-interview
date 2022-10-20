#include "menger.h"

/**
 * empty - Checks if indices are (1, 1), if so, then square is blank
 *
 * @i: Row
 * @j: Column
 * Return: 1 if current block is 1, 1 else 0
 */

int empty(int i, int j)
{
	while (i != 0 && j != 0)
	{
		if (i % 3 == 1 && j % 3 == 1)
			return (0);

		i /= 3, j /= 3;
	}
	return (1);
}

/**
 * menger - goes n levels and
 * prints menger sponge	 of size 3^N
 * @level: level of the Menger Sponge to draw
 *
 * Return: no return
 */
void menger(int level)
{
	int i, j, lvl;

	if (level < 0)
		return;

	for (i = 0, lvl = pow(3, level); i < lvl; i++)
	{
		for (j = 0; j < lvl; j++)
		{
			if (empty(i, j))
				printf("%c", '#');
			else
				printf("%c", ' ');
		}
		printf("\n");
	}
}
