#include <iostream>
using namespace std;
class symmetricMatrix
{
protected:
    int index = 0;

private:
    int size;
    int *arr = nullptr;

public:
    symmetricMatrix(int size)
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
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i >= j)
                {
                    index = i * (i + 1) / 2 + j;
                    cout << arr[index] << " ";
                }
                else
                {

                    index = j * (j + 1) / 2 + i;
                    cout << arr[index] << " ";
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
    int n = 4; 
    symmetricMatrix matrix(n);

    matrix.set(0, 0, 1);
    matrix.set(1, 0, 2);
    matrix.set(1, 1, 3);
    matrix.set(2, 0, 4);
    matrix.set(2, 1, 5);
    matrix.set(2, 2, 6);
    matrix.set(3, 0, 7);
    matrix.set(3, 1, 8);
    matrix.set(3, 2, 9);
    matrix.set(3, 3, 10);

    // Display the symmetric matrix
    matrix.display();
    return 0;
}