#pragma once

class BattlefieldCell
{
public:
    BattlefieldCell(int & xPosition, int & yPosition, bool occupied);
    BattlefieldCell() = default;
    ~BattlefieldCell();
    
    int xIndex;
    int yIndex;

    void SetCellOccupation(bool isCellOccupied, bool isPlayer);
    bool IsCellOccupied();
    bool IsOccupiedByPlayer();

private:
    bool isOccupied{false};
    bool havePlayer{false};
};
