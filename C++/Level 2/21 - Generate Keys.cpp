//Problem 21 - Generate Keys

enum enCharType {
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialC = 3,
    DigitInOrder = 4
};

int RandomNumber(int From, int To)
{
    int Random = rand() % (To - From + 1) + From;
    return Random;
}

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
    {
        int SmallLetter = RandomNumber(97, 122);
        return char(SmallLetter);
    }
    case enCharType::CapitalLetter:
    {
        int CapitalLetter = RandomNumber(65, 90);
        return char(CapitalLetter);
    }
    case enCharType::SpecialC:
    {
        int SpecialC = RandomNumber(33, 47);
        return char(SpecialC);
    }
    case enCharType::DigitInOrder:
    {
        int DigitInOrder = RandomNumber(48, 57);
        return char(DigitInOrder);
    }
    default:
    {
        cout << "Somthing Wrong" << endl;
        return'?';
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
    string word = "";
    for (int i = 1;i <= Length;i++)
    {
        word = word + GetRandomCharacter(CharType);
    }
    return word;
}

string GenerateKey()
{
    string key = "";
  
    key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter, 4);

    return key;
}

void GenerateKeys(int Times)
{
    for (int i = 1;i <= Times;i++)
    {
        cout << "\nKey[" << i << "]: ";
        cout << GenerateKey();
    }
}

int main()
{
    //Problem 21 - Generate Keys

    srand((unsigned)time(NULL));
    GenerateKeys(ReadPositiveNumber("Pleaes enter how many keys to generate?"));
    cout << endl;
}
