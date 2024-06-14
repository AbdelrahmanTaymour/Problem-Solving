#include <iostream>
using namespace std;

//Problem 50 - ATM PIN 3 Times

string ReadPinCode()
{
	string PinCode;
	cout << "Please Enter PIN Code:\n";
	cin >> PinCode;
	return PinCode;
}
bool Login()
{
	string PinCode;
	int Counter = 3;
	do
	{
		Counter--;
		PinCode = ReadPinCode();
		if (PinCode == "1234")
		{
			return 1;
		}
		else
		{
			system("color 4F");
			cout << "\nWrong PIN, you have "<<Counter<<" more try...\n";
		}

	} while (Counter >= 1 && PinCode != "1234");

	return 0;
}

int main()
{
	//Problem 50 - ATM PIN 3 Times

	if (Login())
	{
		system("color 2F");
		cout << "\nYour account balance = " << 7500 << '\n';
	}
	else
	{
		cout << "\nYour card blocked, call the Bank for help.\n";
	}
}
