#include <vector>
#include <string>
#include <iostream>
using namespace std;

//Problem 57 - Compare Date Function

enum enDateCompare {Befor = -1, Equal = 0, After = 1};
struct stDate
{
    short Year;
    short Month;
    short Day;
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

int main()
{
    //Problem 57 - Campare Date Function

    cout << "\nEnter Date1:";
    stDate Date1 = ReadFullDate();
    cout << "\nEnter Date2:";
    stDate Date2 = ReadFullDate();

    cout << "\nCompare Result = " << CompareDates(Date1, Date2);
}
