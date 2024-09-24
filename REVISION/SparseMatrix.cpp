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
    void SparseIt()
    {
        sparseMatrix = new int *[this->nonZeros + 1];
        for (int i = 0; i <= this->nonZeros; i++)
        {
            sparseMatrix[i] = new int[3];
        }
        sparseMatrix[0][0] = this->rows;
        sparseMatrix[0][1] = this->columns;
        sparseMatrix[0][2] = this->nonZeros;
        int index = 1;
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                if (arr[i][j] != 0)
                {
                    sparseMatrix[index][0] = i;
                    sparseMatrix[index][1] = j;
                    sparseMatrix[index][2] = i;
                    index++;
                }
            }
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "Enter dimension of matrix :: " << endl;
    int rows, columns;
    cin >> rows >> columns;
    SparseMatrix A(rows, columns);
    A.setMatrix();
    return EXIT_SUCCESS;
}