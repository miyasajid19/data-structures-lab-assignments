#include <iostream>
#include <cstdlib>
#include "SingleLinkedList.h"
using namespace std;
linkedList removeKey(Node *&head, int key, int &count)
{
    Node *temp = head;
    linkedList ans;
    while (temp != nullptr)
    {
        if (temp->value == key)
        {
            count++;
        }
        else
        {
            ans.InsertAtTail(temp->value);
        }
        temp = temp->next;
    }
    return ans;
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
    int count = 0;
    linkedList ans = removeKey(ll.head, 1, count);
    cout << "Results :: ";
    cout << "the total no. of key nodes are " << count << endl;
    ans.display();
    return EXIT_SUCCESS;
}