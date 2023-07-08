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
            //battlefield.assign(1, newCell);

            printf("[ ]\t");
        }

        printf("\n\n\n");
    }
}
