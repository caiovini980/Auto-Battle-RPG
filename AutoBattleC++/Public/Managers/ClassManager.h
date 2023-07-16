#pragma once

#include <memory>
#include <cstdlib>

#include "../Character.h"
#include "../Enums/Classes.h"
#include "../Classes/BaseClass.h"
#include "../Classes/Archer.h"
#include "../Classes/Cleric.h"
#include "../Classes/Paladin.h"
#include "../Classes/Warrior.h"

class ClassManager
{
public:
    ClassManager();
    ~ClassManager();

    std::shared_ptr<BaseClass> GetClassByClassID(const CharacterClass& classID);
    std::shared_ptr<BaseClass> GetRandomClass();
    CharacterClass GetClassIdByInteger(const int& number);
private:

};

