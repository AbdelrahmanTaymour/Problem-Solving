#include <iostream>
using namespace std;

//Problem 13 - Check Identity Matrix

bool isIdentityMatrix(int arr[3][3], int Rows, int Cols)
{
    for (int i = 0;i < Rows; i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            if (i == j && arr[i][j] != 1)
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
        for(int j = 0;j < Cols;j++)
        {
            printf(" %02d    ", arr[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    //Problem 13 - Check Identity Matrix

    int arr[3][3] = { {1,0,0}, {2,1,0},{0,0,1} };

    cout << "The Matrix: \n";
    PrintMatrix(arr, 3, 3);

    if (isIdentityMatrix(arr, 3, 3))
        cout << "\nYES: Matrix is identity.";
    else
        cout << "\nNo: Matrix is NOT identity.";
}
