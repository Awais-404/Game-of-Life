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

void grid::set_value(int row, int column, int value)
{
    cells[row][column] = value;
}

int grid::get_value(int row, int column)
{
    return cells[row][column];
}

void grid::toggle_cell(int row, int column)
{
    cells[row][column] = !cells[row][column];
}

int grid::get_neighbors(int row, int column)
{
    int live_neighbors = 0;
    for (int i = 0; i < 7; i++)
    {
        int newrow = (row + neighours[i].first + rows) % rows;
        int newcolumn = (column + neighours[i].second + columns) % columns;
        // if (cells[newrow][newcolumn]==1)
        // {
        //     live_neighbors++;
        // }
        
        live_neighbors += cells[newrow][newcolumn];
    }
    return live_neighbors;
}

int grid::get_rows()
{
    return rows;
}

int grid::get_columns()
{
    return columns;
}

void grid::clear_grid()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            cells[row][column] = 0;
        }
        
    }
    
}