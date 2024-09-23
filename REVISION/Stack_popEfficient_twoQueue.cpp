#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

class Stack
{
    int size;
    int capacity;
    queue<int> Queue;
    queue<int> auxilliary;

public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    bool isFull()
    {
        return this->size == this->capacity;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
            return;
        }
        Queue.push(value);
        this->size++; // Update the size after push
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        auxilliary = Queue;
        while (!auxilliary.empty())
        {
            cout << auxilliary.front() << " ";
            auxilliary.pop();
        }
        cout << endl;
    }

    void Pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return;
        }

        while (Queue.size() != 1)
        {
            auxilliary.push(Queue.front());
            Queue.pop();
        }

        Queue.pop(); // Pop the last element (which is the "top" of the stack)
        swap(auxilliary, Queue);
        this->size--; // Update the size after pop
    }

    int Top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }

        return Queue.back(); // The back of the queue is the "top" of the stack
    }
};

int main()
{
    #ifndef onlinejudge
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif // !onlinejudge
    Stack stk(5);
    for (int i = 0; i < 5; i++)
    {
        stk.push(i);
        stk.display();
    }

    cout << "Top element: " << stk.Top() << endl;

    stk.Pop();
    stk.display();

    cout << "Top element after pop: " << stk.Top() << endl;

    return EXIT_SUCCESS;
}
