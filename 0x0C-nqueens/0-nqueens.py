#!/usr/bin/python3
"""
print combinations of n-queen
"""
from sys import argv, exit

solution = []


def solve_queens(row, n, solution):
    if (row == n):
        print(solution)
    else:
        for col in range(n):
            placement = [row, col]
            if valid_placement(solution, placement):
                solution.append(placement)
                solve_queens(row + 1, n, solution)
                solution.remove(placement)


def valid_placement(solution, placement):
    for queen in solution:
        if queen[1] == placement[1]:
            return False
        if (queen[0] + queen[1]) == (placement[0] + placement[1]):
            return False
        if (queen[0] - queen[1]) == (placement[0] - placement[1]):
            return False
    return True


if __name__ == "__main__":
    """main"""
    if len(argv) != 2:
        print('Usage: nqueens N')
        exit(1)
    try:
        n = int(argv[1])
    except Exception:
        print('N must be a number')
        exit(1)
    if n < 4:
        print('N must be at least 4')
        exit(1)

    solve_queens(0, n, solution)
