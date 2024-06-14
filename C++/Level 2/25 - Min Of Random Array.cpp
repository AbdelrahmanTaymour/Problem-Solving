#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 25 - Min Of Random Array

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
int GetMinNumberInArray(int arr[100], int arrLength)
{
    int Min = arr[0];
    for (int i = 1;i < arrLength;i++)
    {
        if (arr[i] < Min)
            Min = arr[i];
    }
    return Min;
}

int main()
{
    //Problem 25 - Min Of Random Array

    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    FillArrayWithRandomNumber(arr, arrLength);

    cout << "Array Elements: ";
    PrintArray(arr, arrLength);

    cout << "Min Number is: ";
    cout << GetMinNumberInArray(arr, arrLength) << endl;
}
