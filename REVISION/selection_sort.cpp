#include <iostream>
#include <vector>
using namespace std;

// Selection Sort Function
void sort(vector<int>& arr) {
    if (arr.size() < 2) // No need to sort if the array has fewer than 2 elements
        return;

    for (int i = 0; i < arr.size() - 1; i++) {
        int minimum = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minimum]) // Find the smallest element in the unsorted part
                minimum = j;
        }
        if (minimum != i)
            swap(arr[i], arr[minimum]); // Swap the smallest element with the first unsorted element
    }
}

int main() {
    vector<int> arr = {3, 2, 1, 4, 5};
    sort(arr);

    for (auto x : arr)
        cout << x << "\t";

    return EXIT_SUCCESS;
}
