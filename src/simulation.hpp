#pragma once
#include "grid.hpp"

class simulation
{
private:
    grid grid, temp_grid;
    // int rows;
    // int columns;
    // int cell_size;
public:
    simulation(int width, int height, int cell_size)
    : grid(width, height, cell_size), temp_grid(width, height, cell_size) {};
    void draw();
    void set_cell_value(int row, int column, int value);
    void toggle_cell(int row, int column);
    void update_grid();
    int getneighbors(int row, int column){return grid.get_neighbors(row, column);}
};