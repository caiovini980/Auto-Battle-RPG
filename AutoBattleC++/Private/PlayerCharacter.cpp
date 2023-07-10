#include "../Public/PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(/* args */)
{
    printf("Creating player character!\n");
    SetActionTurn(Turn::PlayerTurn);
}

PlayerCharacter::~PlayerCharacter()
{
}