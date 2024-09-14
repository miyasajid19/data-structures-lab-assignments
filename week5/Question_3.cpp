#include <iostream>
#include <cstdlib>
#include "SingleLinkedList.h"
using namespace std;
Node *findMiddleNode(Node *head)
{
    Node *slowpointer = head;
    Node *fastPointer = head;
    while (fastPointer != nullptr and fastPointer->next != nullptr)
    {
        slowpointer = slowpointer->next;
        fastPointer = fastPointer->next->next;
    }
    return slowpointer;
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
        ll.display();
    }

    Node *middleNode = findMiddleNode(ll.head);
    if (middleNode)
    {
        cout << "The middle node is: " << middleNode->value << endl;
    }
    else
    {
        cout << "The linked list is empty, no middle node found." << endl;
    }

    return EXIT_SUCCESS;
}
