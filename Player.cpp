#include "Player.h"
#include "MacUILib.h"
#include "objPosArrayList.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPosList = new objPosArrayList;
    
    //creates an object with an initial position [5,5] and of symbol '*' and inserts it into the array
    objPos initial;
    initial.pos->x = 5;
    initial.pos->y = 5;
    initial.symbol = '*';
    playerPosList->insertHead(initial);
}

//copy constructor
Player::Player(Player const &p)
{
    playerPosList = new objPosArrayList;
    p.getPlayerPos();
    myDir = p.myDir;
    mainGameMechsRef = p.mainGameMechsRef;
}


//Copy assignment 
Player& Player::operator=(Player const &p)
{
    if(this  != nullptr)
    {
        p.getPlayerPos();
        myDir = p.myDir;
        mainGameMechsRef = p.mainGameMechsRef;
    }
    return *this;
}


Player::~Player()
{
    delete playerPosList;
    // delete any heap members here
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    char temp = mainGameMechsRef->getInput();

    // PPA3 input processing logic  
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
    //creates temporary varaibles to simplify
    int tempx = 0, tempy = 0;
    tempx = playerPosList->getHeadElement().pos->x;
    tempy = playerPosList->getHeadElement().pos->y;

    //utilizes the same move logic from previous PPAs
    if(myDir == RIGHT)
        {      
            if(tempx < mainGameMechsRef->getBoardSizeX()-2)
            {
                tempx++;
            }
            else
            {
                tempx = 1;
            }
        }

    else if(myDir == LEFT)
    {      
        if(tempx > 1)
        {
            tempx--;
        }
        else
        {
            tempx = mainGameMechsRef->getBoardSizeX()-2;
        }
    }

    else if(myDir == UP)
    {      
        if(tempy > 1 )
        {
            tempy--;
        }
        else
        {
            tempy = mainGameMechsRef->getBoardSizeY()-2;
        }
    }

    else if(myDir == DOWN)
    {      
        if(tempy < mainGameMechsRef->getBoardSizeY()-2)
        {
            tempy++;
        }
        else
        {
            tempy = 1;
        }

    // PPA3 Finite State Machine logic
    }

    //After the head movement was processed, put into a objPos object and insert into the head 
    objPos tempHead = objPos(tempx, tempy, playerPosList->getTailElement().getSymbol());

    playerPosList->insertHead(tempHead);
    
    //Check for food consumption and remove or dont remove tail accordingly
    if(checkFoodConsumption() == false)
    {
        playerPosList->removeTail(); 
    }


}

bool Player::checkFoodConsumption()
{
    objPos head;
    objPos tempFood;

    tempFood = mainGameMechsRef->getFoodPos();
    head = playerPosList->getHeadElement();

    //compares the head element and the food position element to see if they are at the same position
    if(head.pos->x == tempFood.pos->x && head.pos->y == tempFood.pos->y)
    {
        return true;

    }
    return false;
}

void Player::increasePlayerLength()
{
    int tempx = 0, tempy = 0;
    tempx = playerPosList->getHeadElement().pos->x;
    tempy = playerPosList->getHeadElement().pos->y;

    //same as the movePlayer method however does not remove the tail
    if(myDir == RIGHT)
        {      
            if(tempx < mainGameMechsRef->getBoardSizeX()-2)
            {
                tempx++;
            }
            else
            {
                tempx = 1;
            }
        }

    else if(myDir == LEFT)
    {      
        if(tempx > 1)
        {
            tempx--;
        }
        else
        {
            tempx = mainGameMechsRef->getBoardSizeX()-2;
        }
    }

    else if(myDir == UP)
    {      
        if(tempy > 1 )
        {
            tempy--;
        }
        else
        {
            tempy = mainGameMechsRef->getBoardSizeY()-2;
        }
    }

    else if(myDir == DOWN)
    {      
        if(tempy < mainGameMechsRef->getBoardSizeY()-2)
        {
            tempy++;
        }
        else
        {
            tempy = 1;
        }

    }

    objPos tempHead = objPos(tempx, tempy, playerPosList->getTailElement().getSymbol());

    playerPosList->insertHead(tempHead);
}

//Checks to see if one of the snake body elements are equal to each other
bool Player::checkSelfCollision()
{
    int i = 0;
    objPos head = playerPosList->getHeadElement();
    objPos temp;

    //iterates through the elements and compares with the head (because that is the only thing that could cause a collision)
    for(i = 1; i < playerPosList->getSize(); i++){

        temp = playerPosList->getElement(i);
        
        if(head.pos->x == temp.pos->x && head.pos->y == temp.pos->y)
        {
            return true;
        }
    }

    return false;
}