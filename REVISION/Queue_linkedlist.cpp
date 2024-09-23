#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int Value;
    Node *Next;
    Node(int value)
    {
        this->Value = value;
        this->Next = nullptr;
    }
};
class Queue
{
    Node *head;
    Node *tail;
    int size;
    int capacity;

public:
    Queue(int capacity)
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->capacity = capacity;
        this->size = 0;
    }
    bool isEmpty();
    bool isFull();
    void Enqueue(int);
    void Dequeue();
    void Display();
    int Peek();
};
bool Queue ::isEmpty()
{
    return this->size == 0;
}
bool Queue::isFull()
{
    return this->capacity == this->size;
}
void Queue ::Enqueue(int value)
{
    if (isFull())
    {
        cout << "Queue overflow" << endl;
        return;
    }
    Node *new_node = new Node(value);
    if (head == nullptr)
    {
        head = tail = new_node;
    }
    else
    {
        tail->Next = new_node;
        tail = new_node;
    }
    this->size++;
}
void Queue::Dequeue()
{
    if (isEmpty())
    {
        cout << "Queue underflow" << endl;
        return;
    }
    Node *temp = head;
    if (head->Next == nullptr)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        head = head->Next;
    }
    delete temp;
    this->size--;
}
int Queue::Peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return INT_MIN;
    }
    return head->Value;
}
void Queue::Display()
{
    if (isEmpty())
    {
        cout << "Queue is empty";
        return;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->Value << " ";
        temp = temp->Next;
    }
    cout << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Queue queue(5);
    for (int i = 0; i < 6; i++)
    {
        queue.Enqueue(i);
        cout << queue.Peek() << endl;
        queue.Display();
    }
    for (int i = 0; i < 5; i++)
    {
        queue.Dequeue();
        cout << queue.Peek() << endl;
        queue.Display();
    }
    return EXIT_SUCCESS;
}