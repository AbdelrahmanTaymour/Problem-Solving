#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 32 - Copy Array In Reverse Order

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
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
void FillArrayWithRandomNumbers(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}
void ReverseArray(int arr[100], int arrReversed[100], int arrLength)
{
    for (int i = 0;i < arrLength;i++)
    {
        arrReversed[i] = arr[arrLength - i - 1];
    }
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    //Problem 32 - Copy Array In Reverse Order
    
    srand((unsigned)time(NULL));
    int arr[100],arrReversed[100], arrLength;
    arrLength = ReadPositiveNumber("Enter how many elements: ");

    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "Array before Reversed: \n";
    PrintArray(arr, arrLength);
    cout << endl;

    cout << "Array After Reversed: \n";
    ReverseArray(arr, arrReversed, arrLength);
    PrintArray(arrReversed, arrLength);
    cout << endl;
}
