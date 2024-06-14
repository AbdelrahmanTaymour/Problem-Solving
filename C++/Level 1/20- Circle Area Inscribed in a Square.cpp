#include <iostream>
using namespace std;

//Problem 20 - Circle Area Inscribed in a Square

float ReadSqureSide() {
    float A;
    cout << "Enter Squre Side: ";
    cin >> A;
    return A;
}
float CircleAreaInscribedInSqure(float A) {
    const float PI = 3.141592653589793238;
    return (PI * pow(A, 2)) / 4;
}
void PrintReasult(float Area) {
    cout << "\nCircle Area: " << Area << endl;
}

int main()
{
    //Problem 20 - Circle Area Inscribed in a Square
    PrintReasult(CircleAreaInscribedInSqure(ReadSqureSide()));
}
