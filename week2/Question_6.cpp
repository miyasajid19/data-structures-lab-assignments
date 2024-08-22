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

    SparseMatrix operator*(const SparseMatrix &other) const
    {
        // Check if the dimensions match for multiplication
        if (this->columns != other.rows)
        {
            cout << "Matrix dimensions do not match for multiplication." << endl;
            exit(EXIT_FAILURE); // Exit if dimensions are incompatible
        }

        // Transpose the second matrix
        SparseMatrix otherTransposed = other.Transpose();

        // Create a result matrix with the appropriate size
        SparseMatrix product(this->rows, other.columns, this->rows * other.columns);

        int count = 1;

        // Multiply the matrices
        for (int i = 1; i <= this->nonZeros; ++i)
        {
            int rowA = this->sparse[i][0];
            int colA = this->sparse[i][1];
            int valA = this->sparse[i][2];

            for (int j = 1; j <= otherTransposed.nonZeros; ++j)
            {
                int rowB = otherTransposed.sparse[j][0];
                int colB = otherTransposed.sparse[j][1];
                int valB = otherTransposed.sparse[j][2];

                if (colA == rowB)
                {
                    int newRow = rowA;
                    int newCol = colB;
                    int newValue = valA * valB;

                    // Check if this (newRow, newCol) already has a value in the product matrix
                    bool found = false;
                    for (int k = 1; k <= count; ++k)
                    {
                        if (product.sparse[k][0] == newRow && product.sparse[k][1] == newCol)
                        {
                            product.sparse[k][2] += newValue;
                            found = true;
                            break;
                        }
                    }

                    // If not found, add a new entry
                    if (!found)
                    {
                        product.sparse[count][0] = newRow;
                        product.sparse[count][1] = newCol;
                        product.sparse[count][2] = newValue;
                        ++count;
                    }
                }
            }
        }

        // Update the number of non-zero elements in the product matrix
        product.sparse[0][2] = count - 1;

        return product;
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
