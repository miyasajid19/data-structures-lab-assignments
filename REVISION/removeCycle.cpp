#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int Value;
    Node *Next;
    Node(int value)
    {
        this->Value = value;
        this->Next = nullptr;
    }
};

class LinkedLists
{
public:
    Node *head;
    LinkedLists()
    {
        this->head = nullptr;
    }

    void Push(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->Next != nullptr)
        {
            temp = temp->Next;
        }
        temp->Next = new_node;
    }

    void Display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->Value << "->";
            temp = temp->Next;
        }
        cout << "nullptr" << endl;
    }
    bool CheckCycle()
    {
        if (head == nullptr)
        {
            exit(1);
        }
        Node *slowPointer = head;
        Node *fastPointer = head;
        while (fastPointer and fastPointer->Next)
        {
            slowPointer = slowPointer->Next;
            fastPointer = fastPointer->Next->Next;
            if (slowPointer == fastPointer)
            {
                cout << "cyclic at :: " << slowPointer->Value << " Node" << endl;
                return true;
            }
        }
        return false;
    }
    void RemoveCycle()
    {
        if (CheckCycle())
        {
            Node *slowPointer = head;
            Node *fastPointer = head;
            do
            {
                slowPointer = slowPointer->Next;
                fastPointer = fastPointer->Next->Next;
                if (fastPointer == slowPointer)
                {
                    slowPointer->Next = nullptr;
                    break;
                }
            } while (slowPointer != fastPointer);
            cout << "The linked list is no longer cyclic" << endl;
        }
        else
        {
            cout << "The linked list is not cyclic" << endl;
        }
    }
};

int main()
{
#ifndef online_judge
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !online_judge

    LinkedLists list1;
    list1.Push(4);
    list1.Push(1);
    list1.Push(8);
    list1.Push(13);
    list1.Push(2062);
    list1.Push(2061);
    list1.Push(407);
    list1.Push(432);
    cout << boolalpha;
    cout << list1.CheckCycle() << endl;
    list1.Display();
    list1.RemoveCycle();
    list1.head->Next->Next->Next->Next->Next->Next->Next->Next = list1.head->Next->Next->Next->Next->Next->Next;
    cout << list1.CheckCycle() << endl;
    list1.RemoveCycle();
    list1.Display();
    cout << list1.CheckCycle() << endl;
    return EXIT_SUCCESS;
}
