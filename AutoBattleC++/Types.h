#pragma once
class Types
{
public:

    struct GridBox
    {
        int xIndex;
        int yIndex;
        bool ocupied;
        int Index;

        GridBox(int x, int y, bool ocupied, int index)
        {
            xIndex = x;
            yIndex = y;
            ocupied = ocupied;
            Index = index;
        }
    };

    enum CharacterClass
    {
        Paladin = 1,
        Warrior = 2,
        Cleric = 3,
        Archer = 4
    };

};

