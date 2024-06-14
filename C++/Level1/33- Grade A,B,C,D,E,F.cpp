#include <iostream>
using namespace std;

//Problem 33 - Grade A,B,C,D,E,F

int ReadNumberInRange(int From, int To) {

    int Number;

    do
    {
        cout << "Please enter a Grade between " << From << " and " << To << endl;
        cin >> Number;

    } while (Number < From || Number > To);

    return Number;
}
char GetGradeLetter(int Grade) {
    if (Grade >= 90)
        return 'A';
    else if (Grade >= 80)
        return 'B';
    else if (Grade >= 70)
        return 'C';
    else if (Grade >= 60)
        return 'D';
    else if (Grade >= 50)
        return 'E';
    else
        return 'F';
}

int main()
{
    //Problem 33 - Grade A,B,C,D,E,F
    cout << "Result: " << GetGradeLetter(ReadNumberInRange(0, 100)) << endl;
}
