#include <iostream>
using namespace std;

//Problem 11 - Average Pass Fail
enum enPassFail {Pass = 1,Fail = 2};
void ReadNumbers(int& Mark1, int& Mark2, int& Mark3) {
	cout << "Enter Mark 1: ";
	cin >> Mark1;
	cout << "Enter Mark 2: ";
	cin >> Mark2;
	cout << "Enter Mark 3: ";
	cin >> Mark3;
}

int Sum3Marks(int Mark1, int Mark2, int Mark3) {
	return Mark1 + Mark2 + Mark3;
}

float CalculateAverage(int Mark1, int Mark2, int Mark3) {
	return (float)Sum3Marks(Mark1, Mark2, Mark3) / 3;
}

enPassFail CheckAverage(float Average) {
	if (Average >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

void PrintResult(float Average) {
	cout << "The Averge is: " << Average << endl;
	if (CheckAverage(Average) == enPassFail::Pass)
		cout << "Passed" << endl;
	else
		cout << "Faild" << endl;
}

int main()
{
	//Problem 11 - Average Pass Fail
	/*int Mark1, Mark2, Mark3;
	ReadNumbers(Mark1, Mark2, Mark3);
	PrintResult(CalculateAverage(Mark1, Mark2, Mark3));*/
}
