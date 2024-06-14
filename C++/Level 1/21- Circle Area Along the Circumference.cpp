#include <iostream>
using namespace std;

//Problem 21 - Circle Area Along the Circumference

float ReadCircumference() {
    float L;
    cout << "Enter Circumference: ";
    cin >> L;
    return L;
}

float CircleAreaByReadCircumference(float L) {
    const float PI = 3.141592653589793238;
    return pow(L, 2) / (4 * PI);
}

void PrintResult(float Area) {
    cout << "\nCircle Area: " << Area << endl;
}

int main()
{
    //Problem 21 - Circle Area Along the Circumference
    PrintResult(CircleAreaByReadCircumference(ReadCircumference()));
}
