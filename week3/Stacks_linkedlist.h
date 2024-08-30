#include <iostream>
#include <cstdlib>
using namespace std;
template <typename T>
class Node
{
public:
    T value;
    Node *Next;
    Node()
    {
        this->value = NULL;
        this->Next = nullptr;
    }
    Node(T value)
    {
        this->value = value;
        this->Next = nullptr;
    }
};
template <typename T>
class Stacks
{
    int size;
    int capacity;
    Node<T> *head;

public:
    Stacks()
    {
        this->capacity = 0;
        this->size = 0;
    }
    Stacks(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
    }
    void setStacks(int capacity)
    {
        this->capacity = capacity;
    }
    bool isEmpty()
    {
        return this->size == 0;
    }
    bool isFull()
    {
        return this->size == this->capacity;
    }
    void Push(T value)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
            return;
        }
        Node<T> *new_node = new Node<T>(value);
        new_node->Next = head;
        head = new_node;
        size++;
    }
    void Pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return;
        }
        Node<T> *temp = head;
        head = head->Next;
        delete temp;
        size--;
    }
    T Peek()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return T();
        }
        return head->value;
    }
};