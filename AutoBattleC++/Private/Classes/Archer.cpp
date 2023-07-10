#include "../../Public/Classes/Archer.h"

Archer::Archer()
{
    health = 15;
    armour = 8;
    range = 5;
    speed = 2;
}

Archer::~Archer()
{
}

void Archer::ExecuteSpecialAction()
{
    // do anything special that a archer can do
}