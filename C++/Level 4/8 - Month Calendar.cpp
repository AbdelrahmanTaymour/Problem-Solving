#pragma warning(disable : 4996)
#include <iostream>
#include <string>
using namespace std;

//Problem 8 - Month Calendar

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
short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string MonthShortName(short MonthNumber)
{
	string Months[12] = { "Jan", "Feb", "Mar",
	"Apr", "May", "Jun",
	"Jul", "Aug", "Sep",
	"Oct", "Nov", "Dec"
	};
	return (Months[MonthNumber - 1]);
}
void PrintMonthCalendar(short Month, short Year)
{

	int current = DayOfWeekOrder(1, Month, Year);
	int NumberOfDaysInMonth = NumberOfDaysInAMonth(Month, Year);

	printf("\n _______________%s_______________\n\n", MonthShortName(Month).c_str());
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
	int i;
	for (i = 0; i < current; i++)
		printf(" ");

	for (int j = 1;j <= NumberOfDaysInMonth;j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
	printf("\n _________________________________\n");
}

int main()
{
	//Problem 8 - Month Calendar

	short Year = ReadYear();
	short Month = ReadMonth();
	PrintMonthCalendar(Month, Year);
}
