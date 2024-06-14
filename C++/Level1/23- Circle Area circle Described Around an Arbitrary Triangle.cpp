#include <iostream>
using namespace std;

//Problem 23 - Circle Area circle Described Around an Arbitrary Triangle

void ReadTriangleData(float& A, float& B,float& C) {
    cout << "Enter Triangle side A: ";
    cin >> A;
    cout << "Enter Triangle side B: ";
    cin >> B;
    cout << "Enter Triangle side C: ";
    cin >> C;
}
float CircleAreaByTriangle(float A, float B, float C) {
    const float PI = 3.141592653589793238;

    float P = (A + B + C) / 2;
    float T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));

    return PI * pow(T, 2);
}
void PrintResult(float Area) {
    cout << "\nCircle Area: " << Area << endl;
}

int main()
{
    //Problem 23 - Circle Area circle Described Around an Arbitrary Triangle
    float A, B, C;
    ReadTriangleData(A, B, C);
    PrintResult(CircleAreaByTriangle(A, B, C));
}
