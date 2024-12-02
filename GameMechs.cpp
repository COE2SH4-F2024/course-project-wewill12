#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = 0;
    loseFlag = 0;
    score = 0;
    boardSizeX = 30;
    boardSizeY = 15;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = 0;
    loseFlag = 0;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
}

//Copy constructor
GameMechs::GameMechs(GameMechs const &game)
{
    input = game.input;
    exitFlag = game.exitFlag;
    loseFlag = game.loseFlag;
    score = game.score;
    boardSizeX = game.boardSizeX;
    boardSizeY = game.boardSizeY;
}

//Copy assignment 
GameMechs& GameMechs::operator=(GameMechs const &game)
{
    if(this  != nullptr)
    {
        input = game.input;
        exitFlag = game.exitFlag;
        loseFlag = game.loseFlag;
        score = game.score;
        boardSizeX = game.boardSizeX;
        boardSizeY = game.boardSizeY;
    }
    return *this;
}

// No destructor needed as there is nothing new being allocated
GameMechs::~GameMechs()
{
    
}


//the rest of the methods are self explanatory 
bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}   

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

void GameMechs::setExitTrue()
{
    exitFlag = 1;
}

void GameMechs::setLoseFlag()
{
    loseFlag = 1;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here

objPos GameMechs::getFoodPos()
{
    return food;
}

void GameMechs::setFoodPos(objPos a)
{
    food.pos->x = a.pos->x;
    food.pos->y = a.pos->y;
    food.symbol = a.symbol;
}

