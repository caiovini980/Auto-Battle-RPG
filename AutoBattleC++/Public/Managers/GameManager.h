#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
#include <vector>

#include "BattlefieldManager.h"
#include "TurnManager.h"
#include "ClassManager.h"

#include "../BattlefieldCell.h"
#include "../PlayerCharacter.h"
#include "../OpponentCharacter.h"

#include "../Enums/Classes.h"

class GameManager
{
public:
    GameManager();
    ~GameManager();

    void CreateNewGame();

private:
    std::unique_ptr<TurnManager> turnManager;
    std::unique_ptr<ClassManager> classManager;
    std::shared_ptr<BattleFieldManager> battlefieldManager;

    std::shared_ptr<BaseClass> playerClass;
    std::shared_ptr<BaseClass> opponentClass;

    std::shared_ptr<PlayerCharacter> player;
    std::shared_ptr<OpponentCharacter> opponent;

    bool gameOver{false};   

    bool AreFieldInputsValid(int& X, int& Y);

    void InitializeManagers();
    void ExecuteGame();
    void GetChosenPlayerClass(int& input);
    void CreateBattlefield(const int& sizeX, const int& sizeY);
    void SetCharactersPosition();
    void SetupPlayer();
    void SetupOpponent();
    void ExecutePlayerTurn();
    void ExecuteOpponentTurn();
};

