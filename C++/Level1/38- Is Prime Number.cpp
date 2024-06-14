#include <iostream>
using namespace std;

//Problem 38 - Is Prime Number

enum enPrimeNotPrime{Prime = 1, NotPrime = 2};

float ReadPositiveNumber(string Message)
{
	float Number = 0;
	do 
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}
enPrimeNotPrime CheckPrimeNotPrime(int Number)
{
	int M = round(Number / 2);
	for (int Counter = 2;Counter <= M;Counter++) 
	{
		if (Number % Counter == 0)
			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}
void PrintNumberType(int Number)
{
	switch (CheckPrimeNotPrime(Number)) 
	{
	case enPrimeNotPrime::NotPrime:
		cout << endl << "The Number is not Prime" << endl;
		break;
	case enPrimeNotPrime::Prime:
		cout << endl << "The Number is Prime" << endl;
		break;
	}
}

int main()
{
	//Problem 38 - Is Prime Number
	PrintNumberType(ReadPositiveNumber("Please Enter a positive Number: "));
}
