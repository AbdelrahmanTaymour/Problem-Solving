#include <iostream>
#include <string>
using namespace std;

string ReadName() 
{
	string Name;
	cout << "Please Enter your Name: ";
	getline(cin, Name);
	return Name;
}
