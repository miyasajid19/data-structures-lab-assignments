#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
class Stack
{
    int size;
    int capacity;
    queue<int> Queue;
    queue<int> auxilliary;

public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
    }
    bool isEmpty()
    {
        return this->size == 0;
    }
    bool isFull()
    {
        return this->size == this->capacity;
    }
    void push(int value)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
            return;
        }
        auxilliary.push(value);
        while (not Queue.empty())
        {
            auxilliary.push(Queue.front());
            Queue.pop();
        }
        swap(auxilliary, Queue);
        this->size++;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        auxilliary = Queue;
        while (not auxilliary.empty())
        {
            cout << auxilliary.front() << " ";
            auxilliary.pop();
        }
        cout << endl;
    }
    void Pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return;
        }
        Queue.pop();
        this->size--;
    }
    int Top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return Queue.front();
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Stack stk(5);
    for (int i = 0; i < 5; i++)
    {
        stk.push(i);
        stk.display();
    }
    return EXIT_SUCCESS;
}