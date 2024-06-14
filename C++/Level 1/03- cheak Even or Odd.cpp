//Problem #3  cheak Even or Odd

#include <iostream>
#include <string>
using namespace std;

enum enNumberType { Odd = 1, Even = 2 };

int ReadNumbre() {
	int Number;
	cout << "Please Enter a Number: ";
	cin >> Number;
	return Number;
}

enNumberType CheakNumberType(int Number) {
	int result = Number % 2;
	if (result == 0) {
		return enNumberType::Even;
	}
	else {
		return enNumberType::Odd;
	}
}

void PrintNumberType(enNumberType NumberType) {
	if (NumberType == enNumberType::Even) {
		cout << "The Number is Even" << endl;
	}
	else {
		cout<< "The Number is Odd" << endl;
	}
}
