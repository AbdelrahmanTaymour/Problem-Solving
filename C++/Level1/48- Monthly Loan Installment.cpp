#include <iostream>
using namespace std;

//Problem 48 - Monthly Loan Installment

float ReadPsitiveNumber(string Message)
{
	float Number = 0;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
float MonthlyInstallment(float LoanAmount, float HowManyMonths)
{
	return (float)LoanAmount / HowManyMonths;
}

int main()
{
	//Problem 48 - Monthly Loan Installment

	float LoanAmount = ReadPsitiveNumber("Please Enter Loan Amount: ");
	float HowManyMonths = ReadPsitiveNumber("How Many Months: ");

	cout << "\nMonthly Installment = " << MonthlyInstallment(LoanAmount, HowManyMonths) << endl;
}
