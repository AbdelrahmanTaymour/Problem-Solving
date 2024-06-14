#include <iostream>
using namespace std;

//Problem 8 - Digit Frequency

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

int CountDigitFrequency(short DigitToCheck, int Number)
{
	int Remainder = 0, FreqCount = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;

		if (Remainder == DigitToCheck)
			FreqCount++;
	}
	return FreqCount;
}

int main()
{
	//Problem 8 - Digit Frequency
	int Number = ReadPositiveNumber("Please Enter the Number: ");
	short DigitToCheck = ReadPositiveNumber("Please Enter one Number to check: ");

	cout << "Digit " << DigitToCheck << " Frequancy is " 
		<< CountDigitFrequency(DigitToCheck, Number) << " Time(s)." << endl;
}
