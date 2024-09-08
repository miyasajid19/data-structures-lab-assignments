#include <iostream>
#include <cstdlib>
using namespace std;

class Queue
{
    int size;
    int capacity;
    int front;
    int back;
    int *arr;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->front = 0;  
        this->back = -1;  
        arr = new int[capacity];
    }

    bool isFull()
    {
        return this->size == this->capacity;
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    int Size()
    {
        return this->size;
    }

    void Enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue overflow" << endl;
            return;
        }
        this->back++;           
        arr[back] = value;      
        this->size++;           
    }

    void Dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue underflow"<<endl;
            return;
        }
        this->front++;
        this->size--;
    }
    int Peek()
    {
        if(isEmpty())
        {
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
        cout << "Queue elements: ";
        for (int i = this->front; i <= this->back; i++)  // Traverse from front to back
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
