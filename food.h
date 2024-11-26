#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include "objPos.h"
#include "GameMechs.h"



class food
{
    public:
        food(GameMechs* reference);
        ~food();
        void generateFood(objPos blockOff);
        objPos getFoodPos() const;
        

    private:
        objPos foodPos;
        GameMechs* ref;
        
};

#endif