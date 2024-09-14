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
    ~Node() {}
};
class LinkedLists
{
public:
    Node *head;
    LinkedLists()
    {
        head = nullptr;
    }
    void add(int value)
    {
        Node *new_node = new Node(value);
        if (!head)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->Next)
        {
            temp = temp->Next;
        }
        temp->Next = new_node;
    }
    void display()
    {
        if (!head)
        {
            cout << "there is nothing to print" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << "->";
            temp = temp->Next;
        }
        cout << "nullptr" << endl;
    }
};
int getLength(Node *head)
{
    if (!head)
    {
        return 0;
    }
    int counter = 0;
    Node *temp = head;
    while (temp)
    {
        counter++;
        temp = temp->Next;
    }
    return counter;
}
Node* moveHeadBy(Node* head, int length)
{
    Node *temp = head;
    while (length--)
    {
        temp = temp->Next;
    }
    return temp;
}
Node* findIntersection(Node *head1, Node *head2)
{
    if (!head1 || !head2) return nullptr;
    int length1 = getLength(head1);
    int length2 = getLength(head2);
    Node *pointer1 = (length1>length2)?moveHeadBy(head1,length1-length2):head1;
    Node *pointer2 = (length2>length1)?moveHeadBy(head2,length2-length1):head2;

    while (pointer1 and pointer2)
    {
        if (pointer1 == pointer2)
        {
            return pointer1;
        }
        pointer1=pointer1->Next;
        pointer2=pointer2->Next;
    }
    return nullptr;
}
int main()
{
#ifndef JUDGE_ONLINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    LinkedLists list1,list2;
    list1.add(1);
    list1.add(2);
    list1.add(3);
    list1.add(4);
    list1.add(5);
    list1.display();
    cout << "the length of list is " << getLength(list1.head) << endl;
    list2.add(407);
    list2.add(432);
    list2.add(433);
    list2.add(434);
    list2.head->Next->Next->Next->Next=list1.head->Next->Next;
    list2.display();
    cout << "the length of list is " << getLength(list2.head) << endl;
    Node* intersection=findIntersection(list1.head,list2.head);
    if(intersection)
    {
        cout<<intersection->value<<" is the intersection point of both linked lists"<<endl;
    }
    else{
        cout<<-1<<" is the intersection point is not present"<<endl;

    }
    return EXIT_SUCCESS;
}



// ----------------------------------------CHATGPT CODE --1------------------------------------------------
/*
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *Next;

    Node(int value) : value(value), Next(nullptr) {}

    ~Node() {}
};

class LinkedLists {
public:
    Node *head;

    LinkedLists() : head(nullptr) {}

    ~LinkedLists() {
        Node *current = head;
        while (current != nullptr) {
            Node *next = current->Next;
            delete current;
            current = next;
        }
    }

    void add(int value) {
        Node *new_node = new Node(value);
        if (!head) {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->Next) {
            temp = temp->Next;
        }
        temp->Next = new_node;
    }

    void display() const {
        if (!head) {
            cout << "There is nothing to print" << endl;
            return;
        }
        Node *temp = head;
        while (temp) {
            cout << temp->value << "->";
            temp = temp->Next;
        }
        cout << "nullptr" << endl;
    }
};

int getLength(Node *head) {
    int counter = 0;
    while (head) {
        counter++;
        head = head->Next;
    }
    return counter;
}

Node* moveHeadBy(Node* head, int length) {
    while (length-- && head) {
        head = head->Next;
    }
    return head;
}

Node* findIntersection(Node *head1, Node *head2) {
    if (!head1 || !head2) return nullptr;
    int length1 = getLength(head1);
    int length2 = getLength(head2);

    if (length1 > length2) {
        head1 = moveHeadBy(head1, length1 - length2);
    } else {
        head2 = moveHeadBy(head2, length2 - length1);
    }

    while (head1 && head2) {
        if (head1 == head2) {
            return head1;
        }
        head1 = head1->Next;
        head2 = head2->Next;
    }
    return nullptr;
}

int main() {
    LinkedLists list1, list2;
    list1.add(1);
    list1.add(2);
    list1.add(3);
    list1.add(4);
    list1.add(5);
    list1.display();
    cout << "The length of list1 is " << getLength(list1.head) << endl;

    list2.add(407);
    list2.add(432);
    list2.add(433);
    list2.add(434);
    list2.head->Next->Next->Next->Next = list1.head->Next->Next;  // Creating intersection
    list2.display();
    cout << "The length of list2 is " << getLength(list2.head) << endl;

    Node* intersection = findIntersection(list1.head, list2.head);
    if (intersection) {
        cout << intersection->value << " is the intersection point of both linked lists" << endl;
    } else {
        cout << -1 << " is the intersection point not present" << endl;
    }

    return EXIT_SUCCESS;
}
*/




//#######################################CHATGPT CODE 2#################################
/*
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
    ~Node() {}
};
class LinkedLists
{
public:
    Node *head;
    LinkedLists()
    {
        head = nullptr;
    }
    void add(int value)
    {
        Node *new_node = new Node(value);
        if (!head)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->Next)
        {
            temp = temp->Next;
        }
        temp->Next = new_node;
    }
    void display()
    {
        if (!head)
        {
            cout << "there is nothing to print" << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << "->";
            temp = temp->Next;
        }
        cout << "nullptr" << endl;
    }
};
int getLength(Node *head)
{
    if (!head)
    {
        return 0;
    }
    int counter = 0;
    Node *temp = head;
    while (temp)
    {
        counter++;
        temp = temp->Next;
    }
    return counter;
}
Node* moveHeadBy(Node* head, int length)
{
    Node *temp = head;
    while (length--)
    {
        temp = temp->Next;
    }
    return temp;
}
Node* findIntersection(Node *head1, Node *head2)
{
    int length2 = getLength(head2);
    int length1 = getLength(head1);
    Node *pointer1 = nullptr;
    Node *pointer2 = nullptr;
    length1 < length2 ? pointer2=moveHeadBy(head2, length2 - length1) :pointer1= moveHeadBy(head1, length1 - length2);
    while (pointer1)
    {
        if (pointer1 == pointer2)
        {
            return pointer1;
        }
        pointer1=pointer1->Next;
        pointer2=pointer2->Next;
    }
    return nullptr;
}
int main()
{
#ifndef JUDGE_ONLINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    LinkedLists list1,list2;
    list1.add(1);
    list1.add(2);
    list1.add(3);
    list1.add(4);
    list1.add(5);
    list1.display();
    cout << "the length of list is " << getLength(list1.head) << endl;
    list2.add(407);
    list2.add(432);
    list2.add(433);
    list2.add(434);
    list2.head->Next->Next->Next->Next=list1.head->Next->Next;
    list2.display();
    cout << "the length of list is " << getLength(list2.head) << endl;
    Node* intersection=findIntersection(list1.head,list2.head);
    if(intersection)
    {
        cout<<intersection->value<<" is the intersection point of both linked lists"<<endl;
    }
    else{
        cout<<-1<<" is the intersection point is not present"<<endl;

    }
    return EXIT_SUCCESS;
}
*/