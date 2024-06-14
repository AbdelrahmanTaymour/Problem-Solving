#include <iostream>
using namespace std;

//Problem 44 - Day Of Week

enum enDayOfWeek {
    Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7
};
int ReadNumberInRange(string Message, int From, int To)
{
    int Number = 0;
    
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number < From || Number > To);

    return Number;
}
enDayOfWeek ReadDayOfWeek()
{
    return (enDayOfWeek)ReadNumberInRange("Please Enter a Number of day between 1 to 7: ", 1, 7);
}
string GetDayOfWeek(enDayOfWeek Day) {
    switch (Day)
    {
    case enDayOfWeek::Sunday:
        return "It's Sunday";
    case enDayOfWeek::Monday:
        return "It's Monday";
    case enDayOfWeek::Tuesday:
        return "It's Tuesday";
    case enDayOfWeek::Wednesday:
        return "It's Wedensday";
    case enDayOfWeek::Thursday:
        return "It's Thursday";
    case enDayOfWeek::Friday:
        return "It's Friday";
    case enDayOfWeek::Saturday:
        return "It's Saturday";
    default:
        "Not a valid Day";
    }
}

int main()
{
    //Problem 44 - Day Of Week
    cout << GetDayOfWeek(ReadDayOfWeek()) << endl;
}
