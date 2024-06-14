#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 30 - Sum of 2 arrays to a third one

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
int RandomNumber(int From, int To)
{
    int Random = rand() % (To - From + 1) + From;
    return Random;
}
void FillArrayWithRandomNumber(int arr[100], int arrLength)
{
    
    for (int i = 0; i < arrLength; i++)
    {

        arr[i] = RandomNumber(1, 100);
    }
}
void PrintArray(int arr[100], int Length)
{
    for (int i = 0;i < Length;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Sum2Arrays(int arr[100], int arr2[100], int arrSum[100], int arrLength)
{
    for (int i = 0; i < arrLength;i++)
        arrSum[i] = arr[i] + arr2[i];
}


int main()
{
    //Problem 30 - Sum of 2 arrays to a third one

    srand((unsigned)time(NULL));

    int arr[100], arr2[100], arrSum[100];
    int arrLength = ReadPositiveNumber("How Many elements? ");


    FillArrayWithRandomNumber(arr, arrLength);
    FillArrayWithRandomNumber(arr2, arrLength);
    Sum2Arrays(arr, arr2, arrSum, arrLength);

    cout << "Array 1 Elements: \n";
    PrintArray(arr, arrLength);
    cout << endl;

    cout << "Array 2 Elements: \n";
    PrintArray(arr2, arrLength);
    cout << endl;

    cout << "Sum od array 1 and array 2: \n";
    PrintArray(arrSum, arrLength);
    cout << endl;
}
