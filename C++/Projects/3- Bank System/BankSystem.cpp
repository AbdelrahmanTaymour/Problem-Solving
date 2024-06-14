#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

void ShowMainManue();
void ShowTransactionScreen();
void ShowManageUsersScreen();
void GoBackMainManue();
void ShowAccessDeniedMessage();

string ClientFileName = "Clients.txt";
string UsersFileName = "Users.txt";

enum enMainMenueIoptions { eShowClient = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4,
        eFindClient = 5,eTransactions = 6,eManageUsers = 7, eLogout = 8 };
enum enTransactionOptions { eDeposit = 1, eWithdraw = 2, eTotalBalance = 3, eMainMenue = 4};
enum enManageUsersOptions { eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4,
        eFindUser = 5, eMainMenueScreen = 6};
enum enMainMenuePermissions { eAll = -1, pListClients = 1 ,pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8,
        pFindClient = 16,pTransactions = 32,pManageUsers = 64 };

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkToDelete = false;
};
struct stUser
{
    string Username;
    string Password;
    int Permissions;
    bool MarkToDelete = false; 
};

stUser CurrentUser;
bool CheckAccessPermission(enMainMenuePermissions Permission)
{
    if(Permission == enMainMenuePermissions::eAll)
        return true;

    if((Permission & CurrentUser.Permissions) == Permission)
        return true;
    else
        return false;
}
void ShowAccessDeniedMessage()
{
    cout << "\n------------------------------------\n";
    cout << "Access Denied, \nYou dont Have Permission To Do this,\nPlease Conact Your Admin.";
    cout << "\n------------------------------------\n";

    getchar();
}

//Show Clients List
vector<string>SplitString(string s, string Delim)
{
    vector<string> vSplit;
    int pos = 0;
    string sword;

    while((pos = s.find(Delim)) != std::string::npos)
    {
        sword = s.substr(0,pos);
        if(!sword.empty())
            vSplit.push_back(sword);
        s.erase(0,sword.length() + Delim.length());
    }
    if(s!="")
        vSplit.push_back(s);

    return vSplit;
}
sClient ConvertLinetoRecord(string Line, string Sperator = "#//#")
{
    sClient Client;
    vector<string>vClients;
    vClients = SplitString(Line, Sperator);

    Client.AccountNumber = vClients[0];
    Client.PinCode = vClients[1];
    Client.Name = vClients[2];
    Client.Phone = vClients[3];
    Client.AccountBalance = stod(vClients[4]);

    return Client;
}
vector<sClient> LoadCleintsDataFromFile (string FileName)
{
    vector<sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if(MyFile.is_open())
    {
        string line;
        while(getline(MyFile,line))
        {
            vClients.push_back(ConvertLinetoRecord(line));
        }
        MyFile.close();
    }
    return vClients;
}
void PrintClientInfo(sClient Client)
{
    cout<<"| "<<setw(15)<<left<<Client.AccountNumber;
    cout<<"| "<<setw(10)<<left<<Client.PinCode;
    cout<<"| "<<setw(40)<<left<<Client.Name;
    cout<<"| "<<setw(12)<<left<<Client.Phone;
    cout<<"| "<<setw(12)<<left<<Client.AccountBalance;
}
void PrintALLClientData(vector<sClient> vClients)
{
    cout<< "\n\t\t\t\tClient List (" << vClients.size() << ") Client(s).\n";
    cout << "\n________________________________________________________________________________________________\n";
    cout << "| " << left<<setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout<<"| "<<left<<setw(40)<<"Name";
    cout<<"| "<<left<<setw(12)<<"Phone";
    cout<<"| "<<left<<setw(12)<<"Balance";
    cout << "\n________________________________________________________________________________________________\n";

    for(sClient c : vClients)
    {
        PrintClientInfo(c);
        cout << endl;
    }

    cout << "\n\n________________________________________________________________________________________________\n\n";

}
void ShowClientsList()
{
    if(!CheckAccessPermission(enMainMenuePermissions::pListClients))
    {
        ShowAccessDeniedMessage();
        return;
    }
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientFileName);
    PrintALLClientData(vClients);

    //cout<<"Press any key to go back to Main Menue...";
    getchar();
}

