#include <iostream>
using namespace std;

//Problem 12 - Check Tybical Matrices

int RandomNumber(int From, int To)
{
    int Number = rand() % (To - From + 1) + From;
    return Number;
}
void Fill2MatricesRandom(int arr1[3][3], int arr2[3][3], int Rows, int Cols)
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
void Fill2MatrixOrdered(int arr1[3][3], int arr2[3][3], int Rows, int Cols)
{
    int count = 0;
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            count++;
            arr1[i][j] = count;
            arr2[i][j] = count;
        }
    }
}
bool isMatricesTybical(int arr1[3][3], int arr2[3][3], int Rows, int Cols)
{
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            if (arr1[i][j] != arr2[i][j])
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
        cout << endl;
    }
}

int main()
{
    //Problem 12 - Check Tybical Matrices

    srand((unsigned)time(NULL));

    cout << "Random Matrices: \n_________________\n";
    int arr1[3][3], arr2[3][3];
    Fill2MatricesRandom(arr1, arr2, 3, 3);

    cout << "\nThe Matrix1: \n";
    PrintMatrix(arr1, 3, 3);

    cout << "\nThe Matrix2: \n";
    PrintMatrix(arr2, 3, 3);

    if (isMatricesTybical(arr1, arr2, 3, 3))
        cout << "\nYes, the Matrices are Tybical\n";
    else
        cout << "\nNo, The Matrices are not Tybical\n";

    cout << "\nOrdered Matrices: \n_________________\n";
    int arr3[3][3], arr4[3][3];
    Fill2MatrixOrdered(arr3, arr4, 3, 3);

    cout << "\nThe Matrix1: \n";
    PrintMatrix(arr3, 3, 3);

    cout << "\nThe Matrix2: \n";
    PrintMatrix(arr4, 3, 3);

    if (isMatricesTybical(arr3, arr4, 3, 3))
        cout << "\nYes, the Matrices are Tybical\n";
    else
        cout << "\nNo, The Matrices are not Tybical\n";
}
