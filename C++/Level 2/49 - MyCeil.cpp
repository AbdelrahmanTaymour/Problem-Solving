#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 49 - MyCeil

float ReadNumber(string Messenge)
{
    float Number;
    cout << Messenge << endl;
    cin >> Number;
    return Number;
}
float GetFractionPart(float Number)
{
    return Number - (int)Number;
}
int MyCeil(float Number)
{
    if (GetFractionPart(Number) > 0)
    {
        if (Number > 0)
            return Number + 1;
        else
            return Number;
    }
    else
        return Number;
}

int main()
{
    //Problem 49 - MyCeil

    float Number = ReadNumber("Enter Number: ");

    cout << "\nMyCeil: " << MyCeil(Number) << endl;
    cout << "C++ round: " << ceil(Number) << endl;
}
