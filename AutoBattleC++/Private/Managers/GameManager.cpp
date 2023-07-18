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

void GameManager::InitializeManagers()
{
    classManager = std::make_unique<ClassManager>();
    turnManager = std::make_unique<TurnManager>();
}

void GameManager::ExecuteGame()
{
    // execute turns
        // each turn, each character can only execute one action (move, attack, regen health, etc)

    
    system("cls");
    battlefieldManager->UpdateBattlefield("P", "O");
    std::cin.get();
}

void GameManager::CreateBattlefield(const int& sizeX, const int& sizeY)
{
    // create battlefield
    battlefieldManager = std::make_shared<BattleFieldManager>(sizeX, sizeY);
    battlefieldManager->CreateBattlefield();
}

bool GameManager::AreFieldInputsValid(int & X, int & Y)
{
    return X != 0 || Y != 0;
}

void GameManager::SetupPlayer()
{
    // create player character and give it's class
    std::shared_ptr<PlayerCharacter> player = std::make_shared<PlayerCharacter>();
    if (playerClass == nullptr) 
    { 
        printf("Player class isn't setted yet\n"); 
        return; 
    }

    player->SetClass(*playerClass);
    printf("player created\n");

    // Get a cell for the player
    std::shared_ptr<BattlefieldCell> playerCell = battlefieldManager->GetRandomCell();
    if (playerCell == nullptr) { printf("player cell is null\n"); }
    
    // set player on cell
    printf("Player cell at point [%i, %i]\n\n", playerCell->xIndex, playerCell->yIndex);
    player->SetPosition(*playerCell);

    // set player position as occupied
    battlefieldManager->SetCellOccupation(*playerCell, true, true);
}

void GameManager::SetupOpponent()
{
   // create enemy character and give it a random class
    std::shared_ptr<OpponentCharacter> opponent = std::make_shared<OpponentCharacter>();
    opponentClass = classManager->GetRandomClass();

    opponent->SetClass(*opponentClass);

    // Get a cell for the opponent
    std::shared_ptr<BattlefieldCell> opponentCell = battlefieldManager->GetRandomCell();
    if (opponentCell == nullptr) { printf("opponent cell is null\n"); }

    printf("Opponent cell at point [%i, %i]\n\n", opponentCell->xIndex, opponentCell->yIndex);
    opponent->SetPosition(*opponentCell);
    
    // set opponent position as occupied
    battlefieldManager->SetCellOccupation(*opponentCell, true, false);
}

void GameManager::GetChosenPlayerClass(int& input)
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

void GameManager::CreateNewGame() 
{
    InitializeManagers();

    int classChoice{};
    int sizeXChoice{};
    int sizeYChoice{};

    std::cout << "Creating a new game\n\n";
    std::cout << "Choose a class:\n[1] Paladin\n[2] Warrior\n[3] Cleric\n[4] Archer\n";
    std::cin >> classChoice;

    std::cin.get();

    system("cls");
    std::cout << "What's the height of the field? (In units)\n";
    std::cin >> sizeYChoice;

    std::cout << "\nWhat's the width of the field? (In units)\n";
    std::cin >> sizeXChoice;

    if (AreFieldInputsValid(sizeXChoice, sizeYChoice))
    {
        CreateBattlefield(sizeXChoice, sizeYChoice);

        // setup characters
        GetChosenPlayerClass(classChoice);
        SetupPlayer();
        SetupOpponent();

        // get first turn
        printf("\nFirst turn is: %i\n", turnManager->GetCurrentTurn());

        // execute game
        do
        {
            ExecuteGame();
        } while (!gameOver);        
    }
    else
    {
        printf("Inputs are not valid!\n");
    }
}
