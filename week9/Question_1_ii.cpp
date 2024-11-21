#include <iostream>
#include <cstdlib>
using namespace std;
class Heap
{
public:
    void heapify(int arr[], int size, int index)
    {
        int smallest = index;
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;

        if (leftIndex < size and arr[smallest] > arr[leftIndex])
            smallest = leftIndex;
        if (rightIndex < size and arr[smallest] > arr[rightIndex])
            smallest = rightIndex;
        if (smallest != index)
        {
            swap(arr[smallest], arr[index]);
            heapify(arr, size, smallest);
        }
    }
    void sortArr(int arr[], int size)
    {
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(arr, size, i);
        }
        for (int i = size - 1; i > 0; i--)
        {
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
    }
};
int main()
{
    Heap heap;
    int arr[] = {7, 8, 9, 0, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(int);
    cout << "unsorted array :: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << '\t';
    cout << endl;
    heap.sortArr(arr, size);
    cout << "sorted array :: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << '\t';
    cout << endl;
    return EXIT_SUCCESS;
}