#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 31 - Count Letters (Match Case)

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
char InvertCharcterCase(char c)
{
    return isupper(c) ? tolower(c) : toupper(c);
}
int CountLetters(string str, char Letter, bool MatchCase = true)
{
    int counter = 0;
    for (int i = 0;i < str.length();i++)
    {
        if (MatchCase)
        {
            if (str[i] == Letter)
                counter++;
        }
        else
        {
            if (tolower(str[i]) == tolower(Letter))
                counter++;
        }
    }
    return counter;
}

int main()
{
    //Problem 31 - Count Letters (Match Case)

    string str = ReadString();
    char Letter = ReadChar();

    cout << "\nLetter '" << Letter << "' Count = " << CountLetters(str, Letter) << endl;
    cout << "\nLetter '" << Letter << "' or '"<< InvertCharcterCase(Letter)<<"' Count = "
        << CountLetters(str, Letter, false) << endl;
}
