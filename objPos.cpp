#include "objPos.h"
using namespace std;

objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos::objPos(objPos const &p)
{
    pos = new Pos;
    pos->x = p.pos->x;
    pos->y = p.pos->y;
    symbol = p.symbol;
}

objPos& objPos::operator=(const objPos &p)
{
    if(this != nullptr)
    {
        pos->x = p.pos->x;
        pos->y = p.pos->y;
        symbol = p.symbol;
    }
}


objPos::~objPos()
{
    delete pos;
}



// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule




void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
