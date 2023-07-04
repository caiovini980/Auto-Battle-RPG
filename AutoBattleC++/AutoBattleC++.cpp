#include "./Public/Managers/GameManager.h"

int main()
{
    system("cls");
    std::unique_ptr<GameManager> Manager = std::make_unique<GameManager>();
    Manager->CreateNewGame();

    Manager.reset();
}


