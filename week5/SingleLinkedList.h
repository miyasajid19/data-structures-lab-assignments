#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int value):value(value),next(nullptr){}
};
class linkedList{
    private:
    Node* head;
    public:
    linkedList(){
        this->head=nullptr;
    }
    void InsertAtHead(int value)
    {
        Node* new_node=new Node(value);
        if (head == nullptr)
        {
        head= new_node;
        return;
        }
        new_node->next=head;
        head=new_node;
    }
    void InsertAtTail(int value)
    {
        Node* new_node=new Node(value);
        if(head==nullptr)
        {
            head=new_node;
            return;
        }
        Node* temp=head;
         while(temp->next!=nullptr)
         {
            temp=temp->next;
         }
         temp->next=new_node;
    }
    void Insert(int value, int index)
    {
        Node* new_node=new Node(value);
        if(head==nullptr)
        {
            head=new_node;
            return;
        }
        if(index==0)
        {
            InsertAtHead(value);
            return;
        }
        Node* temp=head;
        int Counter=0;
        while((temp!=nullptr) && (Counter<index-1))
        {
            Counter++;
            temp=temp->next;
        }
        if(temp==nullptr)
        {
            cout<<"invalid indexing"<<endl;
            delete new_node;
            return;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
    void DeleteFromHead()
    {
        if(head==nullptr)
        {
            cout<<"the linked list is empty"<<endl;
            return;
        }
        Node* temp=head;
        if(head->next==nullptr)
        {
            head=nullptr;
        }
        else{
            head=head->next;
        }
        delete temp;
    }
    void deleteFromTail()
    {
        if(head==nullptr)
        {
            cout<<"the linked list is empty"<<endl;
            return;
        }
        Node* temp=head;
        if(head->next==nullptr)
        {
            DeleteFromHead();
            return;
        }else{
            while(temp->next->next!=nullptr)
            {
                temp=temp->next;
            }
        }
        Node* todelete=temp->next;
                temp->next=nullptr;
                delete todelete;
        }

int search(int value)
{
    if(head==nullptr)
    {
        return -1;
    }
    Node* temp=head;
    int count=0;
    while(temp!=nullptr)
    {
        if(temp->value==value)
        {
            return count;
        }
        count++;
    temp=temp->next;
    }
    return -1;
}
    void Delete(int index)
        {
            if(head==nullptr)
            {
                cout<<"the linked list is empty"<<endl;
                return;
            }
            if(index==0)
            {
                DeleteFromHead();
                return;
            }
            Node* temp=head;
            int counter=0;
            while(temp!=nullptr && counter<index-1)
            {
                temp=temp->next;
                counter++;
            }
            if(temp==nullptr)
            {
                cout<<"index out of bound"<<endl;
                return;
            }
            Node* todelete=temp->next;
            temp->next=temp->next->next;
            delete todelete;
        }

    
    void display()
    {
        if(head==nullptr)
        {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->value<<"->";
            temp=temp->next;
        }
        cout<<"nullptr"<<endl;
    }
};
