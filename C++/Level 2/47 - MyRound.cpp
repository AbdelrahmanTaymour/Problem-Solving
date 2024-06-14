#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 47 - MyRound

float ReadNumber(string Messenge)
{
    float Number;
    cout << Messenge << endl;
    cin >> Number;
    return Number;
}

float GetFractionPart(float Number)
{
    return Number - int(Number);
}
int MyRound(float Number)
{
    int IntPart = int(Number);

    float FractionsPart = GetFractionPart(Number);
    if (abs(FractionsPart) >= .5)
    {
        if (Number > 0)
            return ++IntPart;
        else
            return --IntPart;
    }
    else
    {
        return IntPart;
    }
}

int main()
{
    //Problem 47 - MyRound

    float Number = ReadNumber("Enter Number: ");

    cout << "\MyRound: " << MyRound(Number) << endl;
    cout << "C++ round: " << round(Number) << endl;
}
