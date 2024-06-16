#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDynamicArray
{
protected:
    int _Size;
    T* _tempArray;
    
public:
    T* OriginalArray;
    
    clsDynamicArray(int size = 0)
    {
        if(size<0)
            size = 0;
        _Size = size;
        OriginalArray = new T[_Size];
    }
    
    ~clsDynamicArray()
    {
        delete[] OriginalArray;
    }
    
    void ReSize(int newSize)
    {
        if(newSize < 0)
            newSize = 0;
        
        if(newSize < _Size)
            _Size = newSize;
        
        _tempArray = new T[newSize];
        
        for(int i=0;i<_Size;i++)
        {
            _tempArray[i] = OriginalArray[i];
        }
        
        _Size = newSize;
        
        delete[] OriginalArray;
        OriginalArray = _tempArray;
    }
    
    bool SetItem(int Index, T Item)
    {
        if(Index >= _Size || _Size < 0)
            return false;
        
        OriginalArray[Index] = Item;
        return true;
    }
    
    T GetItem(int Index)
    {
        return OriginalArray[Index];
    }
    
    int Find(T Item)
    {
        for(int i =0;i<_Size;i++)
        {
            if(OriginalArray[i] == Item)
                return i;
        }
        return -1;
    }
    
    bool DeleteItemAt(int Index)
    {
        if(_Size<= Index || Index < 0)
            return false;
        
        
        _Size--;
        _tempArray = new T[_Size - 1];
        
        for(int i = 0;i<Index;i++)
        {
            _tempArray[i] = OriginalArray[i];
        }
        
        for(int i = Index + 1; i<_Size + 1 ;i++)
        {
            _tempArray[i-1] = OriginalArray[i];
        }
        
        delete[] OriginalArray;
        OriginalArray = _tempArray;
        return true;
    }
    
    void DeleteLastItem()
    {
        DeleteItemAt(_Size - 1);
    }
    
    void DeleteFirstItem()
    {
        DeleteItemAt(0);
    }
    
    bool DeleteItem(T Item)
    {
        int Index = Find(Item);
        
        if(Index == -1)
            return false;
        
        DeleteItemAt(Index);
        return true;
    }
    
    bool InsertAt(int Index, T Item)
    {
        if(Index > _Size || Index < 0)
            return false;
        
        _Size++;
        _tempArray = new T[_Size];
        
        for(int i = 0;i<Index;i++)
        {
            _tempArray[i] = OriginalArray[i];
        }
        
        _tempArray[Index] = Item;
        
        for(int i = Index;i<_Size-1;i++)
        {
            _tempArray[i+1] = OriginalArray[i];
        }
        
        delete[] OriginalArray;
        OriginalArray = _tempArray;
        return true;
    }
    
    void InsertAtBeginning(T Item)
    {
        InsertAt(0, Item);
    }
    
    bool InsertBefore(T Index, T Item)
    {
        if(Index < 1)
            return InsertAt(0, Item);
        else
            return InsertAt(Index - 1, Item);
        
    }
    
    void InsertAfter(T Index, T Item)
    {
        if(Index >= _Size)
            InsertAt(Index - 1, Item);
        else
            InsertAt(Index + 1, Item);
    }
    
    void InsertAtEnd(T Item)
    {
        InsertAt(_Size, Item);
    }
    
    void Reverse()
    {
        _tempArray = new T[_Size];
        
        for(int i = 0;i<_Size ;i++)
        {
            _tempArray[i] = OriginalArray[_Size - i - 1];
        }
        delete[] OriginalArray;
        OriginalArray = _tempArray;
     }
    
    void Clear()
    {
        _Size = 0;
        _tempArray = new T[0];
        delete[] OriginalArray;
        OriginalArray = _tempArray;
        
    }
    
    int Size()
    {
        return _Size;
    }
    
    bool IsEmpty()
    {
        return (_Size == 0) ? true : false;
    }
    
    void PrintList()
    {
        for(int i = 0 ;i < _Size; i++)
        {
            cout << OriginalArray[i] << " ";
        }
        cout << endl;
    }
};
