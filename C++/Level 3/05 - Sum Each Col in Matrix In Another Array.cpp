#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Problem 5 - Sum Each Col in Matrix In Another Array

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

int sumCol(int arr[3][3], short ColNumber, short Rows)
{
    int sum = 0;
    for (short j = 0;j < Rows;j++)
    {
        sum += arr[j][ColNumber];
    }
    return sum;
}

void SumColsInArray(int arr[3][3], int SumCols[3], short Rows, short Cols)
{
    for (int i = 0;i < Cols;i++)
    {
        SumCols[i] = sumCol(arr, i, Rows);
    }
}

void PrintSumAllColsInMatrix(int SumCols[3], short Cols)
{
    cout << "\nThe following are the sum of each Col in the matrix:\n";
    for (int i = 0;i < Cols;i++)
    {
        cout << " Col " << i + 1 << " Sum = " << SumCols[i] << endl;
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
    //Problem 5 - Sum Each Col in Matrix In Another Array

    srand((unsigned)time(NULL));
    int arr[3][3];
    int SumCols[3];
    FillRandomMatrix(arr, 3, 3);
    PrintMatrix(arr, 3, 3);
    SumColsInArray(arr, SumCols, 3, 3);
    PrintSumAllColsInMatrix(SumCols, 3);
}
