#include <iostream>
#include <string>
using namespace std;

//Problem 36 - Simple Calculator

enum enOperationType {
	Add = '+', Subtract = '-', Multiply = '*', Divide = '/'
};
float ReadNumber(string Message) 
{
	float Number = 0;
	cout << Message;
	cin >> Number;
	return Number;
}
enOperationType ReadOpType() 
{
	char OP = '+';
	cout << "Please enter Operation Type ( + , - , * , /): ";
	cin >> OP;
	return (enOperationType)OP;
}
float Calculate(float Number1, float Number2, enOperationType OpType)
{
	switch (OpType) {
	case enOperationType::Add:
			return Number1 + Number2;
	case enOperationType::Subtract:
		return Number1 - Number2;
	case enOperationType::Multiply:
		return Number1 * Number2;
	case enOperationType::Divide:
    {
      if(Number2 == 0)
        Number2 = 1;
		  return Number1 / Number2;
    }
	default:
		return Number1 + Number2;
	}
}

int main()
{
	//Problem 36 - Simple Calculator

	float Number1 = ReadNumber("Please Enter the First Number: ");
	float Number2 = ReadNumber("Please Enter the Second Number: ");
	enOperationType OpType = ReadOpType();

	cout << endl << "Result = " << Calculate(Number1, Number2, OpType) << endl;
}
