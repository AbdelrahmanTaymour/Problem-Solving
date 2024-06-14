#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Problem 3 - Sum Each Row in Matrix in Array

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillRandomMatrix(int arr[3][3], short Rows, short Cols)
{
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

int sumRow(int arr[3][3], short RowNumber, short cols)
{
    int sum = 0;
    for (short j = 0;j < cols;j++)
    {
        sum += arr[RowNumber][j];
    }
    return sum;
}

void SumRowsInArray(int arr[3][3],int SumRows[3], short Rows, short Cols)
{
    for (int i = 0;i < Rows;i++)
    {
        SumRows[i] = sumRow(arr, i, Cols);
    }
}

void PrintSumAllRowsInMatrix(int SumRows[3], short Rows)
{
    cout << "\nThe following are the sum of each row in the matrix:\n";
    for (int i = 0;i < Rows;i++)
    {
        cout << " Row " << i + 1 << " Sum = " << SumRows[i] << endl;
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    cout << "\nThe folowing is a 3x3 Matrix:\n";
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            cout << setw(3) << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    //Problem 3 - Sum Each Row in Matrix in Array

    srand((unsigned)time(NULL));
    int arr[3][3];
    int SumRows[3];
    FillRandomMatrix(arr, 3, 3);
    PrintMatrix(arr, 3, 3);
    SumRowsInArray(arr, SumRows, 3, 3);
    PrintSumAllRowsInMatrix(SumRows, 3);
}
