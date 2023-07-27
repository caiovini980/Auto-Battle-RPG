#pragma once
#include "../Enums/Classes.h"

class BaseClass
{
public:
    BaseClass();
    ~BaseClass();

    int GetBaseArmour() { return this->armour; }
    int GetBaseHealth() { return this->health; }
    int GetBaseSpeed() { return this->speed; }
    int GetBaseRange() { return this->range; }
    int GetBaseDamage() { return this->damage; }

    

protected:
    int armour{0};
    int health{0};
    int speed{0};
    int range{0};
    int damage{0};

    CharacterClass classIndex{ CharacterClass::NoneClass };

    virtual void ExecuteSpecialAction() { }
private:
};
