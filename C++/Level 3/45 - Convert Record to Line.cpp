#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

//Problem 45 - Convert Record to Line

struct sClint
{
    string NumberAccount;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

sClint ReadNewClint()
{
    sClint Clint;
    cout << "Enter Clint Data:\n\n";

    cout << "Enter Account Number? ";
    getline(cin, Clint.NumberAccount);

    cout << "Enter PinCode? ";
    getline(cin, Clint.PinCode);

    cout << "Enter Name? ";
    getline(cin, Clint.Name);

    cout << "Enter Phone? ";
    getline(cin, Clint.Phone);

    cout << "Enter Account Balance? ";
    cin >> Clint.AccountBalance;

    return Clint;
}

string ConvertRecordToLine(sClint Clint, string Sperater = "#//#")
{
    string Line = "";

    Line += Clint.NumberAccount + Sperater;
    Line += Clint.PinCode + Sperater;
    Line += Clint.Name + Sperater;
    Line += Clint.Phone + Sperater;
    Line += to_string(Clint.AccountBalance);

    return Line;
}

int main()
{
    //Problem 45 - Convert Record to Line

    sClint Clint = ReadNewClint();
    cout << "\n\n" << ConvertRecordToLine(Clint);
}
