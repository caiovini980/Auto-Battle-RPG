#pragma once

#include "BaseClass.h"

class Cleric : public BaseClass
{
public:
    Cleric(/* args */);
    ~Cleric();

    virtual void ExecuteSpecialAction() override;
private:
    /* data */
};

