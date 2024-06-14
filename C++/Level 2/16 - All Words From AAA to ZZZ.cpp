#include <iostream>
using namespace std;

//Program 16 - All Words From AAA to ZZZ

void PrintFromAAAtoZZZ()
{
    string word = "";
    for (int i = 65;i <= 90;i++)
    {
        for (int j = 65;j <= 90;j++)
        {
            for (int k = 65;k <= 90;k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                cout << word << endl;

                word = "";
            }
        }
    }
}

int main()
{
    //Program 16 - All Words From AAA to ZZZ
    PrintFromAAAtoZZZ();
}
