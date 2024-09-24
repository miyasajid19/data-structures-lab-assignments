#include <iostream>
#include <cstdlib>
using namespace std;

class Sparse
{
public:
    int **arr;
    int **sparseMatrix;
    int **transposedSparseMatrix;
    int rows;
    int columns;
    int nonZeros;

    int countNonZeros()
    {
        int count = 0;
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                if (arr[i][j] != 0)
                    count++;
            }
        }
        return count;
    }

    Sparse(int rows, int columns)
    {
        this->rows = rows;
        this->columns = columns;
        arr = new int *[rows];
        for (int i = 0; i < this->rows; i++)
        {
            arr[i] = new int[columns];
        }
        cout << "Template created" << endl;
    }

    void setMatrix()
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                cout << "Arr[" << i << "][" << j << "] ::: ";
                cin >> arr[i][j];
            }
        }
    }

    void sparseit()
    {
        this->nonZeros = countNonZeros();
        sparseMatrix = new int *[this->nonZeros + 1];
        for (int i = 0; i <= this->nonZeros; i++)
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
        cout << "Sparse matrix created" << endl;
    }

    void displaySparse()
    {
        if (sparseMatrix == nullptr)
        {
            cout << "Sparse matrix not created" << endl;
            return;
        }
        cout << "rows\tcolumns\tvalues\n";
        for (int i = 0; i <= this->nonZeros; i++)
        {
            cout << sparseMatrix[i][0] << "\t" << sparseMatrix[i][1] << "\t" << sparseMatrix[i][2] << endl;
        }
    }

    void RowMajorSort()
    {
        for (int i = 1; i <= this->nonZeros; i++)
        {
            for (int j = i + 1; j <= nonZeros; j++)
            {
                if (transposedSparseMatrix[i][0] > transposedSparseMatrix[j][0] ||
                    (transposedSparseMatrix[i][0] == transposedSparseMatrix[j][0] && transposedSparseMatrix[i][1] > transposedSparseMatrix[j][1]))
                {
                    swap(transposedSparseMatrix[i], transposedSparseMatrix[j]);
                }
            }
        }
    }

    void Transpose()
    {
        transposedSparseMatrix = new int *[this->nonZeros + 1];
        for (int i = 0; i <= this->nonZeros; i++)
        {
            transposedSparseMatrix[i] = new int[3];
        }
        transposedSparseMatrix[0][0] = this->columns; // rows and columns swapped for transpose
        transposedSparseMatrix[0][1] = this->rows;
        transposedSparseMatrix[0][2] = this->nonZeros;

        int k = 1;
        for (int i = 1; i <= this->nonZeros; i++)
        {
            transposedSparseMatrix[k][0] = sparseMatrix[i][1];
            transposedSparseMatrix[k][1] = sparseMatrix[i][0];
            transposedSparseMatrix[k][2] = sparseMatrix[i][2];
            k++;
        }
        RowMajorSort();
        cout << "Transpose of sparse matrix created" << endl;
    }

    void displayTransposedSparse()
    {
        if (transposedSparseMatrix == nullptr)
        {
            cout << "Transpose matrix not created" << endl;
            return;
        }
        cout << "rows\tcolumns\tvalues\n";
        for (int i = 0; i <= this->nonZeros; i++)
        {
            cout << transposedSparseMatrix[i][0] << "\t" << transposedSparseMatrix[i][1] << "\t" << transposedSparseMatrix[i][2] << endl;
        }
    }
    void addition(Sparse other)
    {
        int result[this->nonZeros + other.nonZeros + 1][3];
        result[0][0] = this->rows;
        result[0][1] = this->columns;
        result[0][2] = 0;

        if (this->rows == other.rows && this->columns == other.columns)
        {
            int index1 = 1, index2 = 1, index3 = 1;

            while (index1 <= this->nonZeros && index2 <= other.nonZeros)
            {
                if (this->sparseMatrix[index1][0] == other.sparseMatrix[index2][0])
                {
                    if (this->sparseMatrix[index1][1] == other.sparseMatrix[index2][1])
                    {
                        result[index3][0] = this->sparseMatrix[index1][0];
                        result[index3][1] = this->sparseMatrix[index1][1];
                        result[index3][2] = this->sparseMatrix[index1][2] + other.sparseMatrix[index2][2];
                        index1++;
                        index2++;
                    }
                    else if (this->sparseMatrix[index1][1] < other.sparseMatrix[index2][1])
                    {
                        result[index3][0] = this->sparseMatrix[index1][0];
                        result[index3][1] = this->sparseMatrix[index1][1];
                        result[index3][2] = this->sparseMatrix[index1][2];
                        index1++;
                    }
                    else
                    {
                        result[index3][0] = other.sparseMatrix[index2][0];
                        result[index3][1] = other.sparseMatrix[index2][1];
                        result[index3][2] = other.sparseMatrix[index2][2];
                        index2++;
                    }
                }
                else if (this->sparseMatrix[index1][0] < other.sparseMatrix[index2][0])
                {
                    result[index3][0] = this->sparseMatrix[index1][0];
                    result[index3][1] = this->sparseMatrix[index1][1];
                    result[index3][2] = this->sparseMatrix[index1][2];
                    index1++;
                }
                else
                {
                    result[index3][0] = other.sparseMatrix[index2][0];
                    result[index3][1] = other.sparseMatrix[index2][1];
                    result[index3][2] = other.sparseMatrix[index2][2];
                    index2++;
                }
                index3++;
            }

            while (index1 <= this->nonZeros)
            {
                result[index3][0] = this->sparseMatrix[index1][0];
                result[index3][1] = this->sparseMatrix[index1][1];
                result[index3][2] = this->sparseMatrix[index1][2];
                index1++;
                index3++;
            }

            while (index2 <= other.nonZeros)
            {
                result[index3][0] = other.sparseMatrix[index2][0];
                result[index3][1] = other.sparseMatrix[index2][1];
                result[index3][2] = other.sparseMatrix[index2][2];
                index2++;
                index3++;
            }

            result[0][2] = index3 - 1;
            cout << "Resultant Sparse Matrix after Addition:" << endl;
            cout << "Row\tCol\tValue" << endl;
            for (int i = 0; i < index3; i++)
            {
                cout << result[i][0] << "\t" << result[i][1] << "\t" << result[i][2] << endl;
            }
        }
        else
        {
            cout << "Matrices cannot be added as dimensions do not match." << endl;
        }
    }
    void Multiplication(Sparse &other)
    {
        if (this->columns != other.rows)
        {
            cout << "Matrices cannot be multiplied due to dimension mismatch." << endl;
            return;
        }

        int **result = new int *[this->rows];
        for (int i = 0; i < this->rows; i++)
        {
            result[i] = new int[other.columns]();
        }

        for (int i = 1; i <= this->nonZeros; i++)
        {
            for (int j = 1; j <= other.nonZeros; j++)
            {
                if (this->sparseMatrix[i][1] == other.sparseMatrix[j][0])
                {
                    result[this->sparseMatrix[i][0]][other.sparseMatrix[j][1]] +=
                        this->sparseMatrix[i][2] * other.sparseMatrix[j][2];
                }
            }
        }

        int resultNonZeros = 0;
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < other.columns; j++)
            {
                if (result[i][j] != 0)
                    resultNonZeros++;
            }
        }

        int **sparseResult = new int *[resultNonZeros + 1];
        for (int i = 0; i <= resultNonZeros; i++)
        {
            sparseResult[i] = new int[3];
        }
        sparseResult[0][0] = this->rows;
        sparseResult[0][1] = other.columns;
        sparseResult[0][2] = resultNonZeros;

        int k = 1;
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < other.columns; j++)
            {
                if (result[i][j] != 0)
                {
                    sparseResult[k][0] = i;
                    sparseResult[k][1] = j;
                    sparseResult[k][2] = result[i][j];
                    k++;
                }
            }
        }

        cout << "Resultant Sparse Matrix after Multiplication:" << endl;
        cout << "Row\tCol\tValue" << endl;
        for (int i = 0; i <= resultNonZeros; i++)
        {
            cout << sparseResult[i][0] << "\t" << sparseResult[i][1] << "\t" << sparseResult[i][2] << endl;
        }

        for (int i = 0; i < this->rows; i++)
        {
            delete[] result[i];
        }
        delete[] result;

        for (int i = 0; i <= resultNonZeros; i++)
        {
            delete[] sparseResult[i];
        }
        delete[] sparseResult;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int rows1, cols1, rows2, cols2;

    // Input first sparse matrix
    cout << "Enter dimensions for the first sparse matrix (rows columns): ";
    cin >> rows1 >> cols1;
    Sparse mat1(rows1, cols1);
    cout << "Enter values for the first sparse matrix:" << endl;
    mat1.setMatrix();
    mat1.sparseit();
    cout << "Sparse matrix 1:" << endl;
    mat1.displaySparse();

    // Input second sparse matrix
    cout << "Enter dimensions for the second sparse matrix (rows columns): ";
    cin >> rows2 >> cols2;
    Sparse mat2(rows2, cols2);
    cout << "Enter values for the second sparse matrix:" << endl;
    mat2.setMatrix();
    mat2.sparseit();
    cout << "Sparse matrix 2:" << endl;
    mat2.displaySparse();

    // Transpose and display the first sparse matrix
    mat1.Transpose();
    cout << "Transposed Sparse Matrix 1:" << endl;
    mat1.displayTransposedSparse();

    // Transpose and display the second sparse matrix
    mat2.Transpose();
    cout << "Transposed Sparse Matrix 2:" << endl;
    mat2.displayTransposedSparse();

    // Addition of the two sparse matrices
    if (rows1 == rows2 && cols1 == cols2)
    {
        cout << "Adding sparse matrix 1 and sparse matrix 2..." << endl;
        mat1.addition(mat2);
    }
    else
    {
        cout << "Matrices cannot be added as dimensions do not match." << endl;
    }

    // Multiplication of the two sparse matrices
    if (cols1 == rows2)
    {
        cout << "Multiplying sparse matrix 1 and sparse matrix 2..." << endl;
        mat1.Multiplication(mat2);
    }
    else
    {
        cout << "Matrices cannot be multiplied due to dimension mismatch." << endl;
    }

    return EXIT_SUCCESS;
}
