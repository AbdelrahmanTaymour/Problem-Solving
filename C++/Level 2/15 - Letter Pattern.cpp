#include <iostream>
using namespace std;

//Problem 15 - Letter Pattern

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
void PrintLetter(int Number)
{
    for (int i = 1;i <= Number;i++)
    {
        for (int j = 1;j <= i;j++)
        {
            cout << char(i + 64);
        }
        cout << "\n";
    }
}
void PrintLetterPattern(int Number) //Another way
{
    cout << "\n";
    for (int i = 65; i <= 65 + Number - 1; i++)
    {
        for (int j = 1; j <= i - 65 + 1; j++)
        {
            cout << char(i);
        }
        cout << "\n";
    }
}

int main()
{
    //Problem 15 - Letter Pattern
    PrintLetter(ReadPositiveNumber("Please Enter a positive Number: "));
}
