#include "../../Public/Managers/GameManager.h"

GameManager::GameManager()
{
    std::cout << "Created a new Game Manager!\n";
    //std::srand(1);// start seed
}

GameManager::~GameManager()
{
    std::cout << "Destroyed the Game Manager!\n";
}

void GameManager::CreateNewGame() 
{
    InitializeManagers();

    int classChoice{};
    int sizeXChoice{};
    int sizeYChoice{};

    std::cout << "Creating a new game\n\n";
    std::cout << "Choose a class:\n[1] Paladin\n[2] Warrior\n[3] Cleric\n[4] Archer\n";
    std::cin >> classChoice;

    // create player character and give it a class based on player's input
    std::shared_ptr<PlayerCharacter> player = std::make_shared<PlayerCharacter>();
    CheckClassInput(classChoice);
    player->SetClass(*playerClass);

    // create enemy character and give it a random class
    std::shared_ptr<OpponentCharacter> opponent = std::make_shared<OpponentCharacter>();
    opponentClass = classManager->GetRandomClass();
    opponent->SetClass(*opponentClass);

    std::cin.get();

    //system("cls");
    std::cout << "What's the height of the field? (In units)\n";
    std::cin >> sizeYChoice;

    std::cout << "\nWhat's the width of the field? (In units)\n";
    std::cin >> sizeXChoice;

    if (AreFieldInputsValid(sizeXChoice, sizeYChoice))
    {
        // create battlefield
        battlefieldManager = std::make_shared<BattleFieldManager>(sizeXChoice, sizeYChoice);
        battlefieldManager->CreateBattlefield();

        // get player's and opponent's respective initial cells
        std::shared_ptr<BattlefieldCell> playerCell = battlefieldManager->GetRandomCell();
        std::shared_ptr<BattlefieldCell> oppponentCell = battlefieldManager->GetRandomCell();

        if (playerCell == nullptr) { printf("player cell is null\n"); }
        if (oppponentCell == nullptr) { printf("oppponent cell is null\n"); }

        printf("Player cell at point [%i, %i]\n", playerCell->xIndex, playerCell->yIndex);
        printf("Opponent cell at point [%i, %i]\n", oppponentCell->xIndex, oppponentCell->yIndex);
        
        // get first turn
        printf("\nFirst turn is: %i\n", turnManager->GetCurrentTurn());

        // execute game
        do
        {
            ExecuteGame();
        } while (!gameOver);        
    }
}

void GameManager::CheckClassInput(int& input)
{
    switch(input)
    {
        case 1:
        std::cout << "Selecting Paladin...\n";
        playerClass = classManager->GetClassByClassID(CharacterClass::PaladinClass);
        break;

        case 2:
        std::cout << "Selecting Warrior...\n";
        playerClass = classManager->GetClassByClassID(CharacterClass::WarriorClass);
        break;

        case 3:
        std::cout << "Selecting Cleric...\n";
        playerClass = classManager->GetClassByClassID(CharacterClass::ClericClass);
        break;

        case 4:
        std::cout << "Selecting Archer...\n";
        playerClass = classManager->GetClassByClassID(CharacterClass::ArcherClass);
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

void GameManager::InitializeManagers()
{
    classManager = std::make_unique<ClassManager>();
    turnManager = std::make_unique<TurnManager>();
}

void GameManager::ExecuteGame()
{
    // execute turns
        // each turn, each character can only execute one action (move, attack, regen health, etc)
}