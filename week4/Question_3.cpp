#include <iostream>
#include <cstdlib>
#include "CircularQueue.h"
using namespace std;

void Interleave(Queue<int> &queue) {
    int totalSize = queue.Size();
    int halfSize = totalSize / 2;
    Queue<int> temp(halfSize);

    for (int i = 0; i < halfSize; i++) {
        temp.Enqueue(queue.Peek());
        queue.Dequeue();
    }

    for (int i = 0; i < totalSize; i++) {
        if (i % 2 == 0) {
            queue.Enqueue(temp.Peek());
            temp.Dequeue();
        } else {
            queue.Enqueue(queue.Peek());
            queue.Dequeue();
        }
    }
}

int main() {
    int size;
    cout << "Enter how many data do you want to insert in the queue? " << endl;
    cin >> size;

    Queue<int> queue(size + 1);

    for (int i = 0; i < size; i++) {
        int num;
        cout << "Enter element: ";
        cin >> num;
        queue.Enqueue(num);
    }

    cout << "Original Queue: ";
    queue.Display();

    Interleave(queue);

    cout << "Interleaved Queue: ";
    queue.Display();

    return EXIT_SUCCESS;
}
