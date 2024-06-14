#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 38 - Copy Odd Numbers to a new Array

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
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
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}
void CopyOddNumbers(int arrSource[100], int arrDestation[100],int arrLength, int& arrDesLength)
{
    for (int i = 0;i < arrLength;i++)
    {
        if (arrSource[i] % 2 != 0)
            AddArrayElement(arrSource[i], arrDestation, arrDesLength);
    }
}

int main()
{
    //Problem 38 - Copy Odd Numbers to a new 

    srand((unsigned)time(NULL));
    int arr[100], arrOdd[100], arrLength = 0, arrOddLength = 0;

    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "Array 1 elements: \n";
    PrintArray(arr, arrLength);

    CopyOddNumbers(arr, arrOdd, arrLength, arrOddLength);
    cout << "Array 2 Odd Numbers: \n";
    PrintArray(arrOdd, arrOddLength);
}
