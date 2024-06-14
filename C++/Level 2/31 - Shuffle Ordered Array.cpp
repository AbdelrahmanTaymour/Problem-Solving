#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 31 - Shuffle Ordered Array

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
void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void FillArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
        arr[i] = i+1;
}
void ShafillArray(int arr[100], int arrLength)
{
    for (int i = 0;i < arrLength;i++)
    {
        swap(arr[RandomNumber(1, arrLength) -1], arr[RandomNumber(1, arrLength) -1]);
    }
}
void PrintArray(int arr[100], int arrLength)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    //Problem 31 - Shuffle Ordered Array

    srand((unsigned)time(NULL)); 
    int arr[100], arrLength;
    arrLength = ReadPositiveNumber("Enter how many elements: ");

    FillArray(arr, arrLength);
    cout << "Array before shuffled: ";
    PrintArray(arr, arrLength);
    cout << endl;

    cout << "Array After shuffled: ";
    ShafillArray(arr, arrLength);
    PrintArray(arr, arrLength);
    cout << endl;
}
