#include <iostream>
#include <cstdlib>
using namespace std;
class Queue
{
    int *arr;
    int front;
    int back;
    int capacity;
    int size;

public:
    Queue(int capacity)
    {
        this->size = 0;
        this->front = 0;
        this->back = -1;
        this->capacity = capacity;
        this->arr = new int[capacity];
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
            cout << "Queue overflow" << endl;
            return;
        }
        this->back++;
        this->arr[this->back] = value;
        this->size++;
    }
    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }
        this->front++;
        this->size--;
    }
    int Peek()
    {
        if (isEmpty())
        {
            cout << "there is no queue" << endl;
            return INT_MIN;
        }
        return arr[front];
    }
    void Display()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
            return;
        }
        for (int i = this->front; i <= this->back; i++)
        {
            cout << arr[i] << " ";
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
    Queue queue(5);
    for (int i = 0; i < 6; i++)
    {
        queue.Enqueue(i + 1);
        cout << queue.Peek() << endl;
        queue.Display();
        cout << endl;
    }
    queue.Dequeue();
    queue.Enqueue(432);
    queue.Display();
    for (int i = 0; i < 6; i++)
    {
        queue.Dequeue();
        cout << queue.Peek() << endl;
        queue.Display();
        cout << endl;
    }
    return EXIT_SUCCESS;
}