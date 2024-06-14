#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 36 - Count Each Word In String

string ReadString()
{
    string str;

    cout << "Please Enter Your String: ";
    getline(cin, str);
    return str;
}
int CountWordsInString(string S1)
{
    string delim = " ";
    int pos = 0;
    int counter = 0;
    string sword;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sword = S1.substr(0, pos);
        if (sword != "")
            counter++;
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
        counter++;
    return counter;
}

int main()
{
    //Problem 36 - Count Each Word In String
    cout << "The Number of words in your string is: " << CountWordsInString("Abdelrahman Mohiddin Taymour") << endl;
}
