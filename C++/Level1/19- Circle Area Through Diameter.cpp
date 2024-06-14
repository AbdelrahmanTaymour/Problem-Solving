#include <iostream>
using namespace std;

//Problem 19 - Circle Area Through Diameter

float ReadDiameter() {
    float D;
    cout << "Enter D: ";
    cin >> D;
    return D;
}
float CircleAreaByDiameter(float D) {
    const float PI = 3.141592653589793238;
    return (pow(D, 2) * PI) / 4;
}
void PrintReasult(float Area) {
    cout << "\nCircle Area: " << Area << endl;
}

int main()
{
    //Problem 19 - Circle Area Through Diameter
    PrintReasult(CircleAreaByDiameter(ReadDiameter()));
}
