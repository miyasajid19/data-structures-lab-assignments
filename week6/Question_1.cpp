#include <iostream>
using namespace std;
class Node
{
public:
    int Value;
    Node *Next;
    Node *Previous;
    Node(int Value)
    {
        this->Value = Value;
        this->Previous = nullptr;
        this->Next = nullptr;
    }
};
class DoubleList
{//all i want was the love and what i get is the pain
public:
    Node *head;
    Node *tail;
    DoubleList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void InsertAtHead(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        head->Previous = new_node;
        new_node->Next = head;
        head = new_node;
    }
    void InsertAtTail(int value)
    {
        Node *new_node = new Node(value);
        if (tail == nullptr)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->Previous = tail;
        tail->Next = new_node;
        tail = new_node;
    }
    void InsertFromHead(int value, int index)
    {
        if (index < 0)
        {
            InsertFromTail(value, -index);
            return;
        }
        if (index == 0)
        {
            InsertAtHead(value);
            return;
        }
        Node *temp = head;
        int count = 0;
        while (temp != nullptr and count < index - 1)
        {
            temp = temp->Next;
            count++;
        }
        if (temp == nullptr)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        if (temp->Next == nullptr)
        {
            InsertAtTail(value);
            return;
        }
        Node *new_node = new Node(value);
        new_node->Next = temp->Next;
        if (temp->Next != nullptr)
        {
            temp->Next->Previous = new_node;
        }
        else
        {
            tail = new_node;
        }
        temp->Next = new_node;
        new_node->Previous = temp;
    }
    void InsertFromTail(int value, int index)
    {
        if (index < 0)
        {
            InsertFromHead(value, -index);
            return;
        }
        if (index == 0)
        {
            InsertAtTail(value);
            return;
        }
        int counter = 0;
        Node *temp = tail;
        while (temp != nullptr and counter < index - 1)
        {
            temp = temp->Previous;
            counter++;
        }
        if (temp == nullptr)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        Node *new_node = new Node(value);
        new_node->Next = temp;
        if (temp->Previous != nullptr)
        {

            new_node->Previous = temp->Previous;
        }
        else
        {
            head = new_node;
        }

        temp->Previous->Next = new_node;
        temp->Previous = new_node;
    }
    void DeleteHead()
    {
        if (head == nullptr)
        {
            cout << "linked list is already empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->Next;
        if (head)
        {
            head->Previous = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }
    void DeleteTail()
    {
        if (tail == nullptr)
        {
            cout << "linked list is already empty" << endl;
            return;
        }
        Node *temp = tail;
        tail = tail->Previous;
        if (tail)
        {
            tail->Next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
    }
    void deleteFromHead(int index)
    {
        if (index < 0)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        Node *temp = head;
        int counter = 0;
        while (temp != nullptr and counter < index)
        {
            temp = temp->Next;
            counter++;
        }
        if (temp == nullptr)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        if (temp == tail)
        {
            DeleteTail();
            return;
        }
        if (temp->Previous != nullptr)
            temp->Previous->Next = temp->Next;

        if (temp->Next != nullptr)
            temp->Next->Previous = temp->Previous;

        delete temp;
    }
    void deleteFromTail(int index)
    {
        if (index < 0)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        Node *temp = tail;
        int counter = 0;
        while (temp != nullptr and counter < index)
        {
            temp = temp->Previous;
            counter++;
        }
        if (temp == nullptr)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        if (temp == head)
        {
            DeleteHead();
            return;
        }
        if (temp->Next != nullptr)
            temp->Next->Previous = temp->Previous;

        if (temp->Previous != nullptr)
            temp->Previous->Next = temp->Next;

        delete temp;
    }
    void display()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        Node *temp = head;
        cout << "nullptr <--> ";
        while (temp != nullptr)
        {
            cout << temp->Value << " <--> ";
            temp = temp->Next;
        }
        cout << "  nullptr" << endl;
    }
    void Reverse_display()
    {
        if (tail == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        Node *temp = tail;
        cout << "nullptr <--> ";
        while (temp != nullptr)
        {
            cout << temp->Value << " <--> ";
            temp = temp->Previous;
        }
        cout << "  nullptr" << endl;
    }
    int searchFromHead(int value)
    {
        Node *temp = head;
        int count = 0;
        while (temp)
        {
            if (temp->Value == value)
            {
                return count;
            }
            temp = temp->Next;
            count++;
        }
        return -1;
    }
    int searchFromTail(int value)
    {
        Node *temp = tail;
        int count = 0;
        while (temp)
        {
            if (temp->Value == value)
            {
                return count;
            }
            temp = temp->Previous;
            count++;
        }
        return -1;
    }
    void Insert(int value)
    {
        InsertAtTail(value);
    }
    void Delete()
    {
        DeleteTail();
    }
    int search(int value)
    {
        return searchFromHead(value);
    }
};
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
