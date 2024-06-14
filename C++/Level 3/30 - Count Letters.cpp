#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 30 - Count Letters

string ReadString()
{
    string str;

    cout << "Please Enter Your String: ";
    getline(cin, str);
    return str;
}
char ReadChar()
{
    char c;
    cout << "Please Enter a charcter: ";
    cin >> c;
    return c;
}
int CountLetter(string str, char Letter)
{
    int counter = 0;
    for (int i = 0;i < str.length();i++)
    {
        if (str[i] == Letter)
            counter++;
    }
    return counter;
}

int main()
{
    //Problem 30 - Count Letters

    string str = ReadString();
    char Letter = ReadChar();

    cout << "\nLetter '" << Letter << "' Count = " << CountLetter(str, Letter) << endl;
}
