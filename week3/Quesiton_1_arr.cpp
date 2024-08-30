#include <iostream>
#include <cstdlib>
using namespace std;
class Stacks
{
    int size;
    int capacity;
    int *arr;

public:
    Stacks() {}
    Stacks(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        arr = new int[capacity]();
    }
    void setStack(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        arr = new int[capacity]();
    }
    void reStack(int capacity)
    {
        this->capacity = capacity;
        int *arr1 = new int[capacity]();
        for (int i = 0; i < size; i++)
        {
            arr1[i] = arr[i];
        }
        delete[] arr;
        arr = arr1;
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
        return size;
    }
    void Push(int value)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
            return;
        }
        arr[this->size++] = value;
    }
    void Pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return;
        }
        this->size--;
    }
    int Peek()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return arr[this->size - 1];
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Stacks()
    {
        delete[] arr;
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