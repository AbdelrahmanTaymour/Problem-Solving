#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 35 - Check Number In Array

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
int ReadNumber(string Message)
{
    int Number = 0;
    cout << Message << endl;
    cin >> Number;
    return Number;
}
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
short GetNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0;i < arrLength;i++)
    {
        if (arr[i] == Number)
            return i;
    }
    return -1;
}
bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return GetNumberPositionInArray(Number,arr,arrLength) != -1;
}

int main()
{
    //Problem 35 - Check Number In Array

    srand((unsigned)time(NULL));
    int arr[100], arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "Array Elements: \n";
    PrintArray(arr, arrLength);
    cout << endl;

    int Number = ReadNumber("Please Enter a Number to search for: ");
    short Position = GetNumberPositionInArray(Number, arr, arrLength);
    cout << "Number you looking for is: " << Number << endl;

    if (IsNumberInArray(Number,arr,arrLength))
        cout << "The Number is Found :-)" << endl;
    else
        cout << "The Number is not Found :-(" << endl;
}
