#include <iostream>
#include <string>
using namespace std;

void PrintTableHeader() 
{
	cout << "\n\n\t\t\tMultiplication Table From 1 to 10\n\n";
	cout << "\t";
	for (int i = 1;i <= 10;i++)
	{
		cout << i << "\t";
	}
	cout << "\n____________________________________________________________________________________\n";
}
string ColumSperator(int i)
{
	if (i < 10)
		return "   |";
	else
		return "  |";
}
void PrintMultipicationTable()
{
	PrintTableHeader();
	for(int i = 1;i<=10;i++)
	{
		cout << " " << i << ColumSperator(i) << "\t";

		for (int j = 1;j <= 10;j++)
		{
			cout << i * j << "\t";
		}
		cout << endl;
	}
}
