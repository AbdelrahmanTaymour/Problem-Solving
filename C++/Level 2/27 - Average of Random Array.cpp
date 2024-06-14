#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 27 - Average of Random Array

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
int SumArray(int arr[100], int arrLength)
{
    int sum = 0;
    for (int i = 0;i < arrLength;i++)
        sum += arr[i];
    return sum;
}
float AverageOfArray(int arr[100], int arrLength)
{
    return (float)SumArray(arr, arrLength) / arrLength;
}

int main()
{
    //Problem 27 - Average of Random Array

    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    FillArrayWithRandomNumber(arr, arrLength);

    cout << "Array Elements: ";
    PrintArray(arr, arrLength);

    cout << "Average of all numbers is: ";
    cout << AverageOfArray(arr, arrLength) << endl;
}
