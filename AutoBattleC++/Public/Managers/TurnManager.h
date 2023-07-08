#pragma once

#include <cstdlib>
#include <iostream>
#include "../Enums/Turns.h"

class TurnManager
{
public:
    TurnManager(/* args */);
    ~TurnManager();

    void ExecuteTurn();
    Turn GetCurrentTurn();

private:
    Turn currentTurn{};

    Turn GetRandomTurn();
    void ChangeTurn();
};

