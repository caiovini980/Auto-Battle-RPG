#include "../Public/OpponentCharacter.h"

OpponentCharacter::OpponentCharacter(/* args */)
{
    printf("Creating opponent character!\n");
    SetActionTurn(Turn::OpponentTurn);
}

OpponentCharacter::~OpponentCharacter()
{
}
