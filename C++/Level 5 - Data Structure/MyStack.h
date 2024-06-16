#pragma once
#include <iostream>
#include "clsMyQueue.h"

template <class T>
class clsMyStack :public clsMyQueue<T>
{
public:
    void push(T newItem)
    {
        clsMyQueue<T>::_MyList.InsertAtBeginning(newItem);
    }
    
    T Top()
    {
        return clsMyQueue<T>::front();
    }
    
    T Bottom()
    {
        return clsMyQueue<T>::back();
    }
};
