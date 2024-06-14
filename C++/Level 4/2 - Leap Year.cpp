#pragma warning(disable : 4996)
#include <iostream>
#include <string>

using namespace std;

//Problem 2 - Leap Year

bool isLeapYear(short Year)
{
	if (Year % 400 == 0)
		return true;
	else if (Year % 4 == 0 && Year % 100 != 0)
	{
		return true;
	}
	return false;
}
short ReadYear()
{
	short Year;
	cout << "\nPlease enter a year to check? ";
	cin >> Year;
	return Year;
}

int main()
{
	//Problem 2 - Leap Year

	if (isLeapYear(ReadYear()))
		cout << "\nIt's a Leap year.\n";
	else
		cout << "\nIt's Not a Leap year.\n";
}
