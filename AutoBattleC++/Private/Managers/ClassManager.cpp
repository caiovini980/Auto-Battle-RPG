#include "../../Public/Managers/ClassManager.h"

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
    case CharacterClass::WarriorClass:
        aux = std::make_shared<Warrior>();
        break;

    case CharacterClass::ArcherClass:
        aux = std::make_shared<Archer>();
        break;

    case CharacterClass::ClericClass:
        aux = std::make_shared<Cleric>();
        break;

    case CharacterClass::PaladinClass:
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
    // TODO: Change hardcode
    int randomClassIndex = 1 + (std::rand() % 4);
    CharacterClass randomClass = GetClassIdByInteger(randomClassIndex);
    return GetClassByClassID(randomClass);
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
