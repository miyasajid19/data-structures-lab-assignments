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
class Stacks
{
    Node *head;
    int capacity;
    int size;

public:
    Stacks()
    {
        this->head = nullptr;
        this->capacity = 0;
        this->size = 0;
    }
    Stacks(int capacity)
    {
        this->head = nullptr;
        this->size = 0;
        this->capacity = capacity;
    }
    bool isEmpty()
    {
        return this->size == 0;
    }
    bool isFull()
    {
        return this->capacity == this->size;
    }
    void Push(int value)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
            return;
        }
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
        }
        else
        {
            new_node->Next = head;
            head = new_node;
        }
        this->size++;
    }
    int Top()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return INT_MAX;
        }
        return head->value;
    }
    void Display()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << "  ";
            temp = temp->Next;
        }
        cout << endl;
    }
    void Pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return;
        }
        Node *temp = head;
        if (head->Next == nullptr)
        {
            this->head = nullptr;
        }
        else
        {
            head = head->Next;
        }
        delete temp;
        this->size--;
    }
    void restack(int capacity)
    {
        if (this->capacity > capacity)
        {
            cout << "invalid indexing" << endl;
        }
        this->capacity = capacity;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Stacks stack(5);
    for (int i = 0; i < 6; i++)
    {
        stack.Push(i + 1);
        stack.Display();
    }
    stack.restack(3);
    stack.restack(7);
    stack.Push(6);
    stack.Display();
    stack.Push(7);
    stack.Display();

    for (int i = 0; i < 7; i++)
    {
        stack.Pop();
        cout << stack.Top() << " is in Top " << endl;
        stack.Display();
    }
    return EXIT_SUCCESS;
}