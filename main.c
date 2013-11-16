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
    grid_t grid = new_grid(atoi(av[1]), atoi(av[2]));

    print_grid(grid, binary_print);
    grid = extend(grid, 2, 2);
    write_cell(grid, (cell_t)42, 0, 0);
    print_grid(grid, my_print);
    {
	int x = 3, y = -10;

	printf("Cell %d %d is [%s]\n", x, y, read_cell(grid, x, y, zero_empty) ? "true" : "false");
	x = 0, y = 0;
	printf("Cell %d %d is [%s]\n", x, y, read_cell(grid, x, y, zero_empty) ? "true" : "false");
    delete_grid(grid);
    }
    return (EXIT_SUCCESS);
}
