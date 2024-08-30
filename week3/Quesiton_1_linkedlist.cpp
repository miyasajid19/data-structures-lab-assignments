#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int value;
    Node *Next;
    Node(int value)
    {
        this->value = value;
        this->Next = nullptr;
    }
};
class Stacks
{
    Node *head;
    int size;
    int capacity;

public:
    Stacks()
    {
        this->size = 0;
        this->capacity = 0;
        this->head = nullptr;
    }
    Stacks(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        this->head = nullptr;
    }
    Stacks(Stacks &stk)
    {
        this->size = stk.size;
        this->capacity = stk.capacity;
        this->head = stk.head;
    }
    void setStack(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        this->head = nullptr;
    }
    bool isEmpty()
    {
        return this->size == 0;
    }
    bool isFull()
    {
        return this->size == this->capacity;
    }
    int Size()
    {
        return this->size;
    }
    void Push(int value)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
            return;
        }
        Node *new_node = new Node(value);
        new_node->Next = head;
        head = new_node;
        size++;
    }
    void reStack(int capacity)
    {
        if(this->size<capacity)
        {
            cout<<"invlaid capacity"<<endl<<"make the size greater than or equal to size"<<endl;
        }
        this->capacity = capacity;
    }
    void Pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return;
        }
        // if (head->Next == nullptr)
        // {
        //     delete head;
        //     head = nullptr;
        //     return;
        // }
        Node *temp = head;
        head = head->Next;
        delete temp;
        size--;
    }
    int Peek()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return head->value;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->Next;
        }
    }
};
int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    Stacks stack;
    int capacity, choice, value;

    cout << "Enter the initial capacity of the stack: ";
    cin >> capacity;
    stack.setStack(capacity);

    do
    {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display Stack" << endl;
        cout << "5. Check if Stack is Empty" << endl;
        cout << "6. Check if Stack is Full" << endl;
        cout << "7. Resize Stack" << endl;
        cout << "8. Get Stack Size" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.Push(value);
            break;

        case 2:
            stack.Pop();
            break;

        case 3:
            cout << "Top element: " << stack.Peek() << endl;
            break;

        case 4:
            stack.display();
            break;

        case 5:
            if (stack.isEmpty())
                cout << "The stack is empty.\n";
            else
                cout << "The stack is not empty.\n";
            break;

        case 6:
            if (stack.isFull())
                cout << "The stack is full.\n";
            else
                cout << "The stack is not full.\n";
            break;

        case 7:
            cout << "Enter new capacity: ";
            cin >> capacity;
            stack.reStack(capacity);
            cout << "Stack resized to " << capacity << endl;
            break;

        case 8:
            cout << "Current stack size: " << stack.Size() << endl;
            break;

        case 9:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 9);
    return EXIT_SUCCESS;
}