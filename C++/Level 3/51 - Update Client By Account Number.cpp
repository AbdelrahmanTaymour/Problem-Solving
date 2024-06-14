#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

//Problem 51 - Update Client By Account Number

string ClientsFileName = "Clients.txt";
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};
vector<string> SplitString(string Line, string Sperator)
{
    vector<string> str;
    int pos = 0;
    string sword;

    while ((pos = Line.find(Sperator)) != std::string::npos)
    {
        sword = Line.substr(0, pos);

        if (sword != "")
            str.push_back(sword);
        Line.erase(0, pos + Sperator.length());
    }
    if (Line != "")
        str.push_back(Line);

    return str;
}
sClient ConvertLineDataToRecord(string Line, string Sperator = "#//#")
{
    vector<string> vSperatLine = SplitString(Line, Sperator);
    sClient Client;

    Client.AccountNumber = vSperatLine[0];
    Client.PinCode = vSperatLine[1];
    Client.Name = vSperatLine[2];
    Client.Phone = vSperatLine[3];
    Client.AccountBalance = stod(vSperatLine[4]);

    return Client;

}
string ConvertRecordToLine(sClient Client, string Sperator = "#//#")
{
    string Line = "";

    Line += Client.AccountNumber + Sperator;
    Line += Client.PinCode + Sperator;
    Line += Client.Name + Sperator;
    Line += Client.Phone + Sperator;
    Line += to_string(Client.AccountBalance);

    return Line;
}
vector<sClient> LoadReacordFromFils(string FileName)
{
    vector<sClient> vRecord;

    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            vRecord.push_back(ConvertLineDataToRecord(Line));
        }

        MyFile.close();
    }

    return vRecord;
}
void PrintClientRecord(sClient Client)
{
    cout << "\nThe following are the client details:\n";

    cout << "\nAccount Number : " << Client.AccountNumber;
    cout << "\nPinCode        : " << Client.PinCode;
    cout << "\nName           : " << Client.Name;
    cout << "\nPhone          : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}
bool FindClientByAccountNumber(string AccountNumber, vector<sClient>vClients, sClient& Client)
{
    for (sClient c : vClients)
    {
        if (c.AccountNumber == AccountNumber)
        {
            Client = c;
            return true;
        }
    }
    return false;
}
string ReadAccountNumber()
{
    cout << "Please Enter the Account Number? ";
    string AccountNumber;
    cin >> AccountNumber;
    return AccountNumber;
}
sClient UpdateClientData(sClient& Client)
{
    cout << "\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}
void SaveClientDataToFile(string FileName, vector<sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {
        for (sClient& c : vClients)
        {
            MyFile << ConvertRecordToLine(c) << endl;
        }
        MyFile.close();
    }
}
void UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientRecord(Client);

        cout << "\n\nAre you sure you want to update the client? y/n? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            for (sClient& c : vClients)
            {
                c = UpdateClientData(c);
                break;
            }


            SaveClientDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }
}


int main()
{
    //Problem 51 - Update Client By Account Number

    vector<sClient> vClients = LoadReacordFromFils(ClientsFileName);
    string AccountNumber = ReadAccountNumber();

    UpdateClientByAccountNumber(AccountNumber, vClients);
}
