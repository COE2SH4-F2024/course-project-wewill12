#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

//DO COPY CONSTRUCTOR - RULES Minimum 4/6 




objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP; 
    listSize = 0;
    aList = new objPos[ARRAY_MAX_CAP]; 
    for (int i=0; i< ARRAY_MAX_CAP - 1; i++){
        aList[i]= objPos(); 
    }
    
}   

objPosArrayList::~objPosArrayList()
{   
    int i; 
    for(i = 0; i < arrayCapacity; i++){
        removeTail();
    }

    delete[] aList;

}

// copy construct 
objPosArrayList:objPosArrayList(const objPosArrayList &var){
    listSize = var.listSize;
    arrayCapacity = var.listSize;

    aList = new objPos[ARRAY_MAX_CAP];

}

// copy assingment operator


int objPosArrayList::getSize() const
{
    return arrayCapacity;

}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(arrayCapacity > 0){
        for(int i = arrayCapacity; i>0; i--){
            aList[i-1] = aList[i];
            listSize++;
        }

        aList[0] = thisPos;

    }
    
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
    
}

void objPosArrayList::removeTail()
{
    
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