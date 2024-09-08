#include <iostream>
#include <cstdlib>
#include "linearQueue.h"
using namespace std;

int main()
{
    int capacity, choice, value;
    
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;
    Queue queue(capacity);

    do
    {
        cout << "\nMenu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Peek\n";
        cout << "5. Check if Queue is Full\n";
        cout << "6. Check if Queue is Empty\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.Enqueue(value);
            break;
        case 2:
            queue.Dequeue();
            break;
        case 3:
            queue.Display();
            break;
        case 4:
            value = queue.Peek();
            if (value == INT_MAX)
                cout << "Queue is empty\n";
            else
                cout << "Front element: " << value << endl;
            break;
        case 5:
            if (queue.isFull())
                cout << "Queue is full\n";
            else
                cout << "Queue is not full\n";
            break;
        case 6:
            if (queue.isEmpty())
                cout << "Queue is empty\n";
            else
                cout << "Queue is not empty\n";
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}
