#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 39 - Join String

vector<string> SplitString(string S1, string delim)
{
    vector<string>Words;
    int pos = 0;
    string sword;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sword = S1.substr(0, pos);
        if (sword != "")
            Words.push_back(sword);
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
        Words.push_back(S1);
    return Words;
}
string JoinString(vector<string> vWords, string Delim)
{
    string str = "";
    for (string& word : vWords)
        str += word + Delim;
    return str.substr(0, str.length() - Delim.length());
}

int main()
{
    //Problem 39 - Join String

    vector<string> vSplitWords = SplitString("Abdelrhaman Taymour Moistafa", " ");
    cout << JoinString(vSplitWords,", ") << endl;
}
