#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 21 - Fibonacci Series With Loop

void PrintFibonacciSeries(int Number)
{
    int Fibo = 0, Prev1 = 0, Prev2 = 1;
    cout << "1   ";
    for (int i = 2;i <= Number;i++)
    {
        Fibo = Prev1 + Prev2;
        cout << Fibo << "   ";
        Prev1 = Prev2;
        Prev2 = Fibo;
    }
}
int fib(int n) //LeetCode
{
    if (n < 2)
        return n;
    int Fib = 0;
    int Prev1 = 0, Prev2 = 1;
    for (int i = 2;i <= n;i++)
    {
        Fib = Prev1 + Prev2;
        Prev1 = Prev2;
        Prev2 = Fib;
    }
    return Fib;
}

int main()
{
    //Problem 21 - Fibonacci Series With Loop
    PrintFibonacciSeries(10);
}
