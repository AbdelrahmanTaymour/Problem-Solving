#include <iostream>
using namespace std;

//Problem 24 - Validate Age Between 18 and 45

int ReadAge() {
    cout << "Enter your Age: ";
    int Age; cin >> Age;
    return Age;
}
bool ValidateNumberInRange(int Age, int From, int To) {
    return (Age >= From && Age <= To);
}
void PrintResult(int Age) {
    if (ValidateNumberInRange(Age, 18, 45))
        cout << Age << " is a Valid Age" << endl;
    else                 
        cout << Age << " is a InValid Age" << endl;
}

int main()
{
    //Problem 24 - Validate Age Between 18 and 45
    PrintResult(ReadAge());
}
