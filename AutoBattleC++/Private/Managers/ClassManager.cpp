#include "../../Public/Managers/ClassManager.h"
#include "../Classes/Archer.cpp"
#include "../Classes/Cleric.cpp"
#include "../Classes/Paladin.cpp"
#include "../Classes/Warrior.cpp"

ClassManager::ClassManager()
{
}

ClassManager::~ClassManager()
{
}

std::shared_ptr<BaseClass> ClassManager::GetClassByClassID(const CharacterClass &classID)
{
    std::shared_ptr<BaseClass> aux;

    switch (classID)
    {
    case WarriorClass:
        aux = std::make_shared<Warrior>();
        break;

    case ArcherClass:
        aux = std::make_shared<Archer>();
        break;

    case ClericClass:
        aux = std::make_shared<Cleric>();
        break;

    case PaladinClass:
        aux = std::make_shared<Paladin>();
        break;

    default:
        aux = nullptr;
        break;
    }

    return aux;
}
std::shared_ptr<BaseClass> ClassManager::GetRandomClass()
{
    int randomClass = 1 + (std::rand() % 4);
    return GetClassByClassID(GetClassIdByInteger(randomClass));
}

CharacterClass ClassManager::GetClassIdByInteger(const int &number)
{
    switch (number)
    {
    case 1:
        return CharacterClass::PaladinClass;

    case 2:
        return CharacterClass::WarriorClass;

    case 3:
        return CharacterClass::ClericClass;

    case 4:
        return CharacterClass::ArcherClass;
    
    default:
        break;
    }
}
