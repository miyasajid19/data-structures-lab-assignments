#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int value;
    Node *Next;
    Node(int value)
    {
        this->value = value;
        this->Next = nullptr;
    }
};
class Queue
{
    int size;
    int capacity;
    Node *head;
    Node *tail;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
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
        Node *new_node = new Node(value);
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
        this->size++;
    }
    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }
        Node *temp = head;
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
        this->size--;
    }
    int Peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return INT_MAX;
        }
        return head->value;
    }
    void Display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->Next;
        }
        cout << endl;
    }
};
