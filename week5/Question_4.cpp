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
Node* reverseRecurrsion(Node* &head)
{
    if (head==NULL  or head->next==NULL)
    {
        return head;
    }
    Node* new_head=reverseRecurrsion(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    linkedList ll;
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(1);
    ll.InsertAtTail(2);
    ll.InsertAtTail(1);
    ll.InsertAtTail(3);
    ll.InsertAtTail(4);
    ll.display();
    ll.head = reverseLinkedList(ll.head);
    ll.display();
    ll.head=reverseLinkedList(ll.head);
    ll.display();
    return EXIT_SUCCESS;
}