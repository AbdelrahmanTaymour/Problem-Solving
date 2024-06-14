#include <iostream>
using namespace std;

//Program 16 - Rectangle area Through Diagonal and side Area

void ReadNumbers(float& A, float& D) {
    cout << "Enter A: ";
    cin >> A;
    cout << "Enter D: ";
    cin >> D;
}

float RectangleAreaBySideAndDiagonal(float A, float D) {
    return A * sqrt(pow(D, 2) - pow(A, 2));
}

void PrintReasult(float Area) {
    cout << "\nArea: " << Area << endl;
}

int main()
{
    //Program 16 - Rectangle area Through Diagonal and side Area
    float A, D;
    ReadNumbers(A, D);
    PrintReasult(RectangleAreaBySideAndDiagonal(A, D));
}
