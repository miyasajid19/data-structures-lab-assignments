#include <iostream>
#include <cstdlib>
#include "SingleLinkedList.h"
using namespace std;
Node *reverseLinkedList(Node *&head)
{
    Node *PreviousPointer = nullptr;
    Node *CurrentPointer = head;
    while (CurrentPointer != nullptr)
    {
        Node *nextpointer = CurrentPointer->next;
        CurrentPointer->next = PreviousPointer;
        PreviousPointer = CurrentPointer;
        CurrentPointer = nextpointer;
    }
    Node *new_head = PreviousPointer;
    return new_head;
}
Node *reverseRecurrsion(Node *&head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    Node *new_head = reverseRecurrsion(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}
int main()
{
    linkedList ll;

    int numElements;
    cout << "Enter the number of elements for the linked list: ";
    cin >> numElements;

    cout << "Enter the elements for the linked list:" << endl;
    for (int i = 0; i < numElements; i++)
    {
        int value;
        cout << "Element " << i + 1 << ": ";
        cin >> value;
        ll.InsertAtTail(value);
    }

    cout << "The original linked list is: ";
    ll.display();

    char choice;
    cout << "Do you want to reverse the linked list? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        ll.head = reverseLinkedList(ll.head);
        cout << "The reversed linked list is: ";
        ll.display();
    }

    cout << "Do you want to reverse it back to the original? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        ll.head = reverseLinkedList(ll.head);
        cout << "The linked list after reversing back is: ";
        ll.display();
    }

    return EXIT_SUCCESS;
}
