#include <iostream>
using namespace std;

//Problem 13 - Number Pattern

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

void PrintNumberPattern(int Number)
{
    for (int i = 1;i <= Number;i++)
    {
        for (int j = 1;j <= i;j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

int main()
{
    //Problem 13 - Number Pattern
    PrintNumberPattern(ReadPositiveNumber("Please Enter Positive Number: "));
}
