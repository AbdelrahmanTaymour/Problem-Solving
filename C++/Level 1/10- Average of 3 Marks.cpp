#include <iostream>
#include <string>
using namespace std;

//Problem #10 Average of 3 Marks
void Read3Marks(int& Mark1, int& Mark2, int& Mark3) {
    cout << "Enter Number 1: ";
    cin >> Mark1;
    cout << "Enter Number 2: ";
    cin >> Mark2;
    cout << "Enter Number 3: ";
    cin >> Mark3;
}
int SumOf3Marks(int Mark1, int Mark2, int Mark3) {
    return Mark1 + Mark2 + Mark3;
}
float CalculateAverage(int Mark1, int Mark2, int Mark3) {
    return (float)SumOf3Marks(Mark1, Mark2, Mark3) / 3;
}
void PrintAverage(float Average) {
    cout << "Average = " << Average << endl;
}

int main()
{
    //Problem #10 Average of 3 Marks
    /*int Mark1, Mark2, Mark3;
    Read3Marks(Mark1, Mark2, Mark3);
    PrintAverage(CalculateAverage(Mark1, Mark2, Mark3));*/
}
