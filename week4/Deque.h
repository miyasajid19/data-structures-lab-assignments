#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int value;
    Node *Next;
    Node *Previous;
    Node(int value) : value(value), Next(nullptr), Previous(nullptr) {}
};
class Deque
{
private:
    int size;
    int capacity;
    Node *head;
    Node *tail;

public:
    Deque(int capacity) : capacity(capacity), size(0), head(nullptr), tail(nullptr) {}
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
    void Push_Front(int value)
    {
        if (isFull())
        {
            cout << "Deque overflow" << endl;
            return;
        }
        Node *new_node = new Node(value);
        if (isEmpty())
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->Next = head;
            head->Previous = new_node;
            head = new_node;
        }
        this->size++;
    }
    void Push_Back(int value)
    {
        if (isFull())
        {
            cout << "Deque overflow" << endl;
            return;
        }
        Node *new_node = new Node(value);
        if (isEmpty())
        {
            head = tail = new_node;
        }
        else
        {
            tail->Next = new_node;
            new_node->Previous = tail;
            tail = new_node;
        }
        this->size++;
    }
    void Pop_Front()
    {
        if (isFull())
        {
            cout << "Deque underflow" << endl;
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
            head->Next->Previous = head->Previous;
            head = head->Next;
        }
        delete temp;
        this->size--;
    }
    void Pop_Back()
    {
        if (isEmpty())
        {
            cout << "Deque underflow" << endl;
            return;
        }
        Node *temp = tail;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail->Previous->Next = nullptr;
            tail = tail->Previous;
        }
        delete temp;
        this->size--;
    }
    int Front()
    {
        if (isEmpty())
        {
            cout << "Deque is empty" << endl;
            return INT_MAX;
        }
        return head->value;
    }
    int Back()
    {
        if (isEmpty())
        {
            cout << "Deque is empty" << endl;
            return INT_MAX;
        }
        return tail->value;
    }
    void Display_Front()
    {
        if (isEmpty())
        {
            cout << "Deque is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->Next;
        }
        cout << nullptr << endl;
    }
    void Display_Back()
    {
        if (isEmpty())
        {
            cout << "Deque is empty" << endl;
            return;
        }
        Node *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->Previous;
        }
        cout << nullptr << endl;
    }
};