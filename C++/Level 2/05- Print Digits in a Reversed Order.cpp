#include <iostream>
using namespace std;

//Problem 5 - Print Digits in a Reversed Order

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

void PrintDigits(int Number)
{
	int Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		cout << Remainder << endl;
	}
}

int main()
{
	//Problem 5 - Print Digits in a Reversed Order
	PrintDigits(ReadPositiveNumber("Please Enter Positive Number: "));
}
