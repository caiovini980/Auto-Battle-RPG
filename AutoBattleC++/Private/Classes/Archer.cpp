#include "../../Public/Classes/Archer.h"

Archer::Archer()
{
    health = 15;
    armour = 8;
    range = 2;
    speed = 2;
    damage = 1;
}

Archer::~Archer()
{
}

void Archer::ExecuteSpecialAction()
{
    // do anything special that a archer can do
}