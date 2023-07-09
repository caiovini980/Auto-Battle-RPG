#pragma once

#include "BaseClass.h"

class Paladin : public BaseClass
{
public:
    Paladin(/* args */);
    ~Paladin();

    virtual void ExecuteSpecialAction() override;
private:
    /* data */
};
