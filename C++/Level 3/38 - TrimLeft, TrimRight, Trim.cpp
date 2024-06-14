#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 38 - TrimLeft, TrimRight, Trim

string TrimLeft(string S1)
{
    for (int i = 0;i < S1.length();i++)
    {
        if (S1[i] != ' ')
            return S1.substr(i, S1.length() - i);
    }
    return "";
}
string TrimRight(string S1)
{
    for (int i = S1.length() - 1;i>=0;i--)
    {
        if (S1[i] != ' ')
            return S1.substr(0, i + 1);
    }
    return "";
}
string Trim(string S1)
{
    return TrimLeft(TrimRight(S1));
}

int main()
{
    //Problem 38 - TrimLeft, TrimRight, Trim

    string S1 = "       Abdelrahman Taymour       ";

    cout << "\nString = " << TrimLeft(S1);
    cout << "\nTrim Right = " << TrimRight(S1);
    cout << "\nTrim = " << Trim(S1);
}
