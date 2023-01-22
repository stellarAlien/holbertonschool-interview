#!/usr/bin/python3

'''Given an n x n 2D matrix
rotate it 90 degrees clockwise'''


def rotate_2d_matrix(matrix):
    """ Function for rotating 2D Matrix 90 degrees clockwise
    You can assume the matrix will have 2 dimensions and will not be empty.
    """
#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """rotate two dimension matrix 90 degrees clockwise
    Args:
        matrix (list[[list]]): a matrix
    """
    n = len(matrix)
    for i in range(int(n / 2)):
        y = (n - i - 1)
        for j in range(i, y):
            x = (n - 1 - j)
            # current number
            tmp = matrix[i][j]
            # change top for left
            matrix[i][j] = matrix[x][i]
            # change left for bottom
            matrix[x][i] = matrix[y][x]
            # change bottom for right
            matrix[y][x] = matrix[j][y]
            # change right for top
            matrix[j][y] = tmp
