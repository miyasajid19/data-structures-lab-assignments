#include <iostream>
#include <cstdlib>
using namespace std;
class SparseMatrix
{
    int **arr;
    int **sparseMatrix;
    int rows;
    int columns;
    int nonZeros;

public:
    SparseMatrix(int rows, int columns)
    {
        this->rows = rows;
        this->columns = columns;
    }
    void setMatrix()
    {

        arr = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[columns]();
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << "Element [" << i << "][" << j << "]::" << endl;
                cin >> arr[i][j];
            }
        }
    }
    int countNonZeros()
    {
        int count = 0;
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                if (arr[i][j] != 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
    void SparseIt()
    {
        this->nonZeros = countNonZeros();
        sparseMatrix = new int *[nonZeros + 1];
        for (int i = 0; i <= nonZeros; i++)
        {
            sparseMatrix[i] = new int[3];
        }
        sparseMatrix[0][0] = this->rows;
        sparseMatrix[0][1] = this->columns;
        sparseMatrix[0][2] = this->nonZeros;
        int k = 1;
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                if (arr[i][j] != 0)
                {
                    sparseMatrix[k][0] = i;
                    sparseMatrix[k][1] = j;
                    sparseMatrix[k][2] = arr[i][j];
                    k++;
                }
            }
        }
    }
    void DisplaySparse()
    {
        cout << "rows\tcolumns\tvalues" << endl;
        for (int i = 0; i <= this->nonZeros; i++)
        {

            cout << sparseMatrix[i][0] << "\t";
            cout << sparseMatrix[i][1] << "\t";
            cout << sparseMatrix[i][2] << "\n";
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    SparseMatrix mat(3, 3);
    mat.setMatrix();
    mat.SparseIt();
    mat.DisplaySparse();
    return EXIT_SUCCESS;
}