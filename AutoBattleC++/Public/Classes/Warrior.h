#pragma once

#include "BaseClass.h"

class Warrior : public BaseClass
{
public:
    Warrior(/* args */);

    ~Warrior();

    void ExecuteSpecialAction() override;

private:
    /* data */
};


