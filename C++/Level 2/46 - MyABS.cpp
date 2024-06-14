#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 46 - MyABS

float ReadNumber(string Messenge)
{
    float Number;
    cout << Messenge << endl;
    cin >> Number;
    return Number;
}
float MyABS(float Number)
{
    if (Number > 0)
        return Number;
    return Number * -1;
}

int main()
{
    //Problem 46 - MyABS

    float Number = ReadNumber("Enter Number: ");

    cout << "\nMyABS: " << MyABS(Number) << endl;
    cout << "C++ abs: " << abs(Number) << endl;
}
