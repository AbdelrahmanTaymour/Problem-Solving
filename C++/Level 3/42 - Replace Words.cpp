#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

//Problem 42 - Replace Words

string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sReplaseTo)
{
    int pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), sReplaseTo);
        pos = S1.find(StringToReplace);
    }
    return S1;
}

int main()
{
    //Problem 42 - Replace Words

    string S1 = "I live in France, France is a nice country.";
    string StringToReplace = "France";
    string sReplaceTo = "Egypt";

    cout << "Original String is: " << S1 << endl << endl;
    cout << "After Replacement : " << ReplaceWordInStringUsingBuiltInFunction(S1, StringToReplace, sReplaceTo) << endl;
}
