#include "../Enums/Classes.h"

class BaseClass
{
public:
    BaseClass() = default;
    ~BaseClass();

protected:
    int armour{0};
    int health{0};
    int speed{0};
    int range{0};

    CharacterClass classIndex{CharacterClass::None};

    virtual void ExecuteSpecialAction(){};

private:
};
