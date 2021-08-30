#include "cell.hpp"
#include <bits/stdc++.h>

class Cells {
    public:
        int cellAmountCol;
        int cellAmountLine;
        int cellSize;
        std::vector<std::vector<Cell>> cells;

        Cells(int screenWidth, int screenHeight, int cellSize);

        void printCells();
        void update();
};