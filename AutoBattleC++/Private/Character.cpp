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
    printf("Setting class as %f!\n", selectedClass);
    characterClass = selectedClass;
}

void Character::Die()
{
    // Character Died! Game over!
}

void Character::SetStats(float & Health, float & Damage)
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