//Add New Client
bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
    vector<sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName,ios::in);

    if(MyFile.is_open())
    {
        string Line;
        sClient Client;
        while(getline(MyFile,Line))
        {
            Client = ConvertLinetoRecord(Line);
            if(Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
        }
        MyFile.close();
    }
    return false;
}
sClient ReadClientInfo()
{
    sClient Client;
    cout << "\nEnter Account Number? ";

    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;

}
string ConvertRecordToLine(sClient client, string Sparator = "#//#")
{
    string Line = "";

    Line+=client.AccountNumber+Sparator;
    Line+=client.PinCode+Sparator;
    Line+=client.Name+Sparator;
    Line+=client.Phone+Sparator;
    Line+=to_string(client.AccountBalance);

    return Line;
}
void SaveRecordInFile(string Line, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName,ios::out | ios::app);

    if(MyFile.is_open())
    {
        MyFile << Line << endl;
        MyFile.close();
    }
}
void AddClient()
{
    sClient Client;
    Client = ReadClientInfo();
    SaveRecordInFile(ConvertRecordToLine(Client),ClientFileName);

}
void AddNewClients()
{
    if(!CheckAccessPermission(enMainMenuePermissions::pAddNewClient))
    {
        ShowAccessDeniedMessage();
        return;
    }
    cout<<"\n___________________________________\n";
    cout<<"\tAdd New Client Screen\n";
    cout<<"\n___________________________________\n";
    cout<<"\nAdding New Clien: \n";
    char More = 'n';

    do
    {
        AddClient();


        cout<<"\nDo you want add more client? y/n? ";
        cin>>More;

    } while (More == 'y' || More == 'Y');

}

