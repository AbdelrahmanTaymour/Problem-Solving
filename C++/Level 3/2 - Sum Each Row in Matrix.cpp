#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Problem 2 - Sum Each Row in Matrix

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

void SumRowsInMatrix(int arr[3][3], short Rows, short Cols)
{
    cout << "\nThe following are the sum of each row in the matrix:\n";
    for (int i = 0;i < Rows;i++)
    {
        cout << " Row " << i+1 << " Sum = " << sumRow(arr, i, Cols) << endl;
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
    //Problem 2 - Sum Each Row in Matrix

    srand((unsigned)time(NULL));
    int arr[3][3];
    FillRandomMatrix(arr, 3, 3);
    PrintMatrix(arr, 3, 3);
    SumRowsInMatrix(arr, 3, 3);
}
