#pragma once
#include "grid.hpp"

class simulation
{
private:
    grid grid;
    int rows;
    int columns;
    int cell_size;
public:
    simulation(int width, int height, int cell_size)
    : grid(width, height, cell_size) {};
    void draw();
    void set_cell_value(int row, int column, int value);
};