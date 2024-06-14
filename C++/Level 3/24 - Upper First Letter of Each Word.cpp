#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//Problem 24 - Upper First Letter of Each Word

string ReadString()
{
    string str;

    cout << "Please Enter Your String: ";
    getline(cin, str);
    return str;
}
string UpperFirstLetterOfEachWord(string Word)
{
    bool isFirstLetter = true;
    for (int i = 0;i < Word.length();i++)
    {
        if (Word[i] != ' ' && isFirstLetter && !(Word[i] >= 'A' && Word[i] <= 'Z'))
            Word[i] -= 32;          //or use function toupper: Word[i] = toupper(Word[i]);

        isFirstLetter = (Word[i] == ' ') ? true : false;
    }


    //or

    //for (short i = 0; i < S1.length(); i++)
    //{
    //    if (S1[i] != ' ' && isFirstLetter)
    //    {
    //        S1[i] = toupper(S1[i]);

    //    }
    //    isFirstLetter = (S1[i] == ' ' ? true : false);
    //}

    return Word;
}

int main()
{
    //Problem 24 - Upper First Letter of Each Word

    string S1 = ReadString();
    cout << "\nString after Conversion\n";
    S1 = UpperFirstLetterOfEachWord(S1);
    cout << S1 << endl;
}
