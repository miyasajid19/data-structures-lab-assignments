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
};

int getLength(LinkedLists temp)
{
    Node *temp_head = temp.head;
    int counter = 0;
    while (temp_head != nullptr)
    {
        temp_head = temp_head->Next;
        counter++;
    }
    return counter;
}

Node *moveHeadBy(LinkedLists temp, int length)
{
    Node *temp_head = temp.head;
    while (length--)
    {
        temp_head = temp_head->Next;
    }
    return temp_head;
}

LinkedLists FindIntersection(LinkedLists list1, LinkedLists list2)
{
    int length1 = getLength(list1);
    int length2 = getLength(list2);
    Node *pointer1 = length1 > length2 ? moveHeadBy(list1, length1 - length2) : list1.head;
    Node *pointer2 = length2 > length1 ? moveHeadBy(list2, length2 - length1) : list2.head;
    LinkedLists solution;
    while (pointer1 && pointer2)
    {
        if (pointer1->Value == pointer2->Value)
        {
            solution.head = pointer1;
            break;
        }
        pointer1 = pointer1->Next;
        pointer2 = pointer2->Next;
    }
    return solution;
}

int main()
{
#ifndef online_judge
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !online_judge
    LinkedLists list1;
    cout << "Creating first linked list (list1) with values 0 to 4:" << endl;
    for (int i = 0; i < 5; i++)
    {
        list1.Push(i);
    }
    list1.Display();

    LinkedLists list2;
    cout << "Creating second linked list (list2) with values 5 to 9:" << endl;
    for (int i = 5; i < 10; i++)
    {
        list2.Push(i);
    }
    list2.Display();

    cout << "Creating an intersection between list1 and list2 starting at list1's 5th element and list2's 4th element:" << endl;
    list1.head->Next->Next->Next->Next->Next = list2.head->Next->Next->Next;
    list1.Display();
    list2.Display();

    cout << "Finding intersection point between the two linked lists:" << endl;
    LinkedLists solution = FindIntersection(list1, list2);
    solution.Display();

    return EXIT_SUCCESS;
}