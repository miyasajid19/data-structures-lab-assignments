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

class CircularLinkedList
{
    Node *head;

public:
    CircularLinkedList()
    {
        this->head = nullptr;
    }

    void InsertAtHead(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            head->Next = head;
            return;
        }
        Node *temp = head;
        while (temp->Next != head)
        {
            temp = temp->Next;
        }
        temp->Next = new_node;
        new_node->Next = head;
        head = new_node;
    }

    void InsertAtTail(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            head->Next = head;
            return;
        }
        Node *temp = head;
        while (temp->Next != head)
        {
            temp = temp->Next;
        }
        new_node->Next = head;
        temp->Next = new_node;
    }

    void Insert(int value, int index)
    {
        if (index < 0)
        {
            cout << "Invalid indexing" << endl;
            return;
        }
        if (index == 0)
        {
            InsertAtHead(value);
            return;
        }
        Node *temp = head;
        int counter = 0;
        while (temp->Next != head and counter < index - 1)
        {
            temp = temp->Next;
            counter++;
        }
        if (counter != index - 1)
        {
            cout << "Invalid indexing " << endl;
            return;
        }
        Node *new_node = new Node(value);
        new_node->Next = temp->Next;
        temp->Next = new_node;
    }

    void deleteFromHead()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->Next == head)
        {
            delete head;
            this->head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->Next != head)
        {
            temp = temp->Next;
        }
        Node *todelete = head;
        head = head->Next;
        temp->Next = head;
        delete todelete;
    }

    void DeleteFromTail()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->Next == head)
        {
            delete head;
            this->head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->Next->Next != head)
        {
            temp = temp->Next;
        }
        Node *todelete = temp->Next;
        temp->Next = head;
        delete todelete;
    }

    void Delete(int index)
    {
        if (index < 0)
        {
            cout << "Invalid indexing" << endl;
            return;
        }
        if (index == 0)
        {
            deleteFromHead();
            return;
        }
        int counter = 0;
        Node *temp = head;
        while (temp->Next != head and counter < index - 1)
        {
            temp = temp->Next;
            counter++;
        }
        if (counter != index - 1)
        {
            cout << "Invalid indexing" << endl;
            return;
        }
        Node *todelete = temp->Next;
        temp->Next = temp->Next->Next;
        delete todelete;
    }

    void Display()
    {
        if (head == nullptr)
        {
            cout << "Circular linked list is empty" << endl;
            return;
        }
        if (head->Next == head)
        {
            cout << "<-" << head->Value << "->" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << "->" << temp->Value << "<-";
            temp = temp->Next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CircularLinkedList list;
    list.InsertAtHead(1);
    list.Display();
    list.InsertAtHead(0);
    list.Display();
    list.InsertAtTail(3);
    list.Display();
    list.Insert(2, 2);
    list.Display();
    list.deleteFromHead();
    list.Display();
    list.DeleteFromTail();
    list.Display();
    list.Delete(1);
    list.Display();

    return EXIT_SUCCESS;
}
