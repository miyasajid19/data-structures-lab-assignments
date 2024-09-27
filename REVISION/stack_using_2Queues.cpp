#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
class Stacks
{
    int size;
    int capacity;
    queue<int> Queue;
    queue<int> helper;

public:
    Stacks(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
    }
    bool isFull()
    {
        return this->size == this->capacity;
    }
    bool isEmpty()
    {
        return this->size == 0;
    }
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack overflow" << endl;
            return;
        }
        helper.push(value);
        while (not Queue.empty())
        {
            helper.push(Queue.front());
            Queue.pop();
        }
        this->size++;
        swap(helper, Queue);
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
    int top()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            exit(1);
        }
        return Queue.front();
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        while (not Queue.empty())
        {
            cout << Queue.front() << " ";
            helper.push(Queue.front());
            Queue.pop();
        }
        swap(helper, Queue);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Stacks stack(5);
    for (int i = 0; i < 6; i++)
    {
        stack.push(i);
        cout << "Top :: " << stack.top() << endl;
        stack.display();
    }
    for (int i = 0; i < 6; i++)
    {
        stack.Pop();
        cout << "Top :: " << stack.top() << endl;
        stack.display();
    }
    return EXIT_SUCCESS;
}