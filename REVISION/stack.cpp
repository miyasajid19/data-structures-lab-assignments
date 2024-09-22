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
        if (this->capacity > this->size)
        {
            cout << "invalid capacity " << endl;
            return;
        }
        this->capacity = capacity;
    }
    void Erase()
    {
        delete[] arr;
        this->size = 0;
        this->capacity = 0;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int cap;
    cout << "enter the capacity for the stacks :: " << endl;
    cin >> cap;
    Stacks stack(cap);
    for (int i = 0; i < 7; i++)
    {
        int a;
        cin >> a;
        stack.Push(a);
        stack.Display();
    }
    for (int i = 0; i < 7; i++)
    {
        cout << stack.Top() << " is in the top" << endl;
        stack.Pop();
        stack.Display();
    }

    return EXIT_SUCCESS;
}