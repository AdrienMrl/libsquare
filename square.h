#ifndef SQUARE_H_
# define SQUARE_H_

#include <stdbool.h>

/* LIB PARAMETERS */
#define DEFAULT_TYPE INT

enum type_e {
    CHAR = sizeof(char),
    INT = sizeof(int),
    LONG = sizeof(long)
};

typedef enum direction_e {
    LEFT,
    RIGHT,
    UP,
    DOWN
} dir_t;

typedef union {
    char ccell;
    int icell;
    long lcell;
} cell_t;

typedef struct grid_s {
    cell_t *data;
    int sizeX;
    int sizeY;
    int bytesize;
    enum type_e type;
} grid_t;

/* function used to change other functions runtime (use their addresses) */
char binary_print(cell_t cell);
bool zero_empty(cell_t cell);
bool always_true(cell_t cell);

/* user API {{{ */

#define CELL(x, y, lenX) ((y) * (lenX) + (x))
#define GET_CELL(x, y) grid.data[CELL(x, y, grid.sizeX)]
#define IN_BOUND(grid, x, y) (x >= 0 && y >= 0 && x < grid.sizeX && y < grid.sizeY)

/* new grid filled with zeros */
grid_t    new_grid(int sizeX, int sizeY);

/* same but with specified type */
grid_t    new_grid_type(int sizeX, int sizeY, enum type_e type);

/* print a grid */
void      print_grid(grid_t grid, char (*skin)(cell_t cell));

/* delete a grid, return an empty grid */
grid_t    delete_grid(grid_t grid);

/* modify grid size */
grid_t    extend(grid_t old, int sizeX, int sizeY);

/* copy a grid into another */
int       grid_cpy(grid_t *dest, grid_t src);

/* read a case : is it free ? */
bool      read_cell(grid_t grid, int x, int y, bool (*cell_status)(cell_t cell));

/* attempt to write 'cell' in grid, but returns false if not possible */
int      write_cell(grid_t grid, cell_t cell, int x, int y);

/* attempt to read cell that is on the 'direction' side of the specified cell
 * */
bool     read_cell_direc(grid_t grid, int x, int y, bool (*cell_status)(cell_t cell), dir_t direction);

/* }}} */

#endif
