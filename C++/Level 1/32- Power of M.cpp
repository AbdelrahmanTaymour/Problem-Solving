#include <iostream>
using namespace std;

//Problem 32 - Power of M

int ReadNumber() {
    cout << "Please Enter a Number: ";
    int Number; cin >> Number;
    return Number;
}
int ReadPower() {
    cout << "Please Enter the power: ";
    int Pow; cin >> Pow;
    return Pow;
}
int Power(int Number, int Power) {
    if (Power == 0)
        return 1;

    int P = 1;
    for (int i = 1;i <= Power;i++) {
        P *= Number;
    }
    return P;
}

int main()
{
    //Problem 32 - Power of M
    cout << "\nResult: " << Power(ReadNumber(), ReadPower()) << endl;
}
