#pragma once

#include "BaseClass.h"

class Paladin : public BaseClass
{
public:
    Paladin(/* args */);
    ~Paladin();

    void ExecuteSpecialAction() override;
private:
    /* data */
};
