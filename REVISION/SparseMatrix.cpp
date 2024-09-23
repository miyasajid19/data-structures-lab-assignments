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
    SparseMatrix operator+(SparseMatrix A)
    {
        if (this->rows != A.rows || this->columns != A.columns)
        {
            cout << "Invalid matrix dimensions" << endl;
            exit(1);
        }

        SparseMatrix result(this->rows, this->columns);
        result.sparseMatrix = new int *[this->nonZeros + A.nonZeros + 1];
        for (int i = 0; i <= this->nonZeros + A.nonZeros; i++)
        {
            result.sparseMatrix[i] = new int[3];
        }

        result.sparseMatrix[0][0] = this->rows;
        result.sparseMatrix[0][1] = this->columns;

        int index1 = 1, index2 = 1, index3 = 1;

        while (index1 <= this->nonZeros && index2 <= A.nonZeros)
        {
            if (this->sparseMatrix[index1][0] == A.sparseMatrix[index2][0])
            {
                if (this->sparseMatrix[index1][1] == A.sparseMatrix[index2][1])
                {
                    result.sparseMatrix[index3][0] = this->sparseMatrix[index1][0];
                    result.sparseMatrix[index3][1] = this->sparseMatrix[index1][1];
                    result.sparseMatrix[index3][2] = this->sparseMatrix[index1][2] + A.sparseMatrix[index2][2];
                    index1++;
                    index2++;
                }
                else if (this->sparseMatrix[index1][1] < A.sparseMatrix[index2][1])
                {
                    result.sparseMatrix[index3][0] = this->sparseMatrix[index1][0];
                    result.sparseMatrix[index3][1] = this->sparseMatrix[index1][1];
                    result.sparseMatrix[index3][2] = this->sparseMatrix[index1][2];
                    index1++;
                }
                else
                {
                    result.sparseMatrix[index3][0] = A.sparseMatrix[index2][0];
                    result.sparseMatrix[index3][1] = A.sparseMatrix[index2][1];
                    result.sparseMatrix[index3][2] = A.sparseMatrix[index2][2];
                    index2++;
                }
            }
            else if (this->sparseMatrix[index1][0] < A.sparseMatrix[index2][0])
            {
                result.sparseMatrix[index3][0] = this->sparseMatrix[index1][0];
                result.sparseMatrix[index3][1] = this->sparseMatrix[index1][1];
                result.sparseMatrix[index3][2] = this->sparseMatrix[index1][2];
                index1++;
            }
            else
            {
                result.sparseMatrix[index3][0] = A.sparseMatrix[index2][0];
                result.sparseMatrix[index3][1] = A.sparseMatrix[index2][1];
                result.sparseMatrix[index3][2] = A.sparseMatrix[index2][2];
                index2++;
            }
            index3++;
        }

        while (index1 <= this->nonZeros)
        {
            result.sparseMatrix[index3][0] = this->sparseMatrix[index1][0];
            result.sparseMatrix[index3][1] = this->sparseMatrix[index1][1];
            result.sparseMatrix[index3][2] = this->sparseMatrix[index1][2];
            index1++;
            index3++;
        }

        while (index2 <= A.nonZeros)
        {
            result.sparseMatrix[index3][0] = A.sparseMatrix[index2][0];
            result.sparseMatrix[index3][1] = A.sparseMatrix[index2][1];
            result.sparseMatrix[index3][2] = A.sparseMatrix[index2][2];
            index2++;
            index3++;
        }

        result.sparseMatrix[0][2] = index3 - 1; // Update the number of non-zero elements
        result.nonZeros = index3 - 1;

        return result;
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
    SparseMatrix mat1(3, 3);
    mat1.setMatrix();
    mat1.SparseIt();
    mat1.DisplaySparse();
    SparseMatrix result = mat1 + mat + mat;
    result.DisplaySparse();
    return EXIT_SUCCESS;
}