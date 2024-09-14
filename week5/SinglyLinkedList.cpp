#include <iostream>
#include "SingleLinkedList.h"
using namespace std;
int main()
{
    linkedList ll;
    int choice, value, index;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert at a specific position\n";
        cout << "4. Delete from the beginning\n";
        cout << "5. Delete from the end\n";
        cout << "6. Delete a specific node by index\n";
        cout << "7. Search for a node and display its position\n";
        cout << "8. Display all node values\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at the beginning: ";
            cin >> value;
            ll.InsertAtHead(value);
            break;

        case 2:
            cout << "Enter value to insert at the end: ";
            cin >> value;
            ll.InsertAtTail(value);
            break;

        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter index to insert at (0 based indexing) : ";
            cin >> index;
            ll.Insert(value, index);
            break;

        case 4:
            ll.DeleteFromHead();
            break;

        case 5:
            ll.deleteFromTail();
            break;

        case 6:
            cout << "Enter index of the node to delete (0 based indexing): ";
            cin >> index;
            ll.Delete(index);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            index = ll.search(value);
            if (index != -1)
                cout << "Node with value " << value << " found at position: " << index << endl;
            else
                cout << "Node with value " << value << " not found." << endl;
            break;

        case 8:
            cout << "Linked list contents: ";
            ll.display();
            break;

        case 0:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
