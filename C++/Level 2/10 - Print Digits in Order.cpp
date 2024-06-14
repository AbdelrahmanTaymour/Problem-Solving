#include <iostream>
using namespace std;

//Problem 10 - Print Digits in Order

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

int ReversedNumbers(int Number)
{
	int Remainder = 0, Reversed = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		Reversed = Reversed * 10 + Remainder;
	}
	return Reversed;
}

void PrintNumbeeInOrder(int Number)
{
	Number = ReversedNumbers(Number);
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
	//Problem 10 - Print Digits in Order
	PrintNumbeeInOrder(ReadPositiveNumber("Enter Positive Number: "));
}
