#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Problem 10 - Sum of Matrix

int RandomNumber(int From, int To)
{
    int Number = rand() % (To - From + 1) + From;
    return Number;
}

void FillMatrixWithRadomNumber(int arr[3][3], int Rows, int Cols)
{
    for (int i = 0; i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

int SumMatrix(int arr[3][3], int Rows, int Cols)
{
    int sum = 0;
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

void PrintMatrix(int arr[3][3], int Rows, int Cols)
{
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            printf(" %02d   ", arr[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    //Problem 10 - Sum of Matrix

    srand((unsigned)time(NULL));
    int arr[3][3];
    FillMatrixWithRadomNumber(arr, 3, 3);

    cout << "The Matrix: \n";
    PrintMatrix(arr, 3, 3);

    cout << "\nThe sum of Matrix is: " << SumMatrix(arr, 3, 3) << endl;
}
