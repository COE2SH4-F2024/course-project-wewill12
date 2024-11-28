#include "objPosArrayList.h"
#include <iostream>
#include <stdio.h>

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP; 
    listSize = 0;
    aList = new objPos[ARRAY_MAX_CAP]; 
}


objPosArrayList::~objPosArrayList()
{   
    delete[] aList;
}

// copy construct 
objPosArrayList::objPosArrayList(const objPosArrayList &a)
{
    listSize = a.listSize;
    arrayCapacity = a.arrayCapacity;
    aList = new objPos[ARRAY_MAX_CAP];

    if(this != nullptr)
    {
        for(int i = 0; i < arrayCapacity; i++)
        {
            aList[i] = a.aList[i];
        }
    }
} 
// copy assingment operator

objPosArrayList& objPosArrayList::operator=(const objPosArrayList &a)
{
    if(this != nullptr)
    {
        delete[] aList;
        listSize = a.listSize;
        arrayCapacity = a.arrayCapacity;
        for(int i = 0; i < arrayCapacity; i++)
        {
            aList[i] = a.aList[i];
        }
    }
    return *this;
}


int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        return;
    }
    for(int i = listSize; i > 0; i--){
        aList[i] = aList[i-1];
    }
    printf("thisPos: [%c]\n", thisPos.symbol);
    aList[0] = thisPos;
    listSize++;

}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize >= 0 && listSize < arrayCapacity){
        aList[listSize] = thisPos; 
        listSize++;  
    } 
}

void objPosArrayList::removeHead()
{
    if(listSize == 0)
    {
        return;
    }

    for(int i =  0; i < arrayCapacity-1; i++)
    {
        aList[i]= aList[i+1];
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    if(listSize == 0)
    {
        return;
    }
    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}