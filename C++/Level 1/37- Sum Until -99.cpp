#include <iostream>
using namespace std;

//Problem 37 - Sum Until -99

float ReadNumber(string Message)
{
	float Number = 0;
	cout << Message;
	cin >> Number;
	return Number;
}
float SumNumbers() 
{
	int Sum = 0, Number = 0, Counter = 0;

	do
	{
		Number = ReadNumber("Please Enter Number " + to_string(Counter) + ": ");
		if (Number == -99)
			break;

		Sum += Number;
		Counter++;
	
	} while (Number != -99);

	return Sum;
}

int main()
{
	//Problem 37 - Sum Until -99
	cout << endl << "Result = " << SumNumbers() << endl;
}
