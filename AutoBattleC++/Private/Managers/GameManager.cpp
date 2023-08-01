#include "../../Public/Managers/GameManager.h"

GameManager::GameManager()
{
    std::cout << "Created a new Game Manager!\n";
    //std::srand(1);// start seed
}

GameManager::~GameManager()
{
    std::cout << "Game finished, thanks for playing it!\n";
}

void GameManager::InitializeManagers()
{
    classManager = std::make_unique<ClassManager>();
    turnManager = std::make_unique<TurnManager>();
}

void GameManager::ExecuteGame()
{
    system("cls");
    printf("current turn is: %i\n", turnManager->GetCurrentTurn());

    if (turnManager->GetCurrentTurn() == Turn::PlayerTurn)
    {
        ExecutePlayerTurn();
    }
    else
    {
        ExecuteOpponentTurn();
    }

    if (!opponent->IsAlive())
    {
        printf("PLAYER WINS!\n");
        gameOver = true;
    }
    else if (!player->IsAlive())
    {
        printf("OPPONENT WINS!\n");
        gameOver = true;
    }
    else
    {
        battlefieldManager->UpdateBattlefield("P", "O");
        turnManager->ChangeTurn();
        gameOver = false;
    }
}



void GameManager::ExecuteCharacterMovement(Character& actionCharacter, Character& otherCharacter)
{
    std::shared_ptr<Directions> directions = battlefieldManager->GetDirectionToMoveCharacterToTarget(actionCharacter, *otherCharacter.GetPosition());

    int newCellXPosition = actionCharacter.GetPosition()->xIndex + directions->x;
    int newCellYPosition = actionCharacter.GetPosition()->yIndex + directions->y;

    // get new cell
    std::shared_ptr<BattlefieldCell> newCell = battlefieldManager->GetCellAtPosition(newCellXPosition, newCellYPosition);

    // move to the new cell
    if (newCell == nullptr) { return; }

    battlefieldManager->SetCellOccupation(*actionCharacter.GetPosition(), false, false);
    actionCharacter.SetPosition(*newCell);

    if (*actionCharacter.GetActionTurn() == Turn::PlayerTurn)
    {
        battlefieldManager->SetCellOccupation(*actionCharacter.GetPosition(), true, true);
    }
    else
    {
        battlefieldManager->SetCellOccupation(*actionCharacter.GetPosition(), true, false);
    }
    
}

void GameManager::ExecuteOpponentTurn()
{
    // if is close to player
    if (battlefieldManager->AreCharactersClose(*opponent, *player))
    {
        // attack
        printf("Opponent attack!\n");
        opponent->Attack(*player);
    }
    else
    {
        // else, move towards the player
        printf("Opponent moves towards the player...\n");
        ExecuteCharacterMovement(*opponent, *player);
    }
}

void GameManager::ExecutePlayerTurn()
{
    // if is close to opponent
    if (battlefieldManager->AreCharactersClose(*player, *opponent))
    {
        // attack
        printf("Player attack!\n");
        player->Attack(*opponent);
    }
    else
    {
        // else, move towards the opponent
        printf("Player moves towards the opponent...\n");
        ExecuteCharacterMovement(*player, *opponent);
    }
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

    this->player = player;
    this->player->SetClass(*playerClass);
    printf("player created\n");

    // Get a cell for the player
    std::shared_ptr<BattlefieldCell> playerCell = battlefieldManager->GetRandomCell();
    if (playerCell == nullptr) { printf("player cell is null\n"); }
    
    // set player on cell
    printf("Player cell at point [%i, %i]\n\n", playerCell->xIndex, playerCell->yIndex);
    this->player->SetPosition(*playerCell);

    // set player position as occupied
    battlefieldManager->SetCellOccupation(*playerCell, true, true);
}

void GameManager::SetupOpponent()
{
   // create enemy character and give it a random class
    std::shared_ptr<OpponentCharacter> opponent = std::make_shared<OpponentCharacter>();
    opponentClass = classManager->GetRandomClass();

    this->opponent = opponent;
    this->opponent->SetClass(*opponentClass);

    // Get a cell for the opponent
    std::shared_ptr<BattlefieldCell> opponentCell = battlefieldManager->GetRandomCell();
    if (opponentCell == nullptr) { printf("opponent cell is null\n"); }

    printf("Opponent cell at point [%i, %i]\n\n", opponentCell->xIndex, opponentCell->yIndex);
    this->opponent->SetPosition(*opponentCell);
    
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
            std::cin.get();
            ExecuteGame();
            printf("\n\n\nPlayer Position: [%i, %i] \tOpponent Position: [%i, %i]\n", player->GetPosition()->xIndex, player->GetPosition()->yIndex, opponent->GetPosition()->xIndex, opponent->GetPosition()->yIndex);
        } while (!gameOver);        
    }
    else
    {
        printf("Inputs are not valid!\n");
    }
}
