#include <iostream>
#include <cstdlib>
using namespace std;

class Stacks
{
    int size;
    int capacity;
    int *arr;
    int minimum;

public:
    Stacks() : size(0), capacity(0), arr(nullptr) {}

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
        // x - minimum= value
        if (size == 0)
        {
            this->minimum = min(minimum, value);
        }
        minimum = min(minimum, value);
        value = value - minimum;
        arr[this->size++] = value;
    }

    void Pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack underflow" << std::endl;
            return;
        }
        this->size--;
    }

    int Peek() const
    {
        if (isEmpty())
        {
            std::cout << "stack is empty" << std::endl;
            return int();
        }

        return arr[this->size - 1] + this->minimum;
    }
    int getMinimum()
    {
        return this->minimum;
    }
    ~Stacks()
    {
        delete[] arr;
    }
};
int main()
{
    Stacks stack(5);

    // Push elements onto the stack and display results
    cout << "Pushing value 4 onto the stack..." << endl;
    stack.Push(4);
    cout << "Top of the stack: " << stack.Peek() << endl;
    cout << "Current minimum value in the stack: " << stack.getMinimum() << endl
         << endl;

    cout << "Pushing value -4 onto the stack..." << endl;
    stack.Push(-4);
    cout << "Top of the stack: " << stack.Peek() << endl;
    cout << "Current minimum value in the stack: " << stack.getMinimum() << endl
         << endl;

    cout << "Pushing value 432 onto the stack..." << endl;
    stack.Push(432);
    cout << "Top of the stack: " << stack.Peek() << endl;
    cout << "Current minimum value in the stack: " << stack.getMinimum() << endl
         << endl;

    cout << "Pushing value -34 onto the stack..." << endl;
    stack.Push(-34);
    cout << "Top of the stack: " << stack.Peek() << endl;
    cout << "Current minimum value in the stack: " << stack.getMinimum() << endl
         << endl;

    return EXIT_SUCCESS;
}
