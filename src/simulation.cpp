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
            int cell_value = grid.get_value(row, column);

            if (cell_value == 1)
            {
                if ( live_neighbors==3 || live_neighbors==2)
                {
                    temp_grid.set_value(row, column, 1);
                }
                else{
                    temp_grid.set_value(row, column, 0);
                }
                
            }
            else
            {
                if (live_neighbors == 3)
                {
                    temp_grid.set_value(row, column, 1);
                }
                else
                {
                    temp_grid.set_value(row, column, 0);
                }
                
            }
            
        }
        
    }
    grid = temp_grid;
}
