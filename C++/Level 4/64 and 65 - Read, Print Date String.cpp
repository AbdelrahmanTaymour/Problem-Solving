#include <vector>
#include <string>
#include <iostream>
using namespace std;

//Problem 64 - and 65 Read, Print Date String

struct stDate
{
    short Year;
    short Month;
    short Day;
};
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; 
    
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); 
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length()); 
       
    }
    if (S1 != "")
    {
        vString.push_back(S1); 
    }
    return vString;
}
stDate StringToDate(string Date)
{
    stDate sDate;
    vector<string> vDate;

    vDate = SplitString(Date, "/");
    sDate.Day = stoi(vDate[0]);
    sDate.Month = stoi(vDate[1]);
    sDate.Year = stoi(vDate[2]);

    return sDate;
}
string DateToString(stDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}
string ReadStringDate(string Message)
{
    string Date;
    cout << Message;
    getline(cin >> ws, Date);
    return Date;
}

int main()
{
    //Problem 64 - and 65 Read, Print Date String
    
    string DateString = ReadStringDate("\nPlease Enter Date dd / mm / yyyy ? "); 
    stDate Date = StringToDate(DateString);

    cout << "\nDay:" << Date.Day << endl;
    cout << "Month:" << Date.Month << endl;
    cout << "Year:" << Date.Year << endl;
    cout << "\nYou Entered: " << DateToString(Date) << "\n";
}
