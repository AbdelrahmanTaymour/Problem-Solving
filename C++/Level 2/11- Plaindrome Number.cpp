#include <iostream>
using namespace std;

//Problem 11 - Plaindrome Number

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
int ReverseNumber(int Number)
{
    int Remainder = 0, Reversed = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Reversed = Reversed * 10 + Remainder;
    }
    return Reversed;
}

bool isPlaindrome(int Number)
{
    return Number == ReverseNumber(Number);
}

void PrintResult(int Number)
{
    if (isPlaindrome(Number))
        cout << "yes, It's a Plaindrome Number.\n";
    else
        cout << "No, It's Not a Plaindrome Number.\n";
}

int main()
{
    //Problem 11 - Plaindrome Number
    PrintResult(ReadPositiveNumber("Please Enter Positive Number to Check: "));
}
