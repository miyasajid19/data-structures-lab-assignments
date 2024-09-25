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
    void InsertAtHead(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        new_node->Next = head;
        head = new_node;
    }
    void InsertAtTail(int value)
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
    void DeleteFromHead()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        Node *temp = head;
        if (head->Next == nullptr)
        {
            head = nullptr;
        }
        else
        {
            head = head->Next;
        }
        delete temp;
    }
    void Create(int num)
    {
        while (num != 0)
        {
            int remainder = num % 10;
            InsertAtTail(remainder);
            num /= 10;
        }
    }
    LinkedLists operator+(LinkedLists list)
    {
        LinkedLists result;
        Node *temp1 = head;
        Node *temp2 = list.head;
        int carry = 0;
        while (temp1 != nullptr or temp2 != nullptr or carry)
        {
            if (temp1 != nullptr and temp2 != nullptr)
            {
                int sum = temp1->Value + temp2->Value + carry;
                temp1 = temp1->Next;
                temp2 = temp2->Next;
                if (sum > 9)
                {
                    carry = sum / 10;
                    sum = sum % 10;
                }
                result.InsertAtTail(sum);
            }
            else if (temp1 != nullptr and temp2 == nullptr)
            {
                int sum = temp1->Value + carry;
                temp1 = temp1->Next;
                if (sum > 9)
                {
                    carry = sum / 10;
                    sum = sum % 10;
                }
                result.InsertAtTail(sum);
            }
            else if (temp1 == nullptr and temp2 != nullptr)
            {
                int sum = temp2->Value + carry;
                temp2 = temp2->Next;
                if (sum > 9)
                {
                    carry = sum / 10;
                    sum = sum % 10;
                }
                result.InsertAtTail(sum);
            }
            else if (carry != 0)
            {
                result.InsertAtTail(carry);
                carry = 0;
            }
        }
        return result;
    }
};
int main()
{
#ifndef online_judge
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !online_judge
    LinkedLists A;
    A.Create(1);
    A.Display();
    LinkedLists B;
    B.Create(11);
    B.Display();
    LinkedLists C = A + B;
    C.Display();
    return EXIT_SUCCESS;
}