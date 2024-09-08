#include <iostream>
#include <cstdlib>
#include "CircularQueue.h"
using namespace std;
void Interleave(Queue<int> &queue)
{
    int x=queue.Size();
    int size = queue.Size() / 2;
    Queue<int> temp(size);
    for (int i = 0; i < size; i++)
    {
        temp.Enqueue(queue.Peek());
        queue.Dequeue();
    }
    for(int i =0;i<x;i++)
    {
        if(i%2==0)
        {
            queue.Enqueue(temp.Peek());
            temp.Dequeue();
        }
        else{
            queue.Enqueue(queue.Peek());
            queue.Dequeue();
        }
    }
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int size;
    cout << "enter how many data do you want to insert in the queue ?" << endl;
    cin >> size;
    Queue<int> queue(size+1);
    for (int i = 0; i < size; i++)
    {
        int num;
        cout << "enter element :: ";
        cin >> num;
        queue.Enqueue(num);
    }
    queue.Display();
    Interleave(queue);
    queue.Display();
    return EXIT_SUCCESS;
}