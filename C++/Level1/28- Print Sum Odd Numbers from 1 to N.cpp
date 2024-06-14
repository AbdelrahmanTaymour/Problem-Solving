#include <iostream>
using namespace std;

//Problem 28 - Print Sum Odd Numbers from 1 to N

enum enEvenOrOdd { Odd = 1, Even = 2 };

int ReadNumber() {
    cout << "Enter Number: ";
    int Num;cin >> Num;
    return Num;
}
enEvenOrOdd CheckEvenOrOdd(int Number) {
    if (Number % 2 == 0)
        return enEvenOrOdd::Even;
    else
        return enEvenOrOdd::Odd;
}
int SumOdd_UsingFor(int Number) {
    int sum = 0;
    for (int i = 1;i <= Number;i++) {
        if (CheckEvenOrOdd(i) == enEvenOrOdd::Odd)
            sum += i;
    }
    return sum;
}
void PrintSumOdd(int Sum) {
    cout << "\nSum Odd: " << Sum << endl;
}

int main()
{
    //Problem 28 - Print Sum Odd Numbers from 1 to N
    int Number = ReadNumber();
    PrintSumOdd(SumOdd_UsingFor(Number));
}
