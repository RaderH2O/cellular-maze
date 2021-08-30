#include "cell.hpp"
#include <vector>
#include <iostream>

void Cell::advance(std::vector<bool> neighbours) {
    int activeNeighbours = 0;
    for (long long unsigned int i = 0;i < neighbours.size();i++) {
        if (neighbours[i]) {
            activeNeighbours++;
        }
        // std::cout << activeNeighbours;
    }

    if (active) {
        if (activeNeighbours >= 1 && activeNeighbours <= 4) {
            newActive = true;
        }
        else {
            newActive = false;
        }
    }
    else {
        if (activeNeighbours == 3) newActive = true;
    }
}

void Cell::updateCell() {
    active = newActive;
}
