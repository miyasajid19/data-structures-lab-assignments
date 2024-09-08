#include <iostream>
#include <cstdlib>
#include "linearQueue.h"
using namespace std;

class Stacks_PopEfficient : public Queue<int>
{
public:
    Stacks_PopEfficient(int capacity) : Queue(capacity) {}

    void Push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        Enqueue(value);
        int size = Size();
        for (int i = 0; i < size - 1; ++i)
        {
            int x = Peek();
            Dequeue();
            Enqueue(x);
        }
    }

    void Pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        Dequeue();
    }

    int Top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return Peek();
    }
};
class Stacks_PushEfficient : public Queue<int>
{
public:
    Stacks_PushEfficient(int capacity) : Queue(capacity) {}

    void Pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        for (int i = 0; i < Size() - 1; i++)
        {
            int value = Peek();
            Dequeue();
            Enqueue(value);
        }
        Dequeue();
    }

    void Push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        Enqueue(value);
    }

    int Top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int topValue;
        int size = Size();
        for (int i = 0; i < size; i++)
        {
            topValue = Peek();
            Dequeue();
            Enqueue(topValue);
        }
        return topValue;
    }
};
int main()
{
    // Testing Stacks_PushEfficient

    cout << "Testing Stacks_PushEfficient" << endl;
    Stacks_PushEfficient pushEfficientStack(3);

    pushEfficientStack.Push(1);
    pushEfficientStack.Display();
    cout << "Top: " << pushEfficientStack.Top() << endl;

    pushEfficientStack.Push(2);
    pushEfficientStack.Display();
    cout << "Top: " << pushEfficientStack.Top() << endl;

    pushEfficientStack.Push(3);
    pushEfficientStack.Display();
    cout << "Top: " << pushEfficientStack.Top() << endl;

    pushEfficientStack.Pop();
    pushEfficientStack.Display();
    cout << "Top: " << pushEfficientStack.Top() << endl;

    pushEfficientStack.Pop();
    pushEfficientStack.Display();
    cout << "Top: " << pushEfficientStack.Top() << endl;

    pushEfficientStack.Pop();
    pushEfficientStack.Display();
    cout << "Top: " << pushEfficientStack.Top() << endl;

    // Add a line break for clarity
    cout << "-----------------------------------------------------" << endl;

    // Testing Stacks_PopEfficient

    cout << "Testing Stacks_PopEfficient" << endl;
    Stacks_PopEfficient popEfficientStack(3);

    popEfficientStack.Push(1);
    popEfficientStack.Display();
    cout << "Top: " << popEfficientStack.Top() << endl;

    popEfficientStack.Push(2);
    popEfficientStack.Display();
    cout << "Top: " << popEfficientStack.Top() << endl;

    popEfficientStack.Push(3);
    popEfficientStack.Display();
    cout << "Top: " << popEfficientStack.Top() << endl;

    popEfficientStack.Pop();
    popEfficientStack.Display();
    cout << "Top: " << popEfficientStack.Top() << endl;

    popEfficientStack.Pop();
    popEfficientStack.Display();
    cout << "Top: " << popEfficientStack.Top() << endl;

    popEfficientStack.Pop();
    popEfficientStack.Display();
    cout << "Top: " << popEfficientStack.Top() << endl;

    return EXIT_SUCCESS;
}
