#!/usr/bin/python3
"""
island_perimeter :returns the perimeter of the island described in grid
"""


def island_perimeter(grid):
    '''The grid is completely surrounded by water
    There is only one island (or nothing).
    The island doesn’t have “lakes”
    (water inside that isn’t connected to the water surrounding the island).
    '''
    if not grid or not grid[0]:
        return 0

    perimeter = 0
    rows, cols = len(grid), len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # count top edge
                if i == 0 or grid[i-1][j] == 0:
                    perimeter += 1

                # count bottom edge
                if i == rows - 1 or grid[i+1][j] == 0:
                    perimeter += 1

                # count left edge
                if j == 0 or grid[i][j-1] == 0:
                    perimeter += 1

                # count right edge
                if j == cols - 1 or grid[i][j+1] == 0:
                    perimeter += 1

    return perimeter
