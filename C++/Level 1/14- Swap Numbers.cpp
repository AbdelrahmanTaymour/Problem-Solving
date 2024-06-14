#include <iostream>
using namespace std;

//Problem 14 - Swap Numbers
void Read2Numbers(int& Number1, int& Number2) {
	cout << "Enter Number 1: ";
	cin >> Number1;
	cout << "Enter Number 2: ";
	cin >> Number2;
}
void Swap2Numbers(int& Number1, int& Number2) {
	int temp = Number1;
	Number1 = Number2;
	Number2 = temp;
}
void PrintNumbers(int Number1, int Number2) {
	cout << "\nEnter Number 1: " << Number1 << endl;
	cout << "Enter Number 2: " << Number2 << endl;
}

int main()
{
	//Problem 14 - Swap Numbers
	/*int Number1, Number2;
	Swap2Numbers(Number1, Number2);
	PrintNumbers(Number1, Number2);*/
}
