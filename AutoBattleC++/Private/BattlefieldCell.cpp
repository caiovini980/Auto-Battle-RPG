#include "../Public/BattlefieldCell.h"

BattlefieldCell::BattlefieldCell(int & xPosition, int & yPosition, bool occupied) 
    : xIndex(xPosition), yIndex(yPosition), isOccupied(occupied)
{
}

BattlefieldCell::~BattlefieldCell()
{
}