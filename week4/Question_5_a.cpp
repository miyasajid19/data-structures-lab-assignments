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

class Stacks_PushEfficient
{
public:
    Queue *queue;
    Queue *temp;
    int capacity;
    int size;

public:
    Stacks_PushEfficient(int capacity)
    {
        this->capacity = capacity;
        this->queue = new Queue(this->capacity);
        this->temp = new Queue(this->capacity);
        this->size = 0;
    }
    void Push(int value)
    {
        if (queue->isFull())
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
        if (queue->isEmpty())
        {
            return -1;
        }
        return queue->Peek();
    }
};
class Stacks_PopEfficient
{
public:
    Queue *queue;
    Queue *temp;
    int capacity;
    int size;

public:
    Stacks_PopEfficient(int capacity)
    {
        this->capacity = capacity;
        this->queue = new Queue(this->capacity);
        this->temp = new Queue(this->capacity);
        this->size = 0;
    }

    void Push(int value)
    {
        if (queue->isFull())
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
        swap(queue, temp);
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

    int Top()
    {
        if (queue->isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return queue->Peek();
    }

    void Display()
    {
        queue->Display();
    }
};

int main()
{
    #ifdef JUDGE_ONLINE
    freopen("output.txt","w",stdout);
    #endif // DEBUG
    Stacks_PopEfficient stack(3);
    stack.Push(1);
    stack.Push(2);
    stack.Push(5);

    cout << "Top element: " << stack.Top() << endl;

    stack.Display();

    stack.Pop();
    cout << "After pop:" << endl;
    cout << "Top element: " << stack.Top() << endl;
    stack.Display();

    stack.Pop();
    cout << "After pop:" << endl;
    cout << "Top element: " << stack.Top() << endl;
    stack.Display();

    stack.Pop();
    cout << "After pop:" << endl;
    cout << "Top element: " << stack.Top() << endl;
    stack.Display();

    stack.Pop();
    cout << "After pop:" << endl;
    cout << "Top element: " << stack.Top() << endl;
    stack.Display();
    cout << endl;
    Stacks_PushEfficient stk(3);
    stk.Push(1);
    stk.Push(2);
    stk.Push(5);

    cout << "Top element: " << stk.Top() << endl;

    stk.Display();

    stk.Pop();
    cout << "After pop:" << endl;
    cout << "Top element: " << stk.Top() << endl;
    stk.Display();

    stk.Pop();
    cout << "After pop:" << endl;
    cout << "Top element: " << stk.Top() << endl;
    stk.Display();

    stk.Pop();
    cout << "After pop:" << endl;
    cout << "Top element: " << stk.Top() << endl;
    stack.Display();

    stk.Pop();
    cout << "After pop:" << endl;
    cout << "Top element: " << stk.Top() << endl;
    stk.Display();
    return EXIT_SUCCESS;
}

