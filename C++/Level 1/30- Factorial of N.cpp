#include <iostream>
using namespace std;

//Problem 30 - Factorial of N

int ReadPositiveNumber(string Message){
    int Number;
    do {
        cout << Message << ": ";
        cin >> Number;
    } while (Number<0);
    return Number;
}

int Factorial(int Number) {
    int F = 1;
    for (int i = Number; i >= 1;i--) {
        F *= i;
    }
    return F;
}

int main()
{
    //Problem 30 - Factorial of N
    cout << Factorial(ReadPositiveNumber("Please Enter a positive Number")) << endl;
}
