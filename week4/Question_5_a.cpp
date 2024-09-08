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
        int size = 0;
    }
    void Push(int value)
    {
        if(queue->isEmpty())
        {
            cout<<"stack overflow"<<endl;
            return;
        }
        temp->Enqueue(value);
        while (not queue->isEmpty())
        {
            temp->Enqueue(queue->Peek());
            queue->Dequeue();
        }
        while(not temp->isEmpty())
        {
            queue->Enqueue(temp->Peek());
            temp->Dequeue();
        }
    }
    void Pop()
    {
        if(queue->isEmpty())
        {
            cout<<"stack underflow"<<endl;
            return;
        }
        queue->Dequeue();
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
    stack.Push(1);
    stack.Push(5);
    cout<<stack.Top();
    stack.Display();
    return EXIT_SUCCESS;
}