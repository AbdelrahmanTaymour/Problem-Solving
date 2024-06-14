#include <iostream>
using namespace std;

//Problem 4 - Perfect Numbers From 1 to N

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

bool isPerfectNumber(int Number)
{
	int sum = 0;
	for (int i = 1;i < Number;i++)
	{
		if (Number % i == 0)
			sum += i;
	}
	return Number == sum;
}

void PrintPerfectNumbersFrom1ToN(int Number)
{
	for (int i = 1;i <= Number;i++)
	{
		if (isPerfectNumber(i)) 
		{
			cout << i << endl;
		}
	}
}

int main()
{
	//Problem 4 - Perfect Numbers From 1 to N
	PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please Enter Positive Number: "));
}
