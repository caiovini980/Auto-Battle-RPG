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
    for (std::shared_ptr<BattlefieldCell> battlefieldCell : battlefield)
    {
        if (battlefieldCell->xIndex == cell.xIndex && battlefieldCell->yIndex == cell.yIndex)
        {
            battlefieldCell->SetCellOccupation(isOccupied, isPlayer);
        }
    }

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
}

void BattleFieldManager::UpdateBattlefield(const char* PlayerIndicator, const char* OpponentIndicator)
{
    for (int lineIndex = 0; lineIndex < amountOfLines; lineIndex++) // Y
    {
        for (int columnIndex = 0; columnIndex < amountOfColumns; columnIndex++) // X
        {
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
                            break;
                        }
                        else
                        {
                            printf("[%c]\t", *OpponentIndicator);
                            break;
                        }
                    }
                    else
                    {
                        printf("[ ]\t");
                        break;
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

std::shared_ptr<BattlefieldCell> BattleFieldManager::GetCellAtPosition(int xPosition, int yPosition)
{
    for (std::shared_ptr<BattlefieldCell> cell : battlefield)
    {
        if (cell->xIndex == xPosition && cell->yIndex == yPosition)
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

    std::shared_ptr<BattlefieldCell> cellA = characterA.GetPosition();
    std::shared_ptr<BattlefieldCell> cellB = characterB.GetPosition();

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

std::shared_ptr<Directions> BattleFieldManager::GetDirectionToMoveCharacterToTarget(Character& character, BattlefieldCell& target)
{
    // (x, y)
    // (1, 0) -> Move right
    // (-1, 0) -> Move left
    // (0, 1) -> Move up
    // (0, -1) -> Move down

    std::shared_ptr<Directions> directions = std::make_shared<Directions>();
    std::shared_ptr<BattlefieldCell> originalPosition = character.GetPosition();

    // MOVE VERTICALLY
    if (originalPosition->yIndex != target.yIndex)
    {
        if (originalPosition->yIndex > target.yIndex)
        {
            directions->y = -1;
        }

        else if (originalPosition->yIndex < target.yIndex)
        {
            directions->y = 1;
        }

        else
        {
            directions->y = 0;
        }
    }

    // MOVE HORIZONTALLY
    if (originalPosition->xIndex != target.xIndex)
    {
        if (originalPosition->xIndex > target.xIndex)
        {
            directions->x = -1;
        }

        else if (originalPosition->xIndex < target.xIndex)
        {
            directions->x = 1;
        }

        else
        {
            directions->x = 0;
        }
    }

    return directions;
}
