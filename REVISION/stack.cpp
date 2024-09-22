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
        
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return EXIT_SUCCESS;
}