#pragma once
#include <iostream>

#include "./Enums/Turns.h"
#include "./Classes/BaseClass.h"

class Character
{
public:
    Character();
    ~Character();

    void SetStats(float& Health, float& Damage);
    void SetActionTurn(const Turn& ActionTurn);
    void Attack(const Character& CharacterAttacked);
    void TakeDamage(const float& DamageTaken);
    void SetClass(const BaseClass& selectedClass);

private:
    float maxHealth{0};
    float currentHealth{0};
    float damage{0};
    Turn actionTurn{Turn::TurnNone};
    BaseClass characterClass{};

    void Die();
};

