#include <iostream>
#include <string>
using namespace std;

// Problem 50 - MySqrt

float ReadNumber(string Messenge)
{
    float Number;
    cout << Messenge << endl;
    cin >> Number;
    return Number;
}
int MySqrt(float Number)
{
    return pow(Number, 0.5);
}


int main()
{
    // Problem 50 - MySqrt

    float Number = ReadNumber("Enter Number: ");

    cout << "\nMySqrt: " << MySqrt(Number) << endl;
    cout << "C++ Sqrt: " << sqrt(Number) << endl;
}
