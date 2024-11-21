#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class PriorityHeap {
public:
    vector<int> heap;

    // Method to maintain the heap property (heapify)
    void heapify(int index) {
        int largest = index;
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;

        if (leftIndex < heap.size() && heap[leftIndex] > heap[largest]) {
            largest = leftIndex;
        }
        if (rightIndex < heap.size() && heap[rightIndex] > heap[largest]) {
            largest = rightIndex;
        }
        if (largest != index) {
            swap(heap[largest], heap[index]);
            heapify(largest);
        }
    }

    // Insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;

        // Rebalance the heap by moving the new element to its correct position
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Remove and return the root (highest priority)
    int remove() {
        if (heap.size() == 0) {
            throw runtime_error("Heap is empty");
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return root;
    }

    // Peek at the root (highest priority) without removing it
    int peek() {
        if (heap.size() == 0) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    // Get the current size of the heap
    int size() {
        return heap.size();
    }

    // Check if the heap is empty
    bool isEmpty() {
        return heap.size() == 0;
    }
};

int main() {
    PriorityHeap pq;
    
    // Insert elements into the priority heap
    pq.insert(7);
    pq.insert(8);
    pq.insert(9);
    pq.insert(0);
    pq.insert(5);
    
    cout << "Priority Heap (Max-Heap) contents: " << endl;
    while (!pq.isEmpty()) {
        cout << pq.remove() << " ";
    }
    cout << endl;
    
    return 0;
}
