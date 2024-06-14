#include <iostream>
using namespace std;

//Problem 18 - Circle Area

float ReadRadious() {
    float R;
    cout << "Enter R: ";
    cin >> R;
    return R;
}
float CircleArea(float R) {
    const float PI = 3.141592653589793238;
    return PI * pow(R, 2);
}
void PrintReasult(float Area) {
    cout << "\nArea: " << Area << endl;
}

int main()
{
    //Problem 18 - Circle Area
    PrintReasult(CircleArea(ReadRadious()));
}
