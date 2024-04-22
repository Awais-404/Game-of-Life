#include "raylib.h"
#include "simulation.hpp"
#include "grid.hpp"
#include <iostream>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    const int cell_size = 10;
    simulation simulation(screenWidth, screenHeight, cell_size);
    simulation.set_cell_value(2,1,1);
    simulation.set_cell_value(2,2,1);
    simulation.set_cell_value(2,3,1);

    InitWindow(screenWidth, screenHeight, "Game of Life");

    SetTargetFPS(5);

    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(0))
        {
            int row, column;
            Vector2 mouse_pos = GetMousePosition();
            row = mouse_pos.y/cell_size;
            column = mouse_pos.x/cell_size;
            simulation.toggle_cell(row, column);
        }
        std::cout<<simulation.getneighbors(3,3); //first row give one less live neighbor
        // simulation.update_grid();

        BeginDrawing();

            ClearBackground(BLACK);
            simulation.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}