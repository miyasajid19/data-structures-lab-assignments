#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
class Stack
{
    int size;
    int capacity;
    queue<int> Queue;

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
    void Push(int value)
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return;
        }

        Queue.push(value);
        for (int i = 0; i < this->size; i++)
        {
            Queue.push(Queue.front());
            Queue.pop();
        }
        this->size++;
    }
    void Pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return;
        }
        Queue.pop();
        this->size--;
    }
    int Top()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return this->Queue.front();
    }
    void Display()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        queue<int> temp = Queue;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Stack stk(5);

    cout << "Pushing elements into the stack:\n";
    for (int i = 1; i <= 5; i++)
    {
        cout << "Push " << i << ":\n";
        stk.Push(i);
        stk.Display();
    }

    cout << "Attempting to push when stack is full:\n";
    stk.Push(6);

    cout << "\nTop of the stack: " << stk.Top() << endl;

    cout << "\nPopping elements from the stack:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Pop:\n";
        stk.Pop();
        stk.Display();
    }

    cout << "Top of the stack after pops: " << stk.Top() << endl;

    cout << "Popping remaining elements:\n";
    stk.Pop();
    stk.Display();
    stk.Pop();
    stk.Display();

    cout << "Attempting to pop from an empty stack:\n";
    stk.Pop();

    return EXIT_SUCCESS;
}
