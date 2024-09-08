#include <iostream>
#include <cstdlib>
#include "linearQueue.h"
using namespace std;

class Stacks : public Queue<int>
{
public:
    Stacks(int capacity) : Queue(capacity) {}

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

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    Stacks stack(3);
    stack.Push(1);
    stack.Display();
    cout << "Top: " << stack.Top() << endl;

    stack.Push(2);
    stack.Display();
    cout << "Top: " << stack.Top() << endl;

    stack.Push(3);
    stack.Display();
    cout << "Top: " << stack.Top() << endl;

    stack.Pop();
    stack.Display();
    cout << "Top: " << stack.Top() << endl;

    stack.Pop();
    stack.Display();
    cout << "Top: " << stack.Top() << endl;

    stack.Pop();
    stack.Display();
    cout << "Top: " << stack.Top() << endl;

    return EXIT_SUCCESS;
}
