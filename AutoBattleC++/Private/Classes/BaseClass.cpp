#include "../../Public/Classes/BaseClass.h"

BaseClass::BaseClass()
{
}

BaseClass::~BaseClass()
{
}

int BaseClass::GetBaseArmour()
{
    return this->armour;
}

int BaseClass::GetBaseHealth()
{
    return this->health;
}

int BaseClass::GetBaseSpeed()
{
    return this->speed;
}

int BaseClass::GetBaseRange()
{
    return this->range;
}

int BaseClass::GetBaseDamage()
{
    return this->damage;
}