#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 34 - Return Number Index In Array

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
short GetNumberPositionInArray(int arr[100], int arrLength, int SearchElement)
{
    for (int i = 0;i < arrLength;i++)
    {
        if (arr[i] == SearchElement)
            return i;
    }
    return -1;
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    //Problem 34 - Return Number Index In Array
    srand((unsigned)time(NULL));
    int arr[100],arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "Array Elements: \n";
    PrintArray(arr, arrLength);
    cout << endl;

    int SearchElement = ReadNumber("Please Enter a Number to search for: ");
    short Position = GetNumberPositionInArray(arr, arrLength, SearchElement);
    cout << "Number you looking for is: " << SearchElement << endl;

    if (Position == -1) 
        cout << "The Number is not Found :-(" << endl;
    else
    {
        cout << "The Number found at position: " << Position << endl;
        cout << "The Number Found its order is: " << Position + 1 << endl;
    }
}
