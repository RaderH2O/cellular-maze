#include "allcells.hpp"
#include <iostream>
#include <vector>

Cells::Cells(int screenWidth, int screenHeight, int cellSize) {
            cellSize = cellSize;
            cellAmountCol = screenWidth / cellSize;
            cellAmountLine = screenHeight / cellSize;
            std::vector<Cell> tmp;
            Cell ctmp;
            srand(time(0));
            for (int i=0;i < cellAmountLine;i++) {
                tmp.push_back(ctmp);
            }
            for (int i=0;i < cellAmountCol;i++) {
                cells.push_back(tmp);
                for (int j=0;j < cellAmountLine;j++) {
                    cells[i][j].active = rand()%2;
                }
            }
}

void Cells::printCells() {
    for (int i=0;i < cellAmountCol;i++) {
        for (int j=0;j < cellAmountLine;j++) {
            std::cout << cells[i][j].active << " ";
        }
        std::cout << "\n";
    }
}

void Cells::update() {
    for (int i = 0;i < cellAmountCol;i++) {
        for (int j = 0;j < cellAmountLine;j++) {
            std::vector<bool> neighbours;
            if (i > 0) neighbours.push_back(cells[i - 1][j].active);
            if (j > 0) neighbours.push_back(cells[i][j - 1].active);
            if (i < cellAmountCol - 1) neighbours.push_back(cells[i + 1][j].active);
            if (j < cellAmountLine - 1) neighbours.push_back(cells[i][j + 1].active);
            if (i > 0 && j > 0) neighbours.push_back(cells[i - 1][j - 1].active);
            if (i > 0 && j < cellAmountLine - 1) neighbours.push_back(cells[i - 1][j + 1].active);
            if (i < cellAmountCol - 1 && j > 0) neighbours.push_back(cells[i + 1][j - 1].active);
            if (i < cellAmountCol - 1 && j < cellAmountLine - 1) neighbours.push_back(cells[i + 1][j + 1].active);
            cells[i][j].advance(neighbours);

            // std::cout << neighbours[0];
        }
    }
    for (int i = 0;i < cellAmountCol;i++) {
        for (int j = 0;j < cellAmountLine;j++) {
            cells[i][j].updateCell();
        }
    }
}