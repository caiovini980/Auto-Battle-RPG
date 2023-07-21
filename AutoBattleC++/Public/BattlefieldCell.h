#pragma once
#include <memory>

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

    std::shared_ptr<BattlefieldCell> upCell{nullptr};
    std::shared_ptr<BattlefieldCell> downCell{nullptr};
    std::shared_ptr<BattlefieldCell> rightCell{nullptr};
    std::shared_ptr<BattlefieldCell> leftCell{nullptr};
};
