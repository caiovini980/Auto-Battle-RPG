#include "../Public/Character.h"

Character::Character()
{
}

Character::~Character()
{
}

void Character::Attack(Character &CharacterAttacked)
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

void Character::Die()
{
    // Character Died! Game over!
}

void Character::SetStats(float & Health, float & Damage)
{
    maxHealth = Health;
    currentHealth = maxHealth;
    damage = Damage;
}

void Character::SetActionTurn(Turn & ActionTurn)
{
    actionTurn = ActionTurn;
}