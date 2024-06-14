#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Program 28 - Coby Array

int RandomNumber(int From, int To)
{
    int Random = rand() % (To - From + 1) + From;
    return Random;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;

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

void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0;i < arrLength;i++)
        arrDestination[i] = arrSource[i];
}

int main()
{
    //Program 28 - Coby Array

    srand((unsigned)time(NULL));

    int arr[100], arr2[100], arrLength;
    FillArrayWithRandomNumber(arr, arrLength);

    cout << "Array Elements: \n";
    PrintArray(arr, arrLength);
    cout << endl;

    CopyArray(arr, arr2, arrLength);
    cout << "Copy Array: \n";
    PrintArray(arr2, arrLength);
    cout << endl;
}
