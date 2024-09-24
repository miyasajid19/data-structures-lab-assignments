#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int ID;
    string Name;
    string Branch;
    long long int Phone;
    char Section;
    float GPA;
    Node *Next;
    Node *Previous;

    Node(int ID, string Name, string Branch, long long int Phone, char Section, float GPA)
    {
        this->ID = ID;
        this->Name = Name;
        this->Branch = Branch;
        this->Phone = Phone;
        this->Section = Section;
        this->GPA = GPA;
        this->Next = nullptr;
        this->Previous = nullptr;
    }
};

class Linkedlist
{
    Node *head;
    Node *tail;

public:
    Linkedlist() : head(nullptr), tail(nullptr) {}

    ~Linkedlist()
    {
        Node *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->Next;
            delete temp;
        }
    }

    void Push_Front(int ID, string Name, string Branch, long long int Phone, char Section, float GPA)
    {
        Node *new_node = new Node(ID, Name, Branch, Phone, Section, GPA);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            head->Previous = new_node;
            new_node->Next = head;
            head = new_node;
        }
    }

    void Push_Back(int ID, string Name, string Branch, long long int Phone, char Section, float GPA)
    {
        Node *new_node = new Node(ID, Name, Branch, Phone, Section, GPA);
        if (tail == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->Next = new_node;
            new_node->Previous = tail;
            tail = new_node;
        }
    }
    void InsertFromFront(int index, int ID, string Name, string Branch, long long int Phone, char Section, float GPA)
    {
        if (index < 0)
        {
            cout << "invlaid index" << endl;
            return;
        }
        if (index == 0)
        {
            Push_Front(ID, Name, Branch, Phone, Section, GPA);
            return;
        }
        int count = 0;
        Node *temp = head;
        while (count < index - 1 and temp != nullptr)
        {
            temp = temp->Next;
            count++;
        }
        if (temp == nullptr)
        {
            Push_Back(ID, Name, Branch, Phone, Section, GPA);
            return;
        }
        Node *new_node = new Node(ID, Name, Branch, Phone, Section, GPA);
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
    void InsertFromBack(int index, int ID, string Name, string Branch, long long int Phone, char Section, float GPA)
{
    if (index < 0)
    {
        cout << "Invalid index" << endl;
        return;
    }

    // Count the number of nodes
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->Next;
    }

    // Validate the index
    if (index >= count)
    {
        cout << "Index out of bounds" << endl;
        return;
    }

    // If index is the last position (equivalent to inserting at the end)
    if (index == 0)
    {
        Push_Back(ID, Name, Branch, Phone, Section, GPA);
        return;
    }

    // Traverse from the end
    int target = count - index - 1;
    temp = tail;
    while (target > 0 && temp != nullptr)
    {
        temp = temp->Previous;
        target--;
    }

    if (temp == nullptr)
    {
        cout << "Unexpected error" << endl;
        return;
    }

    Node *new_node = new Node(ID, Name, Branch, Phone, Section, GPA);
    
    // Insert at the end
    if (temp->Next != nullptr)
    {
        new_node->Next = temp->Next;
        temp->Next->Previous = new_node;
    }
    else
    {
        tail = new_node;
    }
    temp->Next = new_node;
    new_node->Previous = temp;
}

    void display_Front()
    {
        if (head == nullptr)
        {
            cout << "Student data is empty" << endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->ID << " " << temp->Name << " " << temp->Branch << " " << temp->GPA << " " << temp->Phone << endl;

            if (temp->Next != nullptr)
            {
                cout << "\t\t\t\t|\n\t\t\t\t|\n\t\t\t\tV" << endl;
            }

            temp = temp->Next;
        }

        cout << "\t\t\tnullptr" << endl;
    }

    void display_Back()
    {
        if (tail == nullptr)
        {
            cout << "Student data is empty" << endl;
            return;
        }

        Node *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->ID << " " << temp->Name << " " << temp->Branch << " " << temp->GPA << " " << temp->Phone << endl;

            if (temp->Previous != nullptr)
            {
                cout << "\t\t\t\t|\n\t\t\t\t|\n\t\t\t\tV" << endl;
            }

            temp = temp->Previous;
        }

        cout << "\t\t\tnullptr" << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Linkedlist list;
    list.Push_Front(432, "sajid miya", "BE/B.Tech", 9808749490, 'I', 9.55);
    list.Push_Front(433, "sajid miya", "BE/B.Tech", 9808749490, 'I', 9.55);
    list.Push_Front(434, "sajid miya", "BE/B.Tech", 9808749490, 'I', 9.55);
    list.Push_Back(435, "sajid miya", "BE/B.Tech", 9808749490, 'I', 9.55);
    list.Push_Back(436, "sajid miya", "BE/B.Tech", 9808749490, 'I', 9.55);
    list.Push_Back(437, "sajid miya", "BE/B.Tech", 9808749490, 'I', 9.55);
    list.InsertFromFront(2,407,"Pramisha Karki","BE/B.Tech",9808749490,'I',10);
    list.InsertFromFront(2,407,"Pramisha Karki","BE/B.Tech",9808749490,'I',10);
    list.display_Front();
    cout << endl;
    list.display_Back();
    return EXIT_SUCCESS;
}