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
