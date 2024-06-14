#include <vector>
#include <string>
#include <iostream>
using namespace std;

//Problem 65 - Format Date

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
string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(),
            sRepalceTo);
        pos = S1.find(StringToReplace);//find next
    }
    return S1;
}
string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString;

    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
    
    return FormattedDateString;
}


int main()
{
    //Problem 65 - Format Date
    string DateString = ReadStringDate("\nPlease Enter Date  dd / mm / yyyy ? "); 
    stDate Date = StringToDate(DateString);
    
    cout << "\n" << FormateDate(Date) << "\n";
    cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n"; 
}
