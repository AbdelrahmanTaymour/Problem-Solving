#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 26 - Sum Of Random Array

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
int SumNumbersOfArray(int arr[100], int arrLength)
{
    int sum = 0;
    for (int i = 0;i < arrLength;i++)
        sum += arr[i];
    return sum;
}

int main()
{
    //Problem 26 - Sum Of Random Array

    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    FillArrayWithRandomNumber(arr, arrLength);

    cout << "Array Elements: ";
    PrintArray(arr, arrLength);

    cout << "Sum of all numbers is: ";
    cout << SumNumbersOfArray(arr, arrLength) << endl;
}
