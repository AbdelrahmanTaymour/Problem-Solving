#include <iostream>
using namespace std;

//Program 17 - Guess a 3 Letter Password

string ReadPassword(string Message)
{
    string Letters = "";

    cout << Message << endl;
    cin >> Letters;
    
    return Letters;
}
void GuessPassword(string Password)
{
    string word = "";
    int counter = 0;
    cout << endl;

    for (int i = 65;i <= 90;i++)
    {
        for (int j = 65;j <= 90;j++)
        {
            for (int k = 65;k <= 90;k++)
            {
                counter++;

                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                cout << "Trial ["<<counter<<"] : "<< word << endl;

                if (word == Password)
                {
                    cout << "\nPassword is " << word << endl;
                    cout << "Found after " << counter << " Trial(s)" << endl;
                    return;
                }

                word = "";
            }
        }
    }
}

int main()
{
    //Program 17 - Guess a 3 Letter Password
    GuessPassword(ReadPassword("Please Enter 3 Capital Letters: "));
}
