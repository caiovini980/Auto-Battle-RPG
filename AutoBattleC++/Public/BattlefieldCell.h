#pragma once

class BattlefieldCell
{
public:
    BattlefieldCell(int & xPosition, int & yPosition, bool occupied);
    ~BattlefieldCell();

private:
    int xIndex;
    int yIndex;
    bool isOccupied;
};
