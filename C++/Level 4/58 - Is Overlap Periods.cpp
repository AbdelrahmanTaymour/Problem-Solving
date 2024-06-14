#include <vector>
#include <string>
#include <iostream>
using namespace std;

//Problem 58 - Is Overlap Periods

enum enDateCompare { Befor = -1, Equal = 0, After = 1 };
struct stDate
{
    short Year;
    short Month;
    short Day;
};
struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};
short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}
short ReadMonth()
{
    short Month;
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}
short ReadYear()
{
    short Year;
    cout << "Please enter a Year? ";
    cin >> Year;
    return Year;
}
stDate ReadFullDate()
{
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
        Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
            Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month ==
        Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false)
        : false;
}
bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}
enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Befor;
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}
bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{

    if (
        CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Befor
        ||
        CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After 
        )
        return false;
    else
        return true;

}
stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();
    return Period;
}

int main()
{
    //Problem 58 - Is Overlap Periods

    cout << "\nEnter Period 1:";
    stPeriod Period1 = ReadPeriod();
    cout << "\nEnter Period 2:";
    stPeriod Period2 = ReadPeriod();
    if (IsOverlapPeriods(Period1, Period2))
        cout << "\nYes, Periods Overlap\n";
    else
        cout << "\nNo, Periods do not Overlap\n";
}
