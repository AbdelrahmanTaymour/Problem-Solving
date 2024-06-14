#include <iostream>
#include <string>
using namespace std;

struct stInfo {
    string FirstName;
    string LastName;
    int Number;
};
stInfo ReadInfo() {
    stInfo Info;
    cout << "Enter your First Name: ";
    cin >> Info.FirstName;
    cout << "Enter your Last Name: ";
    cin >> Info.LastName;
    return Info;
}
string GetFullName(stInfo Info) {
    string FullName = "";
    FullName = Info.FirstName + " " + Info.LastName;
    return FullName;
}
void PrintFullName(string FullName) {
    cout << "Your Full Name is: " << FullName << endl;
}

int main()
{
    //PrintFullName(GetFullName(ReadInfo()));
}
