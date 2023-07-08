#pragma once
#include <Vector>
#include "Types.h"

class Grid
{

public:

    Grid(int Lines, int Columns);
    ~Grid();

    std::vector<Types::GridBox> grids;

    int xLenght;
    int yLength;
    
    // prints the matrix that indicates the tiles of the battlefield
    void drawBattlefield(int Lines, int Columns);
};

