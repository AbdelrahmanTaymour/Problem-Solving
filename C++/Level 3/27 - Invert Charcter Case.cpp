#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 27 - Invert Charcter Case

char ReadChar()
{
    char c;
    cout << "Please Enter a charcter: ";
    cin >> c;
    return c;
}
char InvertCharcter(char c)
{
    if (c >= 'A' && c <= 'Z' && c != ' ')
        c += 32;
    else if (c >= 'a' && c <= 'z' && c != ' ')
        c -= 32;
    return c;
}

//or
char InvertCharcterCase(char c)
{
    return isupper(c) ? tolower(c) : toupper(c);
}

int main()
{
    //Problem 27 - Invert Charcter Case
    char c = ReadChar();
    cout << "\nChar after inerting: " << InvertCharcterCase(c) << endl;
}

