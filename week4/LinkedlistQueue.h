#include <iostream>
#include <limits> // For std::numeric_limits
using namespace std;

template <typename T>
class Node
{
public:
    T value;
    Node *Next;
    Node(T value) : value(value), Next(nullptr) {}
};

template <typename T>
class Queue
{
    int size;
    int capacity;
    Node<T> *head;
    Node<T> *tail;

public:
    Queue(int capacity) : capacity(capacity), size(0), head(nullptr), tail(nullptr) {}

    bool isEmpty() const
    {
        return size == 0;
    }

    bool isFull() const
    {
        return size == capacity;
    }

    int Size() const
    {
        return size;
    }

    void Enqueue(T value)
    {
        if (isFull())
        {
            cout << "Queue overflow" << endl;
            return;
        }
        Node<T> *new_node = new Node<T>(value);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->Next = new_node;
            tail = new_node;
        }
        size++;
    }

    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }
        Node<T> *temp = head;
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->Next;
        }
        delete temp;
        size--;
    }

    T Peek() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T(); // Return default value for type T
        }
        return head->value;
    }

    void Display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->Next;
        }
        cout << endl;
    }

    ~Queue()
    {
        while (!isEmpty())
        {
            Dequeue();
        }
    }
};
