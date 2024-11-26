#include "Player.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x = 5;
    playerPos.pos->y = 5;
    playerPos.symbol = '*';
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos) const
{
    
    returnPos = playerPos;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    if(MacUILib_hasChar())
    {
        mainGameMechsRef->setInput(MacUILib_getChar());
    }        // PPA3 input processing logic          
}

void Player::movePlayer()
{
    char temp = mainGameMechsRef->getInput();
    if(temp != 0)  // if not null character
        {
            switch(temp)
            {                      
                case ' ':  // exit
                    mainGameMechsRef->setExitTrue();
                    break;

                case 'w':
                    if(myDir != DOWN){
                        myDir = UP;
                    }
                    break;

                case 'a':
                    if(myDir != RIGHT ){
                        myDir = LEFT;
                    }
                    break;

                case 's':
                    if(myDir != UP){
                        myDir = DOWN;
                    }
                    break;

                case 'd':
                    if(myDir != LEFT){            
                        myDir = RIGHT;
                    }
                    break;

                default:
                    break;
            }
        
        }

    if(myDir == RIGHT)
        {      
            if(playerPos.pos->x < 18)
            {
                playerPos.pos->x++;
            }
            else
            {
                playerPos.pos->x = 1;
            }
        }

    else if(myDir == LEFT)
    {      
        if(playerPos.pos->x > 1)
        {
            playerPos.pos->x--;
        }
        else
        {
            playerPos.pos->x = 18;
        }
    }


    else if(myDir == UP)
    {      
        if(playerPos.pos->y > 1 )
        {
            playerPos.pos->y--;
        }
        else
        {
            playerPos.pos->y = 8;
        }
    }

    else if(myDir == DOWN)
    {      
        if(playerPos.pos->y < 8)
        {
            playerPos.pos->y++;
        }
        else
        {
            playerPos.pos->y = 1;
        }
    // PPA3 Finite State Machine logic
    }
    MacUILib_printf("Input: %c", temp);
    mainGameMechsRef->clearInput();
}
// More methods to be added