#include <iostream>
#include <string>
using namespace std;

//Problem #7 Half Number
int ReadNumber() {
    int Number;
    cout << "Please Enter a Number: ";
    cin >> Number;
    return Number;
}
float CalculateHalfNumber(int Number) {
    return (float) Number / 2;
}
void PrintResult(int Number) {
    string result = "Half of " + to_string(Number) + " is: " + to_string(CalculateHalfNumber(Number));
    cout << endl << result << endl;
}

int main()
{
    //Problem #7 Half Number
    //PrintResult(ReadNumber());
}
