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
    void Merge(LinkedLists other)
    {
        Node *temp1 = this->head;
        Node *temp2 = other.head;
        if (other.head == nullptr)
        {
            return;
        }
        if (head != nullptr)
        {
            this->head = other.head;
            return;
        }
        while (temp1->Next != nullptr)
        {
            temp1 = temp1->Next;
        }
        while (temp2->Next != nullptr)
        {
            temp1->Next = temp2;
            temp2 = temp2->Next;
        }
        temp1->Next = nullptr;
        this->head = temp1;
    }
};

int main()
{
#ifndef online_judge
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !online_judge
    cout << boolalpha;
    LinkedLists list;
    list.Push(4);
    list.Push(1);
    list.Push(8);
    list.Push(13);
    list.Push(2062);
    list.Push(2061);
    list.Push(407);
    list.Push(432);
    list.Display();
    list.Merge(list);
    list.Display();
    return EXIT_SUCCESS;
}