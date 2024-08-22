#include <iostream>
#include <cstdlib>
#include <algorithm> // for std::sort
using namespace std;

class SparseMatrix
{
private:
    int **sparse = nullptr;
    int nonZeros;
    int rows, columns;
    int current;

public:
    SparseMatrix(int rows, int columns, int nonZeros)
    {
        this->rows = rows;
        this->columns = columns;
        this->nonZeros = nonZeros;
        this->current = 1; // Start from 1 because index 0 is reserved for matrix dimensions
        sparse = new int *[nonZeros + 1]; // Create an array for storing non-zero values
        for (int i = 0; i <= nonZeros; i++)
        {
            sparse[i] = new int[3]; // Each element holds row, column, and value
        }

        sparse[0][0] = rows;
        sparse[0][1] = columns;
        sparse[0][2] = nonZeros;
    }

    ~SparseMatrix()
    {
        for (int i = 0; i <= nonZeros; i++)
        {
            delete[] sparse[i];
        }
        delete[] sparse;
    }

    void setMatrix(int row, int column, int value)
    {
        if (row >= rows || column >= columns || row < 0 || column < 0)
        {
            cout << "Invalid indexing" << endl;
            return;
        }

        if (current <= nonZeros)
        {
            sparse[current][0] = row;
            sparse[current][1] = column;
            sparse[current][2] = value;
            current++;
        }
        else
        {
            cout << "Exceeded non-zero element limit" << endl;
        }
    }

    void displaySparse() const
    {
        for (int i = 0; i <= nonZeros; i++)
        {
            cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << "\n";
        }
    }

    void displayMatrix() const
    {
        int count = 1;
        for (int i = 0; i < this->sparse[0][0]; i++)
        {
            for (int j = 0; j < this->sparse[0][1]; j++)
            {
                if (count <= nonZeros && sparse[count][0] == i && sparse[count][1] == j)
                {
                    cout << this->sparse[count][2] << "\t";
                    ++count;
                }
                else
                {
                    cout << 0 << "\t";
                }
            }
            cout << endl;
        }
    }

    static bool sortSparse(const int *a, const int *b)
    {
        if (a[0] == b[0])
            return a[1] < b[1]; // Sort by column if rows are equal
        return a[0] < b[0];     // Sort by row
    }

    SparseMatrix Transpose() const
    {
        SparseMatrix transposed(this->columns, this->rows, this->nonZeros); // Create template for transposed matrix
        transposed.sparse[0][0] = this->columns;
        transposed.sparse[0][1] = this->rows;
        transposed.sparse[0][2] = this->nonZeros;

        // Transpose the elements by swapping rows and columns
        for (int i = 1; i <= this->nonZeros; i++)
        {
            transposed.sparse[i][0] = this->sparse[i][1]; // Swap row and column
            transposed.sparse[i][1] = this->sparse[i][0];
            transposed.sparse[i][2] = this->sparse[i][2];
        }

        // Sort the transposed matrix to maintain row-major order
        sort(transposed.sparse + 1, transposed.sparse + nonZeros + 1, sortSparse);

        return transposed;
    }

SparseMatrix operator*(const SparseMatrix &b) const
    {
        if (this->columns != b.rows)
        {
            cout << "Matrix dimensions do not match for multiplication." << endl;
            exit(EXIT_FAILURE);
        }

        SparseMatrix bTransposed = b.Transpose();
        SparseMatrix result(this->rows, b.columns, this->rows * b.columns);

        int apos = 1;
        int bpos;

        while (apos <= this->nonZeros)
        {
            int r = this->sparse[apos][0];

            bpos = 1;
            while (bpos <= bTransposed.nonZeros)
            {
                int c = bTransposed.sparse[bpos][0];

                int tempa = apos;
                int tempb = bpos;

                int sum = 0;

                while (tempa <= this->nonZeros && this->sparse[tempa][0] == r &&
                       tempb <= bTransposed.nonZeros && bTransposed.sparse[tempb][0] == c)
                {
                    if (this->sparse[tempa][1] < bTransposed.sparse[tempb][1])
                        ++tempa;
                    else if (this->sparse[tempa][1] > bTransposed.sparse[tempb][1])
                        ++tempb;
                    else
                        sum += this->sparse[tempa++][2] * bTransposed.sparse[tempb++][2];
                }

                if (sum != 0)
                    result.setMatrix(r, c, sum);

                while (bpos <= bTransposed.nonZeros && bTransposed.sparse[bpos][0] == c)
                    ++bpos;
            }

            while (apos <= this->nonZeros && this->sparse[apos][0] == r)
                ++apos;
        }

        result.nonZeros = result.current - 1;
        return result;
    }
};

int main()
{
    SparseMatrix mat1(4, 4, 4);
    mat1.setMatrix(0, 0, 1);
    mat1.setMatrix(1, 1, 3);
    mat1.setMatrix(2, 2, 2);
    mat1.setMatrix(3, 3, 1);

    SparseMatrix mat2(4, 4, 4);
    mat2.setMatrix(0, 0, 2);
    mat2.setMatrix(1, 1, 3);
    mat2.setMatrix(2, 2, 4);
    mat2.setMatrix(3, 3, 5);

    cout << "Matrix A:" << endl;
    mat1.displayMatrix();
    cout << endl;

    cout << "Matrix B:" << endl;
    mat2.displayMatrix();
    cout << endl;

    SparseMatrix product = mat1 * mat2;
    cout << "Product Matrix:" << endl;
    product.displayMatrix();
    cout << endl;

    SparseMatrix A(2,2,2);
    A.setMatrix(0,0,1);
    A.setMatrix(0,1,2);
    A.displayMatrix();
    cout << endl;
    SparseMatrix B(2,2,2);
    B.setMatrix(1,0,1);
    B.setMatrix(1,1,2);
    B.displayMatrix();

    cout << endl;
    SparseMatrix C=A*B;

    C.displayMatrix();
    return EXIT_SUCCESS;
}
