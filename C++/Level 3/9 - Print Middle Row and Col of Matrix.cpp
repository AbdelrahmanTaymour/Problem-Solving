#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Problem 9 - Print Middle Row and Col of Matrix

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols)
{
    short MiddleRow = Rows / 2;
    for (short j = 0; j < Cols; j++)
    {
        printf(" %0*d ", 2, arr[MiddleRow][j]);
    }
    cout << "\n";
}

void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols)
{
    short MiddleCol = Cols / 2;
    for (short j = 0; j < Rows; j++)
    {
        printf(" %0*d ", 2, arr[j][MiddleCol]);
    }
    cout << "\n";
}

void PrintMartrix(int arr[3][3], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            printf(" %0*d ", 2, arr[i][j]);

        }
        cout << "\n";
    }
}

int main()
{
    //Problem 9 - Print Middle Row and Col of Matrix

    srand((unsigned)time(NULL));

    int arr[3][3];
    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "The Matrix: \n";
    PrintMartrix(arr, 3, 3);

    cout << "\nThe Middle Row: \n";
    PrintMiddleRowOfMatrix(arr, 3, 3);

    cout << "\nThe Middle Col: \n";
    PrintMiddleColOfMatrix(arr, 3, 3);
}
