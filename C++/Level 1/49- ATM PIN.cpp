#include <iostream>
using namespace std;

//Problem 49 - ATM PIN

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
	do
	{
		PinCode = ReadPinCode();
		if (PinCode == "1234")
		{
			return 1;
		}
		else 
		{
			cout << "\nWrong PIN\n";
			system("color 4F");
		}

	} while (PinCode != "1234");

	return 0;
}

int main()
{
	//Problem 49 - ATM PIN
	
	if (Login())
	{
		system("color 2F");
		cout << "\nYour account balance = " << 7500 << '\n';
	}
}
