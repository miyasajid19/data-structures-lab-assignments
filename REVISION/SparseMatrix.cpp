#include <iostream>
#include <cstdlib>
using namespace std;
class SparseMatrix
{
    int **arr;
    int **sparseMatrix;
    int **transposedMatrix;
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
    void RowMajorSort()
    {
        for (int i = 1; i <= this->nonZeros; i++)
        {
            for (int j = i + 1; j <= this->nonZeros; j++)
            {
                if (transposedMatrix[i][0] > transposedMatrix[j][0] or (transposedMatrix[i][0] == transposedMatrix[j][0] and transposedMatrix[i][1] > transposedMatrix[j][1]))
                {
                    swap(transposedMatrix[i], transposedMatrix[j]);
                }
            }
        }
    }
    void Transpose()
    {
        transposedMatrix = new int *[this->nonZeros + 1];
        for (int i = 0; i <= this->nonZeros; i++)
        {
            transposedMatrix[i] = new int[3];
        }
        transposedMatrix[0][0] = this->columns;
        transposedMatrix[0][1] = this->rows;
        transposedMatrix[0][2] = this->nonZeros;

        int k = 1;
        for (int i = 1; i <= this->nonZeros; i++)
        {
            transposedMatrix[k][0] = sparseMatrix[i][1];
            transposedMatrix[k][1] = sparseMatrix[i][0];
            transposedMatrix[k][2] = sparseMatrix[i][2];
            k++;
        }
        RowMajorSort();
        cout << "Transpose of sparse matrix created" << endl;
    }

    void displayTransposedSparse()
    {
        if (transposedMatrix == nullptr)
        {
            cout << "Transpose matrix not created" << endl;
            return;
        }
        cout << "rows\tcolumns\tvalues\n";
        for (int i = 0; i <= this->nonZeros; i++)
        {
            cout << transposedMatrix[i][0] << "\t" << transposedMatrix[i][1] << "\t" << transposedMatrix[i][2] << endl;
        }
    }
    void Mul(SparseMatrix other)
    {
        // if (this->columns != A.rows)
        // {
        //     cout << "Matrix dimension is not valid" << endl;
        //     exit(1);
        // }
        // SparseMatrix result(this->rows, A.columns);
        // int count=0;
        // for (int i = 1; i <= nonZeros; i++)
        // {
        //     for (int j = 1; j <= A.nonZeros; j++)
        //     {
        //         if (this->sparseMatrix[i][1] == A.sparseMatrix[j][0])
        //         {
        //             count++;
        //             result.sparseMatrix[this->sparseMatrix[i][0]][A.sparseMatrix[j][1]] += this->sparseMatrix[i][2] * A.sparseMatrix[j][2];
        //         }
        //     }
        // }
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
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    SparseMatrix mat(3, 3);
    mat.setMatrix();
    mat.SparseIt();
    mat.DisplaySparse();
    mat.Transpose();
    mat.displayTransposedSparse();
    SparseMatrix mat1(3, 3);
    mat1.setMatrix();
    mat1.SparseIt();
    mat1.DisplaySparse();
    SparseMatrix result = mat1 + mat1 + mat + mat;
    result.DisplaySparse();
    result.Transpose();



    cout<<endl<<endl;
    SparseMatrix A(2,2);
    A.setMatrix();
    A.SparseIt();
    A.Transpose();
    SparseMatrix B(2,2);
    B.setMatrix();
    B.SparseIt();
    B.Transpose();
    A.Mul(B);
    return EXIT_SUCCESS;
}