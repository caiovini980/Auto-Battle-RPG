#pragma once

#include "BaseClass.h"

class Warrior : public BaseClass
{
public:
    Warrior(/* args */);
    ~Warrior();

    virtual void ExecuteSpecialAction() override;
private:
    /* data */
};


