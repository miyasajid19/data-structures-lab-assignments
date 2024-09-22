#include <iostream>
#include <cstdlib>
using namespace std;

class Stacks
{
    int *arr;
    int size;
    int capacity;

public:
    Stacks()
    {
        this->arr = nullptr;
        this->size = 0;
        this->capacity = 0;
    }
    Stacks(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        this->arr = new int[capacity]();
    }
    bool isFull()
    {
        return this->size == this->capacity;
    }
    bool isEmpty()
    {
        return this->size == 0;
    }
    void Push(int value)
    {
        if (isFull())
        {
            cout << "Stacks overflow" << endl;
            return;
        }
        this->arr[size++] = value;
    }
    void Pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return;
        }
        size--;
    }
    void Display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = size - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int Top()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        return arr[this->size];
    }
    void restack(int capacity)
    {
        if (this->capacity > capacity)
        {
            cout << "invalid capacity " << endl;
            return;
        }
        this->capacity = capacity;
        int *newarr = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            newarr[i] = arr[i];
        }
        delete arr;
        arr = newarr;
    }
    void Erase()
    {
        delete[] arr;
        this->size = 0;
        this->capacity = 0;
    }
    ~Stacks()
    {
        delete[] arr;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Stacks stack(5);
    for (int i = 0; i < 6; i++)
    {
        stack.Push(i + 1);
        stack.Display();
    }
    stack.restack(3);
    stack.restack(7);
    stack.Push(6);
    stack.Display();
    stack.Push(7);
    stack.Display();

    for (int i = 0; i < 7; i++)
    {
        stack.Pop();
        cout << stack.Top() << " is in Top " << endl;
        stack.Display();
    }
    return EXIT_SUCCESS;
}