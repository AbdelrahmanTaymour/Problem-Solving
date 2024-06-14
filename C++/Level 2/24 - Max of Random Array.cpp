#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 24 - Max of Random Array

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
int GetMaxNumberInArray(int arr[100], int arrLength)
{
    int Max = arr[0];
    for (int i = 1;i < arrLength;i++)
    {
        if (arr[i] > Max)
            Max = arr[i];
    }
    return Max;
}

int main()
{
    //Problem 24 - Max of Random Array

    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    FillArrayWithRandomNumber(arr, arrLength);

    cout << "Array Elements: ";
    PrintArray(arr, arrLength);

    cout << "Max Number is: ";
    cout << GetMaxNumberInArray(arr, arrLength) << endl;
}
