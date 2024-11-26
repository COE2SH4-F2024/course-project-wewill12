#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000 

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


Player *playerpointer;
objPos playerposition;
GameMechs Game;
Player player1 = Player(&Game);

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
    
    Game = GameMechs();
    playerpointer = &player1;
    playerpointer->getPlayerPos(playerposition);
}

void GetInput(void)
{
                            //should get input from the user and store it into
    if(MacUILib_hasChar())  //the game mechanic input
    {
        Game.setInput(MacUILib_getChar()); 
    }
    MacUILib_printf("%c\n", Game.getInput());
}

void RunLogic(void)
{
    player1.updatePlayerDir();
    player1.movePlayer();
    player1.getPlayerPos(playerposition);
   
    if(Game.getExitFlagStatus()||Game.getLoseFlagStatus())
    {
        exitFlag = true;
    }

    Game.clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  

    int x,y;


    for(y = 0; y < Game.getBoardSizeY(); y++){
        for(x = 0; x < Game.getBoardSizeX(); x++)
        {
            if(x == 0 || x == Game.getBoardSizeX() - 1 || y == 0 || y == Game.getBoardSizeY() - 1)
            {
                MacUILib_printf("#");
            }
            else if(playerposition.pos->x == x && playerposition.pos->y == y)
            {
                MacUILib_printf("%c", playerposition.getSymbol());
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Player: [%d,%d] \n", playerposition.pos->x, playerposition.pos->y);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
