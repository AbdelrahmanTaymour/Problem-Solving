#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 29 - Count Small,Capital Letters

string ReadString()
{
    string str;

    cout << "Please Enter Your String: ";
    getline(cin, str);
    return str;
}
int CountCapitalLettersInString(string str)
{
    int Count = 0;
    for (int i = 0;i < str.length();i++)
    {
        if (isupper(str[i]))
            Count++;
    }
    return Count;
}
int CountSmallLettersInString(string str)
{
    int Count = 0;
    for (int i = 0;i < str.length();i++)
    {
        if (islower(str[i]))
            Count++;
    }
    return Count;
}

//Method 2
enum enWhatToCount{SmallLetters = 0, CapitalLetters = 1, All = 3};
int CountLetters(string s1, enWhatToCount WhatToCount = enWhatToCount::All)
{
    if (WhatToCount == enWhatToCount::All)
        return s1.length();

    int count = 0;
    for (int i = 0;i < s1.length();i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters&&isupper(s1[i]))
            count++;

        if (WhatToCount == enWhatToCount::SmallLetters && islower(s1[i]))
            count++;
    }
    return count;
}

int main()
{
    //Problem 29 - Count Small,Capital Letters
    
    string s1 = ReadString();

    cout << "\nString Length: " << s1.length() << endl;
    cout << "Capital Letters Count: " << CountCapitalLettersInString(s1) << endl;
    cout << "Small Letters Count: " << CountSmallLettersInString(s1) << endl;

    cout << "\n\nMethod 2:\n\n";

    cout << "\nString Length: " << CountLetters(s1) << endl;
    cout << "Capital Letters Count: " << CountLetters(s1,enWhatToCount::CapitalLetters) << endl;
    cout << "Small Letters Count: " << CountLetters(s1, enWhatToCount::SmallLetters) << endl;
}
