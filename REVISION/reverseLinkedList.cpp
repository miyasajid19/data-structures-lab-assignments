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
class LinkedLists
{

public:
    Node *head;
    LinkedLists()
    {
        this->head = nullptr;
    }
    void Push(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->Next != nullptr)
        {
            temp = temp->Next;
        }
        temp->Next = new_node;
    }

    void Display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->Value << "->";
            temp = temp->Next;
        }
        cout << "nullptr" << endl;
    }
    void Reverse()
    {
        Node *currentPointer = head;
        Node *previousPointer = nullptr;
        while (currentPointer)
        {
            Node *nextPointer = currentPointer->Next;
            currentPointer->Next = previousPointer;
            previousPointer = currentPointer;
            currentPointer = nextPointer;
        }
        head = previousPointer;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    LinkedLists list;
    for (int i = 1; i < 14; i += 2)
    {
        list.Push(i);
        list.Display();
    }
    list.Reverse();
    list.Display();
    return EXIT_SUCCESS;
}
