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

class LinkedLists
{
public:
    Node *head;
    LinkedLists()
    {
        head = nullptr;
    }

    void push(int value)
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
    void display()
    {
        if (head == nullptr)
        {
            cout << "The linked list is empty\nHence, there is nothing to display" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << "->";
            temp = temp->Next;
        }
        cout << "nullptr" << endl;
    }

    void FirstLastOrder()
    {
        if (!head)
        {
            cout << "The linked list is empty" << endl;
            return;
        }

        // Find the middle of the list
        Node *slowPointer = head;
        Node *fastPointer = head;
        while (fastPointer && fastPointer->Next)
        {
            slowPointer = slowPointer->Next;
            fastPointer = fastPointer->Next->Next;
        }

        // Reverse the second half of the list
        Node *prev = nullptr;
        Node *current = slowPointer;
        while (current)
        {
            Node *next = current->Next;
            current->Next = prev;
            prev = current;
            current = next;
        }
        // 1->2->3<-4<-5
        // Merge the two halves
        Node *firstHalf = head;
        Node *secondHalf = prev;
        while (secondHalf->Next)
        {
            Node *temp1 = firstHalf->Next;
            Node *temp2 = secondHalf->Next;
            firstHalf->Next = secondHalf;
            secondHalf->Next = temp1;

            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    LinkedLists list;
    list.display();

    for (int i = 1; i <= 10; i++)
    {
        list.push(i);
    }

    list.FirstLastOrder();
    list.display();

    return EXIT_SUCCESS;
}