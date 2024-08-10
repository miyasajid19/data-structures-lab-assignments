#include <iostream>
using namespace std;

class TriDiagonalMatrix
{
private:
    int *upperDiagonal;
    int *mainDiagonal;
    int *lowerDiagonal;

public:
    int size;

    TriDiagonalMatrix(int size) : size(size)
    {
        upperDiagonal = new int[size - 1]();
        mainDiagonal = new int[size]();
        lowerDiagonal = new int[size - 1]();
    }

    ~TriDiagonalMatrix()
    {
        delete[] mainDiagonal;
        delete[] upperDiagonal;
        delete[] lowerDiagonal;
    }

    void set(int i, int j, int value)
    {
        if (i == j)
        {
            mainDiagonal[i] = value;
        }
        else if (i < j)
        {
            if (i < size - 1) // Ensure the index is within bounds
            {
                upperDiagonal[i] = value;
            }
        }
        else
        {
            if (j < size - 1) // Ensure the index is within bounds
            {
                lowerDiagonal[j] = value;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j)
                {
                    cout << mainDiagonal[i] << " ";
                }
                else if (i == j - 1)
                {
                    cout << upperDiagonal[i] << " ";
                }
                else if (j == i - 1)
                {
                    cout << lowerDiagonal[j] << " ";
                }
                else
                    cout << "0 ";
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

    TriDiagonalMatrix d1(5);
    d1.set(0, 0, 4);
    d1.set(0, 1, 1);
    d1.set(1, 0, 3);
    d1.set(1, 1, 4);
    d1.set(1, 2, 1);
    d1.set(2, 1, 3);
    d1.set(2, 2, 4);
    d1.set(2, 3, 1);
    d1.set(3, 2, 3);
    d1.set(3, 3, 4);
    d1.set(3, 4, 1);
    d1.set(4, 3, 3);
    d1.set(4, 4, 4);
    d1.display();

    return 0;
}
