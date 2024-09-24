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

    void Merge(LinkedLists &other)
    {
        if (other.head == nullptr) // If the second list is empty, do nothing
        {
            return;
        }

        if (this->head == nullptr) // If the current list is empty, simply point to the other list
        {
            this->head = other.head;
            return;
        }

        Node *temp1 = this->head;
        while (temp1->Next != nullptr) // Traverse to the end of the current list
        {
            temp1 = temp1->Next;
        }
        temp1->Next = other.head; // Attach the other list to the end of the current list
    }
};

int main()
{
#ifndef online_judge
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !online_judge

    LinkedLists list1;
    list1.Push(4);
    list1.Push(1);
    list1.Push(8);
    list1.Push(13);

    LinkedLists list2;
    list2.Push(2062);
    list2.Push(2061);
    list2.Push(407);
    list2.Push(432);

    // Display both lists
    cout << "List 1: ";
    list1.Display();

    cout << "List 2: ";
    list2.Display();

    // Merge list2 into list1
    list1.Merge(list2);

    // Display merged list
    cout << "Merged List: ";
    list1.Display();

    return EXIT_SUCCESS;
}
