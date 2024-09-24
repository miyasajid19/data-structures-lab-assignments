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

    Node *reversebyk(Node *&head, int k)
    {
        Node *currentPointer = head;
        Node *previousPointer = nullptr;
        int counter = 0;
        while (currentPointer and counter < k)
        {
            Node *NextPointer = currentPointer->Next;
            currentPointer->Next = previousPointer;
            previousPointer = currentPointer;
            currentPointer = NextPointer;
            counter++;
        }
        if (currentPointer)
        {
            Node *new_head = reversebyk(currentPointer, k);
            head->Next = new_head;
        }
        return previousPointer;
    }

    void ReverseByK(int k)
    {
        head = reversebyk(head, k);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    LinkedLists list;

    for (int i = 1; i < 14; i += 2)
    {
        list.Push(i);
        list.Display();
    }

    list.ReverseByK(3);
    list.Display();

    return EXIT_SUCCESS;
}
