#include "./Public/Managers/GameManager.h"

int main()
{
    system("cls");
    std::unique_ptr<GameManager> GameController = std::make_unique<GameManager>();
    GameController->CreateNewGame();

    GameController.reset();
}


