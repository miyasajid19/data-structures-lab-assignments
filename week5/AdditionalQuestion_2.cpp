#include <iostream>
#include <cstdlib>
#include "SingleLinkedList.h"
using namespace std;

Node *rotateByK(Node *head, int k)
{
    if (head == nullptr)
    {
        cout << "Linked list is empty\nHence, rotation of linked list is not possible" << endl;
        return nullptr;
    }

    // Count total number of nodes
    Node *temp = head;
    int counter = 1; // Start from 1 to count the head node
    while (temp->next != nullptr)
    {
        counter++;
        temp = temp->next;
    }

    k %= counter;
    if (k == 0)
    {
        return head;
    }
    temp->next = head;
    int stepsToNewHead = counter - k;
    temp = head;
    for (int i = 1; i < stepsToNewHead; i++)
    {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = nullptr;
    return head;
}
int main()
{
    linkedList list;

    int numElements;
    cout << "Enter the number of elements to insert into the linked list: ";
    cin >> numElements;

    cout << "Enter " << numElements << " elements:" << endl;
    for (int i = 0; i < numElements; i++)
    {
        int value;
        cout << "Element " << i + 1 << ": ";
        cin >> value;
        list.InsertAtTail(value);
    }

    cout << "The original linked list is: ";
    list.display();

    int k;
    cout << "Enter the number of rotations (k): ";
    cin >> k;

    list.head = rotateByK(list.head, k);

    cout << "The linked list after rotating by " << k << " is: ";
    list.display();

    return EXIT_SUCCESS;
}