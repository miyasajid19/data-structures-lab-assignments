#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Stacks
{
    int *arr;
    int *minArr;
    int size;
    int capacity;

public:
    Stacks(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        this->arr = new int[capacity]();
        this->minArr = new int[capacity];
    }
    bool IsEmpty()
    {
        return this->size == 0;
    }
    bool IsFull()
    {
        return this->size == this->capacity;
    }
    int Size()
    {
        return this->size;
    }
    void Push(int value)
    {
        if (IsFull())
        {
            cout << "stack overflow" << endl;
            return;
        }

        arr[size] = value;
        if (size == 0)
        {
            minArr[size] = value;
        }
        else
        {
            minArr[size] = min(value, minArr[size - 1]);
        }
        size++;
    }
    void Pop()
    {
        if (IsEmpty())
        {
            cout << "stack underflow" << endl;
            return;
        }
        this->size--;
    }
    int Top()
    {
        if (IsEmpty())
        {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        return this->arr[size - 1]; // Corrected here
    }
    int getMinimum()
    {
        if (size == 0)
        {
            return INT_MIN;
        }
        return this->minArr[size - 1]; // Corrected here
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Stacks stack(5);
    stack.Push(1);
    cout << endl
         << stack.Top();
    cout << endl
         << stack.getMinimum();
    stack.Push(2);
    cout << endl
         << stack.Top();
    cout << endl
         << stack.getMinimum();
    return EXIT_SUCCESS;
}
