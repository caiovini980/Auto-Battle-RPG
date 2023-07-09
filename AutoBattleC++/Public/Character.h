#pragma once
#include "Enums/Turns.h"

class Character
{
public:
    Character();
    ~Character();

    void SetStats(float & Health, float & Damage);
    void SetActionTurn(Turn & ActionTurn);
    void Attack(Character & CharacterAttacked);
    void TakeDamage(const float &DamageTaken);

private:
    float maxHealth{0};
    float currentHealth{0};
    float damage{0};
    Turn actionTurn{Turn::None};

    void Die();
};

