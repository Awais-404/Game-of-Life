#pragma once
#include <vector>
#include <utility>

class grid
{
private:
    int rows;
    int columns;
    int cell_size;
    std::vector<std::vector<int>> cells;
    std::vector<std::pair<int,int>> neighours={
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1},           {0,1},
        {1,-1},   {1,0},  {1,1}
    };
public:
    grid(int width, int height, int cell_size)
    : rows(height/cell_size), columns(width/cell_size), cell_size(cell_size), cells(rows, std::vector<int>(columns,0)) {};
    void draw();
    void set_value(int row, int column, int value);
    int get_value(int row, int column);
    void toggle_cell(int row, int column);
    int get_neighbors(int row, int column);
    int get_rows();
    int get_columns();
};