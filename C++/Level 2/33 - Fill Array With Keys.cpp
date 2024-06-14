#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 33 - Fill Array With Keys

enum enCharType {
    SamallLetter = 1, CapitalLetter = 2,
    SpecialCharacter = 3, Digit = 4
};
int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SamallLetter:
    {
        return char(RandomNumber(97, 122));
        break;
    }
    case enCharType::CapitalLetter:
    {
        return char(RandomNumber(65, 90));
        break;
    }
    case enCharType::SpecialCharacter:
    {
        return char(RandomNumber(33, 47));
        break;
    }
    case enCharType::Digit:
    {
        return char(RandomNumber(48, 57));
        break;
    }
    }
}
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}
string GenerateWord(enCharType CharType, short Length)
{
    string Word;
    for (int i = 1; i <= Length; i++)
    {

        Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
}
string GenerateKey()
{
    string Key = "";

    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

    return Key;
}
void FillArrayWithKeys(string arr[], int arrLength)
{
    for (int i = 0;i < arrLength;i++)
    {
        arr[i] = GenerateKey();
    }
}
void PrintStringArray(string arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Key [" << i << "] : ";
        cout << arr[i] << endl;
    }
    cout << "\n";
}

int main()
{
    //Problem 33 - Fill Array With Keys

    srand((unsigned)time(NULL));
    string arr[100];
    int arrLength = 0;
    arrLength = ReadPositiveNumber("How many Keys? ");

    FillArrayWithKeys(arr, arrLength);
    PrintStringArray(arr, arrLength);
}
