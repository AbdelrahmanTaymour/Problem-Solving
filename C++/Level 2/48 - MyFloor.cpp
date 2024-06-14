#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 48 - MyFloor

float ReadNumber(string Messenge)
{
    float Number;
    cout << Messenge << endl;
    cin >> Number;
    return Number;
}
int MyFloor(float Number)
{
    if (Number >= 0)
        return Number;
    else
        return Number - 1;
}

int main()
{
    //Problem 48 - MyFloor

    float Number = ReadNumber("Enter Number: ");

    cout << "\nMyFloor: " << MyFloor(Number) << endl;
    cout << "C++ round: " << floor(Number) << endl;
}
