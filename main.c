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
    write_cell(grid, (cell_t)42, 0, 0);
    print_grid(grid, my_print);
    {
	int x = 3, y = -10;

	printf("Cell %d %d is [%s]\n", x, y, read_cell(grid, x, y, zero_empty) ? "true" : "false");
	x = 0, y = 0;
	printf("Cell %d %d is [%s]\n", x, y, read_cell(grid, x, y, zero_empty) ? "true" : "false");
	printf("Cell %d %d is [%s]\n", x + 1, y, read_cell_direc(grid, x, y, zero_empty, RIGHT) ? "true" : "false");
	printf("Cell %d %d is [%s]\n", x, y - 1, read_cell_direc(grid, x, y, zero_empty, UP) ? "true" : "false");
    delete_grid(grid);
    }
    return (EXIT_SUCCESS);
}
