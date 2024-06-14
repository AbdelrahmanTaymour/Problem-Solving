#include <iostream>
using namespace std;

//Problem 41 - Weeks and Days

float ReadPositiveNumber(string Message)
{
    float Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}
float HoursToDays(float NumberOfHours)
{
    return (float)NumberOfHours / 24;
}
float HoursToWeeks(float NumberOfHours)
{
    return (float)NumberOfHours / 24 / 7;
}
float DaysToWeeks(float NumberOfDays)
{
    return (float)NumberOfDays / 7;
}

int main()
{
    
    //Problem 41 - Weeks and Days

    float NumberOfHours = ReadPositiveNumber("Please Enter the Number of hours: ");
    float NumberOfDays = HoursToDays(NumberOfHours);
    float NumberOfWeeks = HoursToWeeks(NumberOfHours);

    cout << endl;
    cout << "Total hours: " << NumberOfHours << endl;
    cout << "Total Days: " << NumberOfDays << endl;
    cout << "Total Weeks: " << NumberOfWeeks << endl;
}
