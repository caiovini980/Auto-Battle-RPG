#pragma once

#include "BaseClass.h"

class Archer : public BaseClass
{
public:
    Archer();
    ~Archer();

    void ExecuteSpecialAction() override;
private:
};

