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

    int key;
    cout << "Enter the key value to remove from the linked list: ";
    cin >> key;

    int count = 0;
    linkedList ans = removeKey(ll.head, key, count);

    cout << "Results: " << endl;
    cout << "The total number of nodes with the key value " << key << " removed:: " << count << endl;
    
    cout << "The updated linked list is: ";
    ans.display();

    return EXIT_SUCCESS;
}
