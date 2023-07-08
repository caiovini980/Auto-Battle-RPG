#include "../../Public/Managers/GameManager.h"

GameManager::GameManager()
{
    std::cout << "Created a new Game Manager!\n";
}

GameManager::~GameManager()
{
    std::cout << "Destroyed the Game Manager!\n";
}

void GameManager::CreateNewGame() 
{
    int classChoice{};
    int sizeXChoice{};
    int sizeYChoice{};

    std::cout << "Creating a new game\n\n";
    std::cout << "Choose a class:\n[1] Paladin\n[2] Warrior\n[3] Cleric\n[4] Archer\n";
    std::cin >> classChoice;

    CheckClassInput(classChoice);

    system("cls");
    std::cout << "What's the height of the field? (In units)\n";
    std::cin >> sizeYChoice;

    std::cout << "\nWhat's the width of the field? (In units)\n";
    std::cin >> sizeXChoice;

    if (AreFieldInputsValid(sizeXChoice, sizeYChoice))
    {
        // create battlefield
        std::shared_ptr<BattleFieldManager> battlefieldManager = std::make_shared<BattleFieldManager>(sizeXChoice, sizeYChoice);
        battlefieldManager->CreateBattlefield();
    }

    do
    {
        ExecuteGame();
    } while (!gameOver);
    
    std::cin.get();

    // ask for player's class choice
    // ask player's choice for battlefield size
    // initialize battlefield
    // get random position on the battlefield to spawn the characters
    // execute turns
        // each turn, each character can only execute one action (move, attack, regen health, etc)
}

void GameManager::CheckClassInput(int & input)
{
    switch(input)
    {
        case 1:
        std::cout << "Selecting Paladin...\n";
        break;

        case 2:
        std::cout << "Selecting Warrior...\n";
        break;

        case 3:
        std::cout << "Selecting Cleric...\n";
        break;

        case 4:
        std::cout << "Selecting Archer...\n";
        break;

        default:
        std::cout << "Select one of the available classes, please.\n";
        break;
    }
}

bool GameManager::AreFieldInputsValid(int & X, int & Y)
{
    // todo: check if inputs are numerals

    return true;
}

void GameManager::ExecuteGame()
{

}