#include <iostream>
using namespace std;

//Problem 3 - Perfect Number

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

void PrintResult(int Number)
{
	if (isPerfectNumber(Number))
		cout << Number << " is Perfect Number" << endl;
	else
		cout << Number << " is Not Perfect Number" << endl;
}

int main()
{
	//Problem 3 - Perfect Number
	PrintResult(ReadPositiveNumber("Please Enter Positive Number: "));
}
