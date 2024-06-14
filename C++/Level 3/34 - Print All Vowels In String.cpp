#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 34 - Print All Vowels In String

string ReadString()
{
    string str;

    cout << "Please Enter Your String: ";
    getline(cin, str);
    return str;
}
bool isVowel(char Ch)
{
    Ch = tolower(Ch);
    return (Ch == 'a') || (Ch == 'e') || (Ch == 'i') || (Ch == 'o') || (Ch == 'u');
}
void PrintAllVowelInString(string str)
{
    for (int i = 0;i < str.length();i++)
    {
        if (isVowel(str[i]))
            cout << str[i] << "    ";
    }
}

int main()
{
    //Problem 34 - Print All Vowels In String

    string str = ReadString();
    cout << "\nVowels in string are: ";
    PrintAllVowelInString(str);
}
