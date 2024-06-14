#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

//Problem 16 - Increase Date By One Day

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
	cout << "\nPlease enter a Month? ";
	cin >> Month;
	return Month;
}
short ReadYear()
{
	short Year;
	cout << "\nPlease enter a year? ";
	cin >> Year;
	return Year;
}
struct sDate
{
	short Day;
	short Month;
	short Year;
};
sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}
bool isLeapYear(short Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
short NumberOfDaysInAMonth(short Month, short year)
{
	if (Month < 0 || Month>12)
		return 0;

	short arrNumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(year) ? 29 : 28) : arrNumberOfDays[Month - 1];
}
bool isLastDayInMonth(short Day, short Month, short Year)
{
	return Day == NumberOfDaysInAMonth(Month, Year);
}
bool isLastMonthInYear(short Month)
{
	return Month == 12;
}
sDate IncreaseDateByOneDay(sDate Date)
{
	if (isLastDayInMonth(Date.Day, Date.Month, Date.Year))
	{
		Date.Day = 1;

		if (isLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}
		
	}
	else
		Date.Day++;

	return  Date;
}

int main()
{
	//Problem 16 - Increase Date By One Day

	sDate Date = ReadFullDate();
	Date = IncreaseDateByOneDay(Date);

	cout << "\nDate after add one day is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}
