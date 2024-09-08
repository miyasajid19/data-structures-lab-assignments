#include <iostream>
#include <cstdlib>
#include <climits>
#include "circularQueue.h"
using namespace std;

int MinimumIndex(Queue<int> &queue, int SortedIndex)
{
    int minimumIndex = -1;
    int minimumValue = INT_MAX;
    int size = queue.Size();

    for (int i = 0; i < size; i++)
    {
        int current = queue.Peek();
        queue.Dequeue();

        if (current < minimumValue && i <= SortedIndex)
        {
            minimumIndex = i;
            minimumValue = current;
        }

        queue.Enqueue(current);
    }

    return minimumIndex;
}

void insertMinimumToRear(Queue<int> &queue, int minimumIndex)
{
    int minimumValue;
    int size = queue.Size();

    for (int i = 0; i < size; i++)
    {
        int current = queue.Peek();
        queue.Dequeue();

        if (i != minimumIndex)
        {
            queue.Enqueue(current);
        }
        else
        {
            minimumValue = current;
        }
    }

    queue.Enqueue(minimumValue);
}
void sortQueue(Queue<int> &queue)
{
    int size = queue.Size();

    for (int i = 0; i < size; i++)
    {
        int minimumIndex = MinimumIndex(queue, size - i - 1);

        insertMinimumToRear(queue, minimumIndex);
        cout<<"<==============================================================================>\n";
        queue.Display();
    }
}

int main()
{
    Queue<int> queue(5);
    queue.Enqueue(432);
    queue.Enqueue(407);
    queue.Enqueue(420);
    queue.Enqueue(433);
    queue.Enqueue(417);

    cout << "Queue before sorting: ";
    queue.Display();

    sortQueue(queue);

    cout << "Queue after sorting: ";
    queue.Display();

    return EXIT_SUCCESS;
}
