#include <iostream>
using namespace std;

//Problem 47 - Loan Installment Months

float ReadPsitiveNumber(string Message)
{
	float Number = 0;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

float TotalMonth(float LoanAmount, float MonthlyInstullment)
{
	return (float)LoanAmount / MonthlyInstullment;
}

int main()
{
	//Problem 47 - Loan Installment Months
	float LoanAmount = ReadPsitiveNumber("Please Enter Loan Amount: ");
	float MonthlyInstallment = ReadPsitiveNumber("Please Enter Monthly Installment: ");
	cout << "\nTotal Month to pay = " << TotalMonth(LoanAmount, MonthlyInstallment) << endl;
}
