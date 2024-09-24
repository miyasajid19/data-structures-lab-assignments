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
    void InsertAtHead(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        new_node->Next = head;
        head = new_node;
    }
    void InsertAtTail(int value)
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
    void Insert(int value, int index)
    {
        if (index == 0)
        {
            InsertAtHead(value);
            return;
        }
        Node *new_node = new Node(value);
        int counter = 0;
        Node *temp = head;
        while (temp != nullptr and counter < index - 1)
        {
            temp = temp->Next;
            counter++;
        }
        if (temp == nullptr)
        {
            cout << "invlaid indexing" << endl;
            delete new_node;
            return;
        }
        new_node->Next = temp->Next;
        temp->Next = new_node;
    }
    void UpdateHead(int value)
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        head->Value = value;
    }
    void UpdateTail(int value)
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp->Next != nullptr)
        {
            temp = temp->Next;
        }
        temp->Value = value;
    }
    void Update(int value, int index)
    {

        int counter = 0;
        Node *temp = head;
        while (temp != nullptr and counter < index)
        {
            temp = temp->Next;
            counter++;
        }
        if (temp == nullptr)
        {
            cout << "invlaid indexing" << endl;
            return;
        }
        temp->Value = value;
    }
    void DeleteFromHead()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        Node *temp = head;
        if (head->Next == nullptr)
        {
            head = nullptr;
        }
        else
        {
            head = head->Next;
        }
        delete temp;
    }
    void DeleteFromTail()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        if (head->Next == nullptr)
        {
            DeleteFromHead();
            return;
        }
        Node *temp = head;
        while (temp->Next->Next != nullptr)
        {
            temp = temp->Next;
        }
        Node *toDelete = temp->Next;
        temp->Next = temp->Next->Next;
        delete toDelete;
    }
    void Delete(int index)
    {
        if (index < 0)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        if (index == 0)
        {
            DeleteFromHead();
            return;
        }
        Node *temp = head;
        int counter = 0;
        while (temp != nullptr and counter < index - 1)
        {
            temp = temp->Next;
            counter++;
        }
        if (temp == nullptr)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        if (temp->Next == nullptr)
        {
            DeleteFromTail();
            return;
        }
        Node *toDelete = temp->Next;
        temp->Next = temp->Next->Next;
        delete toDelete;
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
    void ReverseDisplay(Node *temp)
    {
        if (temp == nullptr)
        {
            cout
                << nullptr;
            return;
        }
        ReverseDisplay(temp->Next);
        cout << "<-" << temp->Value;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    LinkedLists list;

    list.InsertAtHead(1);
    list.Display();
    list.ReverseDisplay(list.head);
    cout << endl;

    list.InsertAtHead(2);
    list.Display();
    list.ReverseDisplay(list.head);
    cout << endl;

    list.InsertAtTail(3);
    list.Display();
    list.ReverseDisplay(list.head);
    cout << endl;

    list.Insert(4, 2);
    list.Display();
    list.ReverseDisplay(list.head);
    cout << endl;

    list.UpdateHead(5);
    list.Display();
    list.ReverseDisplay(list.head);
    cout << endl;

    list.UpdateTail(6);
    list.Display();
    list.ReverseDisplay(list.head);
    cout << endl;

    list.Update(7, 2);
    list.Display();
    list.ReverseDisplay(list.head);
    cout << endl;

    list.DeleteFromHead();
    list.Display();
    list.ReverseDisplay(list.head);
    cout << endl;

    list.DeleteFromTail();
    list.Display();
    list.ReverseDisplay(list.head);
    cout << endl;

    list.Delete(1);
    list.Display();
    list.ReverseDisplay(list.head);
    cout << endl;

    return EXIT_SUCCESS;
}
