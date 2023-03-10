#include "Grid.h"
#include "Types.h"


Grid::Grid(int Lines, int Columns)
{
    xLenght = Lines;
    yLength = Columns;
    //Console.WriteLine("The battle field has been created\n");
    for (int i = 0; i < Lines; i++)
    {

        for (int j = 0; j < Columns; j++)
        {
            Types::GridBox* newBox = new Types::GridBox(i, j, false, (Columns * i + j));
            grids.insert(grids.end(), newBox);
            //Console.Write($"{newBox.Index}\n");
        }
    }
	//drawBattlefield(Lines, Columns);
}

Grid::~Grid() 
{

}

void Grid::drawBattlefield(int Lines, int Columns)
{
    for (int i = 0; i < Lines; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            Types::GridBox* currentgrid = new Types::GridBox();
            if (currentgrid->ocupied)
            {
                //if()
                printf("[X]\t");
            }
            else
            {
                printf("[ ]\t");
            }
        }
        printf("\n");
    }
    printf("\n");
}