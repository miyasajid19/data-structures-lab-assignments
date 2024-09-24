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
};
bool IsEqual(LinkedLists list1, LinkedLists list2)
{
    Node *temp1 = list1.head;
    Node *temp2 = list2.head;
    while (temp1 and temp2)
    {
        if (temp1->Value != temp2->Value)
        {
            return false;
        }
        temp1 = temp1->Next;
        temp2 = temp2->Next;
    }
    return temp1==nullptr and temp2==nullptr;
}

int main()
{
#ifndef online_judge
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !online_judge
    cout << boolalpha;
    LinkedLists list;
    list.Push(1);
    list.Push(2);
    list.Push(3);
    list.Push(4);
    LinkedLists list1;
    list1.Push(1);
    list1.Push(2);
    list1.Push(3);
    list1.Push(4);
    cout << IsEqual(list, list1);
    return EXIT_SUCCESS;
}