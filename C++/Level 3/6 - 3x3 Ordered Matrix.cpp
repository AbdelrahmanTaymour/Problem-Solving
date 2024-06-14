#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Problem 6 - 3x3 Ordered Matrix

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
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    cout << "\nThe following is a 3x3 ordered matrix:\n";
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
    //Problem 6 - 3x3 Ordered Matrix

    srand((unsigned)time(NULL));
    int arr[3][3];
    FillMatrixInOrder(arr, 3, 3);
    PrintMatrix(arr, 3, 3);
}
