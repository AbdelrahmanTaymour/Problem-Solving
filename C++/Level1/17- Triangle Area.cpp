#include <iostream>
using namespace std;

//Problem 17 - Triangle Area

void ReadNumbers(float& A, float& H) {
    cout << "Enter A: ";
    cin >> A;
    cout << "Enter H: ";
    cin >> H;
}
float TriangleArea(float A, float H) {
    return (A / 2) * H;
}
void PrintReasult(float Area) {
    cout << "\nArea: " << Area << endl;
}

int main()
{
    //Problem 17 - Triangle Area
    float A, H;
    ReadNumbers(A, H);
    PrintReasult(TriangleArea(A, H));
}
