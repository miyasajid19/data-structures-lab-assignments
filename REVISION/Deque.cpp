#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int Value;
    Node *Next;
    Node *Previous;
    Node(int value)
    {
        this->Value = value;
        this->Previous = nullptr;
        this->Next = nullptr;
    }
};
class Deque
{
    Node *head;
    Node *tail;
    int size;
    int capacity;

public:
    Deque(int capacity)
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
        this->capacity = capacity;
    }
    bool isEmpty();
    bool isFull();
    void Push_Front(int);
    void Push_Back(int);
    void Pop_Front();
    void Pop_Back();
    void Display_Front();
    void Display_Back();
    int Front();
    int Back();
};
bool Deque::isEmpty()
{
    return this->size == 0;
}
bool Deque::isFull()
{
    return this->size == this->capacity;
}
void Deque::Push_Back(int value)
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
        new_node->Previous = tail;
        tail->Next = new_node;
        tail = new_node;
    }
    this->size++;
}
void Deque ::Push_Front(int value)
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
        new_node->Next = head;
        head->Previous = new_node;
        head = new_node;
    }
    this->size++;
}
void Deque::Pop_Back()
{
    if (isEmpty())
    {
        cout << "Deque underflow" << endl;
        return;
    }
    Node *temp = tail;
    tail = tail->Previous;
    if (tail)
    {
        tail->Next = nullptr;
    }
    else
    {
        this->head = nullptr;
    }
    delete temp;
    this->size--;
}
void Deque::Pop_Front()
{
    if (isEmpty())
    {
        cout << "Deque underflow" << endl;
        return;
    }
    Node *temp = head;
    head = head->Next;
    if (head)
    {
        head->Previous = nullptr;
    }
    else
    {
        this->tail = nullptr;
    }
    delete temp;
    this->size--;
}
void Deque::Display_Front()
{
    if (isEmpty())
    {
        cout << "deque is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp)
    {
        cout << temp->Value << " ";
        temp = temp->Next;
    }
    cout << endl;
}
void Deque::Display_Back()
{
    if (isEmpty())
    {
        cout << "deque is empty" << endl;
        return;
    }
    Node *temp = tail;
    while (temp)
    {
        cout << temp->Value << " ";
        temp = temp->Previous;
    }
    cout << endl;
}
int Deque ::Front()
{
    if (isEmpty())
    {
        cout << "Deque is empty" << endl;
        return INT_MAX;
    }
    return head->Value;
}
int Deque ::Back()
{
    if (isEmpty())
    {
        cout << "Deque is empty" << endl;
        return INT_MIN;
    }
    return tail->Value;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Deque dq(5);

    dq.Push_Back(407);
    dq.Push_Back(8);
    dq.Push_Front(432);
    dq.Push_Front(13);
    dq.Push_Back(39);

    cout << "Deque from front: ";
    dq.Display_Front();

    cout << "Deque from back: ";
    dq.Display_Back();

    cout << "Front element: " << dq.Front() << endl;
    cout << "Back element: " << dq.Back() << endl;

    dq.Pop_Front();
    dq.Pop_Back();

    cout << "Deque after popping front and back: ";
    dq.Display_Front();

    dq.Push_Back(2062);
    dq.Push_Back(4);
    dq.Push_Back(8);

    cout << "Final Deque: ";
    dq.Display_Front();

    return EXIT_SUCCESS;
}
