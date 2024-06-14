#include <iostream>
using namespace std;

//Problem 39 - Pay Remainder

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
float CalculatRemainder(float TotalBill, float TotalCashPaid) {
	return TotalCashPaid - TotalBill;
}

int main()
{
	//Problem 39 - Pay Remainder

	float TotalBill = ReadlPositiveNumber("Please Enter Total Bill: ");
	float TotalCashPaid = ReadPositiveNumber("Please Enter Total Cash Paid: ");

	cout << endl;
	cout << "Total Bill = " << TotalBill << endl;
	cout << "Total Cach Paid = " << TotalCashPaid << endl;
	cout << "*****************************" << endl;
	cout << "The Remainder = " << CalculatRemainder(TotalBill, TotalCashPaid) << endl;
}
