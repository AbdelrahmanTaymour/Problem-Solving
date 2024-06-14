#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

//Problem 10 - Days from the beginning of year

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

int main()
{
	//Problem 10 - Days from the beginning of year

	short Days = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();

	cout << "\nNumber of Days from the beginning of year is: " 
		<< NumberOfDaysFromTheBeginingOfTheYear(Days, Month, Year) << endl;
}
