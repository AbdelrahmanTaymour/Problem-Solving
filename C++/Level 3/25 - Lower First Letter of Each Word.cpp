#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 25 - Lower First Letter of Each Word

string ReadString()
{
    string str;

    cout << "Please Enter Your String: ";
    getline(cin, str);
    return str;
}
string LowerFirstLetterOfEachWord(string S)
{
    bool isFirstLetter = true;
    for (int i = 0;i < S.length();i++)
    {
        if (S[i] != ' ' && isFirstLetter && !(S[i] >= 'a' && S[i] <= 'z'))
        {

            S[i] += 32;
            ///or use function tolower: Word[i] = tolower(Word[i]);
        }

        isFirstLetter = (S[i] == ' ') ? true : false;
    }
    return S;
}

int main()
{
    //Problem 25 - Lower First Letter of Each Word

    string S1 = ReadString();
    cout << "\nString after Conversion\n";
    S1 = LowerFirstLetterOfEachWord(S1);
    cout << S1 << endl;
}
