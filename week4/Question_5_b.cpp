#include <iostream>
#include <cstdlib>
#include "linearQueue.h"
using namespace std;
class Stacks : public Queue<int>
{
public:
    Stacks(int capacity) : Queue(capacity) {}
    void Push(int value)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
            return;
        }
        Enqueue(value);
        while (Size() > 1)
        {
            int x = Peek();
            Dequeue();
            Enqueue(x);
        }
    }
    void Pop()
    {
        if(isEmpty())
        {
            cout<<"stack underflow"<<endl;
            return;
        }
        Dequeue();
    }
    int Top()
    {
        if(isEmpty())
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return Peek();
    }
};
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
Stacks stack(3);
stack.Push(1);
stack.Display();
cout<<"Top:::: "<<stack.Top()<<endl;
stack.Push(2);
stack.Display();
cout<<"Top:::: "<<stack.Top()<<endl;
stack.Push(3);
stack.Display();
cout<<"Top:::: "<<stack.Top()<<endl;
    return EXIT_SUCCESS;
}