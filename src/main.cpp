#include "raylib.h"
#include "allcells.hpp"
#include <iostream>
#include <vector>

int main() {
    const int winWidth = 1024;
    const int winHeight = 720;
    const int cellSize = 20;

    Cells cs(winWidth, winHeight, cellSize);
    
    int counter = 0;

    cs.printCells();

    InitWindow(winWidth, winHeight, "Maze Generation :)");
    SetTargetFPS(5);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);

            if (counter < 24) {
                cs.update();
                counter++;
            }

            for (int i=0;i < cs.cellAmountCol;i++) {
                for (int j=0;j < cs.cellAmountLine;j++) {
                    if (cs.cells[i][j].active)
                        DrawRectangle(i*cellSize, j*cellSize, cellSize, cellSize, WHITE);
                }
            }

            DrawText("Maze Generation", 10, 5, 20, LIGHTGRAY);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}