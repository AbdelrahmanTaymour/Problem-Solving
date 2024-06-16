#pragma once
#include <iostream>
#include "clsDynamicArray.h"

template <class T>
class clsMyQueueArr {
protected:
    clsDynamicArray<T> _MyArray;
    
public:
    void push(T value)
    {
        _MyArray.InsertAtEnd(value);
    }
    
    void Print()
    {
        _MyArray.PrintList();
    }
    
    int Size()
    {
        return _MyArray.Size();
    }
    
    bool IsEmpty()
    {
        _MyArray.IsEmpty();
    }
    
    T front()
    {
        return _MyArray.GetItem(0);
    }
    
    T back()
    {
        return _MyArray.GetItem(Size()-1);
    }
    
    void pop()
    {
        _MyArray.DeleteFirstItem();
    }
    
    T GetItem(T Index)
    {
        return _MyArray.GetItem(Index);
    }
    
    void Reverse()
    {
        _MyArray.Reverse();
    }
    
    void UpdateItem(T Index, T newValue)
    {
        _MyArray.SetItem(Index, newValue);
    }
    
    void InsertAfter(T Index, T Item)
    {
        _MyArray.InsertAt(Index, Item);
    }
    
    void InsertAtFront(T Item)
    {
        _MyArray.InsertAtBeginning(Item);
    }
    
    void InsertAtBack(T Item)
    {
        _MyArray.InsertAtEnd(Item);
    }
    
    void Clear()
    {
        _MyArray.Clear();
    }
};
