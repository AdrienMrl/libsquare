#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include "square.h"

char binary_print(cell_t cell)
{
    return (cell.ccell ? '#' : '_');
}

bool zero_empty(cell_t cell)
{
    return (cell.ccell);
}

bool always_true(cell_t cell)
{
    return (true);
}

grid_t new_grid_type(int sizeX, int sizeY, enum type_e type)
{
    grid_t buffer;

    buffer.sizeX = sizeX;
    buffer.sizeY = sizeY;
    buffer.type = type;
    /* FIXME: find of way of consuming less memory */
    buffer.bytesize = sizeX * sizeY * sizeof(cell_t);
    assert(buffer.data = malloc(buffer.bytesize));

    bzero(buffer.data, buffer.bytesize);
    return buffer;
}

grid_t new_grid(int sizeX, int sizeY)
{
    return new_grid_type(sizeX, sizeY, DEFAULT_TYPE);
}

void print_grid(grid_t grid, char (*skin)(cell_t cell))
{
    int i, j;

    for (i = 0; i < grid.sizeY; i++)
    {
	for (j = 0; j < grid.sizeX; j++)
	{
	    printf("%c", skin(GET_CELL(j, i)));
	}
	printf("\n");
    }
}

grid_t delete_grid(grid_t grid)
{
    grid_t buf;

    bzero(&buf, sizeof(buf));
    free(grid.data);
    return buf;
}

int grid_cpy(grid_t *dest, grid_t src)
{
    /* FIXME: use my_memcpy */
    if (dest->bytesize < src.bytesize)
	return -1;
    memcpy(dest->data, src.data, src.bytesize);
    return 0;
}

grid_t extend(grid_t old, int sizeX, int sizeY)
{
    grid_t buf;

    buf = new_grid_type(sizeX, sizeY, old.type);
    grid_cpy(&buf, old);
    delete_grid(old);
    return (buf);
}

bool read_cell(grid_t grid, int x, int y, bool (*cell_status)(cell_t cell))
{
    if (!IN_BOUND(grid, x, y))
	return (false);
    return (cell_status(GET_CELL(x, y)));
}

int      write_cell(grid_t grid, cell_t cell, int x, int y)
{
    if (read_cell(grid, x, y, always_true) == false)
	return (-1);
    GET_CELL(x, y) = cell;
    return (0);
}
