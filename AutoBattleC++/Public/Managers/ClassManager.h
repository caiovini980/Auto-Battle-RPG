#pragma once

#include "Character.h"
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

    BaseClass GetClassByClassID(const CharacterClass& classID);
private:

};

