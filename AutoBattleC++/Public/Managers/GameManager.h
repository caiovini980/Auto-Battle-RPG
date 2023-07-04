#pragma once
#include <iostream>
#include <string>
#include <memory>

class GameManager
{
public:
    GameManager(/* args */);
    ~GameManager();

    void CreateNewGame();

private:
    void ExecuteGame();
    void CheckInput(int input);
};

