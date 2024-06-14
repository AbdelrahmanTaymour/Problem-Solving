#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 37 - Split String

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
void PrintVector(vector<string>vWords)
{
    for (string &word : vWords)
        cout << word << endl;
}

int main()
{
    //Problem 37 - Split String

    vector<string> vSplitWords = SplitString("Abdelrhaman Taymour Moistafa", " ");
    cout << "\nTokens: " << vSplitWords.size() << endl;
    PrintVector(vSplitWords);
}
