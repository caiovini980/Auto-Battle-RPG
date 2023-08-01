#include "../Public/Character.h"

Character::Character()
{
}

Character::~Character()
{
}

void Character::Attack(Character& CharacterAttacked)
{
    if (isDead) 
    { 
        printf("Character already dead!\n");
        return; 
    }

    // if pass character armour, CharacterAttacked takes damage
    int attackChance = 1 + (rand() % 20);

    if (attackChance > CharacterAttacked.GetClass()->GetBaseArmour())
    {
        if (attackChance >= 19)
        {
            printf("CRITICAL HIT!\n");
            CharacterAttacked.TakeDamage(characterClass.GetBaseDamage() * 2);
            return;
        }

        printf("HIT!\n");
        CharacterAttacked.TakeDamage(characterClass.GetBaseDamage());
        return;
    }

    printf("MISSED!\n");
}

void Character::TakeDamage(const float &DamageTaken)
{
    currentHealth -= DamageTaken;
    if (*GetActionTurn() == Turn::PlayerTurn)
    {
        printf("Player health is: %f\n", currentHealth);
    }
    else
    {
        printf("Opponent health is: %f\n", currentHealth);
    }

    if (currentHealth <= 0)
    {
        currentHealth = 0;
        Die();
    }
}

void Character::SetClass(const BaseClass& selectedClass)
{
    printf("selectedClass health: %i\n", characterClass.GetBaseHealth());
    characterClass = selectedClass;
    printf("selectedClass health: %i\n", characterClass.GetBaseHealth());
    SetStats(characterClass.GetBaseHealth(), characterClass.GetBaseDamage());
    isDead = false;
}

void Character::Die()
{
    // Character Died! Game over!
    printf("Character DIED!\n");
    isDead = true;
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

bool Character::IsAlive()
{
    return !isDead;
}

// TODO - Change this to smart pointer 
std::shared_ptr<BattlefieldCell> Character::GetPosition()
{
    return std::make_shared<BattlefieldCell>(position);
}

// TODO - Change this to smart pointer
std::shared_ptr<BaseClass> Character::GetClass()
{
    return std::make_shared<BaseClass>(characterClass);
}

std::shared_ptr<Turn> Character::GetActionTurn()
{
    return std::make_shared<Turn>(actionTurn);
}
