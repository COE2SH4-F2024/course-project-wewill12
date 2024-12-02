#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "food.h"
using namespace std;

#define DELAY_CONST 100000 

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

Player* player1;
GameMechs* Game;
food * apple;



int main(void)
{

    Initialize();
    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;

    Game = new GameMechs();
    player1 = new Player(Game);
    apple = new food(Game);


    objPosArrayList* playerPosList = player1->getPlayerPos();

    apple->generateFood(*playerPosList);
    
    objPos temp = apple->getFoodPos();
    Game->setFoodPos(temp);
}

void GetInput(void)
{
    //the same input processing logic
    if(MacUILib_hasChar()) 
    {
       Game->setInput(MacUILib_getChar()); 
    }
}

void RunLogic(void)
{
    //assigning the objPosArrayList from the player object and assigning it into a pointer to access it
    objPosArrayList* playerPosList = player1->getPlayerPos();
    player1->updatePlayerDir();
    player1->movePlayer();
    
    //after the logic has moved the player, check to see if there was a self collision or if user has exited the game
    if(player1->checkSelfCollision())
    {
        Game->setLoseFlag();
        exitFlag = true;       
    }

    else if(Game->getExitFlagStatus())
    {
        exitFlag = true;
    }


    //Checking to see if food was consumed, and if true then increase score and generate new food pos 
    if(player1->checkFoodConsumption() == true)
    {
        Game->incrementScore();
        apple->generateFood(*playerPosList);    
        Game->setFoodPos(apple->getFoodPos());
    }
    Game->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    
    //initialize all the varaibles that will be accessed here
    objPosArrayList* playerPosList = player1->getPlayerPos();
    objPos temp = playerPosList->getHeadElement();
    objPos tempFood = apple->getFoodPos();
    bool flag;
    int x,y;

    MacUILib_printf("Food [%d,%d],\n",Game->getFoodPos().pos->x, Game->getFoodPos().pos->y);
    MacUILib_printf("Player [%d,%d], Score: %d\n", temp.pos->x,temp.pos->y, Game->getScore());

    //Use a triple loop with a flag to print out all parts of the snake
    for(y = 0; y < Game->getBoardSizeY(); y++){
        for(x = 0; x < Game->getBoardSizeX(); x++){

            flag = false;

            for(int z = 0; z < playerPosList->getSize(); z++){

                temp = playerPosList->getElement(z);
                if(temp.pos->x == x && temp.pos->y == y) // snake printer
                {
                    MacUILib_printf("%c", temp.symbol);
                    flag = true; //the purpose of the flag is to prevent more elements than the bordersize to print
                    break;   
                }
            }

            if(tempFood.pos->x == x && tempFood.pos->y == y && flag == false) //food printer 
            {
                MacUILib_printf("%c", tempFood.symbol);
                flag = true;
            }

            else if(x == 0 || x == Game->getBoardSizeX() - 1 || y == 0 || y == Game->getBoardSizeY() - 1) //border printer
            {
                MacUILib_printf("#");
                flag = true;
            }

            else if(flag == false) //empty space printer
            {
                MacUILib_printf(" ");
            }

            }
            MacUILib_printf("\n");
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen(); 

    if(Game->getLoseFlagStatus())
    {
        MacUILib_printf("You Lost");
    }

    else if(Game->getExitFlagStatus())
    {
        MacUILib_printf("You Quit");
    }

    //dealllocate all the memory that was allocated in the beginning
    delete Game;
    delete player1;
    delete apple;


    MacUILib_uninit();
}
