#include <iostream>
using namespace std;

//Problem 20 - Palindrome Matrix

bool isPalindrome(int arr[3][3], int Rows, int Cols)
{
    for (int i = 0;i < Rows;i++)
    {
        for (int j = 0;j < Cols/2;j++)
        {
            if (arr[i][j] != arr[i][Cols - 1 - j])
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
            printf(" %02d    ", arr[i][j]);
        }
        cout << endl;
    }
}


int main()
{
    //Problem 20 - Palindrome Matrix

    int arr[3][3] = { {3,10,3},{3,0,3},{3,6,3} };

    cout << "The Matrix: \n";
    PrintMatrix(arr, 3, 3);

    if (isPalindrome(arr, 3, 3))
    cout << "\nYes: It is Palindrome.\n";
    else
    cout << "\nNo: It is not a Palindrome.\n";
}
