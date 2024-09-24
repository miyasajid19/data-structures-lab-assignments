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

    Node* ReverseList(Node *node)
    {
        if (node == nullptr || node->Next == nullptr)
        {
            return node;
        }
        Node *new_head = ReverseList(node->Next);
        node->Next->Next = node;
        node->Next = nullptr;
        return new_head;
    }

    void Reverse()
    {
        head = ReverseList(head);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    LinkedLists list;

    for (int i =1;i<14; i++)
    {
        list.Push(i);
        list.Display();
    }

    list.Reverse();
    list.Display();

    return EXIT_SUCCESS;
}
