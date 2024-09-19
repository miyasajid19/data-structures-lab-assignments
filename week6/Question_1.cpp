#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main()
{
    DoubleList dl;
    int choice, value, index, searchValue;

    while (true)
    {
        cout << "\nDoubly Linked List Operations Menu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at specific position from Head\n";
        cout << "4. Insert at specific position from Tail\n";
        cout << "5. Delete Head\n";
        cout << "6. Delete Tail\n";
        cout << "7. Delete at specific position from Head\n";
        cout << "8. Delete at specific position from Tail\n";
        cout << "9. Search from Head\n";
        cout << "10. Search from Tail\n";
        cout << "11. Display List\n";
        cout << "12. Display List in Reverse\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at head: ";
            cin >> value;
            dl.InsertAtHead(value);
            break;
        case 2:
            cout << "Enter value to insert at tail: ";
            cin >> value;
            dl.InsertAtTail(value);
            break;
        case 3:
            cout << "Enter value and position from head: ";
            cin >> value >> index;
            dl.InsertFromHead(value, index);
            break;
        case 4:
            cout << "Enter value and position from tail: ";
            cin >> value >> index;
            dl.InsertFromTail(value, index);
            break;
        case 5:
            dl.DeleteHead();
            break;
        case 6:
            dl.DeleteTail();
            break;
        case 7:
            cout << "Enter position from head to delete: ";
            cin >> index;
            dl.deleteFromHead(index);
            break;
        case 8:
            cout << "Enter position from tail to delete: ";
            cin >> index;
            dl.deleteFromTail(index);
            break;
        case 9:
            cout << "Enter value to search from head: ";
            cin >> searchValue;
            index = dl.searchFromHead(searchValue);
            if (index == -1)
                cout << "Value not found\n";
            else
                cout << "Value found at position (from head): " << index << endl;
            break;
        case 10:
            cout << "Enter value to search from tail: ";
            cin >> searchValue;
            index = dl.searchFromTail(searchValue);
            if (index == -1)
                cout << "Value not found\n";
            else
                cout << "Value found at position (from tail): " << index << endl;
            break;
        case 11:
            dl.display();
            break;
        case 12:
            dl.Reverse_display();
            break;
        case 13:
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
