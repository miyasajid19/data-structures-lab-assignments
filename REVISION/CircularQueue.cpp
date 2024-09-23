#include <iostream>
#include <cstdlib>
using namespace std;

class Queue
{
    int *arr;
    int back;
    int front;
    int size;
    int capacity;

public:
    Queue(int capacity)
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
        this->front = -1;
        this->back = -1;
    }

    bool isFull()
    {
        return this->size == this->capacity;
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    void Enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue overflow" << endl;
            return;
        }

        if (isEmpty())
        {
            this->front = 0;
            this->back = 0;
        }
        else
        {
            this->back = (back + 1) % capacity;
        }

        arr[back] = value;
        size++;
    }

    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }

        if (front == back)
        {
            // Reset the queue when removing the last element
            front = -1;
            back = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        size--;
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

    int Size()
    {
        return this->size;
    }

    void Display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == back)
                break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main()
{
    Queue Circular_Q(5);

    for (int i = 0; i < 5; i++)
    {
        Circular_Q.Enqueue(i);
        cout << "Peek: " << Circular_Q.Peek() << endl;
        cout << "Queue: ";
        Circular_Q.Display();
    }

    Circular_Q.Dequeue();
    Circular_Q.Display();

    return EXIT_SUCCESS;
}
