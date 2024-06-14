#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 35 - Print Each Word In String

string ReadString()
{
    string str;

    cout << "Please Enter Your String: ";
    getline(cin, str);
    return str;
}
void PrintEachWordInString(string str)
{
    for (int i = 0;i < str.length();i++)
    {
        while (str[i] != ' '&&i!=str.length())
        {
            cout << str[i];
            i++;
        }
        cout << endl;
    }
}

//or
void PrintEachWordInStringMethod2(string S1)
{
    string delim = " ";
    int pos = 0;
    string sword;
    cout << "\nYour string wrords are: \n\n";
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sword = S1.substr(0, pos);
        if (sword != "")
        {
            cout << sword << endl;
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
        cout << S1 << endl;
}

int main()
{
    //Problem 35 - Print Each Word In String

    string str = ReadString();
    PrintEachWordInString(str);
    PrintEachWordInStringMethod2(str);
}
