#pragma warning(disable : 4996)
#include <iostream>
#include <string>

using namespace std;

//Problem 3 - Leap Year (One Line Of Code)

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

int main()
{
	//Problem 3 - Leap Year (One Line Of Code)

	if (isLeapYear(ReadYear()))
		cout << "\nIt's a Leap year.\n";
	else
		cout << "\nIt's Not a Leap year.\n";
}
