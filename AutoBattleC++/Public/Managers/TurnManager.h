#pragma once

#include <cstdlib>
#include <iostream>
#include "../Enums/Turns.h"

class TurnManager
{
public:
    TurnManager(/* args */);
    ~TurnManager();
 
    void ChangeTurn();
    Turn GetCurrentTurn();

private:
    Turn currentTurn{};

    Turn GetRandomTurn();
};

