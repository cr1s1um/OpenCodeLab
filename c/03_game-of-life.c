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
    grid_initialize(grid);

    grid[5][4]=ALIVE;
    grid[5][5]=ALIVE;
    grid[5][6]=ALIVE;

    print_grid(grid);
    return 0;
}
