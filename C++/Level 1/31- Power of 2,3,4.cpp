#include <iostream>
using namespace std;

//Problem 31 - Power of 2,3,4

int ReadNumber() {
    cout << "Please Enter a Number: ";
    int Number; cin >> Number;
    return Number;
}
void PowerOf2_3_4(int Number) {
    int a, b, c;
    a = Number * Number;
    b = Number * Number * Number;
    c = Number * Number * Number * Number;
    cout << a << " " << b << " " << c << endl;
}

int main()
{
    //Problem 31 - Power of 2,3,4
    PowerOf2_3_4(ReadNumber());
}
