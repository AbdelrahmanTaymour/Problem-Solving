#include <iostream>
using namespace std;

//Problem 2 - Prime Numbers From 1 to N

enum enPrimeNotPrime {
	Prime = 1, NotPrime = 2
};

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

enPrimeNotPrime CheckPrimeNotPrime(int Number)
{
	int M = Number / 2;
	for (int i = 2;i <= M;i++) 
	{
		if (Number % i == 0)
			return enPrimeNotPrime::NotPrime;
	}
	
	return enPrimeNotPrime::Prime;
}

void PrintPrimeNumbers(int Number)
{
	cout << "\nPrint prime Number From 1 to " << Number << " are: \n";

	for (int i = 1;i <= Number;i++)
	{
		if (CheckPrimeNotPrime(i) == enPrimeNotPrime::Prime)
			cout << i << endl;
	}
}

int main()
{
	//Problem 2 - Prime Numbers From 1 to N
	PrintPrimeNumbers(ReadPositiveNumber("Please Ente Positive Number: "));
}
