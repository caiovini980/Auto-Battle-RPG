#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>

#include "BattlefieldManager.h"
#include "TurnManager.h"
#include "../BattlefieldCell.h"

class GameManager
{
public:
    GameManager();
    ~GameManager();

    void CreateNewGame();

private:
    bool gameOver{false};   

    bool AreFieldInputsValid(int & X, int & Y);

    void ExecuteGame();
    void CheckClassInput(int & input);
};

