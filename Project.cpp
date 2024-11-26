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
objPos seen;
GameMechs Game;
Player player1 = Player(&Game);

int main(void)
{

    Initialize();


    Game = GameMechs();
    playerpointer = &player1;
    playerpointer->getPlayerPos(seen);

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

    Game = GameMechs(5,5);
}

void GetInput(void)
{
    player1.updatePlayerDir();
    player1.movePlayer();
   
}

void RunLogic(void)
{
    if(Game.getExitFlagStatus()||Game.getLoseFlagStatus())
    {
        exitFlag = true;
    }
    
}

void DrawScreen(void)
{
    //MacUILib_clearScreen();  move this back later

    int x,y;

    for(y = 0; y < Game.getBoardSizeY(); y++){
        for(x = 0; x < Game.getBoardSizeX(); x++)
        {
            if(x == 0 || x == Game.getBoardSizeX() - 1 || y == 0 || y == Game.getBoardSizeY() - 1)
            {
                MacUILib_printf("#");
            }
            else if(seen.pos->x == x && seen.pos->y == y)
            {
                MacUILib_printf("%c", seen.getSymbol());
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Player: [%d,%d] \n", seen.pos->x, seen.pos->y);
    MacUILib_clearScreen();
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
