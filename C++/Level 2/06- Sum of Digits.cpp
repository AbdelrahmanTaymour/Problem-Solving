#include <iostream>
using namespace std;

//Problem 6 - Sum of Digits

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

int SumOfDigits(int Number)
{
	int Remainder = 0, sum = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		sum += Remainder;
	}
	return sum;
}

int main()
{
	//Problem 6 - Sum of Digits
	cout << "\nSum of Digits = " <<
		SumOfDigits(ReadPositiveNumber("Please Enter Positive Number: ")) << endl;
}
