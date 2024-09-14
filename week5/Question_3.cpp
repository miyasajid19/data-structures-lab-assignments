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
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    linkedList ll;
    for (int i = 1; i <= 6; i++)
    {
        ll.InsertAtTail(i);
        ll.display();
    }
    Node *middleNode = findMiddleNode(ll.head);
    cout << "The middle Node is  :: " << middleNode->value << endl;
    return EXIT_SUCCESS;
}