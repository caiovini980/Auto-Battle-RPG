#pragma once

#include "BaseClass.h"

class Archer : public BaseClass
{
public:
    Archer();
    ~Archer();

    virtual void ExecuteSpecialAction() override;
private:
};

