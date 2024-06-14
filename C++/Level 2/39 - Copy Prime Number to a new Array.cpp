#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 39 - Copy Prime Number to a new Array

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };
enPrimNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;
    }
    return enPrimNotPrime::Prime;
}
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
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}
void CopyPrimeNumbers(int arrSource[100], int arrDestation[100], int arrLength, int& arrDesLength)
{
    for (int i = 0;i < arrLength;i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
            AddArrayElement(arrSource[i], arrDestation, arrDesLength);
    }
}

int main()
{
    //Problem 39 - Copy Prime Number to a new Array

    srand((unsigned)time(NULL));
    int arr[100], arrPrime[100], arrLength = 0, arrPrimeLength = 0;

    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "Array 1 elements: \n";
    PrintArray(arr, arrLength);

    CopyPrimeNumbers(arr, arrPrime, arrLength, arrPrimeLength);
    cout << "\nArray 2 Prime Numbers: \n";
    PrintArray(arrPrime, arrPrimeLength);
}
