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

    bool IsPalindrome()
    {
        if (!head || !head->Next)
            return true; // A single node or empty list is a palindrome

        Node *slowPointer = head, *fastPointer = head;

        // Step 1: Find the middle of the linked list
        while (fastPointer && fastPointer->Next)
        {
            slowPointer = slowPointer->Next;
            fastPointer = fastPointer->Next->Next;
        }

        // Step 2: Reverse the second half of the linked list
        Node *prev = nullptr, *current = slowPointer, *nextNode = nullptr;
        while (current)
        {
            nextNode = current->Next;
            current->Next = prev;
            prev = current;
            current = nextNode;
        }

        // Step 3: Compare the first half and the reversed second half
        Node *head1 = head, *head2 = prev; // prev is the new head of the reversed half
        while (head2)                      // Only need to compare till the end of head2 (reversed second half)
        {
            if (head1->value != head2->value)
                return false;
            head1 = head1->Next;
            head2 = head2->Next;
        }

        return true;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    LinkedLists list;
    cout << boolalpha;

    // Adding elements to the linked list
    list.push(1);
    list.push(2);
    list.push(4);
    list.push(1);

    // Display the list
    list.display();

    // Check if the list is a palindrome
    cout << "Is the linked list a palindrome? " << list.IsPalindrome() << endl;

    return EXIT_SUCCESS;
}
