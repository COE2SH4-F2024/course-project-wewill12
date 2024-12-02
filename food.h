#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"



class food
{
    public:
        food(GameMechs* reference);
        food(food const &b);
        food& operator=(food const &a);
        ~food();
        
        void generateFood(objPosArrayList blockOff);
        objPos getFoodPos() const;
        void setFood(food a);
        

    private:
        objPos foodPos;
        GameMechs* ref;
        
};

#endif