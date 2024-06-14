#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Problem 1 - 3*3 Random Matrix

int RandomNumber(int From, int To)
{
    return rand() % (To - From +1) + From;
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
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            cout <<setw(3)<< arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    //Problem 1 - 3*3 Random Matrix

    srand((unsigned)time(NULL));
    int arr[3][3];
    FillRandomMatrix(arr, 3, 3);
    PrintMatrix(arr, 3, 3);
}
