#include "../../Public/Classes/Cleric.h"

Cleric::Cleric(/* args */)
{
    health = 15;
    armour = 8;
    range = 5;
    speed = 1;
}

Cleric::~Cleric()
{
}

void Cleric::ExecuteSpecialAction()
{
    // heal himself
}