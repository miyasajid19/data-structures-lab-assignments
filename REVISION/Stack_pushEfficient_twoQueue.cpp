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
        auxilliary.push(value);
        while (not Queue.empty())
        {
            auxilliary.push(Queue.front());
            Queue.pop();
        }
        swap(auxilliary, Queue);
        this->size++;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        auxilliary = Queue;
        while (not auxilliary.empty())
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
        Queue.pop();
        this->size--;
    }
    int Top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return Queue.front();
    }
};int main()
{
    Stack stk(5);

    cout << "Pushing elements into the stack:\n";
    for (int i = 1; i <= 5; i++)
    {
        cout << "Push " << i << ":\n";
        stk.push(i);
        stk.display();
    }

    cout << "Attempting to push when stack is full:\n";
    stk.push(6);

    cout << "\nTop of the stack: " << stk.Top() << endl;

    cout << "\nPopping elements from the stack:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Pop:\n";
        stk.Pop();
        stk.display();
    }

    cout << "Top of the stack after pops: " << stk.Top() << endl;

    cout << "Popping remaining elements:\n";
    stk.Pop();
    stk.display();
    stk.Pop();
    stk.display();

    cout << "Attempting to pop from an empty stack:\n";
    stk.Pop();

    return EXIT_SUCCESS;
}
