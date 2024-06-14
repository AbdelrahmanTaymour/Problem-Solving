#include <iostream>
using namespace std;

//Problem 9 - Count Frequency For each Digit

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
void PrintAllDigitsFrequencey(int Number)
{
	for (int i = 0;i < 10;i++) 
	{
		short DigitFrecquencey = 0;
		DigitFrecquencey = CountDigitFrequency(i, Number);

		if (DigitFrecquencey > 0) 
		{
			cout << "Digit " << i << " Frequancy is "
				<< DigitFrecquencey << " Time(s)." << endl;
		}
	}
}

int main()
{
	//Problem 9 - Count Frequency For each Digit
	int Number = ReadPositiveNumber("Please Enter Positive Number: ");
	PrintAllDigitsFrequencey(Number);
}
