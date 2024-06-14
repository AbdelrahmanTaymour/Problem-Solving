#pragma warning(disable : 4996)
#include <iostream>
#include <string>

using namespace std;


//Problem 4 - Number of Days - Hours - Minutes - Seconds In a Year

short ReadYear()
{
	short Year;
	cout << "\nPlease enter a year to check? ";
	cin >> Year;
	return Year;
}
bool isLeapYear(short Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
int NumberOfDaysInAYear(short year)
{
	return isLeapYear(year) ? 366 : 365;
}
int NumberOfHoursInAYear(short year)
{
	return NumberOfDaysInAYear(year) * 24;
}
int NumberOfMinutesInAYear(short year)
{
	return NumberOfHoursInAYear(year) * 60;
}
int NumberOfSecondsInAYear(short year)
{
	return NumberOfMinutesInAYear(year) * 60;
}

int main()
{
	//Problem 4 - Number of Days - Hours - Minutes - Seconds In a Year

	short Year = ReadYear();

	cout << "\nNumber of Days in Year [" << Year << "] is " << NumberOfDaysInAYear(Year);
	cout << "\nNumber of Hours in Year [" << Year << "] is " << NumberOfHoursInAYear(Year);
	cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutesInAYear(Year);
	cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSecondsInAYear(Year);

	system("pause>0");
}
