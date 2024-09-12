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

    ~Queue()
    {
        delete[] arr;
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
            return -1; // Change to -1 to indicate empty
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
        int i = front;
        do
        {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (back + 1) % capacity);
        cout << endl;
    }
};
class Stacks_PushEfficient {
public:
    Queue *queue;
    Queue *temp;
    int size;

    Stacks_PushEfficient(int capacity) {
        this->queue = new Queue(capacity);
        this->temp = new Queue(capacity);
        this->size = 0;
    }

    ~Stacks_PushEfficient() {
        delete queue;
        delete temp;
    }

    void Push(int value) {
        if (queue->isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        queue->Enqueue(value);  // Simply enqueue in the main queue
        this->size++;
    }

    void Pop() {
        if (queue->isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        // Transfer all elements except the last one to the temporary queue
        while (queue->Size() > 1) {
            temp->Enqueue(queue->Peek());
            queue->Dequeue();
        }
        // Remove the last element
        queue->Dequeue();
        // Restore elements from temp to queue
        while (!temp->isEmpty()) {
            queue->Enqueue(temp->Peek());
            temp->Dequeue();
        }
        this->size--;
    }

    void Display() {
        queue->Display();
    }

    int Top() {
        if (queue->isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        // Move all elements to temp and get the last one
        int topValue;
        while (!queue->isEmpty()) {
            topValue = queue->Peek();
            temp->Enqueue(topValue);
            queue->Dequeue();
        }
        // Restore elements from temp to queue
        while (!temp->isEmpty()) {
            queue->Enqueue(temp->Peek());
            temp->Dequeue();
        }
        return topValue;
    }
};


class Stacks_PopEfficient
{
public:
    Queue *queue;
    Queue *temp;
    int size;

    Stacks_PopEfficient(int capacity)
    {
        this->queue = new Queue(capacity);
        this->temp = new Queue(capacity);
        this->size = 0;
    }

    ~Stacks_PopEfficient()
    {
        delete queue;
        delete temp;
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

    Stacks_PushEfficient stack(3);
    stack.Push(1);
    stack.Push(2);
    stack.Push(5);

    cout << "Top element (Pop-Efficient): " << stack.Top() << endl;
    stack.Display();

    stack.Pop();
    cout << "After pop:" << endl;
    cout << "Top element (Pop-Efficient): " << stack.Top() << endl;
    stack.Display();

    stack.Pop();
    cout << "After pop:" << endl;
    cout << "Top element (Pop-Efficient): " << stack.Top() << endl;
    stack.Display();

    stack.Pop();
    cout << "After pop:" << endl;
    cout << "Top element (Pop-Efficient): " << stack.Top() << endl;
    stack.Display();

    stack.Pop();
    cout << "After pop:" << endl;
    cout << "Top element (Pop-Efficient): " << stack.Top() << endl;
    stack.Display();
    cout << endl;

    Stacks_PushEfficient stk(3);
    stk.Push(1);
    stk.Push(2);
    stk.Push(5);

    cout << "Top element (Push-Efficient): " << stk.Top() << endl;
    stk.Display();

    stk.Pop();
    cout << "After pop:" << endl;
    cout << "Top element (Push-Efficient): " << stk.Top() << endl;
    stk.Display();

    stk.Pop();
    cout << "After pop:" << endl;
    cout << "Top element (Push-Efficient): " << stk.Top() << endl;
    stk.Display();

    stk.Pop();
    cout << "After pop:" << endl;
    cout << "Top element (Push-Efficient): " << stk.Top() << endl;
    stk.Display();

    stk.Pop();
    cout << "After pop:" << endl;
    cout << "Top element (Push-Efficient): " << stk.Top() << endl;
    stk.Display();

    return EXIT_SUCCESS;
}
