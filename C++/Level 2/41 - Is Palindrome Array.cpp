#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Problem 41 - Is Palindrome Array

int ReadPositiveNumber(string Messenge)
{
    int Number;
    do
    {
        cout << Messenge << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}
void ReadArray(int arr[100], int arrLength)
{
    for (int i = 0;i < arrLength;i++)
    {
        cout << "Element [" << i + 1 << "]: ";
        cin >> arr[i];
    }
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0;i < arrLength;i++)
    {
        cout << arr[i] << " ";
    }
}
bool isArrayPalindrome(int arr[100], int arrLength)
{
    for (int i = 0;i < arrLength / 2 ; i++)
    {
        if (arr[i] != arr[arrLength - 1 - i])
            return false;
    }
    return true;
}

void PrintCheckArrayPalingrome(int arr[100], int arrLength)
{
    cout << endl;
    if (!isArrayPalindrome(arr, arrLength))
    {
        cout << "No, Array is not Palindrome" << endl;
        return;
    }

    cout << "Yes, Array is Palindrome" << endl;
}

int main()
{
    //Problem 41 - Is Palindrome Array

    int arr[100], arrLength;
    
    ReadArray(arr, arrLength);
    cout << "Array: \n";
    PrintArray(arr, arrLength);

    PrintCheckArrayPalingrome(arr, arrLength);
}
