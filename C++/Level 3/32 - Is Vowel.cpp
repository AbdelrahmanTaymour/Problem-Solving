#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 32 - Is Vowel

char ReadChar()
{
    char c;
    cout << "Please Enter a charcter: ";
    cin >> c;
    return c;
}
bool isVowel(char Ch)
{
    Ch = tolower(Ch);
    return (Ch == 'a') || (Ch == 'e') || (Ch == 'i') || (Ch == 'o') || (Ch == 'u');
}

int main()
{
    //Problem 32 - Is Vowel

    char Ch = ReadChar();

    if (isVowel(Ch))
        cout << "\nYes: it is a vowel.\n";
    else
        cout << "\nNo: it is not a vowel.\n";
}
