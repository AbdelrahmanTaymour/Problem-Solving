#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 33 - Count Vowel

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
int CountVowel(string str)
{
    int Counter = 0;
    for (int i = 0;i < str.length();i++)
    {
        if (isVowel(str[i]))
            Counter++;
    }
    return Counter;
}

int main()
{
    //Problem 33 - Count Vowel

    string str = ReadString();

    cout << "\nNumber of vowels: " << CountVowel(str) << endl;
}
