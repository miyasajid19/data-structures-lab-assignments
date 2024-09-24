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
    bool IsPlaindrome()
    {
        Node *slowPointer = head;
        Node *fastPointer = head;
        while (fastPointer and fastPointer->Next)
        {
            slowPointer = slowPointer->Next;
            fastPointer = fastPointer->Next->Next;
        }
        Node *second = slowPointer->Next;
        slowPointer->Next = nullptr;
        Node *first = slowPointer;
        // reversing the second pointer
        while (second)
        {
            Node *nextNode = second->Next;
            second->Next = first;
            first = second;
            second = nextNode;
        }
        Node *head1 = head;
        Node *head2 = first;
        while (head1 and head2)
        {
            if (head1->value == head2->value)
            {
                return true;
            }
            head1=head1->Next;
            head2=head2->Next;
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
cout<<boolalpha;
list.push(1);
list.push(3);
list.push(2);
list.push(1);
cout<<list.IsPlaindrome();
    return EXIT_SUCCESS;
}