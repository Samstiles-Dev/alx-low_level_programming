#!/usr/bin/python3
"""A Module that calcs the perimeter of an island in a grid."""


def num_water_neighbors(grid, i, j):
    """This returns the num of water neighbors a cell has in a grid."""

    _num = 0

    if i <= 0 or not grid[i - 1][j]:
        _num += 1
    if j <= 0 or not grid[i][j - 1]:
        _num += 1
    if j >= len(grid[i]) - 1 or not grid[i][j + 1]:
        _num += 1
    if i >= len(grid) - 1 or not grid[i + 1][j]:
        _num += 1

    return _num


def island_perimeter(grid):
    """Returns the perimeter of the island in grid."""

    _perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j]:
                _perimeter += num_water_neighbors(grid, i, j)

    return _perimeter
