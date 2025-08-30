#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time

"""
Appunti - Grid 5x5

..... (0,2)(0,3)(0,4)
...*. (1,2)[1,3](1,4)        
..... (2,2)(2,3)(2,4)
.....
.....

"""

GRID_COLS = 15
GRID_ROWS = 15
ALIVE = 1
DEATH = 0
GRID_SIZE = GRID_COLS * GRID_ROWS

# get_cell
def get_cell(y, x):
    if y < GRID_COLS and y >= 0 and x < GRID_ROWS and x >= 0:
        return y * GRID_COLS + x

    if y >= GRID_COLS or y < 0:
        y = y % GRID_COLS
    if x >= GRID_ROWS or x < 0:
        x = x % GRID_ROWS
    return (y * GRID_COLS + x)

def grid_inizialize(grid, grid_size, state):
    for i in range(grid_size):
        grid.append(state)

def show_grid(grid, col, row):
    print("\x1b[H\x1b[2J")
    for j in range(col):
        for i in range(row):
            print(grid[get_cell(j, i)], end="")
        print()

def count_alive(grid, y, x):
    alive = 0
    alive = (
        grid[get_cell(y - 1, x - 1)] + grid[get_cell(y - 1, x)] + grid[get_cell(y - 1, x + 1)] + 
        grid[get_cell(y, x - 1)] + grid[get_cell(y, x + 1)] + 
        grid[get_cell(y + 1, x - 1)] + grid[get_cell(y + 1, x)] + grid[get_cell(y + 1, x + 1)]
    )
    return alive

def main():
    grid = []
    new_grid = []

    grid_inizialize(grid, GRID_SIZE, DEATH)
    grid_inizialize(new_grid, GRID_SIZE, DEATH)

    grid[get_cell(5, 4)] = ALIVE
    grid[get_cell(5, 5)] = ALIVE
    grid[get_cell(5, 6)] = ALIVE

    #grid[get_cell(0, 1)] = ALIVE
    #grid[get_cell(1, 2)] = ALIVE
    #grid[get_cell(2, 0)] = ALIVE
    #grid[get_cell(2, 1)] = ALIVE
    #grid[get_cell(2, 2)] = ALIVE

    while(True):
        show_grid(grid, GRID_COLS, GRID_ROWS)
        # 
        grid = new_grid[:]
        time.sleep(1)

if __name__ == "__main__":
    main()
