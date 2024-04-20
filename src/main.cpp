#include "raylib.h"
#include "grid.hpp"
#include "simulation.hpp"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    simulation simulation(screenWidth, screenHeight, 10);
    simulation.set_cell_value(1,0,1);

    InitWindow(screenWidth, screenHeight, "Basic window");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

            ClearBackground(BLACK);
            simulation.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}