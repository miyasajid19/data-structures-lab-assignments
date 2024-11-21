#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void merger(vector<int>& arr, int start, int middle, int end) {
    int size1 = middle - start + 1;
    int size2 = end - middle;

    // Create temporary vectors
    vector<int> arr1(size1);
    vector<int> arr2(size2);

    // Copy data to temporary vectors
    for (int i = 0; i < size1; i++)
        arr1[i] = arr[start + i];
    for (int i = 0; i < size2; i++)
        arr2[i] = arr[middle + 1 + i];

    // Merge the temporary vectors back into the original array
    int i = 0, j = 0, k = start;
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            arr[k++] = arr1[i++];
        } else {
            arr[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1[], if any
    while (i < size1) {
        arr[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2[], if any
    while (j < size2) {
        arr[k++] = arr2[j++];
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int middle = start + (end - start) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);

        // Merge the sorted halves
        merger(arr, start, middle, end);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return EXIT_SUCCESS;
}
