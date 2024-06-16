#pragma once
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template<class T>
class clsMyQueue
{
protected:
    clsDblLinkedList<T> _MyList;
    
public:
    
    void push(T Item)
    {
        _MyList.InsertAtEnd(Item);
    }
    
    void pop()
    {
        
        _MyList.DeleteFirstNode();
    }
    
    void Print()
    {
        _MyList.PrintList();
    }
    
    int Size()
    {
        return _MyList.Size();
    }
    
    bool IsEmpty()
    {
        return _MyList.IsEmpty();
    }
    
    T front()
    {
        return _MyList.GetItem(0);
    }
    
    T back()
    {
        return _MyList.GetItem(Size() - 1);
    }
    
    T GetItem(int Index)
    {
        return _MyList.GetItem(Index);
    }
    
    void Reverse()
    {
        _MyList.Reverse();
    }
    
    void UpdateItem(int Index, T newValue)
    {
        _MyList.UpdateItem(Index, newValue);
    }
    
    void InsertAfter(int Index, T newItem)
    {
        _MyList.InsertAfter(Index, newItem);
    }
    
    void InsertAtFront(T newItem)
    {
        _MyList.InsertAtBeginning(newItem);
    }
    
    void InsertAtBack(T newItem)
    {
        _MyList.InsertAtEnd(newItem);
    }
    
    void Clear()
    {
        _MyList.Clear();
    }
    
};
