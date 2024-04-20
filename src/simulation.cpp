#include "simulation.hpp"

void simulation::draw()
{
    grid.draw();
}

void simulation::set_cell_value(int row, int column, int value)
{
    grid.setvalue(row, column, value);
}