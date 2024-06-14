#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

//Problem 11 - Date from Day Order In a year

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
short NumberOfDaysFromTheBeginingOfTheYear(short Days, short Month, short Year)
{
	int NumberOfDays = 0;

	for (int i = 1;i < Month;i++)
	{
		NumberOfDays += NumberOfDaysInAMonth(i, Year);
	}

	NumberOfDays += Days;
	return NumberOfDays;
}
struct sDate
{
	short Day;
	short Month;
	short Year;
};
sDate DateFromDayOrderInAYear(short days, short year)
{
	sDate Date;
	Date.Year = year;
	Date.Month = 1;

	short RemainingDays = days;
	short MonthDays = 0;

	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, year);
		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}

int main()
{
	//Problem 11 - Date from Day Order In a year

	short Days = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short TotalDays = NumberOfDaysFromTheBeginingOfTheYear(Days, Month, Year);

	cout << "\nNumber of Days from the beginning of year is: " << TotalDays << endl;

	sDate Date = DateFromDayOrderInAYear(TotalDays, Year);
	cout << "\nDate for [" << TotalDays << "] is ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}
