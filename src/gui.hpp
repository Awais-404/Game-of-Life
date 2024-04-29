#pragma once
#include "raylib.h"

void draw_play_button(float x, float y, float width, float height, bool var){
    DrawRectangle(x-width/2, y-height/2, width, height, BLACK);
    DrawRectangleLinesEx({x-width/2, y-height/2, width, height}, 3, WHITE);
    if (var)
    {
        DrawText("PAUSE", x-MeasureText("PAUSE",25)/2, y-MeasureText("PAUSE",25)/7, 25, WHITE);
    }else{
        DrawText("PLAY", x-MeasureText("PLAY",30)/2, y-MeasureText("PLAY",30)/6, 30, WHITE);
    }
}

void draw_clear_button(float x, float y, float width, float height){
    DrawRectangle(x-width/2, y-height/2, width, height, BLACK);
    DrawRectangleLinesEx({x-width/2, y-height/2, width, height}, 3, WHITE);
    DrawText("CLEAR", x-MeasureText("CLEAR",25)/2, y-MeasureText("CLEAR",25)/7, 25, WHITE);
}

void draw_FPS(float x, float y, float width, float height, const char* fps){
    DrawRectangle(x-width/2, y-height/2, width, height, BLACK);
    DrawRectangleLinesEx({x-width/2, y-height/2, width, height}, 3, WHITE);
    DrawText(fps, x-MeasureText(fps,25)/2, y-MeasureText(fps,25)/7, 25, WHITE);
}