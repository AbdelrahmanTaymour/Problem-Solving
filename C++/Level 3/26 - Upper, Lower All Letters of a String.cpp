#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 26 - Upper, Lower All Letters of a String

string ReadString()
{
    string str;

    cout << "Please Enter Your String: ";
    getline(cin, str);
    return str;
}
string UpperLetters(string s1)
{
    for (int i = 0;i < s1.length();i++)
    {
        if (!(s1[i] >= 'A' && s1[i] <= 'Z') && s1[i] != ' ')
            s1[i] -= 32;
    }
    return s1;
}
string LowerLetters(string s1)
{
    for (int i = 0;i < s1.length();i++)
    {
        if (!(s1[i] >= 'a' && s1[i] <= 'z') && s1[i] != ' ')
            s1[i] += 32;
    }
    return s1;
}

int main()
{
    //Problem 26 - Upper, Lower All Letters of a String

    string s1 = ReadString();

    cout << "\nString after upper:\n";
    cout << UpperLetters(s1) << endl;

    cout << "\nString after lower:\n";
    cout << LowerLetters(s1) << endl;
}
