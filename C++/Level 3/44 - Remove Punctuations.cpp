#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

//Problem 44 - Remove Punctuations

string RemovePunctuationsFromString(string s1)
{
    string s2 = "";
    for (int i = 0;i < s1.length();i++)
    {
        if (!ispunct(s1[i]))
            s2 += s1[i];
    }
    return s2;
}

int main()
{
    //Problem 44 - Remove Punctuations

    string S1 = "Welcome to Jordan, Jordan is a nice country; it's amazing."; 
    cout << "Original String:\n" << S1;
    cout << "\n\nPauncuations Removed:\n" << RemovePunctuationsFromString(S1);
}
