#include <iostream>
using namespace std;

//Problem 25 - Read Until Age Between

int ReadAge() {
    cout << "Enter your Age between 18 and 45: ";
    int Age; cin >> Age;
    return Age;
}
bool ValidateNumberInRange(int Age, int From, int To) {
    return (Age >= From && Age <= To);
}
int ReadUntilAgeBetween(int From, int To) {
    int Age = 0;
    do
    {
        Age = ReadAge();

    } while (!ValidateNumberInRange(Age, From, To));

    return Age;
}
void PrintResult(int Age) {
    cout << Age << " is a Valid Age" << endl;
}

int main()
{
    //Problem 25 - Read Until Age Between
    PrintResult(ReadUntilAgeBetween(18, 45));
}
