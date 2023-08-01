#pragma once
#include <iostream>
#include <memory>
#include <cstdlib>

#include "./Enums/Turns.h"
#include "./Classes/BaseClass.h"
#include "./BattlefieldCell.h"

class Character
{
public:
    Character();
    ~Character();

    void SetStats(const float& Health, const float& Damage);
    void SetActionTurn(const Turn& ActionTurn);
    void Attack(Character& CharacterAttacked);
    void TakeDamage(const float& DamageTaken);
    void SetClass(const BaseClass& selectedClass);
    void SetPosition(const BattlefieldCell& cell);

    bool IsAlive();

    std::shared_ptr<BattlefieldCell> GetPosition();
    std::shared_ptr<BaseClass> GetClass();
    std::shared_ptr<Turn> GetActionTurn();
    

private:
    float maxHealth{0};
    float currentHealth{0};
    float damage{0};
    bool isDead{ false };

    BaseClass characterClass;
    BattlefieldCell position;

    Turn actionTurn{Turn::TurnNone};

    void Die();
};

