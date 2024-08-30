#include <iostream>
#include <cstdlib>
#include <climits> // For INT_MAX
using namespace std;

class Stacks
{
    int size;
    int capacity;
    int *arr;
    int minimum;

public:
    Stacks() : size(0), capacity(0), arr(nullptr), minimum(INT_MAX) {}

    Stacks(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        arr = new int[capacity]();
        this->minimum = INT_MAX;
    }

    void setStack(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        arr = new int[capacity]();
        this->minimum = INT_MAX;
    }

    void reStack(int capacity)
    {
        this->capacity = capacity;
        int *arr1 = new int[capacity]();
        for (int i = 0; i < size; i++)
        {
            arr1[i] = arr[i];
        }
        delete[] arr;
        arr = arr1;
    }

    bool isEmpty() const
    {
        return this->size == 0;
    }

    bool isFull() const
    {
        return this->size == this->capacity;
    }

    int Size() const
    {
        return size;
    }

    void Push(int value)
    {
        if (isFull())
        {
            std::cout << "Stack overflow" << std::endl;
            return;
        }

        if (isEmpty())
        {
            minimum = value;
            arr[this->size++] = 0; // Store 0 as diff when minimum is same as value
        }
        else
        {
            int diff = value - minimum;
            arr[this->size++] = diff;
            if (diff < 0)
            {
                minimum = value;
            }
        }
    }

    void Pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack underflow" << std::endl;
            return;
        }

        int top = arr[this->size - 1];
        if (top < 0)
        {
            minimum = minimum - top; // Restore previous minimum
        }
        this->size--;
    }

    int Peek() const
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
            return INT_MAX; // Return a placeholder
        }

        int top = arr[this->size - 1];
        if (top < 0)
        {
            return minimum; // Return the minimum as it's the top element
        }
        else
        {
            return top + minimum; // Recover original value
        }
    }

    int getMinimum() const
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
            return INT_MAX; // Return placeholder for empty stack
        }
        return minimum;
    }

    ~Stacks()
    {
        delete[] arr;
    }
};
int main()
{
    Stacks stack(5);

    cout << "Pushing value 10 onto the stack..." << endl;
    stack.Push(10);
    cout << "Top of the stack: " << stack.Peek() << endl;
    cout << "Current minimum value in the stack: " << stack.getMinimum() << endl
         << endl;

    cout << "Pushing value 5 onto the stack..." << endl;
    stack.Push(5);
    cout << "Top of the stack: " << stack.Peek() << endl;
    cout << "Current minimum value in the stack: " << stack.getMinimum() << endl
         << endl;

    cout << "Pushing value 15 onto the stack..." << endl;
    stack.Push(15);
    cout << "Top of the stack: " << stack.Peek() << endl;
    cout << "Current minimum value in the stack: " << stack.getMinimum() << endl
         << endl;

    cout << "Pushing value 1 onto the stack..." << endl;
    stack.Push(1);
    cout << "Top of the stack: " << stack.Peek() << endl;
    cout << "Current minimum value in the stack: " << stack.getMinimum() << endl
         << endl;

    cout << "Pushing value -1 onto the stack..." << endl;
    stack.Push(-1);
    cout << "Top of the stack: " << stack.Peek() << endl;
    cout << "Current minimum value in the stack: " << stack.getMinimum() << endl
         << endl;

    // Popping elements and checking the state
    cout << "Popping top element..." << endl;
    stack.Pop();
    cout << "After popping, top of the stack: " << stack.Peek() << endl;
    cout << "Current minimum value in the stack: " << stack.getMinimum() << endl
         << endl;

    cout << "Popping top element..." << endl;
    stack.Pop();
    cout << "After popping, top of the stack: " << stack.Peek() << endl;
    cout << "Current minimum value in the stack: " << stack.getMinimum() << endl
         << endl;

    return EXIT_SUCCESS;
}
