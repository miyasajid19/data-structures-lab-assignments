#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class SparseMatrix
{
    vector<vector<int>> arr;
    vector<vector<int>> sparseMatrix;
    vector<vector<int>> transposedMatrix;
    int rows, columns, nonZeros;

public:
    SparseMatrix(int rows, int columns) : rows(rows), columns(columns), nonZeros(0) {}

    void setMatrix()
    {
        arr.resize(rows, vector<int>(columns, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << "Element [" << i << "][" << j << "]:: ";
                cin >> arr[i][j];
            }
        }
    }

    int countNonZeros()
    {
        int count = 0;
        for (const auto &row : arr)
        {
            for (int val : row)
            {
                if (val != 0)
                    count++;
            }
        }
        return count;
    }

    void SparseIt()
    {
        nonZeros = countNonZeros();
        sparseMatrix.resize(nonZeros + 1, vector<int>(3));
        sparseMatrix[0] = {rows, columns, nonZeros};

        int k = 1;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (arr[i][j] != 0)
                {
                    sparseMatrix[k++] = {i, j, arr[i][j]};
                }
            }
        }
    }

    void DisplaySparse() const
    {
        cout << "rows\tcolumns\tvalues" << endl;
        for (const auto &row : sparseMatrix)
        {
            cout << row[0] << "\t" << row[1] << "\t" << row[2] << "\n";
        }
    }

    SparseMatrix operator+(const SparseMatrix &A) const
    {
        if (rows != A.rows || columns != A.columns)
        {
            throw invalid_argument("Invalid matrix dimensions for addition");
        }

        SparseMatrix result(rows, columns);
        result.sparseMatrix.resize(nonZeros + A.nonZeros + 1, vector<int>(3));
        result.sparseMatrix[0] = {rows, columns, 0};

        int index1 = 1, index2 = 1, index3 = 1;

        while (index1 <= nonZeros && index2 <= A.nonZeros)
        {
            if (sparseMatrix[index1][0] == A.sparseMatrix[index2][0])
            {
                if (sparseMatrix[index1][1] == A.sparseMatrix[index2][1])
                {
                    result.sparseMatrix[index3++] = {
                        sparseMatrix[index1][0],
                        sparseMatrix[index1][1],
                        sparseMatrix[index1][2] + A.sparseMatrix[index2][2]};
                    index1++;
                    index2++;
                }
                else if (sparseMatrix[index1][1] < A.sparseMatrix[index2][1])
                {
                    result.sparseMatrix[index3++] = sparseMatrix[index1++];
                }
                else
                {
                    result.sparseMatrix[index3++] = A.sparseMatrix[index2++];
                }
            }
            else if (sparseMatrix[index1][0] < A.sparseMatrix[index2][0])
            {
                result.sparseMatrix[index3++] = sparseMatrix[index1++];
            }
            else
            {
                result.sparseMatrix[index3++] = A.sparseMatrix[index2++];
            }
        }

        while (index1 <= nonZeros)
        {
            result.sparseMatrix[index3++] = sparseMatrix[index1++];
        }

        while (index2 <= A.nonZeros)
        {
            result.sparseMatrix[index3++] = A.sparseMatrix[index2++];
        }

        result.sparseMatrix[0][2] = index3 - 1; // Update number of non-zero elements
        return result;
    }

    SparseMatrix operator*(const SparseMatrix &other) const
    {
        if (columns != other.rows)
        {
            throw invalid_argument("Matrices cannot be multiplied due to dimension mismatch.");
        }

        SparseMatrix result(rows, other.columns);
        result.sparseMatrix.resize(rows * other.columns + 1, vector<int>(3));
        result.sparseMatrix[0] = {rows, other.columns, 0};

        vector<vector<int>> temp(rows, vector<int>(other.columns, 0));

        for (int i = 1; i <= nonZeros; i++)
        {
            for (int j = 1; j <= other.nonZeros; j++)
            {
                if (sparseMatrix[i][1] == other.sparseMatrix[j][0])
                {
                    temp[sparseMatrix[i][0]][other.sparseMatrix[j][1]] +=
                        sparseMatrix[i][2] * other.sparseMatrix[j][2];
                }
            }
        }

        int k = 1;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.columns; j++)
            {
                if (temp[i][j] != 0)
                {
                    result.sparseMatrix[k++] = {i, j, temp[i][j]};
                }
            }
        }

        result.sparseMatrix[0][2] = k - 1; // Update number of non-zero elements
        return result;
    }

    void Transpose()
    {
        transposedMatrix.resize(nonZeros + 1, vector<int>(3));
        transposedMatrix[0] = {columns, rows, nonZeros};

        for (int i = 1; i <= nonZeros; i++)
        {
            transposedMatrix[i] = {sparseMatrix[i][1], sparseMatrix[i][0], sparseMatrix[i][2]};
        }
        RowMajorSort();
        cout << "Transpose of sparse matrix created" << endl;
    }

    void RowMajorSort()
    {
        for (int i = 1; i <= nonZeros; i++)
        {
            for (int j = i + 1; j <= nonZeros; j++)
            {
                if (transposedMatrix[i][0] > transposedMatrix[j][0] ||
                    (transposedMatrix[i][0] == transposedMatrix[j][0] && transposedMatrix[i][1] > transposedMatrix[j][1]))
                {
                    swap(transposedMatrix[i], transposedMatrix[j]);
                }
            }
        }
    }

    void displayTransposedSparse() const
    {
        if (transposedMatrix.empty())
        {
            cout << "Transpose matrix not created" << endl;
            return;
        }
        cout << "rows\tcolumns\tvalues\n";
        for (const auto &row : transposedMatrix)
        {
            cout << row[0] << "\t" << row[1] << "\t" << row[2] << endl;
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

    SparseMatrix sumResult = mat1 + mat1 + mat + mat;
    sumResult.DisplaySparse();
    sumResult.Transpose();

    cout << endl
         << endl;

    SparseMatrix A(2, 2);
    A.setMatrix();
    A.SparseIt();
    A.Transpose();

    SparseMatrix B(2, 2);
    B.setMatrix();
    B.SparseIt();
    B.Transpose();

    SparseMatrix mulResult = A * B;
    cout << "Result of Multiplication:" << endl;
    mulResult.DisplaySparse();

    return EXIT_SUCCESS;
}
