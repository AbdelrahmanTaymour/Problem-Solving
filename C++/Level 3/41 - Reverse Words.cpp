#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

//Problem 41 - Reverse Words

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vStr;
    int pos = 0;
    string sword;
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sword = S1.substr(0, pos);
        if (sword != "")
            vStr.push_back(sword);
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
        vStr.push_back(S1);
    return vStr;
}
string ReverseString(string str)
{
    vector<string> vSplitString = SplitString(str, " ");
    string revString = "";
    vector<string>::iterator iter = vSplitString.end();
    while (iter != vSplitString.begin())
    {
        iter--;
        revString += *iter + " ";
    }
    
    return revString.substr(0, revString.length() - 1);
}

int main()
{
    //Problem 41 - Reverse Words
    cout << ReverseString("Abdelrahman Taymour Mostafa") << endl;
}
