#include <iostream>
using namespace std;
class Node
{
public:
    int Value;
    Node *Next;
    Node *Previous;
    Node(int Value)
    {
        this->Value = Value;
        this->Previous = nullptr;
        this->Next = nullptr;
    }
};
class DoubleList
{
public:
    Node *head;
    Node *tail;
    DoubleList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void InsertAtHead(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        head->Previous = new_node;
        new_node->Next = head;
        head = new_node;
    }
    void InsertAtTail(int value)
    {
        Node *new_node = new Node(value);
        if (tail == nullptr)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->Previous = tail;
        tail->Next = new_node;
        tail = new_node;
    }
    void InsertFromHead(int value, int index)
    {
        if (index < 0)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        if (index == 0)
        {
            InsertAtHead(value);
            return;
        }
        Node *temp = head;
        int count = 0;
        while (temp != nullptr and count < index - 1)
        {
            temp = temp->Next;
            count++;
        }
        if (temp == nullptr)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        if (temp->Next == nullptr)
        {
            InsertAtTail(value);
            return;
        }
        Node *new_node = new Node(value);
        new_node->Next = temp->Next;
        if (temp->Next != nullptr)
        {
            temp->Next->Previous = new_node;
        }
        else
        {
            tail = new_node;
        }
        temp->Next = new_node;
        new_node->Previous = temp;
    }
    void InsertFromTail(int value, int index)
    {
        if (index < 0)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        if (index == 0)
        {
            InsertAtTail(value);
            return;
        }
        int counter = 0;
        Node *temp = tail;
        while (temp != nullptr and counter < index - 1)
        {
            temp = temp->Previous;
            counter++;
        }
        if (temp == nullptr)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        Node *new_node = new Node(value);
        new_node->Next = temp;
        if (temp->Previous != nullptr)
        {

            new_node->Previous = temp->Previous;
        }
        else
        {
            head = new_node;
        }

        temp->Previous->Next = new_node;
        temp->Previous = new_node;
    }
    void DeleteHead()
    {
        if (head == nullptr)
        {
            cout << "linked list is already empty" << endl;
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
            tail = nullptr;
        }
        delete temp;
    }
    void DeleteTail()
    {
        if (tail == nullptr)
        {
            cout << "linked list is already empty" << endl;
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
            head = nullptr;
        }
        delete temp;
    }
    void deleteFromHead(int index)
    {
        if (index < 0)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        Node *temp = head;
        int counter = 0;
        while (temp != nullptr and counter < index)
        {
            temp = temp->Next;
            counter++;
        }
        if (temp == nullptr)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        if (temp == tail)
        {
            DeleteTail();
            return;
        }
        if (temp->Previous != nullptr)
            temp->Previous->Next = temp->Next;

        if (temp->Next != nullptr)
            temp->Next->Previous = temp->Previous;

        delete temp;
    }
    void deleteFromTail(int index)
    {
        if (index < 0)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        Node *temp = tail;
        int counter = 0;
        while (temp != nullptr and counter < index)
        {
            temp = temp->Previous;
            counter++;
        }
        if (temp == nullptr)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        if (temp == head)
        {
            DeleteHead();
            return;
        }
        if (temp->Next != nullptr)
            temp->Next->Previous = temp->Previous;

        if (temp->Previous != nullptr)
            temp->Previous->Next = temp->Next;

        delete temp;
    }
    void display()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        Node *temp = head;
        cout << "nullptr <--> ";
        while (temp != nullptr)
        {
            cout << temp->Value << " <--> ";
            temp = temp->Next;
        }
        cout << "  nullptr" << endl;
    }
    void Reverse_display()
    {
        if (tail == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        Node *temp = tail;
        cout << "nullptr <--> ";
        while (temp != nullptr)
        {
            cout << temp->Value << " <--> ";
            temp = temp->Previous;
        }
        cout << "  nullptr" << endl;
    }
};
int main()
{
    DoubleList dl;
    dl.display();
    dl.Reverse_display();
    dl.InsertAtHead(1);
    dl.display();
    dl.Reverse_display();
    dl.InsertAtTail(4);
    dl.display();
    dl.Reverse_display();
    dl.InsertFromHead(2, 1);
    dl.display();
    dl.Reverse_display();
    dl.InsertFromTail(3, 1);
    dl.display();
    dl.Reverse_display();
    dl.DeleteHead();
    dl.display();
    dl.Reverse_display();
    dl.DeleteTail();
    dl.display();
    dl.Reverse_display();
    dl.InsertAtHead(0);
    dl.InsertAtHead(1);
    dl.InsertAtHead(2);
    dl.display();
    dl.Reverse_display();
    dl.deleteFromHead(1);
    dl.display();
    dl.Reverse_display();
    dl.deleteFromTail(1);
    dl.display();
    dl.Reverse_display();
    dl.deleteFromTail(1);
    dl.display();
    dl.Reverse_display();
    dl.deleteFromTail(1);
    dl.display();
    dl.Reverse_display();
}