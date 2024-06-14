#include <iostream>
using namespace std;

//Problem 7 - Reverse Number

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

int main()
{
	//Problem 7 - Reverse Number
	cout << "\nReversed Number is " <<
		ReversedNumbers(ReadPositiveNumber("Please Enter Positive Number: ")) << endl;
}
