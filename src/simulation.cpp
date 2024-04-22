#include "simulation.hpp"
#include "raylib.h"

void simulation::draw()
{
    grid.draw();
}

void simulation::set_cell_value(int row, int column, int value)
{
    grid.set_value(row, column, value);
}

void simulation::toggle_cell(int row, int column)
{
    grid.toggle_cell(row, column);
}

void simulation::update_grid()
{
    for (int row = 0; row < grid.get_rows(); row++)
    {
        for (int column = 0; column < grid.get_columns(); column++)
        {
            int live_neighbors = grid.get_neighbors(row, column);
            if (grid.get_value(row, column)==1)
            {
                if ((live_neighbors<2) || (live_neighbors>3))
                {
                    temp_grid.set_value(row, column, 0);
                }else{
                    temp_grid.set_value(row, column, 1);
                }
                
            }
            else if((grid.get_value(row, column)==0) && (live_neighbors == 3))
            {
                temp_grid.set_value(row, column, 1);
            }
            
        }
        
    }
    grid = temp_grid;
    temp_grid.clear_grid();
}
