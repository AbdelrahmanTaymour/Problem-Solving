#include <iostream>
using namespace std;

//Problem 22 - Circle Area Inscribed in an Isosceles Triangle

void ReadTriangleData(float& A, float& B) {
    cout << "Enter Triangle side A: ";
    cin >> A;
    cout << "Enter Triangle side B: ";
    cin >> B;
}

float CircleAreaByTriangle(float A, float B) {
    const float PI = 3.141592653589793238;
    return PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));
}

void PrintResult(float Area) {
    cout << "\nCircle Area: " << Area << endl;
}

int main()
{
    //Problem 22 - Circle Area Inscribed in an Isosceles Triangle
    float A, B;
    ReadTriangleData(A, B);
    PrintResult(CircleAreaByTriangle(A, B));
}
