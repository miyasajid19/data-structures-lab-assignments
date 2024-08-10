#include <iostream>
using namespace std;

class SparseMatrix {
public:
    int *rowIndex = nullptr;
    int *columnIndex = nullptr;
    int *values = nullptr;
    int rows, columns, nonzeros;

    SparseMatrix(int row, int column, int nonZero) {
        this->rows = row;
        this->columns = column;
        this->nonzeros = nonZero;
        rowIndex = new int[nonZero]();
        columnIndex = new int[nonZero]();
        values = new int[nonZero]();
    }

    ~SparseMatrix() {
        delete[] rowIndex;
        delete[] columnIndex;
        delete[] values;
    }

    void set(int row, int column, int value, int index) {
        if (index >= nonzeros) {
            cerr << "Index out of bounds!" << endl;
            return;
        }
        rowIndex[index] = row;
        columnIndex[index] = column;
        values[index] = value;
    }

    void display() {
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (k < nonzeros && rowIndex[k] == i && columnIndex[k] == j) {
                    cout << values[k++] << " ";
                } else {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }
};

SparseMatrix Transpose(const SparseMatrix& matrix) {
    SparseMatrix transposed(matrix.columns, matrix.rows, matrix.nonzeros);
    for (int i = 0; i < matrix.nonzeros; i++) {
        transposed.set(matrix.columnIndex[i], matrix.rowIndex[i], matrix.values[i], i);
    }
    return transposed;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int rows = 4, cols = 4, nnz = 4;
    SparseMatrix matrix(rows, cols, nnz);

    // Set elements (row, col, value, index)
    matrix.set(0, 1, 5, 0);
    matrix.set(1, 2, 8, 1);
    matrix.set(2, 3, 6, 2);
    matrix.set(3, 0, 7, 3);

    // Display the original sparse matrix
    matrix.display();
    cout << endl;

    // Display the transposed sparse matrix
    SparseMatrix transposed = Transpose(matrix);
    transposed.display();

    return 0;
}
