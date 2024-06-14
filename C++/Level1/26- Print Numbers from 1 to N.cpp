#include <iostream>
using namespace std;

//Problem 26 - Print Numbers from 1 to N

int ReadNumber() {
    cout << "Enter Number: ";
    int Num;cin >> Num;
    return Num;
}

void PrintRangeFrom1toN_UsingWhile(int N) {
    int counter = 0;
    cout << "Range painted using While loop:" << endl;
    while (counter < N) {
        counter++;
        cout << counter << endl;
    }
}

void PrintRangeFrom1toN_UsingDoWhile(int N) {
    int counter = 0;
    cout << "Range painted using Do-While loop:" << endl;
    do {
        counter++;
        cout << counter << endl;
    } while (counter < N);
}

void PrintRangeFrom1toN_UsingFor(int N) {
    cout << "Range painted using For loop:" << endl;
    for(int counter = 1;counter <=N;counter++)
        cout << counter << endl;
}

int main()
{
    //Problem 26 - Print Numbers from 1 to N
    int Number = ReadNumber();
    PrintRangeFrom1toN_UsingWhile(Number);
    PrintRangeFrom1toN_UsingDoWhile(Number);
    PrintRangeFrom1toN_UsingFor(Number);
}
