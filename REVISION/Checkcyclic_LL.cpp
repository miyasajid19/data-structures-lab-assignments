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
    bool CheckCycle()
    {
        Node *slowPointer = head;
        Node *fastPointer = head;
        while (fastPointer and fastPointer->Next)
        {
            slowPointer = slowPointer->Next;
            fastPointer = fastPointer->Next->Next;
            if (slowPointer == fastPointer)
            {
                cout << "Cycle detected at node with value: " << slowPointer->value << endl;
                return true;
            }
        }
        return false;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    LinkedLists list;

    cout << "Inserting values 0 to 4 into the linked list." << endl;
    for (int i = 0; i < 5; i++)
    {
        list.push(i);
    }
    cout << "Displaying the linked list:" << endl;
    list.display();

    cout << "Checking for cycle in the list (No cycle expected):" << endl;
    cout << boolalpha << list.CheckCycle() << endl;
    cout << "Creating a cycle by linking the last node to the third node." << endl;
    list.head->Next->Next->Next->Next->Next = list.head->Next->Next;
    cout << "Checking for cycle in the list (Cycle expected):" << endl;
    cout << list.CheckCycle() << endl;
    return EXIT_SUCCESS;
}