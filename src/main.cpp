#include "raylib.h"
#include "simulation.hpp"
#include "gui.hpp"
#include <iostream>
#include <string>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 700;

    const int gridWidth = 800;
    const int gridHeight = 600;
    const int cell_size = 14;

    int width = 100;
    int height = 50;

    simulation simulation(gridWidth, gridHeight, cell_size);
    int FPS = 10;

    bool is_running = false;

    InitWindow(screenWidth, screenHeight, "Game of Life");

    while (!WindowShouldClose())
    {
        SetTargetFPS(FPS);
        std::string fps = "FPS="+std::to_string(FPS);
        const char* fps_char[]= {fps.c_str()};
        if (IsMouseButtonPressed(0))
        {
            Vector2 mouse_pos = GetMousePosition();
            if (mouse_pos.y<gridHeight)
            {
                int row, column;
                row = mouse_pos.y/cell_size;
                column = mouse_pos.x/cell_size;
                simulation.toggle_cell(row, column);
            }
            else if(CheckCollisionPointRec(mouse_pos, Rectangle{(float)400-width/2, (float)650-height/2, 100, 50}))
            {
                if (!is_running)
                {
                    is_running = true;
                }
                else if (is_running)
                {
                    is_running = false;
                }
            }
            else if(CheckCollisionPointRec(mouse_pos, Rectangle{(float)600-width/2, (float)650-height/2, 100, 50}))
            {
                simulation.clear_grid();
            }
            
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            if (!is_running)
            {
                is_running = true;
            }
            else if (is_running)
            {
                is_running = false;
            }
        }

        if (IsKeyPressed(KEY_UP) || IsKeyPressedRepeat(KEY_UP))
        {
            FPS++;
        }
        if (IsKeyPressed(KEY_DOWN) || IsKeyPressedRepeat(KEY_DOWN))
        {
            if (FPS > 3)
            {
                FPS--;
            }
        }
        
        if (is_running)
        {
            simulation.update_grid();
        }
        
        BeginDrawing();

            ClearBackground(BLACK);
            simulation.draw();
            draw_play_button(400, 650, width, height, is_running);
            draw_clear_button(600, 650, width, height);
            draw_FPS(200, 650, width, height, *fps_char);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}