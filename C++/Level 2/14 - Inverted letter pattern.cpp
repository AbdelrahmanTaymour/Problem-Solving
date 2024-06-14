#include <iostream>
using namespace std;

//Problem 14 - Inverted letter pattern

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}
void PrintInvertedLetter(int Number)
{
    for (int i = Number;i >= 1;i--)
    {
        for (int j = 1; j <= i;j++) 
        {
            cout << char(i + 64);
        }
        cout << "\n";
    }
}
void PrintInvertedLetterPattern(int Number) //Another way
{
    cout << "\n";
    for (int i = 65 + Number - 1; i >= 65; i--)
    {
        for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)
        {
            cout << char(i);
        }
        cout << "\n";
    }
}

int main()
{
    //Problem 14 - Inverted letter pattern
    PrintInvertedLetter(ReadPositiveNumber("Please Enter Positive Number: "));
}
