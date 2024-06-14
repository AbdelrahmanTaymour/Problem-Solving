#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 22 - Repeated Elements Count In Array

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

void ReadArray(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    cout << "\nEnter array elements: \n";

    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
    cout << endl;
}

void PrintArray(int arr[100], int Length)
{
    for (int i = 0;i < Length;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int TimesRepeated(int Number, int arr[100], int arrLength)
{
    int Counter = 0;
    for (int i = 0;i < arrLength;i++)
    {
        if (Number == arr[i])
        {
            Counter++;
        }
    }
    return Counter;
}

int main()
{
    //Problem 22 - Repeated Elements Count In Array

    int arr[100], arrLength, NumberToCheck;
    ReadArray(arr, arrLength);

    NumberToCheck = ReadPositiveNumber("Enter the number you want to check : "); 
    cout << "\nOriginal array: ";

    PrintArray(arr, arrLength);
    cout << "\nNumber " << NumberToCheck;
    cout << " is repeated ";
    cout << TimesRepeated(NumberToCheck, arr, arrLength) << " time(s)\n";
}
