#include <iostream>
using namespace std;

//Problem 18 - Intersected Number in Matrices

bool isExist(int arr[3][3], int Rows, int Cols, int Number)
{
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            if (arr[i][j] == Number)
                return true;
        }
    }
    return false;
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
void PrintIntersectedNumbers(int arr1[3][3], int arr2[3][3], int Rows, int Cols)
{
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            if (isExist(arr2, Rows, Cols, arr1[i][j]))
                cout << arr1[i][j] << "\t";
        }
    }
}

int main()
{
    //Problem 18 - Intersected Number in Matrices

    int arr1[3][3] = { {15,10,1},{3,0,80},{1,6,9} };
    int arr2[3][3] = { {17,10,16},{15,10,80},{1,0,9} };

    cout << "The Matrix1: \n";
    PrintMatrix(arr1, 3, 3);

    cout << "The Matrix2: \n";
    PrintMatrix(arr2, 3, 3);

    cout << "\nIntersected Number are: \n";
    PrintIntersectedNumbers(arr1, arr2, 3, 3);
}
