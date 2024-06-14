#include <iostream>
using namespace std;

//Problem 14 - Check Scalar Matrix

bool isScalarMatrix(int arr[3][3], int Rows, int Cols)
{
    int FirstDiagElemement = arr[0][0];
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            if (i == j && arr[i][j] != FirstDiagElemement)
                return false;
            else if (i != j && arr[i][j] != 0)
                return false;
        }
    }
    return true;
}
void PrintMatrix(int arr[3][3], int Rows, int Cols)
{
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            printf(" %02d   ", arr[i][j]);
        }
        cout << "\n";
    }
}

int main()
{
    //Problem 14 - Check Scalar Matrix

    int arr[3][3] = { {9,0,0},{0,9,0},{0,0,9} };
    
    cout << "The Matrix: \n";
    PrintMatrix(arr, 3, 3);

    if (isScalarMatrix(arr, 3, 3))
        cout << "\nYes\n";
    else
        cout << "\nNo\n";
}
