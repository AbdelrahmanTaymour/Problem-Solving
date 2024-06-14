
#include <iostream>
using namespace std;

//Problem 11 - Check Matrices Equality

int RandomNumber(int From, int To)
{
    int Number = rand() % (To - From + 1) + From;
    return Number;
}
void Fill2MatricesRandom(int arr1[3][3],int arr2[3][3], int Rows, int Cols)
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
int SumMatrix(int arr[3][3], int Rows, int Cols)
{
    int Sum = 0;
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            Sum += arr[i][j];
        }
    }
    return Sum;
}
bool isMatricesEqual(int arr1[3][3], int arr2[3][3], int Rows, int Cols)
{
    return SumMatrix(arr1, 3, 3) == SumMatrix(arr2, 3, 3);
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
    //Problem 11 - Check Matrices Equality

    srand((unsigned)time(NULL));
    
    cout << "Random Matrices: \n_________________\n";
    int arr1[3][3], arr2[3][3];
    Fill2MatricesRandom(arr1, arr2, 3, 3);

    cout << "\nThe Matrix1: \n";
    PrintMatrix(arr1, 3, 3);

    cout << "\nThe Matrix2: \n";
    PrintMatrix(arr2, 3, 3);

    if (isMatricesEqual(arr1, arr2, 3, 3))
        cout << "\nYes, the Matrices are equal\n";
    else
        cout << "\nNo, The Matrices are not equal\n";


    cout << "\nOrdered Matrices: \n_________________\n";
    int arr3[3][3], arr4[3][3];
    Fill2MatrixOrdered(arr3, arr4, 3, 3);

    cout << "\nThe Matrix1: \n";
    PrintMatrix(arr3, 3, 3);

    cout << "\nThe Matrix2: \n";
    PrintMatrix(arr4, 3, 3);

    if (isMatricesEqual(arr3, arr4, 3, 3))
        cout << "\nYes, the Matrices are equal\n";
    else
        cout << "\nNo, The Matrices are not equal\n";
}
