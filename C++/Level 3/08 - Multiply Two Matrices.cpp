#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Problem 8 - Multiply Two Matrices

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void Fill2Matrixes(int arr1[3][3], int arr2[3][3], int Rows, int Cols)
{
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            arr1[i][j] = RandomNumber(1, 10);
            arr2[i][j] = RandomNumber(1, 10);
        }
    }
}

void MultiplyTwoMatrices(int arr1[3][3], int arr2[3][3], int arrResult[3][3], int Rows, int Cols)
{
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            arrResult[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}

void PrintMatricx(int arr[3][3], int Rows, int Cols)
{
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            if (arr[i][j] < 10)
                cout << 0 << arr[i][j] << "    ";
            else
                cout << arr[i][j] << "    ";
        }
        cout << endl;
    }
}

int main()
{
    //Problem 8 - Multiply Two Matrices

    int arr1[3][3], arr2[3][3], arrResult[3][3];
    Fill2Matrixes(arr1, arr2, 3, 3);
    MultiplyTwoMatrices(arr1, arr2, arrResult, 3, 3);

    cout << "\nMatrix1:\n";
    PrintMatricx(arr1, 3, 3);
    
    cout << "\nMatrix2:\n";
    PrintMatricx(arr2, 3, 3);

    cout << "\nResult:\n";
    PrintMatricx(arrResult, 3, 3);
}
