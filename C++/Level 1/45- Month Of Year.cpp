#include <iostream>
using namespace std;

//Problem 45 - Month Of Year

enum enMonthOfYear {
    January = 1, February = 2, March = 3, 
    April = 4, May = 5, June = 6, July = 7, 
    August = 8, September = 9, October = 10, 
    November = 11, December = 12
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
enMonthOfYear ReadMonthOfYear()
{
    return (enMonthOfYear)ReadNumberInRange("Please Enter a Number of day between 1 to 12: ", 1, 12);
}
string GetMonthOfYear(enMonthOfYear Month)
{
    switch(Month)
    {
    case enMonthOfYear::January:
        return "It's Juanuary";
    case enMonthOfYear::February:
        return "It's February";
    case enMonthOfYear::March:
        return "It's March";
    case enMonthOfYear::April:
        return "It's April";
    case enMonthOfYear::May:
        return "It's May";
    case enMonthOfYear::June:
        return "It's June";
    case enMonthOfYear::July:
        return "It's July";
    case enMonthOfYear::August:
        return "It's August";
    case enMonthOfYear::September:
        return "It's September";
    case enMonthOfYear::October:
        return "It's October";
    case enMonthOfYear::November:
        return "It's November";
    case enMonthOfYear::December:
        return "It's December";
    default:
        return "Wrong Month";
    }
}

int main()
{
    //Problem 45 - Month Of Year
    cout << GetMonthOfYear(ReadMonthOfYear()) << endl;
}
