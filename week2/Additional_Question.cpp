#include <iostream>
#include <cstdlib>
using namespace std;

int saddlePoint(int **arr, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        int minRow = arr[i][0];
        int colIndex = 0;
        for (int j = 1; j < column; j++)
        {
            if (arr[i][j] < minRow)
            {
                minRow = arr[i][j];
                colIndex = j;
            }
        }

        bool isSaddle = true;
        for (int k = 0; k < row; k++)
        {
            if (arr[k][colIndex] > minRow)
            {
                isSaddle = false;
                break;
            }
        }

        if (isSaddle)
        {
            return minRow;
        }
    }
    return -1;
}

int main()
{
    int **arr;
    int row, column;
    cout << "Enter the dimensions of the 2-D array (rows and columns): ";
    cin >> row >> column;

    arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[column];
    }

    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> arr[i][j];
        }
    }

    int saddle = saddlePoint(arr, row, column);
    if (saddle == -1)
    {
        cout << "No saddle point found.\n";
    }
    else
    {
        cout << "Saddle point: " << saddle << endl;
    }

    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return EXIT_SUCCESS;
}
