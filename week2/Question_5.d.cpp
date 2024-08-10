#include <iostream>
using namespace std;
class upperTriangularMatrix
{
protected:
    int index = 0;

private:
    int size;
    int *arr = nullptr;

public:
    upperTriangularMatrix(int size)
    {
        this->size = size;
        arr = new int[size * (size + 1) / 2]();
    }
    void set(int i, int j, int value)
    {

        if (j >= i)
        {
            arr[index++] = value;
        }
        else
        {
            cout << "not valid";
        }
    }
    void display()
    {
        int k = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (j >= i)
                {
                    cout << arr[k++] << " ";
                }
                else
                {
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
    upperTriangularMatrix matrix(n);

    // Set elements in the lower triangular matrix
    matrix.set(0, 0, 5);
    matrix.set(0, 1, 8);
    matrix.set(1, 1, 7);
    matrix.set(0, 2, 3);
    matrix.set(1, 2, 6);
    matrix.set(2, 2, 4);
    matrix.set(0, 3, 2);
    matrix.set(1, 3, 9);
    matrix.set(2, 3, 1);
    matrix.set(3, 3, 10);
    matrix.display();
    return 0;
}
