#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

//Problem 46 - Convert Line Data to Record

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};
vector<string> SpirateData(string Line, string Derim)
{
    vector<string> vSprate;

    int pos = 0;
    string sWord = "";


    while ((pos = Line.find(Derim)) != std::string::npos)
    {
        sWord = Line.substr(0, pos);
        if (sWord != "")
            vSprate.push_back(sWord);
        Line.erase(0, pos + Derim.length());
    }

    if (Line != "")
        vSprate.push_back(Line);

    return vSprate;
}
sClient ConvertLineDataToRecord(string Line, string Sperator = "#//#")
{
    sClient Client;

    vector<string> vClintData;
    vClintData = SpirateData(Line, Sperator);

    Client.AccountNumber = vClintData[0];
    Client.PinCode = vClintData[1];
    Client.Name = vClintData[2];
    Client.Phone = vClintData[3];
    Client.AccountBalance = stod(vClintData[4]);

    return Client;
}
void PrintClientRecord(sClient Client)
{
    cout << "\n\nThe Client Record:\n";

    cout << "\nAccount Number : " << Client.AccountNumber;
    cout << "\nPinCode        : " << Client.PinCode;
    cout << "\nName           : " << Client.Name;
    cout << "\nPhone          : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

int main()
{
    //Problem 46 - Convert Line Data to Record
    
    string ClientRecord = "A244#//#1234#//#Abdelrahman Taymour#//#01093284077#//#5000.000000";
    sClient Client;
    Client = ConvertLineDataToRecord(ClientRecord);
    PrintClientRecord(Client);
}
