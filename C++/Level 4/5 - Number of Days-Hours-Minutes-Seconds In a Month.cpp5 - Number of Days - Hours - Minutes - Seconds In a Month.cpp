#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

//Problem 5 - Number of Days-Hours-Minutes-Seconds In a Month

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

	if (Month == 2)
		return isLeapYear(year) ? 29 : 28;
	
	short arr31Days[7] = { 1,3,5,7,8,10,12 };

	for (int i = 1; i <= 7;i++)
	{
		if (arr31Days[i - 1] == Month)
			return 31;
	}

	return 30;
}
int NumberOfHoursInAMonth(short Month, short year)
{
	return NumberOfDaysInAMonth(Month, year) * 24;
}
int NumberOfMinutesInAMonth(short Month, short year)
{
	return NumberOfHoursInAMonth(Month, year) * 60;
}
int NumberOfSecondsInAMonth(short Month, short year)
{
	return NumberOfMinutesInAMonth(Month, year) * 60;
}

int main()
{
	//Problem 5 - Number of Days - Hours - Minutes - Seconds In a Month

	short Year = ReadYear();
	short Month = ReadMonth();
  
	cout << "\nNumber of Days in Month [" << Month << "] is " << NumberOfDaysInAMonth(Month, Year);
	cout << "\nNumber of Hours in Month [" << Month << "] is " << NumberOfHoursInAMonth(Month, Year);
	cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInAMonth(Month, Year);
	cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInAMonth(Month, Year);
  
	system("pause>0");
}
