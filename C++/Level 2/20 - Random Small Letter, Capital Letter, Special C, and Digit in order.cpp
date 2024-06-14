#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Program 20 - Random Small Letter, Capital Letter, Special C, and Digit in order

int RandomNumber(int From, int To)
{
    int Random = rand() % (To - From + 1) + From;
    return Random;
}

enum enCharType {
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialC = 3,
    DigitInOrder = 4
};

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

int main()
{
    //Program 20 - Random Small Letter, Capital Letter, Special C, and Digit in order

    srand((unsigned)time(NULL));
    
    cout << GetRandomCharacter(enCharType::SmallLetter) << endl;
    cout << GetRandomCharacter(enCharType::CapitalLetter) << endl;
    cout << GetRandomCharacter(enCharType::SpecialC) << endl;
    cout << GetRandomCharacter(enCharType::DigitInOrder) << endl;
}
