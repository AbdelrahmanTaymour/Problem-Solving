#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

//Problem 48 - Show All Clients

string ClientsFileName = "Clients.txt";
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
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
void PrintClientData(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}
void PrintAllClientsData(vector<sClient> vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s)."; 
    cout << "\n_______________________________________________________";
    cout << "_______________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Account Balance";

    cout << "\n_______________________________________________________";
    cout << "_______________________________________________\n" << endl;

    for (sClient& Client : vClients)
    {
        PrintClientData(Client);
        cout << endl;
    }

    cout << "\n_______________________________________________________";
    cout << "_______________________________________________\n" << endl;
}

int main()
{
    //Problem 48 - Show All Clients

    vector<sClient> vClients = LoadReacordFromFils(ClientsFileName);
    PrintAllClientsData(vClients);
}
