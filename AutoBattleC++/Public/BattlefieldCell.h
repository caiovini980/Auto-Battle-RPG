#pragma once

class BattlefieldCell
{
public:
    BattlefieldCell(int & xPosition, int & yPosition, bool occupied);
    BattlefieldCell() = default;
    ~BattlefieldCell();
    
    int xIndex;
    int yIndex;

private:
    bool isOccupied;
};
