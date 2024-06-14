#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

//Problem 7 - Day Name

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string DayShortName(short NumberOfDay)
{
	string arr[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Satrday" };
	return arr[NumberOfDay];
}
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

int main()
{
	//Problem 7 - Day Name

	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();
  
	cout << "\nDate :" << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order : " << DayOfWeekOrder(Day, Month, Year);
	cout << "\nDay Name : " << DayShortName(DayOfWeekOrder(Day, Month, Year));
}
