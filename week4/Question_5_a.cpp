#include <iostream>
#include <cstdlib>
using namespace std;

class Queue
{
public:
    int size;
    int capacity;
    int *arr;
    int front;
    int back;

    Queue(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->front = 0;
        this->back = -1;
        arr = new int[capacity];
    }
    bool isEmpty()
    {
        return this->size == 0;
    }
    bool isFull()
    {
        return this->size == this->capacity;
    }
    int Size()
    {
        return this->size;
    }
    void Enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        this->back = (this->back + 1) % capacity;
        arr[back] = value;
        this->size++;
    }
    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        this->front = (this->front + 1) % this->capacity;
        this->size--;
    }
    int Peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return int();
        }
        return arr[this->front];
    }
    void Display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front <= back)
        {
            for (int i = front; i <= back; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < capacity; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= back; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

class Stacks
{
public:
    Queue *queue;
    Queue *temp;
    int capacity;
    int size;

public:
    Stacks(int capacity)
    {
        this->capacity = capacity;
        this->queue = new Queue(this->capacity);
        this->temp = new Queue(this->capacity);
        this->size = 0; // initialize size here
    }
    void Push(int value)
    {
        if (queue->isFull()) // Check for stack overflow by checking if the queue is full
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        temp->Enqueue(value);
        while (!queue->isEmpty())
        {
            temp->Enqueue(queue->Peek());
            queue->Dequeue();
        }
        while (!temp->isEmpty())
        {
            queue->Enqueue(temp->Peek());
            temp->Dequeue();
        }
        this->size++;
    }
    void Pop()
    {
        if (queue->isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        queue->Dequeue();
        this->size--;
    }
    void Display()
    {
        queue->Display();
    }
    int Top()
    {
        return queue->Peek();
    }
};

int main()
{
    Stacks stack(3);
    stack.Push(1);
    stack.Push(2);
    stack.Push(5);

    cout << "Top element: " << stack.Top() << endl;

    stack.Display();

    stack.Pop();
    cout << "After pop:" << endl;
    stack.Display();

    return EXIT_SUCCESS;
}
