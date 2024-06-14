#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 40 - Join String(Overloading)

string JoinString(vector<string> vWords, string Delim)
{
    string str = "";
    for (string& word : vWords)
        str += word + Delim;
    return str.substr(0, str.length() - Delim.length());
}
string JoinString(string arr[], int arrLength, string Delim)
{
    string str = "";
    for (int i =0;i< arrLength;i++)
        str += arr[i] + Delim;
    return str.substr(0, str.length() - Delim.length());
}


int main()
{
    //Problem 40 - Join String (Overloading)

    cout << "After Join with Vector: ";
    vector<string> vSplitWords = { "Abdelrahman","Taymour","Mostafa" };
    cout << JoinString(vSplitWords,",");

    cout << "\n\nAfter Join with Vector: ";
    string arr[] = { "Abdelrahman","Taymour","Mostafa" };
    cout << JoinString(arr, 3, ",");
}
