#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
class Stacks
{
    queue<int> Queue;
    int size;
    int capacity;

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
            cout << "stack overflow" << endl;
            return;
        }
        Queue.push(value);
        for (int i = 0; i < this->size; i++)
        {
            Queue.push(Queue.front());
            Queue.pop();
        }
        this->size++;
    }
    void pop()
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
            cout << "stack is empty";
            // if this is encounterred then it will stop the further execution of N program
            // to handle this you can use
            // return INT_MIN;
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
        queue<int> temp = Queue;
        while (not temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
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
        cout << "Top : " << stack.top() << endl;
        stack.display();
    }
    for (int i = 0; i < 6; i++)
    {
        stack.pop();
        cout << "Top : " << stack.top() << endl;
        stack.display();
    }
    return EXIT_SUCCESS;
}