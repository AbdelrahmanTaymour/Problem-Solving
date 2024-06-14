#include <iostream>
using namespace std;

//Problem 16 - Check Sparse Matrix

int CountNumberInMatrix(int arr[3][3], int Rows, int Cols, int Number)
{
    int Counter = 0;
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            if (arr[i][j] == Number)
                Counter++;
        }
    }
    return Counter;
}
bool isSparse(int arr[3][3], int Rows, int Cols)
{
    int MatrixSize = Rows * Cols;
    return CountNumberInMatrix(arr, Rows, Cols, 0) >= (MatrixSize / 2);
}
void PrintMatrix(int arr[3][3], int Rows, int Cols)
{
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            printf(" %02d    ", arr[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    //Problem 16 - Check Sparse Matrix

    int arr[3][3] = { {0,0,1},{0,0,0},{1,0,9} };
    cout << "The Matrix: \n";
    PrintMatrix(arr, 3, 3);

    if (isSparse(arr, 3, 3))
        cout << "\nYes: It is Sparse.\n";
    else
        cout << "\nNo: It is not Sparse.\n";
}
