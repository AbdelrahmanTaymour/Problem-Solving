#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 28 - Invert All Letters Case

string ReadString()
{
    string str;

    cout << "Please Enter Your String: ";
    getline(cin, str);
    return str;
}
char InvertCharCase(char c)
{
    return isupper(c) ? tolower(c) : toupper(c);
}
string InvertAllLettersCase(string str)
{
    for (int i = 0;i < str.length();i++)
    {
        str[i] = InvertCharCase(str[i]);
    }
    return str;
}

int main()
{
    //Problem 28 - Invert All Letters Case

    string str = ReadString();

    cout << "\nString after inverting: \n";
    cout << InvertAllLettersCase(str) << endl;
}
