#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

//Problem 14 - Date1 Equals To Date2

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
bool isDate1EqualsToDate2(sDate Date1, sDate Date2)
{
	return Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day;
}

int main()
{
	//Problem 14 - Date1 Equals To Date2

	sDate Date1 = ReadFullDate();
	cout << endl;
	sDate Date2 = ReadFullDate();

	if (isDate1EqualsToDate2(Date1, Date2))
		cout << "\nYes, Date1 is Equal Date2.\n";
	else
		cout << "\nNo, Date1 is not Equal Date2.\n";
}
