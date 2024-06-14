#include <iostream>
using namespace std;

//Problem 17 - Number Exists In Matrix

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

int main()
{
    //Problem 17 - Number Exists In Matrix

    int arr[3][3] = { {0,0,1},{0,0,0},{1,0,9} };
    int Number;
    cout << "The Matrix: \n";
    PrintMatrix(arr, 3, 3);
    
    cout << "\nPlease Enter the number to look for in Matrix? \n";
    cin >> Number;
    
    if (isExist(arr, 3, 3, Number))
        cout << "\nYes, it is there.\n";
    else
        cout << "\nNo, it is not there.\n";
}
