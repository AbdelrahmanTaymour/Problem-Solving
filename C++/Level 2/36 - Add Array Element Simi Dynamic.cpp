#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 36 - Add Array Element Simi Dynamic

int ReadNumber()
{
    int Number;
    cout << "\nPlease enter a number? ";
    cin >> Number;
    return Number;
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}
void InputUserNumbersInArray(int arr[100], int& arrLength)
{
    bool AddMore = true;

    do
    {
        AddArrayElement(ReadNumber(), arr, arrLength);

        cout << "\nDo you want to add more numbers? [0]:No, [1] : yes ? ";
        cin >> AddMore;

    } while (AddMore);
}

int main()
{
    //Problem 36 - Add Array Element Simi Dynamic

    int arr[100], arrLength = 0;
    InputUserNumbersInArray(arr, arrLength);

    cout << "Array Length: " << arrLength << endl;
    cout << "Array Elements: ";
    PrintArray(arr, arrLength);
}
