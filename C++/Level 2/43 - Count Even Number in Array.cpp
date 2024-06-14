#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 43 - Count Even Number in Array

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

int CountEvenNumber(int arr[100], int arrLength)
{
    int EvenCounter = 0;
    for (int i = 0;i < arrLength;i++)
    {
        if (arr[i] % 2 == 0)
            EvenCounter++;
    }
    return EvenCounter;
}

int main()
{
    //Problem 43 - Count Even Number in Array

    srand((unsigned)time(NULL));
    int arr[100], arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "Array: \n";
    PrintArray(arr, arrLength);

    cout << "\nEven Number Count is: ";
    cout << CountEvenNumber(arr, arrLength);
}
