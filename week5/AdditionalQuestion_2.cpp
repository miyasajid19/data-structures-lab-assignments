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
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    linkedList list;
    list.display();

    for (int i = 0; i < 10; i++)
    {
        list.InsertAtTail(i);
        list.display();
    }

    list.head = rotateByK(list.head, 3);
    list.display();

    return EXIT_SUCCESS;
}