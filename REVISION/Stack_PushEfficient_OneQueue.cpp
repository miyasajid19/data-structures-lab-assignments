#include <iostream>
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

    // Push-efficient stack implementation
    void Push(int value)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
            return;
        }
        Queue.push(value); // Just push the value directly
        this->size++;
    }

    void Pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return;
        }

        // To pop the last added element, rotate the queue to get the last element in front
        int n = this->size;
        for (int i = 0; i < n - 1; i++)
        {
            Queue.push(Queue.front());
            Queue.pop();
        }
        Queue.pop(); // Pop the "last-in" element
        this->size--;
    }

    int Top()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return -1;
        }

        // Rotate queue to access the last added element, which is the "top" of the stack
        int n = this->size;
        for (int i = 0; i < n - 1; i++)
        {
            Queue.push(Queue.front());
            Queue.pop();
        }

        int topElement = Queue.front();
        Queue.push(Queue.front()); // Move the top element back to the queue
        Queue.pop();

        return topElement;
    }

    void Display()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return;
        }

        queue<int> temp = Queue; // Copy the queue for display purposes
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
    Stack stk(5);

    cout << "Pushing elements into the stack:\n";
    for (int i = 1; i <= 5; i++)
    {
        cout << "Push " << i << ":\n";
        stk.Push(i);
        stk.Display();
    }

    cout << "Attempting to push when stack is full:\n";
    stk.Push(6); // This should trigger stack overflow

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
    stk.Pop(); // This should trigger stack underflow

    return EXIT_SUCCESS;
}