//Delete Client
void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " <<Client.Name;
    cout << "\nPhone        : " <<Client.Phone;
    cout << "\nAccount Balance: "<<to_string(Client.AccountBalance);
}
string ReadAccountNumber()
{
    cout<<"\nPlease Enter Account Number? ";
    string AccountNumber;
    cin>>AccountNumber;
    return AccountNumber;
}
bool FindClientByAccountNumber(string AccountNumber, vector<sClient>vClients, sClient& Client)
{
    for(sClient c : vClients)
    {
        if(c.AccountNumber == AccountNumber)
        {
            Client = c;
            return true;
        }
    }
    return false;
}
void MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
    for(sClient& c : vClients)
    {
        if(c.AccountNumber == AccountNumber)
        {
            c.MarkToDelete = true;
        }
    }
}
void SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName,ios::out);

    if(MyFile.is_open())
    {
        for(sClient c : vClients)
        {
            if(c.MarkToDelete == false)
            {
                MyFile << ConvertRecordToLine(c)<<endl;
            }
        }
        MyFile.close();
    }
}
void DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    char Ans = 'n';
    if(FindClientByAccountNumber(AccountNumber,vClients,Client))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Ans;

        if(tolower(Ans) == 'y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber,vClients);
            SaveCleintsDataToFile(ClientFileName,vClients);

            vClients = LoadCleintsDataFromFile(ClientFileName);
            cout << "\n\nClient Deleted Successfully.";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }
}
void DeleteClient()
{
    if(!CheckAccessPermission(enMainMenuePermissions::pDeleteClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientFileName);
    sClient Client;

    cout<<"\n___________________________________\n";
    cout<<"\tDelete Client Screen\n";
    cout<<"\n___________________________________\n";

    string AccountNumber = ReadAccountNumber();
    DeleteClientByAccountNumber(AccountNumber,vClients);

}

//Update Client
sClient ChangeClientRecord(string AccountNumber, vector<sClient>& vClient)
{
    sClient Client;

    Client.AccountNumber = AccountNumber;
    cout << "\n\nEnter PinCode? ";
    getline(cin>>ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;

}
void UpdateClient()
{
    if(!CheckAccessPermission(enMainMenuePermissions::pUpdateClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    vector<sClient>vClients = LoadCleintsDataFromFile(ClientFileName);
    sClient Client;
    string AccountNumber = ReadAccountNumber();
    char Ans = 'n';

    if(FindClientByAccountNumber(AccountNumber,vClients,Client))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want update this client? y/n? ";
        cin>>Ans;

        if(Ans == 'y' || Ans == 'Y')
        {
            for(sClient& c : vClients)
            {
                if(c.AccountNumber == AccountNumber)
                {
                    c = ChangeClientRecord(AccountNumber, vClients);
                    break;
                }
            }
            SaveCleintsDataToFile(ClientFileName,vClients);
            cout << "\n\nClient Updated Successfully.";
        }
        
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }

    getchar();
}

//Find Client
void FindClient()
{
    if(!CheckAccessPermission(enMainMenuePermissions::pFindClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    vector<sClient>vCliens = LoadCleintsDataFromFile(ClientFileName);
    sClient Client;
    string AccountNumber = ReadAccountNumber();

    if(FindClientByAccountNumber(AccountNumber,vCliens,Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }

}

//Deposit
double DepositByAccountNumber(string AccountNumber, vector<sClient>& vClients, double DepositAmount)
{
    for(sClient& c : vClients)
    {
        if(c.AccountNumber == AccountNumber)
        {
            c.AccountBalance += DepositAmount;
            return c.AccountBalance;
        }
    }
    return 0;
}
void PerformDeposit(string AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    double amount;
    char Ans = 'n';
    while(!FindClientByAccountNumber(AccountNumber,vClients,Client))
    {
        cout<<"\nClient with ["<<AccountNumber<<"] does not exist.\n";
        AccountNumber = ReadAccountNumber();
    }

    PrintClientCard(Client);
    double TotalBalance = Client.AccountBalance;
    cout<<"\n\nPlease Enter deposit amount? ";
    cin >> amount;

    cout << "\n\nAre you sure you want perform this transaction? y/n ? ";
    cin >> Ans;

    if(tolower(Ans) == 'y')
    {
        TotalBalance = DepositByAccountNumber(AccountNumber, vClients, amount);
        SaveCleintsDataToFile(ClientFileName,vClients);

        vClients = LoadCleintsDataFromFile(ClientFileName);
        cout<<"\nDone Successfully, The new balance is "<<TotalBalance<<".\n";
    }

}
void ShowDepositScreen()
{
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientFileName);

    cout<<"\n---------------------------------\n";
    cout<<"\tDeposit Screen";
    cout<<"\n---------------------------------\n";

    string AccountNumber = ReadAccountNumber();
    PerformDeposit(AccountNumber,vClients);

}

//Withdraw
double WithdrawByAccountNumber(string AccountNumber, vector<sClient>& vClients, double WithdrawAmount)
{
    for(sClient& c : vClients)
    {
        if(c.AccountNumber == AccountNumber)
        {
            c.AccountBalance += WithdrawAmount * -1;
            return c.AccountBalance;
        }
    }
    return 0;
}
void PerformWithdraw(string AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    double amount;
    char Ans = 'n';
    if(FindClientByAccountNumber(AccountNumber,vClients,Client))
    {

        PrintClientCard(Client);
        double TotalBalance = Client.AccountBalance;


        cout<<"\n\nPlease Enter Withdraw amount? ";
        cin >> amount;
        while(amount > TotalBalance)
        {
            cout<<"\nAmount Exceeds the balance, you vsn withdraw up to: "<<TotalBalance;
            cout<<"\nPlease Enter Withdraw amount? ";
            cin >> amount;
        }

        cout << "\n\nAre you sure you want perform this transaction? y/n ? ";
        cin >> Ans;

        if(tolower(Ans) == 'y')
        {

            TotalBalance = WithdrawByAccountNumber(AccountNumber, vClients, amount);
            SaveCleintsDataToFile(ClientFileName,vClients);

            vClients = LoadCleintsDataFromFile(ClientFileName);
            cout<<"\nDone Successfully, The new balance is "<<TotalBalance<<".\n";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
    }

}
void ShowWithdrawScreen()
{
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientFileName);

    cout<<"\n---------------------------------\n";
    cout<<"\nWithdraw Screen";
    cout<<"\n---------------------------------\n";

    string AccountNumber = ReadAccountNumber();
    PerformWithdraw(AccountNumber,vClients);

}

//Total Balance
void PrintClientBalanse(sClient Client)
{
    cout<<"| "<<setw(15)<<left<<Client.AccountNumber;
    cout<<"| "<<setw(40)<<left<<Client.Name;
    cout<<"| "<<setw(12)<<left<<Client.AccountBalance;
}
void PrintALLClientBalance(vector<sClient> vClients)
{
    double TotalClientsBalance = 0;
    cout<< "\t\t\tClient List (" << vClients.size() << ") Client(s).\n";
    cout << "\n________________________________________________________________________________________________\n";
    cout << "| " << left<<setw(15) << "Account Number";
    cout<<"| "<<left<<setw(40)<<"Name";
    cout<<"| "<<left<<setw(12)<<"Balance";
    cout << "\n________________________________________________________________________________________________\n";

    for(sClient& c : vClients)
    {
        TotalClientsBalance += c.AccountBalance;
        PrintClientBalanse(c);
        cout << endl;
    }

    cout << "\n\n________________________________________________________________________________________________\n\n";
    cout <<"\n\t\tTotal Balance = " << TotalClientsBalance << endl;
}
void TotalBalanceScreen()
{
    vector<sClient>vClients = LoadCleintsDataFromFile(ClientFileName);

    PrintALLClientBalance(vClients);

}

//Transactions Menue Screen
short ReadTransactionOption()
{
    int Choose;
    cout<<"Chooce what do you want to do? [1 to 4]? ";
    cin>> Choose;
    return Choose;
}
void PerformTransactionsOption(enTransactionOptions Option)
{
    switch (Option)
    {
        case enTransactionOptions::eDeposit:
            system("clear");
            ShowDepositScreen();
            ShowTransactionScreen();
            break;
        case enTransactionOptions::eWithdraw:
            system("clear");
            ShowWithdrawScreen();
            ShowTransactionScreen();
            break;

        case enTransactionOptions::eTotalBalance:
            system("clear");
            TotalBalanceScreen();
            ShowTransactionScreen();
            break;

        case enTransactionOptions::eMainMenue:
            system("clear");
            ShowMainManue();
            break;
    }
}
void ShowTransactionScreen()
{
    if(!CheckAccessPermission(enMainMenuePermissions::pTransactions))
    {
        ShowAccessDeniedMessage();
        GoBackMainManue();
        return;
    }
    cout<<"\n==================================================\n";
    cout<<"\t\tTransactions Menue Screen\n";
    cout<<"==================================================\n";
    cout<<"\t[1] Deposit.\n";
    cout<<"\t[2] Withdraw.\n";
    cout<<"\t[3] Total Balance.\n";
    cout<<"\t[4] Main Menue.\n";
    cout<<"==================================================\n";

    PerformTransactionsOption((enTransactionOptions)ReadTransactionOption());
}

//Mange Users
stUser ConvertLinetoRecordUser(string Line, string Sperator = "#//#")
{
    stUser User;
    vector<string>vUsers;
    vUsers = SplitString(Line, Sperator);

    User.Username = vUsers[0];
    User.Password = vUsers[1];
    User.Permissions = stoi(vUsers[2]);

    return User;
}
vector<stUser> LoadUsersDataFromFile (string FileName)
{
    vector<stUser> vUsers;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if(MyFile.is_open())
    {
        string line;
        while(getline(MyFile,line))
        {
            vUsers.push_back(ConvertLinetoRecordUser(line));
        }
        MyFile.close();
    }
    return vUsers;
}
bool FindUserByUsernameAndPassword(string UserName, string Password, stUser& user)
{
    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    for(stUser& U : vUsers)
    {
        if(U.Username == UserName && U.Password == Password)
        {
            user = U;
            return true;
        }
    }
    return false;
}
bool FindUserByUsername(string UserName)
{
    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    for(stUser U : vUsers)
    {
        if(U.Username == UserName)
            return true;
    }
    return false;
}
bool FindUserByUsername(string UserName, stUser& User)
{
    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    for(stUser U : vUsers)
    {
        if(U.Username == UserName)
        {
            User = U;
            return true;
        }
    }
    return false;
}
bool LoadUserInfo(string UserName, string Password)
{
    if(FindUserByUsernameAndPassword(UserName, Password, CurrentUser))
        return true;
    else
        return false;
}
string ConvertUserRecordToLine(stUser User, string Sparator = "#//#")
{
    string Line = "";

    Line +=User.Username + Sparator;
    Line +=User.Password+Sparator;
    Line +=to_string(User.Permissions);

    return Line;
}
void SaveUsersDataToFile(string FileName, vector<stUser> vUsers)
{
    fstream MyFile;
    MyFile.open(FileName,ios::out);

    if(MyFile.is_open())
    {
        for(stUser U : vUsers)
        {
            if(U.MarkToDelete == false)
            {
                MyFile << ConvertUserRecordToLine(U)<<endl;
            }
        }
        MyFile.close();
    }
}


//List Users
void PrintUserInfo(stUser User)
{
    cout<<"| "<<setw(15)<<left<<User.Username;
    cout<<"| "<<setw(10)<<left<<User.Password;
    cout<<"| "<<setw(40)<<left<<User.Permissions;
}
void PrintAllUserData(vector<stUser> vUsers)
{
    cout<< "\n\t\t\t\tUsers List (" << vUsers.size() << ") User(s).\n";
    cout << "\n________________________________________________________________________________________________\n";
    cout << "| " << left <<setw(15) << "Username";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left <<setw(40) <<"Permissions";
    cout << "\n________________________________________________________________________________________________\n";

    if(vUsers.size() == 0)
        cout << "\t\t\t\tNo Users Available In the System!";
    else
    {
        for(stUser& U : vUsers)
        {
            PrintUserInfo(U);
            cout<<endl;
        }
    }

    cout << "\n________________________________________________________________________________________________\n";

}
void ShowListUsers()
{
    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    PrintAllUserData(vUsers);
    getchar();
}

//Add New User
int ReadPermissionsToSet()
{
    int Permissions = 0;
    char Answer = 'n';

    cout << "\nDo you want to give full access? y/n? ";
    cin>>Answer;

    if(Answer == 'Y' || Answer == 'y')
    {
        return -1;
    }

    cout << "\nDo you want to give access to : \n ";

    cout << "\nShow Client List? y/n? "; cin>>Answer;
    if(Answer == 'Y' || Answer == 'y')
        Permissions += enMainMenuePermissions::pListClients;

    cout<< "\nAdd New Client? y/n? "; cin>>Answer;
    if(Answer == 'Y' || Answer == 'y')
        Permissions += enMainMenuePermissions::pAddNewClient;

    cout<< "\nAdd Delete Client? y/n? "; cin>>Answer;
    if(Answer == 'Y' || Answer == 'y')
        Permissions += enMainMenuePermissions::pDeleteClient;

    cout<< "\nAdd Update Client? y/n? "; cin>>Answer;
    if(Answer == 'Y' || Answer == 'y')
        Permissions += enMainMenuePermissions::pUpdateClient;

    cout<< "\nAdd Find Client? y/n? "; cin>>Answer;
    if(Answer == 'Y' || Answer == 'y')
        Permissions += enMainMenuePermissions::pFindClient;

    cout<< "\nTransactions? y/n? "; cin>>Answer;
    if(Answer == 'Y' || Answer == 'y')
        Permissions += enMainMenuePermissions::pTransactions;

    cout<< "\nManage Users? y/n? "; cin>>Answer;
    if(Answer == 'Y' || Answer == 'y')
        Permissions += enMainMenuePermissions::pManageUsers;

    return Permissions;
}
stUser ReadNewUser()
{
    stUser User;

    cout<< "Enter Username? ";
    getline(cin>>ws,User.Username);

    while(FindUserByUsername(User.Username))
    {
        cout << "\nUser with [" << User.Username << "] already exists, Enter another Account Number? ";
        getline(cin>>ws,User.Username);
    }

    cout<<"Enter Password? ";
    getline(cin,User.Password);

    User.Permissions = ReadPermissionsToSet();

    return User;
}
void AddNewUser()
{
    stUser User;
    User = ReadNewUser();
    SaveRecordInFile(ConvertUserRecordToLine(User),UsersFileName);
}
void AddNewUsers()
{
    system("clear");
    cout<<"\n___________________________________\n";
    cout<<"\tAdd New User Screen\n";
    cout<<"\n___________________________________\n";
    cout<<"\nAdding New User: \n";
    char AddMore = 'Y';
    
    do
    {
        AddNewUser();

        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin>>AddMore;

    } while (toupper(AddMore) == 'Y');
    
    getchar();

}

//Delete User
void PrintUserCard(stUser User)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nUsarname    : " << User.Username;
    cout << "\nPassword    : " << User.Password;
    cout << "\nPermissions : " <<to_string(User.Permissions);
}
string ReadUsername()
{
    cout<<"\nPlease Enter Username? ";
    string Username;
    cin>>Username;
    return Username;
}
void MarkUserForDeleteByAccountNumber(string username, vector<stUser>& vUsers)
{
    for(stUser& U : vUsers)
    {
        if(U.Username == username)
        {
            U.MarkToDelete = true;
        }
    }
}
void DeleteUserByAccountNumber(string Username, vector<stUser>& vUsers)
{
    if(Username == "Admin")
    {
        cout<<"\nYou cannot Delete this User.\n";
        return;
    }

    stUser User;
    char Ans = 'n';

    if(FindUserByUsername(Username,User))
    {
        PrintUserCard(User);

        cout << "\n\nAre you sure you want delete this User? y/n ? ";
        cin >> Ans;

        if(tolower(Ans) == 'y')
        {
            MarkUserForDeleteByAccountNumber(Username,vUsers);
            SaveUsersDataToFile(UsersFileName,vUsers);

            vUsers = LoadUsersDataFromFile(UsersFileName);
            cout << "\n\nUser Deleted Successfully.";
        }
    }
    else
    {
        cout << "\nClient with Username(" << Username << ") is Not Found!";
    }
}
void DeleteUser()
{
    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    stUser User;

    cout<<"\n___________________________________\n";
    cout<<"\tDelete User Screen\n";
    cout<<"\n___________________________________\n";

    string Username = ReadUsername();
    
    DeleteUserByAccountNumber(Username,vUsers);
    getchar();
}

//Update User
stUser ChangeUserRecord(string Username, vector<stUser>& vUsers)
{
    stUser User;

    User.Username = Username;

    cout<<"\n\nEnter Password? ";
    getline(cin>>ws,User.Password);

    User.Permissions = ReadPermissionsToSet();

    return User;
}
void UpdateUser()
{
    system("clear");
    cout<<"\n___________________________________\n";
    cout<<"\tUdate User Screen\n";
    cout<<"\n___________________________________\n";

    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    stUser User;
    string Username = ReadUsername();
    char Answer = 'n';

    if(FindUserByUsername(Username,User))
    {
        PrintUserCard(User);

        cout << "\n\nAre you sure you want update this User? y/n? ";
        cin>>Answer;
        if(toupper(Answer) == 'Y')
        {
            for(stUser& U : vUsers)
            {
                if(U.Username == Username)
                {
                    U = ChangeUserRecord(Username, vUsers);
                    break;
                }
            }
            SaveUsersDataToFile(UsersFileName ,vUsers);
            cout << "\n\nUser Updated Successfully.";
        }
    }
    else
    {
        cout << "\nUser with Username (" << Username << ") is Not Found!";
    }

    getchar();
}

//Find User
void FindUser()
{
    system("clear");
    cout<<"\n___________________________________\n";
    cout<<"\tFind User Screen\n";
    cout<<"\n___________________________________\n";

    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    stUser User;
    string Username = ReadUsername();

    if(FindUserByUsername(Username,User))
    {
        PrintUserCard(User);
    }
    else
    {
        cout << "\nUser with Username (" << Username << ") is Not Found!";
    }

    getchar();
}


//Manage Users Screen
void GoBackManageUsersScreen()
{
    cout<<"\n\nPress any key to go back to Main Manue...";
    getchar();
    ShowManageUsersScreen();
}
short ReadManageUsersOption()
{
    int Choose;
    cout<<"Chooce what do you want to do? [1 to 6]? ";
    cin>> Choose;
    return Choose;
}
void PerformManageUsersOption(enManageUsersOptions Option)
{
    switch (Option)
    {
        case enManageUsersOptions::eListUsers:
            system("clear");
            ShowListUsers();
            GoBackManageUsersScreen();
            break;
        case enManageUsersOptions::eAddNewUser:
            system("clear");
            AddNewUsers();
            GoBackManageUsersScreen();
            break;

        case enManageUsersOptions::eDeleteUser:
            system("clear");
            DeleteUser();
            GoBackManageUsersScreen();
            break;

        case enManageUsersOptions::eUpdateUser:
            system("clear");
            UpdateUser();
            GoBackManageUsersScreen();
            break;

        case enManageUsersOptions::eFindUser:
            system("clear");
            FindUser();
            GoBackManageUsersScreen();
            break;

        case enManageUsersOptions::eMainMenueScreen:
            system("clear");
            ShowMainManue();
            break;
    }
}
void ShowManageUsersScreen()
{
    if(!CheckAccessPermission(enMainMenuePermissions::pManageUsers))
    {
        ShowAccessDeniedMessage();
        GoBackMainManue();
        return;
    }
    system("clear");
    cout<<"\n==================================================\n";
    cout<<"\t\tTransactions Menue Screen\n";
    cout<<"==================================================\n";
    cout<<"\t[1] List Users.\n";
    cout<<"\t[2] Add New User.\n";
    cout<<"\t[3] Delete User.\n";
    cout<<"\t[4] Update User.\n";
    cout<<"\t[5] Find User.\n";
    cout<<"\t[6] Main Menue.\n";
    cout<<"==================================================\n";

    PerformManageUsersOption((enManageUsersOptions)ReadManageUsersOption());
}


//Login
void Login()
{
    system("clear");
    vector<stUser> sUsers = LoadUsersDataFromFile(UsersFileName);

    bool LoginFaild = false;
    string Username, Password;

    cout<<"\n=======================================\n";
    cout<<"\t\tLogin Screen\n";
    cout<<"=======================================\n";

    do
    {
        if(LoginFaild)
        {
            cout<<"Invalid Username/Password!\n";
        }

        cout<<"Enter Username? ";
        cin>> Username;
        cout<<"Enter Password? ";
        cin>> Password;

        LoginFaild = !LoadUserInfo(Username,Password);

    }while(LoginFaild);

    system("clear");
    ShowMainManue();
}

//Main
short ReadMainMenueOption()
{
    int Choose;
    cout<<"Choose what do you want to do? [1 to 8]? ";
    cin>> Choose;
    return Choose;
}
void GoBackMainManue()
{
    cout<<"\n\nPress any key to go back to Main Manue...";
    getchar();
    ShowMainManue();
}
void PerformMainOption(enMainMenueIoptions Option)
{

    switch(Option)
    {
        case enMainMenueIoptions::eShowClient:
            system("clear");
            ShowClientsList();
            GoBackMainManue();
            break;

        case enMainMenueIoptions::eAddNewClient:
            system("clear");
            AddNewClients();
            GoBackMainManue();
            break;

        case enMainMenueIoptions::eDeleteClient:
            system("clear");
            DeleteClient();
            GoBackMainManue();
            break;

        case enMainMenueIoptions::eUpdateClient:
            system("clear");
            UpdateClient();
            GoBackMainManue();
            break;

        case enMainMenueIoptions::eFindClient:
            system("clear");
            FindClient();
            GoBackMainManue();
            break;

        case enMainMenueIoptions::eTransactions:
            system("clear");
            ShowTransactionScreen();
            break;

        case enMainMenueIoptions::eManageUsers:
            system("clear");
            ShowManageUsersScreen();
            break;

        case enMainMenueIoptions::eLogout:
            system("clear");
            Login();
            break;

    }
}
void ShowMainManue()
{
    system("clear");
    cout<<"\n=======================================\n";
    cout<<"\t\tMain Menue Screen\n";
    cout<<"=======================================\n";
    cout<<"\t[1] Show Clients List.\n";
    cout<<"\t[2] Add New Client.\n";
    cout<<"\t[3] Delete Client.\n";
    cout<<"\t[4] Update Client Info.\n";
    cout<<"\t[5] Find Client.\n";
    cout<<"\t[6] Transactions.\n";
    cout<<"\t[7] Manage Users.\n";
    cout<<"\t[8] Logout.\n";
    cout<<"=======================================\n";

    PerformMainOption((enMainMenueIoptions)ReadMainMenueOption());
}


int main()
{
    Login();
}
