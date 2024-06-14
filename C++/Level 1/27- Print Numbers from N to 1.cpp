#include <iostream>
using namespace std;

//Problem 27 - Print Numbers from N to 1

int ReadNumber() {
    cout << "Enter Number: ";
    int Num;cin >> Num;
    return Num;
}
void PrintRangeFromNto1_UsingWhile(int N) {
    int counter = N;
    cout << "Range painted using While loop:" << endl;
    while (counter >= 1 ) {
        cout << counter << endl;
        counter--;
    }
}
void PrintRangeFromNto1_UsingDoWhile(int N) {
    int counter = N;
    cout << "Range painted using Do-While loop:" << endl;
    do {
        cout << counter << endl;
        counter--;
    } while (counter >= 1);
}
void PrintRangeFromNto1_UsingFor(int N) {
    cout << "Range painted using For loop:" << endl;
    for (int counter = N;counter >= 1;counter--)
        cout << counter << endl;
}

int main()
{
    //Problem 27 - Print Numbers from N to 1
    int Number = ReadNumber();
    PrintRangeFromNto1_UsingWhile(Number);
    PrintRangeFromNto1_UsingDoWhile(Number);
    PrintRangeFromNto1_UsingFor(Number);
}
