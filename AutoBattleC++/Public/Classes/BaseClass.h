#pragma once

#include "../Enums/Classes.h"

class BaseClass
{
public:
    BaseClass();
    ~BaseClass();

    int GetBaseArmour();
    int GetBaseHealth();
    int GetBaseSpeed();
    int GetBaseRange();
    int GetBaseDamage();

protected:
    int armour{0};
    int health{0};
    int speed{0};
    int range{0};
    int damage{0};

    CharacterClass classIndex{CharacterClass::NoneClass};

    virtual void ExecuteSpecialAction(){};

private:
};
