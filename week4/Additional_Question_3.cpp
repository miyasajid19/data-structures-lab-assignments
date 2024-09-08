#include <iostream>
#include <cstdlib>
#include <string>
#include "circularQueue.h"
using namespace std;

int PageReplacement(Queue<int> &queue, int frame)
{
    cout << "pages\t";
    for (int i = 1; i <= frame; i++)
    {
        cout << "frame " << i << "\t";
    }
    cout << "Hit/Fault\n";

    int hits = 0, faults = 0;
    int frames[3] = {-1, -1, -1};
    int index = 0;

    for (int i = 0; i < queue.Size(); i++)
    {
        int currentPage = queue.Peek();
        queue.Dequeue();

        bool hit = false;

        for (int j = 0; j < frame; j++)
        {
            if (frames[j] == currentPage)
            {
                hit = true;
                break;
            }
        }

        cout << currentPage << "\t";

        if (hit)
        {
            hits++;
            for (int j = 0; j < frame; j++)
            {
                cout << frames[j] << "\t";
            }
            cout << "Hit\n";
        }
        else
        {
            faults++;
            frames[index] = currentPage;
            index = (index + 1) % frame;

            for (int j = 0; j < frame; j++)
            {
                cout << frames[j] << "\t";
            }
            cout << "Fault\n";
        }

        queue.Enqueue(currentPage);
    }

    cout << "Total Hits: " << hits << "\n";
    cout << "Total Faults: " << faults << "\n";

    return faults;
}

int main()
{
    int size;
    cout << "How many pages do you have? ";
    cin >> size;

    Queue<int> queue(size);

    for (int i = 0; i < size; i++)
    {
        int x;
        cout << "Enter page no. :: ";
        cin >> x;
        queue.Enqueue(x);
    }

    cout << "How many frames do you want to give in the main memory? ";
    int frame;
    cin >> frame;

    PageReplacement(queue, frame);

    return EXIT_SUCCESS;
}
