#include "../../Public/Managers/TurnManager.h"

TurnManager::TurnManager(/* args */)
{
    currentTurn = GetRandomTurn();
}

TurnManager::~TurnManager()
{
}

void TurnManager::ChangeTurn() 
{
    if (currentTurn == Turn::PlayerTurn)
    {
        currentTurn = Turn::OpponentTurn;
    } 
    else 
    {
        currentTurn = Turn::PlayerTurn;
    }
}

Turn TurnManager::GetRandomTurn()
{
    int random = 1 + (std::rand() % 2);

    switch (random)
    {
    case 1:
        return Turn::PlayerTurn;
    case 2:
        return Turn::OpponentTurn;
    default:
        break;
    }
}


Turn TurnManager::GetCurrentTurn()
{
    return currentTurn;
}