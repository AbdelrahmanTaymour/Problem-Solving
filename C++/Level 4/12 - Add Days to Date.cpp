#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

//Problem 12 - Add Days to Date

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
short ReadAddDays()
{
	short AddDays = 0;
	cout << "\nHow many days to add? ";
	cin >> AddDays;
	return AddDays;
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
sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}
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
sDate DateAddDays(short days, sDate Date)
{
	short RemainingDay = days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
	short MonthDay = 0;
	Date.Month = 1;

	while (true)
	{
		MonthDay = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (RemainingDay > MonthDay)
		{
			RemainingDay -= MonthDay;
			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
		}
		else
		{
			Date.Day = RemainingDay;
			break;
		}
	}
	return Date;
}

int main()
{
	//Problem 12 - Add Days to Date

	sDate Date = ReadFullDate();
	short Days = ReadAddDays();

	Date = DateAddDays(Days, Date);

	cout << "\nDate after adding [" << Days << "] days is ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}
