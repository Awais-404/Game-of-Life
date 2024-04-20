#include "grid.hpp"
#include "raylib.h"

void grid::draw()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column<columns; column++)
        {
            Color color = cells[row][column]? WHITE : DARKGRAY;
            DrawRectangle(column*cell_size, row*cell_size, cell_size-1, cell_size-1, color);
        }
    }
    
}

void grid::setvalue(int row, int column, int value)
{
    cells[row][column] = value;
}
