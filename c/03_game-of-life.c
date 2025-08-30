#include <stdio.h>

#define GRID_COLS 15
#define GRID_ROWS 15
#define ALIVE 1
#define DEAD 0

void grid_initialize(int grid[][GRID_COLS]){
    for(int j=0; j < GRID_ROWS; j++)
        for(int i=0; i < GRID_COLS; i++)
            grid[j][i] = 0;
}

void print_grid(int grid[][GRID_COLS]){
    for(int j=0; j < GRID_ROWS; j++){
        for(int i=0; i < GRID_COLS; i++)
            printf("%d", grid[j][i]);
        printf("\n");
    }
}

int main(){
    int grid[GRID_ROWS][GRID_COLS];
    int new_grid[GRID_ROWS][GRID_COLS];
    grid_inizialize(grid);
    print_grid(grid);
    return 0;
}
