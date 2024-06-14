#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 29 - Copy Only Prime Numbers

enum enPrimeNotPrime {
    Prime = 1, NotPrime = 2
};

enPrimeNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int i = 2;i <= M;i++)
    {
        if (Number % i == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}

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

void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
{
    int counter = -1;
    for (int i = 0;i < arrLength;i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime) 
        {
            counter++;
            arrDestination[counter] = arrSource[i];
        }
    }
    arr2Length = counter;
}

int main()
{
    //Problem 29 - Copy Only Prime Numbers

    srand((unsigned)time(NULL));

    int arr[100], arr2[100], arrLength, arr2Length = 0;
    FillArrayWithRandomNumber(arr, arrLength);

    cout << "Array Elements: \n";
    PrintArray(arr, arrLength);
    cout << endl;

    CopyOnlyPrimeNumbers(arr, arr2, arrLength, arr2Length);
    cout << "Prime Numbers in Array 2: \n";
    PrintArray(arr2, arr2Length);
    cout << endl;
}
