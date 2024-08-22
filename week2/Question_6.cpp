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
        this->current = 1;                // Start from 1 because index 0 is reserved for matrix dimensions
        sparse = new int *[nonZeros + 1]; // Create an array for storing non-zero values
        for (int i = 0; i <= nonZeros; i++)
        {
            sparse[i] = new int[3]; // Each element holds row, column, and value
        }

        sparse[0][0] = rows;
        sparse[0][1] = columns;
        sparse[0][2] = nonZeros;
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

    void displaySparse()
    {
        for (int i = 0; i <= nonZeros; i++)
        {
            cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << "\n";
        }
    }

    void displayMatrix()
    {
        int count = 1;
        for (int i = 0; i < this->sparse[0][0]; i++)
        {
            for (int j = 0; j < this->sparse[0][1]; j++)
            {
                if (count <= nonZeros and sparse[count][0] == i and sparse[count][1] == j)
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

    // Helper function to sort the sparse matrix based on rows, and if rows are same, then based on columns
    static bool sortSparse(const int *a, const int *b)
    {
        if (a[0] == b[0])
            return a[1] < b[1]; // Sort by column if rows are equal
        return a[0] < b[0];     // Sort by row
    }

    SparseMatrix Transpose()
    {
        SparseMatrix transposed(this->columns, this->rows, this->nonZeros); // create template for transposed matrix
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
    SparseMatrix operator+(const SparseMatrix &other)
    {
        // Check if the dimensions match for addition
        if (this->rows != other.rows || this->columns != other.columns)
        {
            cout << "Matrix dimensions do not match for addition." << endl;
            exit(EXIT_FAILURE); // Exit if dimensions are incompatible
        }

        // Create a result matrix, initially assuming the worst case (nonZeros of both matrices)
        SparseMatrix sum(this->rows, this->columns, this->nonZeros + other.nonZeros);

        int i = 1, j = 1, k = 1; // i and j are for the current positions in both matrices, k is for the result matrix

        // Traverse through both sparse matrices
        while (i <= this->nonZeros && j <= other.nonZeros)
        {
            // If the current element in this matrix comes before the current element in other
            if (this->sparse[i][0] < other.sparse[j][0] ||
                (this->sparse[i][0] == other.sparse[j][0] && this->sparse[i][1] < other.sparse[j][1]))
            {
                sum.sparse[k][0] = this->sparse[i][0];
                sum.sparse[k][1] = this->sparse[i][1];
                sum.sparse[k][2] = this->sparse[i][2];
                i++;
            }
            // If the current element in other matrix comes before the current element in this
            else if (other.sparse[j][0] < this->sparse[i][0] ||
                     (other.sparse[j][0] == this->sparse[i][0] && other.sparse[j][1] < this->sparse[i][1]))
            {
                sum.sparse[k][0] = other.sparse[j][0];
                sum.sparse[k][1] = other.sparse[j][1];
                sum.sparse[k][2] = other.sparse[j][2];
                j++;
            }
            // If both elements have the same row and column, add their values
            else
            {
                sum.sparse[k][0] = this->sparse[i][0];
                sum.sparse[k][1] = this->sparse[i][1];
                sum.sparse[k][2] = this->sparse[i][2] + other.sparse[j][2];
                i++;
                j++;
            }
            k++;
        }

        // Copy any remaining elements from this matrix
        while (i <= this->nonZeros)
        {
            sum.sparse[k][0] = this->sparse[i][0];
            sum.sparse[k][1] = this->sparse[i][1];
            sum.sparse[k][2] = this->sparse[i][2];
            i++;
            k++;
        }

        // Copy any remaining elements from the other matrix
        while (j <= other.nonZeros)
        {
            sum.sparse[k][0] = other.sparse[j][0];
            sum.sparse[k][1] = other.sparse[j][1];
            sum.sparse[k][2] = other.sparse[j][2];
            j++;
            k++;
        }

        // Update the number of non-zero elements in the sum matrix
        sum.sparse[0][2] = k - 1;

        return sum;
    }
};
int main()
{
    SparseMatrix mat(4, 4, 4);
    mat.setMatrix(0, 0, 1);
    mat.setMatrix(1, 1, 3);
    mat.setMatrix(3, 0, 2);
    mat.setMatrix(3, 3, 1);

    cout << "Original Sparse Matrix:" << endl;
    mat.displaySparse();
    cout << endl;

    cout << "Original Matrix Representation:" << endl;
    mat.displayMatrix();
    cout << endl;

    SparseMatrix transposed = mat.Transpose();
    cout << "Transposed Matrix Representation:" << endl;
    transposed.displayMatrix();
    cout << endl;
    transposed = transposed + mat;
    transposed.displayMatrix();
    return EXIT_SUCCESS;
}