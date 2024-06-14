#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 22 - Fibonacci Series With Recursion

void PrintFibonacciSeries(int Number, int Prev1, int Prev2)
{
    int Fib = 0;
    if (Number > 0)
    {
        Fib = Prev1 + Prev2;
        Prev1 = Prev2;
        Prev2 = Fib;
        cout << Fib << "   ";
        PrintFibonacciSeries(Number - 1, Prev1, Prev2);
    }
}

int main()
{
    //Problem 22 - Fibonacci Series With Recursion
    PrintFibonacciSeries(10, 1, 0);
}
