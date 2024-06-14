#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

// Problem 15 - Last Day, Last Month

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
bool isLastDayInMonth(short Day, short Month, short Year)
{
	return Day == NumberOfDaysInAMonth(Month, Year);
}
bool isLastMonthInYear(short Month)
{
	return Month == 12;
}

int main()
{
	//Problem 15 - Last Day, Last Month

	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();

	if (isLastDayInMonth(Day, Month, Year))
		cout << "\nYes, it's last day in month.\n";
	else
		cout << "\nNo, it's Not last day in month.\n";

	if (isLastMonthInYear(Month))
		cout << "\nYes, it's last month in year.\n";
	else
		cout << "\nNo, it's Not last month in year.\n";
}
