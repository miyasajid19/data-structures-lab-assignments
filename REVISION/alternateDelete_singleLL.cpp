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

class LinkedLists
{
public:
    Node *head;
    LinkedLists()
    {
        head = nullptr;
    }

    void push(int value)
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
    void display()
    {
        if (head == nullptr)
        {
            cout << "The linked list is empty\nHence, there is nothing to display" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << "->";
            temp = temp->Next;
        }
        cout << "nullptr" << endl;
    }
    void Alternatedelete()
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        while (temp && temp->Next)
        {
            Node *todelete = temp->Next;
            temp->Next = temp->Next->Next;
            delete todelete;
            temp = temp->Next; // Move temp by one node
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    LinkedLists list;
    for (int i = 1; i < 14; i++)
        list.push(i);
    list.display();
    list.Alternatedelete();
    list.display();
    return EXIT_SUCCESS;
}