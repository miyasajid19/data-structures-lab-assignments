#include <iostream>
#include <cstdlib>
using namespace std;
class SparseMatrix
{
    int **arr;
    int **sparseMatrix;
    int **TransposeSparse;
    int rows;
    int columns;
    int nonZeros;

public:
    SparseMatrix(int rows, int columns)
    {
        this->rows = rows;
        this->columns = columns;
        arr = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[columns];
        }
    }
    void setMatrix()
    {
        int count = 0;
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                cout << "Arr[" << i << "][" << j << "] :: " << endl;
                cin >> arr[i][j];
                if (arr[i][j] != 0)
                    count++;
            }
        }
        this->nonZeros = count++;
    }
    
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return EXIT_SUCCESS;
}