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
      // PPA3 input processing logic        
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
    mainGameMechsRef->clearInput();
}

void Player::movePlayer()
{
    if(myDir == RIGHT)
        {      
            if(playerPos.pos->x < mainGameMechsRef->getBoardSizeX()-2)
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
            playerPos.pos->x = mainGameMechsRef->getBoardSizeX()-2;
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
            playerPos.pos->y = mainGameMechsRef->getBoardSizeY()-2;
        }
    }

    else if(myDir == DOWN)
    {      
        if(playerPos.pos->y < mainGameMechsRef->getBoardSizeY()-2)
        {
            playerPos.pos->y++;
        }
        else
        {
            playerPos.pos->y = 1;
        }
    // PPA3 Finite State Machine logic
    }
}
// More methods to be added