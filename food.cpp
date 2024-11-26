#include <iostream>
#include "food.h"
#include "objPos.h"
#include "GameMechs.h"

food::food(GameMechs* reference)
{
    foodPos = objPos();
    ref = reference;
}

food::~food()
{

}

void food::generateFood(objPos blockOff)
{
    int xSize  = ref->getBoardSizeX(), ySize = ref->getBoardSizeY();
    srand(time(NULL));
    do
    {
        
        foodPos.pos->x = rand() % (xSize-1);
        foodPos.pos->y = rand() % (ySize-1);

    }while(blockOff.pos->x == foodPos.pos->x && blockOff.pos->y == foodPos.pos->y || foodPos.pos->x == 0 || foodPos.pos->y == 0);

    do
    {

    foodPos.symbol = rand() % 93 + 33;
    }while(foodPos.symbol == '*');//Because * is our character symbol

}

objPos food::getFoodPos() const
{
    return foodPos;
}
