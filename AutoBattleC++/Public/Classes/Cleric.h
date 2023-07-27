#pragma once

#include "BaseClass.h"

class Cleric : public BaseClass
{
public:
    Cleric(/* args */);
    ~Cleric();

    void ExecuteSpecialAction() override;
private:
    /* data */
};

