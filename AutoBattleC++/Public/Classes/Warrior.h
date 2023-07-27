#pragma once

#include "BaseClass.h"

class Warrior : public BaseClass
{
public:
    Warrior(/* args */)
    {
        health = 25;
        armour = 10;
        range = 1;
        speed = 1;
        damage = 4;
    }

    ~Warrior() {}

    void ExecuteSpecialAction() override {};

private:
    /* data */
};


