#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * grid_init - add 2 3*3 grids
 *  @grid1: first sandpile (to be used later in palce)
	 * @grid2: second sandpile
	 */

	void grid_init(int grid1[3][3], int grid2[3][3])
	{
		int i, j;

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] = grid1[i][j] + grid2[i][j];
			}
		}
	}

/**
* grid_print - print a 3*3 grid
* @grid: sandpile
*/
	void grid_print(int grid[3][3])
	{
		int i = 0;
		int j = 0;

		printf("=\n");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (j)
					printf(" ");
				printf("%d", grid[i][j]);
			}
			printf("\n");
		}
	}

/**
* unstable - checks if sandpile is unstable
* @grid: sandpile
* Return: 1 if stable else 0
*/
	size_t unstable(int grid[3][3])
	{
		int i, j;

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid[i][j] > 3)
					return (1);
			}
		}
		return (0);
	}

/**
* stabilize -  stabilize sandpile
* @grid1: matrix
*/

	void stabilize(int grid1[3][3])
	{
		int i = 0;
		int j = 0;

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid1[i][j] = grid1[i][j] - 4;
					if ((i - 1) >= 0 && (i - 1) < 3)
						grid1[i - 1][j] += 1;
					if ((j - 1) >= 0 && (j - 1) < 3)
						grid1[i][j - 1] += 1;
					if ((i + 1) >= 0 && (i + 1) < 3)
						grid1[i + 1][j] += 1;
					if ((j + 1) >= 0 && (j + 1) < 3)
						grid1[i][j + 1] += 1;
				}
			}
		}
	}

/**
* sandpiles_sum - sum 2 sandpiles
* @grid1: first matrix
* @grid2: second matrix
*/

	void sandpiles_sum(int grid1[3][3], int grid2[3][3])
	{
		grid_init(grid1, grid2);
		while (unstable(grid1))
		{
			grid_print(grid1);
			stabilize(grid1);
		}
	}
