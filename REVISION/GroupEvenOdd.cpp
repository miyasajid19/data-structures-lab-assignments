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
    void GroupEvenOdd()
    {
        if (!head || !head->Next)
        {
            return;
        }

        Node *oddPointer = head;
        Node *evenPointer = head->Next;
        Node *evenhead = evenPointer;

        while (evenPointer && evenPointer->Next)
        {
            oddPointer->Next = evenPointer->Next;
            oddPointer = oddPointer->Next;
            evenPointer->Next = oddPointer->Next;
            evenPointer = evenPointer->Next;
        }

        oddPointer->Next = evenhead; // Attach the even list at the end of the odd list
    }
};

int main()
{
#ifndef Sajidmiya
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !Sajidmiya
    LinkedLists list;
    list.display();

    for (int i = 1; i < 10; i++)
    {
        list.push(i);
        list.display();
    }

    list.GroupEvenOdd();
    list.display();

    return EXIT_SUCCESS;
}