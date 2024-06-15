#pragma once
#include <iostream>
#include <string>
#include <clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include <vector>
#include <fstream>

using namespace std;
class clsBankClient  public clsPerson
{
private

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;


    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;

    struct stTransferLogRecord;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = ##)
    {
        vectorstring vClientData;
        vClientData = clsStringSplit(Line, Seperator);

        return clsBankClient(enModeUpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], clsUtilDecryptText(vClientData[5]), stod(vClientData[6]));

    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = ##)
    {

        string stClientRecord = ;
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += clsUtilEncryptText(Client.PinCode) + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static  vector clsBankClient _LoadClientsDataFromFile()
    {

        vector clsBankClient vClients;

        fstream MyFile;
        MyFile.open(Clients.txt, iosin);read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector clsBankClient vClients)
    {

        fstream MyFile;
        MyFile.open(Clients.txt, iosout);overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C  vClients)
            {
                if (C.MarkedForDeleted() == false)
                {
                    we only write records that are not marked for delete.  
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile  DataLine  endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector clsBankClient _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C  _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open(Clients.txt, iosout  iosapp);

        if (MyFile.is_open())
        {

            MyFile  stDataLine  endl;

            MyFile.close();
        }

    }

    string _PrepareTransferRecord(clsBankClient SourseClient, clsBankClient DestinationClient,float Amount,string Seperator = ##)
    {
        string TransferRecord = ;
        
        TransferRecord += clsDateGetSystemDateTimeString() + Seperator;
        TransferRecord += SourseClient.AccountNumber() + Seperator;
        TransferRecord += DestinationClient.AccountNumber() + Seperator;
        TransferRecord += to_string(Amount) + Seperator;
        TransferRecord += to_string(SourseClient.AccountBalance) + Seperator;
        TransferRecord += to_string(DestinationClient.AccountBalance) + Seperator;
        TransferRecord += CurrentUser.UserName;

        return TransferRecord;
    }

    static stTransferLogRecord _ConverTransferRegisterLineToRecord(string Line, string Seperator = ##)
    {
        stTransferLogRecord Record;
        vectorstring vRecord = clsStringSplit(Line, Seperator);

        Record.DateTime = vRecord[0];
        Record.SAccountNumber = vRecord[1];
        Record.DAccountNumber = vRecord[2];
        Record.Amount = stof(vRecord[3]);
        Record.SAccountBalace = stof(vRecord[4]);
        Record.DAccountBalance = stof(vRecord[5]);
        Record.UserName = vRecord[6];


        return Record;
    }

    void _RegisterTransfer(clsBankClient SourseClient, clsBankClient DestinationClient, float Amount)
    {
        string stDataLine = _PrepareTransferRecord(SourseClient, DestinationClient, Amount);

        fstream MyFile;
        MyFile.open(TransferLog.txt, iosout  iosapp);

        if (MyFile.is_open())
        {
            MyFile  stDataLine  endl;

            MyFile.close();
        }
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enModeEmptyMode, , , , , , , 0);
    }

public


    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) 
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    struct stTransferLogRecord
    {
        string DateTime;
        string SAccountNumber;
        string DAccountNumber;
        float Amount;
        float SAccountBalace;
        float DAccountBalance;
        string UserName;
    };

    bool IsEmpty()
    {
        return (_Mode == enModeEmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open(Clients.txt, iosin);read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open(Clients.txt, iosin);read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enModeEmptyMode
        {
            if (IsEmpty())
            {

                return enSaveResultssvFaildEmptyObject;

            }
        }

        case enModeUpdateMode
        {

            _Update();

            return enSaveResultssvSucceeded;
            break;
        }

        case enModeAddNewMode
        {
            This will add new record to file or database
            if (clsBankClientIsClientExist(_AccountNumber))
            {
                return enSaveResultssvFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                We need to set the mode to update after add new
                _Mode = enModeUpdateMode;
                return enSaveResultssvSucceeded;
            }

            break;
        }
        }



    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClientFind(AccountNumber);
        return (!Client1.IsEmpty());
    }

    bool Delete()
    {
        vector clsBankClient _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C  _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

        this = _GetEmptyClientObject();

        return true;

    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enModeAddNewMode, , , , , AccountNumber, , 0);
    }

    static vector clsBankClient GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static float GetTotalBalances()
    {
        vector clsBankClient vClients = clsBankClientGetClientsList();

        double TotalBalances = 0;

        for (clsBankClient Client  vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;

    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount)
    {
        if (Amount  _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }

    }

    
    bool Transfer(float Amount, clsBankClient& DestinationClient)
    {
        if (Amount  AccountBalance)
        {
            return false;
        }

        Withdraw(Amount);
        DestinationClient.Deposit(Amount);
        _RegisterTransfer(this, DestinationClient, Amount);

        return true;
    }
    
    static vectorstTransferLogRecord GetTransferRecordList()
    {
        
        vectorstTransferLogRecord vRecords;

        fstream MyFile;
        MyFile.open(TransferLog.txt, iosin);

        if (MyFile.is_open())
        {
            string Line;
            stTransferLogRecord Record;

            while (getline(MyFile, Line))
            {
                Record = _ConverTransferRegisterLineToRecord(Line);
                vRecords.push_back(Record);
            }

            MyFile.close();
        }

        return vRecords;
    }

};

