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
    int capacity;
    cout << "Enter the capacity for stack: ";
    cin >> capacity;

    Stacks stk(capacity);

    cout << "Enter " << capacity << " values to push onto the stack:" << endl;
    for (int i = 0; i < capacity; i++)
    {
        int num;
        cin >> num;
        stk.Push(num);
        cout << "Top: " << stk.Top() << endl;
        cout << "Minimum: " << stk.getMinimum() << endl
             << endl;
    }

    cout << "Popping elements from the stack:" << endl;
    for (int i = 0; i < capacity; i++)
    {
        stk.Pop();
        cout << "Top: " << stk.Top() << endl;
        cout << "Minimum: " << stk.getMinimum() << endl
             << endl;
    }

    return 0;
}
