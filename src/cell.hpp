#include <vector>

class Cell {
    public:
        bool active = false;
        bool newActive = false;

        void advance(std::vector<bool> neighbours);
        void updateCell();
};