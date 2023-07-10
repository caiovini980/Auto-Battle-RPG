#pragma once

#include "../Enums/Classes.h"

class BaseClass
{
public:
    BaseClass();
    ~BaseClass();

protected:
    int armour{0};
    int health{0};
    int speed{0};
    int range{0};

    CharacterClass classIndex{CharacterClass::NoneClass};

    virtual void ExecuteSpecialAction(){};

private:
};
