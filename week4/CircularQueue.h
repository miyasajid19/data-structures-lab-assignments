#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

class Queue
{
    int size;
    int capacity;
    int *arr;
    int front;
    int back;

public:
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
            return INT_MAX;
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
        cout << "Queue: ";
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
