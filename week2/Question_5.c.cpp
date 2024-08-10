#include <iostream>
using namespace std;
class LowerTriangularMatrix
{
protected:
    int index = 0;

private:
    int size;
    int *arr = nullptr;

public:
    LowerTriangularMatrix(int size)
    {
        this->size = size;
        arr = new int[size * (size + 1) / 2]();
    }
    void set(int i, int j, int value)
    {

        if (i >= j)
        {
            arr[index++] = value;
        }
        else
        {
            cout << "not valid";
        }
    }
void display() {
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i >= j) {
                cout << arr[k++] << " "; 
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl; 
    }
}

    };

    int main()
    {
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif
        int n = 4; // Example size of the matrix (4x4)
        LowerTriangularMatrix matrix(n);

        // Set elements in the lower triangular matrix
        matrix.set(0, 0, 5);
        matrix.set(1, 0, 8);
        matrix.set(1, 1, 7);
        matrix.set(2, 0, 3);
        matrix.set(2, 1, 6);
        matrix.set(2, 2, 4);
        matrix.set(3, 0, 2);
        matrix.set(3, 1, 9);
        matrix.set(3, 2, 1);
        matrix.set(3, 3, 10);
        matrix.display();
        return 0;
    }
