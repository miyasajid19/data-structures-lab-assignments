#include <iostream>
#include <cstdlib>
using namespace std;
template <typename T>
class Node
{
public:
    T value;
    Node *Next;
    Node *Previous;
    Node(T value) : value(value), Next(nullptr), Previous(nullptr) {}
};
template <typename T>
class Deque
{
private:
    int size;
    int capacity;
    Node<T> *head;
    Node<T> *tail;

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
        Node<T> *new_node = new Node<T>(value);
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
        Node<T> *new_node = new Node<T>(value);
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
        if (isEmpty())
        {
            cout << "Deque underflow" << endl;
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
        Node<T> *temp = tail;
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
        Node<T> *temp = head;
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
        Node<T> *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->Previous;
        }
        cout << nullptr << endl;
    }
};
