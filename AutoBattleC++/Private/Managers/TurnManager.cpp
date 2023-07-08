#include "../../Public/Managers/TurnManager.h"

TurnManager::TurnManager(/* args */)
{
    currentTurn = GetRandomTurn();
}

TurnManager::~TurnManager()
{
}

void TurnManager::ExecuteTurn()
{
    ChangeTurn();
}

void TurnManager::ChangeTurn()
{
    if (currentTurn == PlayerTurn)
    {
        currentTurn = OpponentTurn;
    } else {
        currentTurn = PlayerTurn;
    }
}

Turn TurnManager::GetRandomTurn()
{
    int random = 1 + (std::rand() % 2);

    switch (random)
    {
    case 1:
        return PlayerTurn;
    case 2:
        return OpponentTurn;
    default:
        break;
    }
}


Turn TurnManager::GetCurrentTurn()
{
    return currentTurn;
}