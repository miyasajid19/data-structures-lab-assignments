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
Node *SwapAlternate(Node *&head)
{
    if (not head or not head->Next)
    {
        return head;
    }
    Node *secondNode = head->Next;
    head->Next = SwapAlternate(secondNode->Next);
    secondNode->Next = head;
    return secondNode;
}

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
    list.head = SwapAlternate(list.head);
    list.Display();
    return EXIT_SUCCESS;
}