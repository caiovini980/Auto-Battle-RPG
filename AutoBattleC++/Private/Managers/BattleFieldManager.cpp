#include "../../Public/Managers/BattlefieldManager.h"

BattleFieldManager::BattleFieldManager(/* args */)
{
    std::cout << "Creating Battlefield\n";
}

BattleFieldManager::BattleFieldManager(int & x, int & y) : amountOfColumns(x), amountOfLines(y)
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

            printf("[ ]\t");
        }

        printf("\n\n\n");
    }
}

std::shared_ptr<BattlefieldCell> BattleFieldManager::GetRandomCell()
{
    int randomPositionX = 1 + (std::rand() % amountOfColumns - 1);
    int randomPositionY = 1 + (std::rand() % amountOfLines - 1);

    //printf("Searching for cell [%i, %i]\n\n", randomPositionX, randomPositionY);

    for (int i = 0; i < battlefield.size() + 1; i++)
    {
        std::shared_ptr<BattlefieldCell> cell = battlefield[i];
        //printf("Scanning cell [%i, %i]\n", cell->xIndex, cell->yIndex);

        if (cell->xIndex == randomPositionX && cell->yIndex == randomPositionY)
        {
            return cell;
        }
    }

    //printf("\nCan't find cell [%i, %i]\n", randomPositionX, randomPositionY);
    return nullptr;
}
