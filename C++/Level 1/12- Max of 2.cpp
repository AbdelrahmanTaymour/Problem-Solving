#include <iostream>
using namespace std;

//Problem 12 - Max of 2
void Read2Numbers(int& Number1, int& Number2) {
	cout << "Enter Number 1: ";
	cin >> Number1;
	cout << "Enter Number 2: ";
	cin >> Number2;
}

int MaxOf2Numbers(int Number1, int Number2) {
	if (Number1 > Number2) {
		return Number1;
	}
	else
		return Number2;
}

void PrintMax(int Max) {
	cout << "\nMax: " << Max;
}

int main()
{
	//Problem 12 - Max of 2
	/*int Number1, Number2;
	//Read2Numbers(Number1, Number2);
	PrintMaxOf2Numbers(MaxOf2Numbers(Number1, Number2));*/
}
