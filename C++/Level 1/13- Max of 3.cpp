#include <iostream>
using namespace std;

//Problem 13 - Max of 3
void Read3Numbers(int& Number1, int& Number2, int& Number3) {
	cout << "Enter Number 1: ";
	cin >> Number1;
	cout << "Enter Number 2: ";
	cin >> Number2;
	cout << "Enter Number 3: ";
	cin >> Number3;
}

int MaxOf3Numbers(int Number1, int Number2, int Number3) {
	if (Number1 > Number2)
		if (Number1 > Number3)
			return Number1;
		else
			return Number3;
	else
		if (Number2 > Number3)
			return Number2;
		else 
			return Number3;
}

void PrintMaxOf3Numbers(int Max) {
	cout << "The Max Number is: " << Max << endl;
}

int main()
{
	//Problem 13 - Max of 3
	/*int Number1, Number2, Number3;
	Read3Numbers(Number1, Number2, Number3);
	PrintMaxOf3Numbers(MaxOf3Numbers(Number1, Number2, Number3));*/
}
