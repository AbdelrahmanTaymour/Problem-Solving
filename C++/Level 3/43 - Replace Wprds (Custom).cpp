#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

//Problem 43 - Replace Wprds(Custom)

vector<string> SplitString(string s1, string Delim)
{
    vector<string> vSplit;
    int pos = 0;
    string sWord = "";

    while ((pos = s1.find(Delim)) != std::string::npos)
    {
        sWord = s1.substr(0, pos);
        if (sWord != "")
            vSplit.push_back(sWord);
        s1.erase(0, pos + Delim.length());
    }
    if (s1 != "")
        vSplit.push_back(s1);
    return vSplit;
}
string LowerAllString(string s1)
{
    for (int i = 0;i < s1.length();i++)
    {
        s1[i] = tolower(s1[i]);
    }
    return s1;
}
string JoinString(vector<string>vWords, string Delim)
{
    string s = "";
    for (string& word : vWords)
    {
        s += word + " ";
    }
    return s.substr(0, s.length() - Delim.length());
}
string ReplaceWordInStringUsingSplit(string s1, string StringToReplace, string ReplaceTo, bool MatchCase = true)
{
    vector<string>vSplitString = SplitString(s1, " ");
    for (string& word : vSplitString)
    {
        if (MatchCase)
        {
            if (word == StringToReplace)
                word = ReplaceTo;
        }
        else
        {
            if (LowerAllString(word) == LowerAllString(StringToReplace))
                word = ReplaceTo;
        }
    }
    return JoinString(vSplitString, " ");
}

int main()
{
    //Problem 43 - Replace Wprds (Custom)

    string S1 = "Welcome to Spain , Spain is a nice country";
    string StringToReplace = "Spain";
    string ReplaceTo = "Egypt";

    cout << "\nOriginal String:\n" << S1;
    cout << "\n\nReplace with match case: ";
    cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo);
    cout << "\n\nReplace with dont match case: ";
    cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo, false);
}
