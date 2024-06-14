#include <iostream>
using namespace std;

//Problem 29 - Print Sum Even Numbers from 1 to N

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
int SumEven_UsingFor(int Number) {
    int sum = 0;
    for (int i = 1;i <= Number;i++) {
        if (CheckEvenOrOdd(i) == enEvenOrOdd::Even)
            sum += i;
    }
    return sum;
}
void PrintSumEven(int Sum) {
    cout << "\nSum Even: " << Sum << endl;
}

int main()
{
    //Problem 29 - Print Sum Even Numbers from 1 to N
    int Number = ReadNumber();
    PrintSumEven(SumEven_UsingFor(Number));
}
