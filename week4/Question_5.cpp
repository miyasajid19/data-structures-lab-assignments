#include <iostream>
#include <cstdlib>
#include "linearQueue.h"

using namespace std;

class PushEfficientStack : public Queue<int> {
    Queue<int> *auxQueue;

public:
    PushEfficientStack(int capacity) : Queue<int>(capacity) {
        auxQueue = new Queue<int>(capacity);
    }

    ~PushEfficientStack() {
        delete auxQueue;
    }

    void Push(int value) {
        if (this->isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }

        // Enqueue new element to auxQueue
        auxQueue->Enqueue(value);

        // Move all elements from the current queue to auxQueue
        while (!this->isEmpty()) {
            auxQueue->Enqueue(this->Peek());
            this->Dequeue();
        }

        // Swap the roles of the two queues
        swap(this->arr, auxQueue->arr);
        swap(this->front, auxQueue->front);
        swap(this->back, auxQueue->back);
        swap(this->size, auxQueue->size);
    }

    void Pop() {
        if (this->isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        this->Dequeue();
    }

    int Top() {
        if (this->isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return this->Peek();
    }
};

class PopEfficientStack : public Queue<int> {
    Queue<int> *auxQueue;

public:
    PopEfficientStack(int capacity) : Queue<int>(capacity) {
        auxQueue = new Queue<int>(capacity);
    }

    ~PopEfficientStack() {
        delete auxQueue;
    }

    void Push(int value) {
        if (this->isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        this->Enqueue(value);
    }

    void Pop() {
        if (this->isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }

        // Move elements except the last one to auxQueue
        while (this->Size() > 1) {
            auxQueue->Enqueue(this->Peek());
            this->Dequeue();
        }

        // Remove the last element (top of the stack)
        this->Dequeue();

        // Restore elements from auxQueue back to the original queue
        while (!auxQueue->isEmpty()) {
            this->Enqueue(auxQueue->Peek());
            auxQueue->Dequeue();
        }
    }

    int Top() {
        if (this->isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        int topValue;
        // Move elements to find the top value
        while (!this->isEmpty()) {
            topValue = this->Peek();
            auxQueue->Enqueue(topValue);
            this->Dequeue();
        }

        // Restore elements back to the original queue
        while (!auxQueue->isEmpty()) {
            this->Enqueue(auxQueue->Peek());
            auxQueue->Dequeue();
        }

        return topValue;
    }
};

int main() {
    PopEfficientStack popStack(5);
    popStack.Push(1);
    cout << popStack.Top() << endl;
    popStack.Display();
    popStack.Push(2);
    cout << popStack.Top() << endl;
    popStack.Display();
    popStack.Push(3);
    cout << popStack.Top() << endl;
    popStack.Display();
    popStack.Push(4);
    cout << popStack.Top() << endl;
    popStack.Display();
    popStack.Push(5);
    cout << popStack.Top() << endl;
    popStack.Display();
    popStack.Pop();
    cout << popStack.Top() << endl;
    popStack.Display();
    popStack.Pop();
    cout << popStack.Top() << endl;
    popStack.Display();
    popStack.Pop();
    cout << popStack.Top() << endl;
    popStack.Display();
    popStack.Pop();
    cout << popStack.Top() << endl;
    popStack.Display();
    popStack.Pop();
    cout << popStack.Top() << endl;
    popStack.Display();
    popStack.Pop();
    cout << popStack.Top() << endl;
    popStack.Display();
    cout << "-----------------------------------------------------" << endl;

    return EXIT_SUCCESS;
}
