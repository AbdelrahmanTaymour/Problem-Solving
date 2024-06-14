#include <iostream>
using namespace std;

//Program 35 - Piggy Bank Calculator

struct stPiggyBankContenet {
    int Pennies, Nickels, Dimes, Quarters, Dollars;
};
stPiggyBankContenet ReadPiggyBankContenet() {

    stPiggyBankContenet PiggyBankContenet;

    cout << "Pennies: ";
    cin >> PiggyBankContenet.Pennies;
    cout << "Nickels: ";
    cin >> PiggyBankContenet.Nickels;
    cout << "Dimes: ";
    cin >> PiggyBankContenet.Dimes;
    cout << "Quarters: ";
    cin >> PiggyBankContenet.Quarters;
    cout << "Dollars: ";
    cin >> PiggyBankContenet.Dollars;

    return PiggyBankContenet;
}
int CalculateTotalPennies(stPiggyBankContenet PiggyBankContenet) {
    int TotalPennies = 0;
    TotalPennies = PiggyBankContenet.Pennies * 1 + PiggyBankContenet.Nickels * 5 + PiggyBankContenet.Dimes * 10 + 
        PiggyBankContenet.Quarters * 25 + PiggyBankContenet.Dollars * 100;

    return TotalPennies;
}


int main()
{
    //Program 35 - Piggy Bank Calculator
    int TotalPennies = CalculateTotalPennies(ReadPiggyBankContenet());
    cout << "Total Pennies: " << TotalPennies << endl;
    cout << "Total Dollars: " << (float)TotalPennies / 100 << endl;
}
