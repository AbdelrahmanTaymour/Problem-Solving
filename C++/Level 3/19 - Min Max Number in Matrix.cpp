#include <iostream>
using namespace std;

//Problem 19 - Min Max Number in Matrix

int MaxNumberInMatrix(int arr[3][3], int Rows, int Cols)
{
    int Max = arr[0][0];
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            if (arr[i][j] > Max)
                Max = arr[i][j];
        }
    }
    return Max;
}
int MinNumberInMatrix(int arr[3][3], int Rows, int Cols)
{
    int Min = arr[0][0];
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols;j++)
        {
            if (Min > arr[i][j])
                Min = arr[i][j];
        }
    }
    return Min;
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
    //Problem 19 - Min Max Number in Matrix

    int arr[3][3] = { {15,10,1},{3,0,80},{1,6,9} };

    cout << "The Matrix: \n";
    PrintMatrix(arr, 3, 3);

    cout << "\nThe Min Number: " << MinNumberInMatrix(arr, 3, 3) << endl;;

    cout << "\nThe Max Number: " << MaxNumberInMatrix(arr, 3, 3) << endl;
}
