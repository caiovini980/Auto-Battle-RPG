#include "../Public/Character.h"
#include "Classes/BaseClass.cpp"

Character::Character()
{
}

Character::~Character()
{
}

void Character::Attack(const Character& CharacterAttacked)
{
    // if pass character armour, CharacterAttacked takes damage
}

void Character::TakeDamage(const float &DamageTaken)
{
    if (currentHealth > 0)
    {
        currentHealth -= DamageTaken;
        return;
    }
    
    Die();
}

void Character::SetClass(const BaseClass& selectedClass)
{
    printf("selectedClass health: %i\n", characterClass.GetBaseHealth());
    characterClass = selectedClass;
    printf("selectedClass health: %i\n", characterClass.GetBaseHealth());
    SetStats(characterClass.GetBaseHealth(), characterClass.GetBaseDamage());
}

void Character::Die()
{
    // Character Died! Game over!
}

void Character::SetStats(const float& Health, const float& Damage)
{
    printf("Setting stats as:\tHealth: %f \tDamage: %f!\n", Health, Damage);
    maxHealth = Health;
    currentHealth = maxHealth;
    damage = Damage;

}

void Character::SetActionTurn(const Turn& ActionTurn)
{
    actionTurn = ActionTurn;
}

void Character::SetPosition(const BattlefieldCell& cell)
{
    position = cell;
}

void Character::Move(int& xDirection, int& yDirection)
{
    if (xDirection != 0)
    {
        if (xDirection > 0)
        {
            // go right
        }
        else if (xDirection < 0)
        {
            // go left
        }
    }
    
    else if (yDirection != 0)
    {
        if (yDirection > 0)
        {
            // go up
        }
        else if (yDirection < 0)
        {
            // go down
        }
    }
}

// TODO - Change this to smart pointer
BattlefieldCell* Character::GetPosition()
{
    return &position;
}

// TODO - Change this to smart pointer
BaseClass* Character::GetClass()
{
    return &characterClass;
}