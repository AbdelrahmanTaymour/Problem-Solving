#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 23 - Print First Letter of Each Word

* string ReadString()
{
    string str;

    cout << "Please Enter Your String: ";
    getline(cin, str);
    return str;
}
void PrintFirstLetterOfEachWord(string Word)
{
    bool isFirstLetter = true;
    for (int i = 0;i < Word.length();i++)
    {
        if (Word[i] != ' ' && isFirstLetter)
            cout << Word[i] << endl;

        isFirstLetter = (Word[i] == ' ') ? true : false;
    }
}

int main()
{
    //Problem 23 - Print First Letter of Each Word
    PrintFirstLetterOfEachWord(ReadString());
}
