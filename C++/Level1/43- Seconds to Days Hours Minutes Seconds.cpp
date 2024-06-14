#include <iostream>
using namespace std;

//Problem 43 - Seconds to Days Hours Minutes Seconds

struct strTaskDuration {
    int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}
strTaskDuration SecondsToTaskDuration(int TotalSeconds)
{
    strTaskDuration TaskDuration;
    const int SecondsPerDay = 24 * 60 * 60;
    const int SecondsPerHours = 60 * 60;
    const int SecondsPerMinuts = 60;

    int Remainder = 0;
    TaskDuration.NumberOfDays = floor(TotalSeconds / SecondsPerDay);
    Remainder = TotalSeconds % SecondsPerDay;
    TaskDuration.NumberOfHours = floor(Remainder / SecondsPerHours);
    Remainder = Remainder % SecondsPerHours;
    TaskDuration.NumberOfMinutes = floor(Remainder / SecondsPerMinuts);
    Remainder = Remainder % SecondsPerMinuts;
    TaskDuration.NumberOfSeconds = Remainder;

    return TaskDuration;

}
void PrintTaskDuration(strTaskDuration TaskDuration)
{
    cout << "\n";
    cout << TaskDuration.NumberOfDays << ":" << TaskDuration.NumberOfHours << ":" 
        << TaskDuration.NumberOfMinutes << ":" << TaskDuration.NumberOfSeconds << endl;
}

int main()
{
    //Problem 43 - Seconds to Days Hours Minutes Seconds
    int TotalSeconds = ReadPositiveNumber("Please Enter Total Seconds: ");
    PrintTaskDuration(SecondsToTaskDuration(TotalSeconds));
}
