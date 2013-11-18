#include <stdlib.h>
#include <stdio.h>
#include "square.h"

char my_print(cell_t cell)
{
    return (cell.ccell ? 'I' : 'O');
}

/*
** just a test/demo file
*/
int main(int ac, char **av)
{
    int sizeX, sizeY;
    grid_t grid;

    sizeX = atoi(av[1] ?: "10");
    sizeY = atoi(av[2] ?: "5");
    grid = new_grid(sizeX, sizeY);

    print_grid(grid, binary_print);
    grid = extend(grid, 2, 2);
    write_cell(grid, (cell_t)42, (pos_t){ 0, 0 });
    print_grid(grid, my_print);
    {
	pos_t pos = { .x = 3, .y = -10 };

	printf("Cell %d %d is [%s]\n", pos.x, pos.y, read_cell(grid, pos, zero_empty) ? "true" : "false");
    pos = (pos_t){0, 0};
	printf("Cell %d %d is [%s]\n", pos.x, pos.y, read_cell(grid, pos, zero_empty) ? "true" : "false");
	printf("Cell %d %d is [%s]\n", pos.x + 1, pos.y, read_cell_direc(grid, pos, zero_empty, RIGHT) ? "true" : "false");
	printf("Cell %d %d is [%s]\n", pos.x, pos.y - 1, read_cell_direc(grid, pos, zero_empty, UP) ? "true" : "false");
    {
        pos_t new_pos = read_cell_around(grid, pos, zero_empty);
        printf("Cell %d %d have an availible cell in [%d][%d]\n", pos.x, pos.y, new_pos.x, new_pos.y);
        pos.x++;
        new_pos = read_cell_around(grid, pos, zero_empty);
        printf("Cell %d %d have an availible cell in [%d][%d]\n", pos.x, pos.y, new_pos.x, new_pos.y);
    }
    delete_grid(grid);
    }
    return (EXIT_SUCCESS);
}
