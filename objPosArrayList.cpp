#include "objPosArrayList.h"
#include <iostream>
#include <stdio.h>

    objPosArrayList::objPosArrayList()
    {
        arrayCapacity = ARRAY_MAX_CAP; 
        listSize = 0;        
        aList = new objPos[ARRAY_MAX_CAP]; 
    }


    objPosArrayList::~objPosArrayList()
    {   
        delete[] aList;
        aList = nullptr;
    }

// copy construct 
objPosArrayList::objPosArrayList(const objPosArrayList &a)
{
    arrayCapacity = a.arrayCapacity;
    aList = new objPos[ARRAY_MAX_CAP];

    if(this != nullptr)
    {
        for(int i = 0; i < arrayCapacity; i++)
        {
            aList[i] = a.aList[i];
        }
    }
    listSize = a.listSize;

} 
// copy assingment operator
objPosArrayList& objPosArrayList::operator=(const objPosArrayList &a)
{
    if(this != nullptr)
    {
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

//moves all the elements over and inserts an element at the head
void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        return;
    }
    for(int i = listSize; i > 0; i--){
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;
    listSize++;

}

//inserts a tail object
void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize >= 0 && listSize < arrayCapacity){
        aList[listSize] = thisPos; 
        listSize++;  
    } 
}

//removes the 0th element by shifting everything over (overwriting the 0th element)
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

//simply reduces the list size
void objPosArrayList::removeTail()
{
    if(listSize == 0)
    {
        return;
    }
    listSize--;
}

//the rest are self explanatory
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