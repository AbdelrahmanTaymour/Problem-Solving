#pragma once
#include <iostream>
#include "clsMyStack.h"

using namespace std;

class clsMyString {
    
    clsMyStack<string> _Undo;
    clsMyStack<string> _Redo;
    string _Value = "";
    
public:
    
    void SetValue(string Vlaue)
    {
        _Undo.push(_Value);
        _Value = Vlaue;
    }
    
    string GetValue()
    {
        return _Value;
    }
    
    void Undo()
    {
        if(!_Undo.IsEmpty())
        {
            _Redo.push(_Value);
            _Value = _Undo.Top();
            _Undo.pop();
        }
    }
    
    void Redo()
    {
        if(!_Redo.IsEmpty())
        {
            _Undo.push(_Value);
            _Value = _Redo.Top();
            _Redo.pop();
        }
    }  
};
