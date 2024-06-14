#include <iostream>
#include <string>
using namespace std;

//Problem #9 Sum of 3 numbers
void Read3Number(int& Num1, int& Num2, int& Num3) {
    cout << "Enter Number 1: ";
    cin >> Num1;
    cout << "Enter Number 2: ";
    cin >> Num2;
    cout << "Enter Number 3: ";
    cin >> Num3;
}
int SumOf3Nums(int Num1, int Num2, int Num3) {
    return Num1 + Num2 + Num3;
}
void PrintSum3Nums(int Total) {
    cout << "Sum = " << Total << endl;
}

int main()
{
    //Problem #9 Sum of 3 numbers
    /*
    int Num1, Num2, Num3;
    Read3Number(Num1, Num2, Num3);
    PrintSum3Nums(SumOf3Nums(Num1, Num2, Num3));
    */

}
