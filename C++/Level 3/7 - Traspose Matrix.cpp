#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Problem 7 - Traspose Matrix

void FillMatrixInOrder(int arr[3][3], short Rows, short Cols)
{
    short counter = 0;
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            counter++;
            arr[i][j] = counter;
        }
    }
}
void TrasposeMatrix(int arr[3][3], int TrasposeArr[3][3], int Rows, int Cols)
{
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            TrasposeArr[i][j] = arr[j][i];
        }
    }
}
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    
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
    //Problem 7 - Traspose Matrix

    int arr[3][3]; int TrasposeArr[3][3];

    cout << "\nThe following is a 3x3 ordered matrix:\n";
    FillMatrixInOrder(arr, 3, 3);
    PrintMatrix(arr, 3, 3);

    cout << "\nThe Following is 3x3 Traspose of the Matrix:\n";
    TrasposeMatrix(arr, TrasposeArr, 3, 3);
    PrintMatrix(TrasposeArr, 3, 3);
}
