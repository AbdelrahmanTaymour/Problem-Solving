#pragma warning(disable : 4996)
#include <iostream>
#include <string>

using namespace std;

//Problem 6 - Number of Days in a Month Short Logic

short ReadYear()
{
	short Year;
	cout << "\nPlease enter a year to check? ";
	cin >> Year;
	return Year;
}
short ReadMonth()
{
	short Year;
	cout << "\nPlease enter a month to check? ";
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

int main()
{
	//Problem 6 - Number of Days in a Month Short Logic

	short Year = ReadYear();
	short Month = ReadMonth();
	cout << "\nNumber of Days in Month [" << Month << "] is " << NumberOfDaysInAMonth(Month, Year);
}
