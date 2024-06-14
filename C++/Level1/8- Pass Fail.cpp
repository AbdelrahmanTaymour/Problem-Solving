#include <iostream>
#include <string>
using namespace std;

//Problem #8 Pass Fail
enum enPassFail{Pass = 1, Fail = 0};
int ReadMark() {
    int Mark;
    cout << "Enter your Mark: ";
    cin >> Mark;
    return Mark;
}
enPassFail CheckMark(int Mark) {
    if (Mark >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}
void PrintMarkcheck(int Number) {
    if (CheckMark(Number) == enPassFail::Pass)
        cout << "You Passed.\n";
    else
        cout << "You Failed.\n";
}

int main()
{
    //Problem #8 Pass Fail
    //PrintMarkcheck(ReadMark());
}
