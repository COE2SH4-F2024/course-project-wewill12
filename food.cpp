#include <iostream>
#include "food.h"
#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

food::food(GameMechs* reference)
{
    foodPos = objPos();
    ref = reference;
}

//Copy constructor
food::food(food const &b)
{
    foodPos = objPos();
    foodPos.pos->x = b.getFoodPos().pos->x;
    foodPos.pos->y = b.getFoodPos().pos->y;
    foodPos.symbol = b.getFoodPos().getSymbol();
}

//Copy assignment 
food& food::operator=(food const &a)
{
    if(this  != nullptr)
    {
        foodPos = objPos();
        foodPos.pos->x = a.getFoodPos().pos->x;
        foodPos.pos->y = a.getFoodPos().pos->y;
        foodPos.symbol = a.getFoodPos().getSymbol();
    }
    return *this;
}

//Nothing new is being allocated 
food::~food()
{

}


void food::generateFood(objPosArrayList blockOff)
{
    int original = 0;
    int xSize  = ref->getBoardSizeX(), ySize = ref->getBoardSizeY();//creating variables to reduce text
    srand(time(NULL));


    //same random generation logic from previous PPAs
    while(!original)
    {
        original = 1;

        foodPos.pos->x = rand() % (xSize-1);
        foodPos.pos->y = rand() % (ySize-1);

        for(int i = 0; i < blockOff.getSize(); i++)
        {
            if(blockOff.getElement(i).pos->x == foodPos.pos->x && blockOff.getElement(i).pos->y == foodPos.pos->y || foodPos.pos->x == 0 || foodPos.pos->y == 0)
            {
                original = 0;
                break;
            }
        }
    }


    //Random symbol generation (not sure if needed)
    do
    {
    foodPos.symbol = rand() % 93 + 33;
    }while(foodPos.symbol == '*');//Because * is our character symbol

}

objPos food::getFoodPos() const
{
    return foodPos;
}

//Makes a deep copy of a into the foodPos object
void food::setFood(food a)
{
    foodPos.pos->x = a.getFoodPos().pos->x;
    foodPos.pos->y = a.getFoodPos().pos->y;
    foodPos.symbol = a.getFoodPos().symbol;
}
