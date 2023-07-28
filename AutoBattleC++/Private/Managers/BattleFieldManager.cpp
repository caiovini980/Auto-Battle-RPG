#include "../../Public/Managers/BattlefieldManager.h"

BattleFieldManager::BattleFieldManager(/* args */)
{
    std::cout << "Creating Battlefield\n";
}

BattleFieldManager::BattleFieldManager(const int & x, const int & y) : amountOfColumns(x), amountOfLines(y)
{
    std::cout << "Creating Battlefield with measurements\n";
}

BattleFieldManager::~BattleFieldManager()
{
    std::cout << "Destroying Battlefield\n";
}

void BattleFieldManager::CreateBattlefield()
{
    // create cells
    for (int columnIndex = 0; columnIndex < amountOfColumns; columnIndex++) // X
    {
        for (int lineIndex = 0; lineIndex < amountOfLines; lineIndex++) // Y
        {
            std::shared_ptr<BattlefieldCell> newCell = std::make_shared<BattlefieldCell>(columnIndex, lineIndex, false);
            battlefield.insert(battlefield.begin(), newCell);
            AddOnVector(*newCell, freeCells);

            printf("[ ]\t");
        }

        printf("\n\n\n");
    }

    printf("OCCUPIED CELLS: \n");
    PrintVector(occupiedCells);
    printf("FREE CELLS: \n");
    PrintVector(freeCells);
}

void BattleFieldManager::SetCellOccupation(BattlefieldCell& cell, bool isOccupied, bool isPlayer)
{
    //printf("Setting cell at position [%i, %i] as occupied? %d\n\n", cell.xIndex, cell.yIndex, isOccupied);
    cell.SetCellOccupation(isOccupied, isPlayer);

    if (isOccupied)
    {
        RemoveFromVector(cell, freeCells);
        AddOnVector(cell, occupiedCells);
    }
    else
    {
        RemoveFromVector(cell, occupiedCells);
        AddOnVector(cell, freeCells);
    }
    
    printf("OCCUPIED CELLS: \n");
    PrintVector(occupiedCells);
    printf("FREE CELLS: \n");
    PrintVector(freeCells);
}

void BattleFieldManager::UpdateBattlefield(const char* PlayerIndicator, const char* OpponentIndicator)
{
    for (int lineIndex = 0; lineIndex < amountOfLines; lineIndex++) // Y
    {
        for (int columnIndex = 0; columnIndex < amountOfColumns; columnIndex++) // X
        {
            // get cell
            // if it's occupied, print [X]
            // if it's free, print [ ]
            for (int i = 0; i < battlefield.size(); i++)
            {
                if (battlefield[i]->xIndex == columnIndex &&
                    battlefield[i]->yIndex == lineIndex)
                {
                    if (battlefield[i]->IsCellOccupied())
                    {
                        if (battlefield[i]->IsOccupiedByPlayer())
                        {
                            printf("[%c]\t", *PlayerIndicator);
                        }
                        else
                        {
                            printf("[%c]\t", *OpponentIndicator);
                        }
                    }
                    else
                    {
                        printf("[ ]\t");
                    }
                }
            }
        }

        printf("\n\n\n");
    }
}

std::shared_ptr<BattlefieldCell> BattleFieldManager::GetRandomCell()
{
    int randomFreeCellIndex = std::rand() % freeCells.size();

    for (int i = 0; i < battlefield.size() + 1; i++)
    {
        std::shared_ptr<BattlefieldCell> cell = battlefield[i];

        if (cell->xIndex == freeCells[randomFreeCellIndex].xIndex && 
            cell->yIndex == freeCells[randomFreeCellIndex].yIndex)
        {
            return cell;
        }
    }

    return nullptr;
}

void BattleFieldManager::AddOnVector(const BattlefieldCell& cell, std::vector<BattlefieldCell> &vector)
{
    // check if already have this cell
    vector.insert(vector.begin(), cell);
}

void BattleFieldManager::RemoveFromVector(const BattlefieldCell &cell, std::vector<BattlefieldCell> &vector)
{
    for (int i  = 0; i < vector.size(); i++)
    {
        if (cell.xIndex == vector[i].xIndex && cell.yIndex == vector[i].yIndex)
        {
            vector.erase(vector.begin() + i);
            return;
        }
    }
}

void BattleFieldManager::PrintVector(const std::vector<BattlefieldCell> &vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        printf("VECTOR: [%i, %i]\n", vector[i].xIndex, vector[i].yIndex);
    }
}

bool BattleFieldManager::AreCharactersClose(Character& characterA, Character& characterB)
{
    int rangeA = characterA.GetClass()->GetBaseRange();
    int rangeB = characterB.GetClass()->GetBaseRange();

    BattlefieldCell* cellA = characterA.GetPosition();
    BattlefieldCell* cellB = characterB.GetPosition();

    // check range for attack on 4 directions
    if (cellA->xIndex + rangeA >= cellB->xIndex && cellA->yIndex == cellB->yIndex ||    // come from the right
        cellA->yIndex + rangeA >= cellB->yIndex && cellA->xIndex == cellB->xIndex ||    // come from the top
        cellA->xIndex - rangeA <= cellB->xIndex && cellA->yIndex == cellB->yIndex ||    // come from the left
        cellA->yIndex - rangeA <= cellB->yIndex && cellA->xIndex == cellB->xIndex)      // come from the bottom
    {
        printf("Characters are close enought to attack\n");
        return true;
    }

    return false;
}
